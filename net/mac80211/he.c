// SPDX-License-Identifier: GPL-2.0-only
/*
 * HE handling
 *
 * Copyright(c) 2017 Intel Deutschland GmbH
 * Copyright(c) 2019 - 2020 Intel Corporation
 */

#include "ieee80211_i.h"

static void
ieee80211_update_from_he_6ghz_capa(const struct ieee80211_he_6ghz_capa *he_6ghz_capa,
				   struct sta_info *sta)
{
	enum ieee80211_smps_mode smps_mode;

	if (sta->sdata->vif.type == NL80211_IFTYPE_AP ||
	    sta->sdata->vif.type == NL80211_IFTYPE_AP_VLAN) {
		switch (le16_get_bits(he_6ghz_capa->capa,
				      IEEE80211_HE_6GHZ_CAP_SM_PS)) {
		case WLAN_HT_CAP_SM_PS_INVALID:
		case WLAN_HT_CAP_SM_PS_STATIC:
			smps_mode = IEEE80211_SMPS_STATIC;
			break;
		case WLAN_HT_CAP_SM_PS_DYNAMIC:
			smps_mode = IEEE80211_SMPS_DYNAMIC;
			break;
		case WLAN_HT_CAP_SM_PS_DISABLED:
			smps_mode = IEEE80211_SMPS_OFF;
			break;
		}

		sta->sta.smps_mode = smps_mode;
	} else {
		sta->sta.smps_mode = IEEE80211_SMPS_OFF;
	}

	switch (le16_get_bits(he_6ghz_capa->capa,
			      IEEE80211_HE_6GHZ_CAP_MAX_MPDU_LEN)) {
	case IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_11454:
		sta->sta.max_amsdu_len = IEEE80211_MAX_MPDU_LEN_VHT_11454;
		break;
	case IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_7991:
		sta->sta.max_amsdu_len = IEEE80211_MAX_MPDU_LEN_VHT_7991;
		break;
	case IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_3895:
	default:
		sta->sta.max_amsdu_len = IEEE80211_MAX_MPDU_LEN_VHT_3895;
		break;
	}

	sta->sta.he_6ghz_capa = *he_6ghz_capa;
}

void
ieee80211_he_cap_ie_to_sta_he_cap(struct ieee80211_sub_if_data *sdata,
				  struct ieee80211_supported_band *sband,
				  const u8 *he_cap_ie, u8 he_cap_len,
				  const struct ieee80211_he_6ghz_capa *he_6ghz_capa,
				  struct sta_info *sta)
{
	struct ieee80211_sta_he_cap *he_cap = &sta->sta.he_cap;
	struct ieee80211_he_cap_elem *he_cap_ie_elem = (void *)he_cap_ie;
	u8 he_ppe_size;
	u8 mcs_nss_size;
	u8 he_total_size;

	memset(he_cap, 0, sizeof(*he_cap));

	if (!he_cap_ie || !ieee80211_get_he_sta_cap(sband))
		return;

	/* Make sure size is OK */
	mcs_nss_size = ieee80211_he_mcs_nss_size(he_cap_ie_elem);
	he_ppe_size =
		ieee80211_he_ppe_size(he_cap_ie[sizeof(he_cap->he_cap_elem) +
						mcs_nss_size],
				      he_cap_ie_elem->phy_cap_info);
	he_total_size = sizeof(he_cap->he_cap_elem) + mcs_nss_size +
			he_ppe_size;
	if (he_cap_len < he_total_size)
		return;

	memcpy(&he_cap->he_cap_elem, he_cap_ie, sizeof(he_cap->he_cap_elem));

	/* HE Tx/Rx HE MCS NSS Support Field */
	memcpy(&he_cap->he_mcs_nss_supp,
	       &he_cap_ie[sizeof(he_cap->he_cap_elem)], mcs_nss_size);

	/* Check if there are (optional) PPE Thresholds */
	if (he_cap->he_cap_elem.phy_cap_info[6] &
	    IEEE80211_HE_PHY_CAP6_PPE_THRESHOLD_PRESENT)
		memcpy(he_cap->ppe_thres,
		       &he_cap_ie[sizeof(he_cap->he_cap_elem) + mcs_nss_size],
		       he_ppe_size);

	he_cap->has_he = true;

	sta->cur_max_bandwidth = ieee80211_sta_cap_rx_bw(sta);
	sta->sta.bandwidth = ieee80211_sta_cur_vht_bw(sta);

	if (sband->band == NL80211_BAND_6GHZ && he_6ghz_capa)
		ieee80211_update_from_he_6ghz_capa(he_6ghz_capa, sta);
}

void
ieee80211_he_op_ie_to_bss_conf(struct ieee80211_vif *vif,
			const struct ieee80211_he_operation *he_op_ie)
{
	memset(&vif->bss_conf.he_oper, 0, sizeof(vif->bss_conf.he_oper));
	if (!he_op_ie)
		return;

	vif->bss_conf.he_oper.params = __le32_to_cpu(he_op_ie->he_oper_params);
	vif->bss_conf.he_oper.nss_set = __le16_to_cpu(he_op_ie->he_mcs_nss_set);
}

void
ieee80211_he_spr_ie_to_bss_conf(struct ieee80211_vif *vif,
				const struct ieee80211_he_spr *he_spr_ie_elem)
{
	struct ieee80211_he_obss_pd *he_obss_pd =
					&vif->bss_conf.he_obss_pd;
	const u8 *data;

	memset(he_obss_pd, 0, sizeof(*he_obss_pd));

	if (!he_spr_ie_elem)
		return;
	data = he_spr_ie_elem->optional;

	if (he_spr_ie_elem->he_sr_control &
	    IEEE80211_HE_SPR_NON_SRG_OFFSET_PRESENT)
		data++;
	if (he_spr_ie_elem->he_sr_control &
	    IEEE80211_HE_SPR_SRG_INFORMATION_PRESENT) {
		he_obss_pd->max_offset = *data++;
		he_obss_pd->min_offset = *data++;
		he_obss_pd->enable = true;
	}
}
