// SPDX-License-Identifier: GPL-2.0-or-later
/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  RPC Pipe client / server routines
 *  Copyright (C) Luke Kenneth Casson Leighton 1997-2001.
 */

/* NT error codes - see nterr.h */
#include <linux/types.h>
#include <linux/fs.h>
#include "nterr.h"

const struct nt_err_code_struct nt_errs[] = {
	{"NT_STATUS_OK", NT_STATUS_OK},
	{"NT_STATUS_UNSUCCESSFUL", NT_STATUS_UNSUCCESSFUL},
	{"NT_STATUS_NOT_IMPLEMENTED", NT_STATUS_NOT_IMPLEMENTED},
	{"NT_STATUS_INVALID_INFO_CLASS", NT_STATUS_INVALID_INFO_CLASS},
	{"NT_STATUS_INFO_LENGTH_MISMATCH", NT_STATUS_INFO_LENGTH_MISMATCH},
	{"NT_STATUS_ACCESS_VIOLATION", NT_STATUS_ACCESS_VIOLATION},
	{"NT_STATUS_BUFFER_OVERFLOW", NT_STATUS_BUFFER_OVERFLOW},
	{"NT_STATUS_IN_PAGE_ERROR", NT_STATUS_IN_PAGE_ERROR},
	{"NT_STATUS_PAGEFILE_QUOTA", NT_STATUS_PAGEFILE_QUOTA},
	{"NT_STATUS_INVALID_HANDLE", NT_STATUS_INVALID_HANDLE},
	{"NT_STATUS_BAD_INITIAL_STACK", NT_STATUS_BAD_INITIAL_STACK},
	{"NT_STATUS_BAD_INITIAL_PC", NT_STATUS_BAD_INITIAL_PC},
	{"NT_STATUS_INVALID_CID", NT_STATUS_INVALID_CID},
	{"NT_STATUS_TIMER_NOT_CANCELED", NT_STATUS_TIMER_NOT_CANCELED},
	{"NT_STATUS_INVALID_PARAMETER", NT_STATUS_INVALID_PARAMETER},
	{"NT_STATUS_NO_SUCH_DEVICE", NT_STATUS_NO_SUCH_DEVICE},
	{"NT_STATUS_NO_SUCH_FILE", NT_STATUS_NO_SUCH_FILE},
	{"NT_STATUS_INVALID_DEVICE_REQUEST",
	 NT_STATUS_INVALID_DEVICE_REQUEST},
	{"NT_STATUS_END_OF_FILE", NT_STATUS_END_OF_FILE},
	{"NT_STATUS_WRONG_VOLUME", NT_STATUS_WRONG_VOLUME},
	{"NT_STATUS_NO_MEDIA_IN_DEVICE", NT_STATUS_NO_MEDIA_IN_DEVICE},
	{"NT_STATUS_UNRECOGNIZED_MEDIA", NT_STATUS_UNRECOGNIZED_MEDIA},
	{"NT_STATUS_NONEXISTENT_SECTOR", NT_STATUS_NONEXISTENT_SECTOR},
	{"NT_STATUS_MORE_PROCESSING_REQUIRED",
	 NT_STATUS_MORE_PROCESSING_REQUIRED},
	{"NT_STATUS_NO_MEMORY", NT_STATUS_NO_MEMORY},
	{"NT_STATUS_CONFLICTING_ADDRESSES",
	 NT_STATUS_CONFLICTING_ADDRESSES},
	{"NT_STATUS_NOT_MAPPED_VIEW", NT_STATUS_NOT_MAPPED_VIEW},
	{"NT_STATUS_UNABLE_TO_FREE_VM", NT_STATUS_UNABLE_TO_FREE_VM},
	{"NT_STATUS_UNABLE_TO_DELETE_SECTION",
	 NT_STATUS_UNABLE_TO_DELETE_SECTION},
	{"NT_STATUS_INVALID_SYSTEM_SERVICE",
	 NT_STATUS_INVALID_SYSTEM_SERVICE},
	{"NT_STATUS_ILLEGAL_INSTRUCTION", NT_STATUS_ILLEGAL_INSTRUCTION},
	{"NT_STATUS_INVALID_LOCK_SEQUENCE",
	 NT_STATUS_INVALID_LOCK_SEQUENCE},
	{"NT_STATUS_INVALID_VIEW_SIZE", NT_STATUS_INVALID_VIEW_SIZE},
	{"NT_STATUS_INVALID_FILE_FOR_SECTION",
	 NT_STATUS_INVALID_FILE_FOR_SECTION},
	{"NT_STATUS_ALREADY_COMMITTED", NT_STATUS_ALREADY_COMMITTED},
	{"NT_STATUS_ACCESS_DENIED", NT_STATUS_ACCESS_DENIED},
	{"NT_STATUS_BUFFER_TOO_SMALL", NT_STATUS_BUFFER_TOO_SMALL},
	{"NT_STATUS_OBJECT_TYPE_MISMATCH", NT_STATUS_OBJECT_TYPE_MISMATCH},
	{"NT_STATUS_NONCONTINUABLE_EXCEPTION",
	 NT_STATUS_NONCONTINUABLE_EXCEPTION},
	{"NT_STATUS_INVALID_DISPOSITION", NT_STATUS_INVALID_DISPOSITION},
	{"NT_STATUS_UNWIND", NT_STATUS_UNWIND},
	{"NT_STATUS_BAD_STACK", NT_STATUS_BAD_STACK},
	{"NT_STATUS_INVALID_UNWIND_TARGET",
	 NT_STATUS_INVALID_UNWIND_TARGET},
	{"NT_STATUS_NOT_LOCKED", NT_STATUS_NOT_LOCKED},
	{"NT_STATUS_PARITY_ERROR", NT_STATUS_PARITY_ERROR},
	{"NT_STATUS_UNABLE_TO_DECOMMIT_VM",
	 NT_STATUS_UNABLE_TO_DECOMMIT_VM},
	{"NT_STATUS_NOT_COMMITTED", NT_STATUS_NOT_COMMITTED},
	{"NT_STATUS_INVALID_PORT_ATTRIBUTES",
	 NT_STATUS_INVALID_PORT_ATTRIBUTES},
	{"NT_STATUS_PORT_MESSAGE_TOO_LONG",
	 NT_STATUS_PORT_MESSAGE_TOO_LONG},
	{"NT_STATUS_INVALID_PARAMETER_MIX",
	 NT_STATUS_INVALID_PARAMETER_MIX},
	{"NT_STATUS_INVALID_QUOTA_LOWER", NT_STATUS_INVALID_QUOTA_LOWER},
	{"NT_STATUS_DISK_CORRUPT_ERROR", NT_STATUS_DISK_CORRUPT_ERROR},
	{"NT_STATUS_OBJECT_NAME_INVALID", NT_STATUS_OBJECT_NAME_INVALID},
	{"NT_STATUS_OBJECT_NAME_NOT_FOUND",
	 NT_STATUS_OBJECT_NAME_NOT_FOUND},
	{"NT_STATUS_OBJECT_NAME_COLLISION",
	 NT_STATUS_OBJECT_NAME_COLLISION},
	{"NT_STATUS_HANDLE_NOT_WAITABLE", NT_STATUS_HANDLE_NOT_WAITABLE},
	{"NT_STATUS_PORT_DISCONNECTED", NT_STATUS_PORT_DISCONNECTED},
	{"NT_STATUS_DEVICE_ALREADY_ATTACHED",
	 NT_STATUS_DEVICE_ALREADY_ATTACHED},
	{"NT_STATUS_OBJECT_PATH_INVALID", NT_STATUS_OBJECT_PATH_INVALID},
	{"NT_STATUS_OBJECT_PATH_NOT_FOUND",
	 NT_STATUS_OBJECT_PATH_NOT_FOUND},
	{"NT_STATUS_OBJECT_PATH_SYNTAX_BAD",
	 NT_STATUS_OBJECT_PATH_SYNTAX_BAD},
	{"NT_STATUS_DATA_OVERRUN", NT_STATUS_DATA_OVERRUN},
	{"NT_STATUS_DATA_LATE_ERROR", NT_STATUS_DATA_LATE_ERROR},
	{"NT_STATUS_DATA_ERROR", NT_STATUS_DATA_ERROR},
	{"NT_STATUS_CRC_ERROR", NT_STATUS_CRC_ERROR},
	{"NT_STATUS_SECTION_TOO_BIG", NT_STATUS_SECTION_TOO_BIG},
	{"NT_STATUS_PORT_CONNECTION_REFUSED",
	 NT_STATUS_PORT_CONNECTION_REFUSED},
	{"NT_STATUS_INVALID_PORT_HANDLE", NT_STATUS_INVALID_PORT_HANDLE},
	{"NT_STATUS_SHARING_VIOLATION", NT_STATUS_SHARING_VIOLATION},
	{"NT_STATUS_QUOTA_EXCEEDED", NT_STATUS_QUOTA_EXCEEDED},
	{"NT_STATUS_INVALID_PAGE_PROTECTION",
	 NT_STATUS_INVALID_PAGE_PROTECTION},
	{"NT_STATUS_MUTANT_NOT_OWNED", NT_STATUS_MUTANT_NOT_OWNED},
	{"NT_STATUS_SEMAPHORE_LIMIT_EXCEEDED",
	 NT_STATUS_SEMAPHORE_LIMIT_EXCEEDED},
	{"NT_STATUS_PORT_ALREADY_SET", NT_STATUS_PORT_ALREADY_SET},
	{"NT_STATUS_SECTION_NOT_IMAGE", NT_STATUS_SECTION_NOT_IMAGE},
	{"NT_STATUS_SUSPEND_COUNT_EXCEEDED",
	 NT_STATUS_SUSPEND_COUNT_EXCEEDED},
	{"NT_STATUS_THREAD_IS_TERMINATING",
	 NT_STATUS_THREAD_IS_TERMINATING},
	{"NT_STATUS_BAD_WORKING_SET_LIMIT",
	 NT_STATUS_BAD_WORKING_SET_LIMIT},
	{"NT_STATUS_INCOMPATIBLE_FILE_MAP",
	 NT_STATUS_INCOMPATIBLE_FILE_MAP},
	{"NT_STATUS_SECTION_PROTECTION", NT_STATUS_SECTION_PROTECTION},
	{"NT_STATUS_EAS_NOT_SUPPORTED", NT_STATUS_EAS_NOT_SUPPORTED},
	{"NT_STATUS_EA_TOO_LARGE", NT_STATUS_EA_TOO_LARGE},
	{"NT_STATUS_NONEXISTENT_EA_ENTRY", NT_STATUS_NONEXISTENT_EA_ENTRY},
	{"NT_STATUS_NO_EAS_ON_FILE", NT_STATUS_NO_EAS_ON_FILE},
	{"NT_STATUS_EA_CORRUPT_ERROR", NT_STATUS_EA_CORRUPT_ERROR},
	{"NT_STATUS_FILE_LOCK_CONFLICT", NT_STATUS_FILE_LOCK_CONFLICT},
	{"NT_STATUS_LOCK_NOT_GRANTED", NT_STATUS_LOCK_NOT_GRANTED},
	{"NT_STATUS_DELETE_PENDING", NT_STATUS_DELETE_PENDING},
	{"NT_STATUS_CTL_FILE_NOT_SUPPORTED",
	 NT_STATUS_CTL_FILE_NOT_SUPPORTED},
	{"NT_STATUS_UNKNOWN_REVISION", NT_STATUS_UNKNOWN_REVISION},
	{"NT_STATUS_REVISION_MISMATCH", NT_STATUS_REVISION_MISMATCH},
	{"NT_STATUS_INVALID_OWNER", NT_STATUS_INVALID_OWNER},
	{"NT_STATUS_INVALID_PRIMARY_GROUP",
	 NT_STATUS_INVALID_PRIMARY_GROUP},
	{"NT_STATUS_NO_IMPERSONATION_TOKEN",
	 NT_STATUS_NO_IMPERSONATION_TOKEN},
	{"NT_STATUS_CANT_DISABLE_MANDATORY",
	 NT_STATUS_CANT_DISABLE_MANDATORY},
	{"NT_STATUS_NO_LOGON_SERVERS", NT_STATUS_NO_LOGON_SERVERS},
	{"NT_STATUS_NO_SUCH_LOGON_SESSION",
	 NT_STATUS_NO_SUCH_LOGON_SESSION},
	{"NT_STATUS_NO_SUCH_PRIVILEGE", NT_STATUS_NO_SUCH_PRIVILEGE},
	{"NT_STATUS_PRIVILEGE_NOT_HELD", NT_STATUS_PRIVILEGE_NOT_HELD},
	{"NT_STATUS_INVALID_ACCOUNT_NAME", NT_STATUS_INVALID_ACCOUNT_NAME},
	{"NT_STATUS_USER_EXISTS", NT_STATUS_USER_EXISTS},
	{"NT_STATUS_NO_SUCH_USER", NT_STATUS_NO_SUCH_USER},
	{"NT_STATUS_GROUP_EXISTS", NT_STATUS_GROUP_EXISTS},
	{"NT_STATUS_NO_SUCH_GROUP", NT_STATUS_NO_SUCH_GROUP},
	{"NT_STATUS_MEMBER_IN_GROUP", NT_STATUS_MEMBER_IN_GROUP},
	{"NT_STATUS_MEMBER_NOT_IN_GROUP", NT_STATUS_MEMBER_NOT_IN_GROUP},
	{"NT_STATUS_LAST_ADMIN", NT_STATUS_LAST_ADMIN},
	{"NT_STATUS_WRONG_PASSWORD", NT_STATUS_WRONG_PASSWORD},
	{"NT_STATUS_ILL_FORMED_PASSWORD", NT_STATUS_ILL_FORMED_PASSWORD},
	{"NT_STATUS_PASSWORD_RESTRICTION", NT_STATUS_PASSWORD_RESTRICTION},
	{"NT_STATUS_LOGON_FAILURE", NT_STATUS_LOGON_FAILURE},
	{"NT_STATUS_ACCOUNT_RESTRICTION", NT_STATUS_ACCOUNT_RESTRICTION},
	{"NT_STATUS_INVALID_LOGON_HOURS", NT_STATUS_INVALID_LOGON_HOURS},
	{"NT_STATUS_INVALID_WORKSTATION", NT_STATUS_INVALID_WORKSTATION},
	{"NT_STATUS_PASSWORD_EXPIRED", NT_STATUS_PASSWORD_EXPIRED},
	{"NT_STATUS_ACCOUNT_DISABLED", NT_STATUS_ACCOUNT_DISABLED},
	{"NT_STATUS_NONE_MAPPED", NT_STATUS_NONE_MAPPED},
	{"NT_STATUS_TOO_MANY_LUIDS_REQUESTED",
	 NT_STATUS_TOO_MANY_LUIDS_REQUESTED},
	{"NT_STATUS_LUIDS_EXHAUSTED", NT_STATUS_LUIDS_EXHAUSTED},
	{"NT_STATUS_INVALID_SUB_AUTHORITY",
	 NT_STATUS_INVALID_SUB_AUTHORITY},
	{"NT_STATUS_INVALID_ACL", NT_STATUS_INVALID_ACL},
	{"NT_STATUS_INVALID_SID", NT_STATUS_INVALID_SID},
	{"NT_STATUS_INVALID_SECURITY_DESCR",
	 NT_STATUS_INVALID_SECURITY_DESCR},
	{"NT_STATUS_PROCEDURE_NOT_FOUND", NT_STATUS_PROCEDURE_NOT_FOUND},
	{"NT_STATUS_INVALID_IMAGE_FORMAT", NT_STATUS_INVALID_IMAGE_FORMAT},
	{"NT_STATUS_NO_TOKEN", NT_STATUS_NO_TOKEN},
	{"NT_STATUS_BAD_INHERITANCE_ACL", NT_STATUS_BAD_INHERITANCE_ACL},
	{"NT_STATUS_RANGE_NOT_LOCKED", NT_STATUS_RANGE_NOT_LOCKED},
	{"NT_STATUS_DISK_FULL", NT_STATUS_DISK_FULL},
	{"NT_STATUS_SERVER_DISABLED", NT_STATUS_SERVER_DISABLED},
	{"NT_STATUS_SERVER_NOT_DISABLED", NT_STATUS_SERVER_NOT_DISABLED},
	{"NT_STATUS_TOO_MANY_GUIDS_REQUESTED",
	 NT_STATUS_TOO_MANY_GUIDS_REQUESTED},
	{"NT_STATUS_GUIDS_EXHAUSTED", NT_STATUS_GUIDS_EXHAUSTED},
	{"NT_STATUS_INVALID_ID_AUTHORITY", NT_STATUS_INVALID_ID_AUTHORITY},
	{"NT_STATUS_AGENTS_EXHAUSTED", NT_STATUS_AGENTS_EXHAUSTED},
	{"NT_STATUS_INVALID_VOLUME_LABEL", NT_STATUS_INVALID_VOLUME_LABEL},
	{"NT_STATUS_SECTION_NOT_EXTENDED", NT_STATUS_SECTION_NOT_EXTENDED},
	{"NT_STATUS_NOT_MAPPED_DATA", NT_STATUS_NOT_MAPPED_DATA},
	{"NT_STATUS_RESOURCE_DATA_NOT_FOUND",
	 NT_STATUS_RESOURCE_DATA_NOT_FOUND},
	{"NT_STATUS_RESOURCE_TYPE_NOT_FOUND",
	 NT_STATUS_RESOURCE_TYPE_NOT_FOUND},
	{"NT_STATUS_RESOURCE_NAME_NOT_FOUND",
	 NT_STATUS_RESOURCE_NAME_NOT_FOUND},
	{"NT_STATUS_ARRAY_BOUNDS_EXCEEDED",
	 NT_STATUS_ARRAY_BOUNDS_EXCEEDED},
	{"NT_STATUS_FLOAT_DENORMAL_OPERAND",
	 NT_STATUS_FLOAT_DENORMAL_OPERAND},
	{"NT_STATUS_FLOAT_DIVIDE_BY_ZERO", NT_STATUS_FLOAT_DIVIDE_BY_ZERO},
	{"NT_STATUS_FLOAT_INEXACT_RESULT", NT_STATUS_FLOAT_INEXACT_RESULT},
	{"NT_STATUS_FLOAT_INVALID_OPERATION",
	 NT_STATUS_FLOAT_INVALID_OPERATION},
	{"NT_STATUS_FLOAT_OVERFLOW", NT_STATUS_FLOAT_OVERFLOW},
	{"NT_STATUS_FLOAT_STACK_CHECK", NT_STATUS_FLOAT_STACK_CHECK},
	{"NT_STATUS_FLOAT_UNDERFLOW", NT_STATUS_FLOAT_UNDERFLOW},
	{"NT_STATUS_INTEGER_DIVIDE_BY_ZERO",
	 NT_STATUS_INTEGER_DIVIDE_BY_ZERO},
	{"NT_STATUS_INTEGER_OVERFLOW", NT_STATUS_INTEGER_OVERFLOW},
	{"NT_STATUS_PRIVILEGED_INSTRUCTION",
	 NT_STATUS_PRIVILEGED_INSTRUCTION},
	{"NT_STATUS_TOO_MANY_PAGING_FILES",
	 NT_STATUS_TOO_MANY_PAGING_FILES},
	{"NT_STATUS_FILE_INVALID", NT_STATUS_FILE_INVALID},
	{"NT_STATUS_ALLOTTED_SPACE_EXCEEDED",
	 NT_STATUS_ALLOTTED_SPACE_EXCEEDED},
	{"NT_STATUS_INSUFFICIENT_RESOURCES",
	 NT_STATUS_INSUFFICIENT_RESOURCES},
	{"NT_STATUS_DFS_EXIT_PATH_FOUND", NT_STATUS_DFS_EXIT_PATH_FOUND},
	{"NT_STATUS_DEVICE_DATA_ERROR", NT_STATUS_DEVICE_DATA_ERROR},
	{"NT_STATUS_DEVICE_NOT_CONNECTED", NT_STATUS_DEVICE_NOT_CONNECTED},
	{"NT_STATUS_DEVICE_POWER_FAILURE", NT_STATUS_DEVICE_POWER_FAILURE},
	{"NT_STATUS_FREE_VM_NOT_AT_BASE", NT_STATUS_FREE_VM_NOT_AT_BASE},
	{"NT_STATUS_MEMORY_NOT_ALLOCATED", NT_STATUS_MEMORY_NOT_ALLOCATED},
	{"NT_STATUS_WORKING_SET_QUOTA", NT_STATUS_WORKING_SET_QUOTA},
	{"NT_STATUS_MEDIA_WRITE_PROTECTED",
	 NT_STATUS_MEDIA_WRITE_PROTECTED},
	{"NT_STATUS_DEVICE_NOT_READY", NT_STATUS_DEVICE_NOT_READY},
	{"NT_STATUS_INVALID_GROUP_ATTRIBUTES",
	 NT_STATUS_INVALID_GROUP_ATTRIBUTES},
	{"NT_STATUS_BAD_IMPERSONATION_LEVEL",
	 NT_STATUS_BAD_IMPERSONATION_LEVEL},
	{"NT_STATUS_CANT_OPEN_ANONYMOUS", NT_STATUS_CANT_OPEN_ANONYMOUS},
	{"NT_STATUS_BAD_VALIDATION_CLASS", NT_STATUS_BAD_VALIDATION_CLASS},
	{"NT_STATUS_BAD_TOKEN_TYPE", NT_STATUS_BAD_TOKEN_TYPE},
	{"NT_STATUS_BAD_MASTER_BOOT_RECORD",
	 NT_STATUS_BAD_MASTER_BOOT_RECORD},
	{"NT_STATUS_INSTRUCTION_MISALIGNMENT",
	 NT_STATUS_INSTRUCTION_MISALIGNMENT},
	{"NT_STATUS_INSTANCE_NOT_AVAILABLE",
	 NT_STATUS_INSTANCE_NOT_AVAILABLE},
	{"NT_STATUS_PIPE_NOT_AVAILABLE", NT_STATUS_PIPE_NOT_AVAILABLE},
	{"NT_STATUS_INVALID_PIPE_STATE", NT_STATUS_INVALID_PIPE_STATE},
	{"NT_STATUS_PIPE_BUSY", NT_STATUS_PIPE_BUSY},
	{"NT_STATUS_ILLEGAL_FUNCTION", NT_STATUS_ILLEGAL_FUNCTION},
	{"NT_STATUS_PIPE_DISCONNECTED", NT_STATUS_PIPE_DISCONNECTED},
	{"NT_STATUS_PIPE_CLOSING", NT_STATUS_PIPE_CLOSING},
	{"NT_STATUS_PIPE_CONNECTED", NT_STATUS_PIPE_CONNECTED},
	{"NT_STATUS_PIPE_LISTENING", NT_STATUS_PIPE_LISTENING},
	{"NT_STATUS_INVALID_READ_MODE", NT_STATUS_INVALID_READ_MODE},
	{"NT_STATUS_IO_TIMEOUT", NT_STATUS_IO_TIMEOUT},
	{"NT_STATUS_FILE_FORCED_CLOSED", NT_STATUS_FILE_FORCED_CLOSED},
	{"NT_STATUS_PROFILING_NOT_STARTED",
	 NT_STATUS_PROFILING_NOT_STARTED},
	{"NT_STATUS_PROFILING_NOT_STOPPED",
	 NT_STATUS_PROFILING_NOT_STOPPED},
	{"NT_STATUS_COULD_NOT_INTERPRET", NT_STATUS_COULD_NOT_INTERPRET},
	{"NT_STATUS_FILE_IS_A_DIRECTORY", NT_STATUS_FILE_IS_A_DIRECTORY},
	{"NT_STATUS_NOT_SUPPORTED", NT_STATUS_NOT_SUPPORTED},
	{"NT_STATUS_REMOTE_NOT_LISTENING", NT_STATUS_REMOTE_NOT_LISTENING},
	{"NT_STATUS_DUPLICATE_NAME", NT_STATUS_DUPLICATE_NAME},
	{"NT_STATUS_BAD_NETWORK_PATH", NT_STATUS_BAD_NETWORK_PATH},
	{"NT_STATUS_NETWORK_BUSY", NT_STATUS_NETWORK_BUSY},
	{"NT_STATUS_DEVICE_DOES_NOT_EXIST",
	 NT_STATUS_DEVICE_DOES_NOT_EXIST},
	{"NT_STATUS_TOO_MANY_COMMANDS", NT_STATUS_TOO_MANY_COMMANDS},
	{"NT_STATUS_ADAPTER_HARDWARE_ERROR",
	 NT_STATUS_ADAPTER_HARDWARE_ERROR},
	{"NT_STATUS_INVALID_NETWORK_RESPONSE",
	 NT_STATUS_INVALID_NETWORK_RESPONSE},
	{"NT_STATUS_UNEXPECTED_NETWORK_ERROR",
	 NT_STATUS_UNEXPECTED_NETWORK_ERROR},
	{"NT_STATUS_BAD_REMOTE_ADAPTER", NT_STATUS_BAD_REMOTE_ADAPTER},
	{"NT_STATUS_PRINT_QUEUE_FULL", NT_STATUS_PRINT_QUEUE_FULL},
	{"NT_STATUS_NO_SPOOL_SPACE", NT_STATUS_NO_SPOOL_SPACE},
	{"NT_STATUS_PRINT_CANCELLED", NT_STATUS_PRINT_CANCELLED},
	{"NT_STATUS_NETWORK_NAME_DELETED", NT_STATUS_NETWORK_NAME_DELETED},
	{"NT_STATUS_NETWORK_ACCESS_DENIED",
	 NT_STATUS_NETWORK_ACCESS_DENIED},
	{"NT_STATUS_BAD_DEVICE_TYPE", NT_STATUS_BAD_DEVICE_TYPE},
	{"NT_STATUS_BAD_NETWORK_NAME", NT_STATUS_BAD_NETWORK_NAME},
	{"NT_STATUS_TOO_MANY_NAMES", NT_STATUS_TOO_MANY_NAMES},
	{"NT_STATUS_TOO_MANY_SESSIONS", NT_STATUS_TOO_MANY_SESSIONS},
	{"NT_STATUS_SHARING_PAUSED", NT_STATUS_SHARING_PAUSED},
	{"NT_STATUS_REQUEST_NOT_ACCEPTED", NT_STATUS_REQUEST_NOT_ACCEPTED},
	{"NT_STATUS_REDIRECTOR_PAUSED", NT_STATUS_REDIRECTOR_PAUSED},
	{"NT_STATUS_NET_WRITE_FAULT", NT_STATUS_NET_WRITE_FAULT},
	{"NT_STATUS_PROFILING_AT_LIMIT", NT_STATUS_PROFILING_AT_LIMIT},
	{"NT_STATUS_NOT_SAME_DEVICE", NT_STATUS_NOT_SAME_DEVICE},
	{"NT_STATUS_FILE_RENAMED", NT_STATUS_FILE_RENAMED},
	{"NT_STATUS_VIRTUAL_CIRCUIT_CLOSED",
	 NT_STATUS_VIRTUAL_CIRCUIT_CLOSED},
	{"NT_STATUS_NO_SECURITY_ON_OBJECT",
	 NT_STATUS_NO_SECURITY_ON_OBJECT},
	{"NT_STATUS_CANT_WAIT", NT_STATUS_CANT_WAIT},
	{"NT_STATUS_PIPE_EMPTY", NT_STATUS_PIPE_EMPTY},
	{"NT_STATUS_CANT_ACCESS_DOMAIN_INFO",
	 NT_STATUS_CANT_ACCESS_DOMAIN_INFO},
	{"NT_STATUS_CANT_TERMINATE_SELF", NT_STATUS_CANT_TERMINATE_SELF},
	{"NT_STATUS_INVALID_SERVER_STATE", NT_STATUS_INVALID_SERVER_STATE},
	{"NT_STATUS_INVALID_DOMAIN_STATE", NT_STATUS_INVALID_DOMAIN_STATE},
	{"NT_STATUS_INVALID_DOMAIN_ROLE", NT_STATUS_INVALID_DOMAIN_ROLE},
	{"NT_STATUS_NO_SUCH_DOMAIN", NT_STATUS_NO_SUCH_DOMAIN},
	{"NT_STATUS_DOMAIN_EXISTS", NT_STATUS_DOMAIN_EXISTS},
	{"NT_STATUS_DOMAIN_LIMIT_EXCEEDED",
	 NT_STATUS_DOMAIN_LIMIT_EXCEEDED},
	{"NT_STATUS_OPLOCK_NOT_GRANTED", NT_STATUS_OPLOCK_NOT_GRANTED},
	{"NT_STATUS_INVALID_OPLOCK_PROTOCOL",
	 NT_STATUS_INVALID_OPLOCK_PROTOCOL},
	{"NT_STATUS_INTERNAL_DB_CORRUPTION",
	 NT_STATUS_INTERNAL_DB_CORRUPTION},
	{"NT_STATUS_INTERNAL_ERROR", NT_STATUS_INTERNAL_ERROR},
	{"NT_STATUS_GENERIC_NOT_MAPPED", NT_STATUS_GENERIC_NOT_MAPPED},
	{"NT_STATUS_BAD_DESCRIPTOR_FORMAT",
	 NT_STATUS_BAD_DESCRIPTOR_FORMAT},
	{"NT_STATUS_INVALID_USER_BUFFER", NT_STATUS_INVALID_USER_BUFFER},
	{"NT_STATUS_UNEXPECTED_IO_ERROR", NT_STATUS_UNEXPECTED_IO_ERROR},
	{"NT_STATUS_UNEXPECTED_MM_CREATE_ERR",
	 NT_STATUS_UNEXPECTED_MM_CREATE_ERR},
	{"NT_STATUS_UNEXPECTED_MM_MAP_ERROR",
	 NT_STATUS_UNEXPECTED_MM_MAP_ERROR},
	{"NT_STATUS_UNEXPECTED_MM_EXTEND_ERR",
	 NT_STATUS_UNEXPECTED_MM_EXTEND_ERR},
	{"NT_STATUS_NOT_LOGON_PROCESS", NT_STATUS_NOT_LOGON_PROCESS},
	{"NT_STATUS_LOGON_SESSION_EXISTS", NT_STATUS_LOGON_SESSION_EXISTS},
	{"NT_STATUS_INVALID_PARAMETER_1", NT_STATUS_INVALID_PARAMETER_1},
	{"NT_STATUS_INVALID_PARAMETER_2", NT_STATUS_INVALID_PARAMETER_2},
	{"NT_STATUS_INVALID_PARAMETER_3", NT_STATUS_INVALID_PARAMETER_3},
	{"NT_STATUS_INVALID_PARAMETER_4", NT_STATUS_INVALID_PARAMETER_4},
	{"NT_STATUS_INVALID_PARAMETER_5", NT_STATUS_INVALID_PARAMETER_5},
	{"NT_STATUS_INVALID_PARAMETER_6", NT_STATUS_INVALID_PARAMETER_6},
	{"NT_STATUS_INVALID_PARAMETER_7", NT_STATUS_INVALID_PARAMETER_7},
	{"NT_STATUS_INVALID_PARAMETER_8", NT_STATUS_INVALID_PARAMETER_8},
	{"NT_STATUS_INVALID_PARAMETER_9", NT_STATUS_INVALID_PARAMETER_9},
	{"NT_STATUS_INVALID_PARAMETER_10", NT_STATUS_INVALID_PARAMETER_10},
	{"NT_STATUS_INVALID_PARAMETER_11", NT_STATUS_INVALID_PARAMETER_11},
	{"NT_STATUS_INVALID_PARAMETER_12", NT_STATUS_INVALID_PARAMETER_12},
	{"NT_STATUS_REDIRECTOR_NOT_STARTED",
	 NT_STATUS_REDIRECTOR_NOT_STARTED},
	{"NT_STATUS_REDIRECTOR_STARTED", NT_STATUS_REDIRECTOR_STARTED},
	{"NT_STATUS_STACK_OVERFLOW", NT_STATUS_STACK_OVERFLOW},
	{"NT_STATUS_NO_SUCH_PACKAGE", NT_STATUS_NO_SUCH_PACKAGE},
	{"NT_STATUS_BAD_FUNCTION_TABLE", NT_STATUS_BAD_FUNCTION_TABLE},
	{"NT_STATUS_DIRECTORY_NOT_EMPTY", NT_STATUS_DIRECTORY_NOT_EMPTY},
	{"NT_STATUS_FILE_CORRUPT_ERROR", NT_STATUS_FILE_CORRUPT_ERROR},
	{"NT_STATUS_NOT_A_DIRECTORY", NT_STATUS_NOT_A_DIRECTORY},
	{"NT_STATUS_BAD_LOGON_SESSION_STATE",
	 NT_STATUS_BAD_LOGON_SESSION_STATE},
	{"NT_STATUS_LOGON_SESSION_COLLISION",
	 NT_STATUS_LOGON_SESSION_COLLISION},
	{"NT_STATUS_NAME_TOO_LONG", NT_STATUS_NAME_TOO_LONG},
	{"NT_STATUS_FILES_OPEN", NT_STATUS_FILES_OPEN},
	{"NT_STATUS_CONNECTION_IN_USE", NT_STATUS_CONNECTION_IN_USE},
	{"NT_STATUS_MESSAGE_NOT_FOUND", NT_STATUS_MESSAGE_NOT_FOUND},
	{"NT_STATUS_PROCESS_IS_TERMINATING",
	 NT_STATUS_PROCESS_IS_TERMINATING},
	{"NT_STATUS_INVALID_LOGON_TYPE", NT_STATUS_INVALID_LOGON_TYPE},
	{"NT_STATUS_NO_GUID_TRANSLATION", NT_STATUS_NO_GUID_TRANSLATION},
	{"NT_STATUS_CANNOT_IMPERSONATE", NT_STATUS_CANNOT_IMPERSONATE},
	{"NT_STATUS_IMAGE_ALREADY_LOADED", NT_STATUS_IMAGE_ALREADY_LOADED},
	{"NT_STATUS_ABIOS_NOT_PRESENT", NT_STATUS_ABIOS_NOT_PRESENT},
	{"NT_STATUS_ABIOS_LID_NOT_EXIST", NT_STATUS_ABIOS_LID_NOT_EXIST},
	{"NT_STATUS_ABIOS_LID_ALREADY_OWNED",
	 NT_STATUS_ABIOS_LID_ALREADY_OWNED},
	{"NT_STATUS_ABIOS_NOT_LID_OWNER", NT_STATUS_ABIOS_NOT_LID_OWNER},
	{"NT_STATUS_ABIOS_INVALID_COMMAND",
	 NT_STATUS_ABIOS_INVALID_COMMAND},
	{"NT_STATUS_ABIOS_INVALID_LID", NT_STATUS_ABIOS_INVALID_LID},
	{"NT_STATUS_ABIOS_SELECTOR_NOT_AVAILABLE",
	 NT_STATUS_ABIOS_SELECTOR_NOT_AVAILABLE},
	{"NT_STATUS_ABIOS_INVALID_SELECTOR",
	 NT_STATUS_ABIOS_INVALID_SELECTOR},
	{"NT_STATUS_NO_LDT", NT_STATUS_NO_LDT},
	{"NT_STATUS_INVALID_LDT_SIZE", NT_STATUS_INVALID_LDT_SIZE},
	{"NT_STATUS_INVALID_LDT_OFFSET", NT_STATUS_INVALID_LDT_OFFSET},
	{"NT_STATUS_INVALID_LDT_DESCRIPTOR",
	 NT_STATUS_INVALID_LDT_DESCRIPTOR},
	{"NT_STATUS_INVALID_IMAGE_NE_FORMAT",
	 NT_STATUS_INVALID_IMAGE_NE_FORMAT},
	{"NT_STATUS_RXACT_INVALID_STATE", NT_STATUS_RXACT_INVALID_STATE},
	{"NT_STATUS_RXACT_COMMIT_FAILURE", NT_STATUS_RXACT_COMMIT_FAILURE},
	{"NT_STATUS_MAPPED_FILE_SIZE_ZERO",
	 NT_STATUS_MAPPED_FILE_SIZE_ZERO},
	{"NT_STATUS_TOO_MANY_OPENED_FILES",
	 NT_STATUS_TOO_MANY_OPENED_FILES},
	{"NT_STATUS_CANCELLED", NT_STATUS_CANCELLED},
	{"NT_STATUS_CANNOT_DELETE", NT_STATUS_CANNOT_DELETE},
	{"NT_STATUS_INVALID_COMPUTER_NAME",
	 NT_STATUS_INVALID_COMPUTER_NAME},
	{"NT_STATUS_FILE_DELETED", NT_STATUS_FILE_DELETED},
	{"NT_STATUS_SPECIAL_ACCOUNT", NT_STATUS_SPECIAL_ACCOUNT},
	{"NT_STATUS_SPECIAL_GROUP", NT_STATUS_SPECIAL_GROUP},
	{"NT_STATUS_SPECIAL_USER", NT_STATUS_SPECIAL_USER},
	{"NT_STATUS_MEMBERS_PRIMARY_GROUP",
	 NT_STATUS_MEMBERS_PRIMARY_GROUP},
	{"NT_STATUS_FILE_CLOSED", NT_STATUS_FILE_CLOSED},
	{"NT_STATUS_TOO_MANY_THREADS", NT_STATUS_TOO_MANY_THREADS},
	{"NT_STATUS_THREAD_NOT_IN_PROCESS",
	 NT_STATUS_THREAD_NOT_IN_PROCESS},
	{"NT_STATUS_TOKEN_ALREADY_IN_USE", NT_STATUS_TOKEN_ALREADY_IN_USE},
	{"NT_STATUS_PAGEFILE_QUOTA_EXCEEDED",
	 NT_STATUS_PAGEFILE_QUOTA_EXCEEDED},
	{"NT_STATUS_COMMITMENT_LIMIT", NT_STATUS_COMMITMENT_LIMIT},
	{"NT_STATUS_INVALID_IMAGE_LE_FORMAT",
	 NT_STATUS_INVALID_IMAGE_LE_FORMAT},
	{"NT_STATUS_INVALID_IMAGE_NOT_MZ", NT_STATUS_INVALID_IMAGE_NOT_MZ},
	{"NT_STATUS_INVALID_IMAGE_PROTECT",
	 NT_STATUS_INVALID_IMAGE_PROTECT},
	{"NT_STATUS_INVALID_IMAGE_WIN_16", NT_STATUS_INVALID_IMAGE_WIN_16},
	{"NT_STATUS_LOGON_SERVER_CONFLICT",
	 NT_STATUS_LOGON_SERVER_CONFLICT},
	{"NT_STATUS_TIME_DIFFERENCE_AT_DC",
	 NT_STATUS_TIME_DIFFERENCE_AT_DC},
	{"NT_STATUS_SYNCHRONIZATION_REQUIRED",
	 NT_STATUS_SYNCHRONIZATION_REQUIRED},
	{"NT_STATUS_DLL_NOT_FOUND", NT_STATUS_DLL_NOT_FOUND},
	{"NT_STATUS_OPEN_FAILED", NT_STATUS_OPEN_FAILED},
	{"NT_STATUS_IO_PRIVILEGE_FAILED", NT_STATUS_IO_PRIVILEGE_FAILED},
	{"NT_STATUS_ORDINAL_NOT_FOUND", NT_STATUS_ORDINAL_NOT_FOUND},
	{"NT_STATUS_ENTRYPOINT_NOT_FOUND", NT_STATUS_ENTRYPOINT_NOT_FOUND},
	{"NT_STATUS_CONTROL_C_EXIT", NT_STATUS_CONTROL_C_EXIT},
	{"NT_STATUS_LOCAL_DISCONNECT", NT_STATUS_LOCAL_DISCONNECT},
	{"NT_STATUS_REMOTE_DISCONNECT", NT_STATUS_REMOTE_DISCONNECT},
	{"NT_STATUS_REMOTE_RESOURCES", NT_STATUS_REMOTE_RESOURCES},
	{"NT_STATUS_LINK_FAILED", NT_STATUS_LINK_FAILED},
	{"NT_STATUS_LINK_TIMEOUT", NT_STATUS_LINK_TIMEOUT},
	{"NT_STATUS_INVALID_CONNECTION", NT_STATUS_INVALID_CONNECTION},
	{"NT_STATUS_INVALID_ADDRESS", NT_STATUS_INVALID_ADDRESS},
	{"NT_STATUS_DLL_INIT_FAILED", NT_STATUS_DLL_INIT_FAILED},
	{"NT_STATUS_MISSING_SYSTEMFILE", NT_STATUS_MISSING_SYSTEMFILE},
	{"NT_STATUS_UNHANDLED_EXCEPTION", NT_STATUS_UNHANDLED_EXCEPTION},
	{"NT_STATUS_APP_INIT_FAILURE", NT_STATUS_APP_INIT_FAILURE},
	{"NT_STATUS_PAGEFILE_CREATE_FAILED",
	 NT_STATUS_PAGEFILE_CREATE_FAILED},
	{"NT_STATUS_NO_PAGEFILE", NT_STATUS_NO_PAGEFILE},
	{"NT_STATUS_INVALID_LEVEL", NT_STATUS_INVALID_LEVEL},
	{"NT_STATUS_WRONG_PASSWORD_CORE", NT_STATUS_WRONG_PASSWORD_CORE},
	{"NT_STATUS_ILLEGAL_FLOAT_CONTEXT",
	 NT_STATUS_ILLEGAL_FLOAT_CONTEXT},
	{"NT_STATUS_PIPE_BROKEN", NT_STATUS_PIPE_BROKEN},
	{"NT_STATUS_REGISTRY_CORRUPT", NT_STATUS_REGISTRY_CORRUPT},
	{"NT_STATUS_REGISTRY_IO_FAILED", NT_STATUS_REGISTRY_IO_FAILED},
	{"NT_STATUS_NO_EVENT_PAIR", NT_STATUS_NO_EVENT_PAIR},
	{"NT_STATUS_UNRECOGNIZED_VOLUME", NT_STATUS_UNRECOGNIZED_VOLUME},
	{"NT_STATUS_SERIAL_NO_DEVICE_INITED",
	 NT_STATUS_SERIAL_NO_DEVICE_INITED},
	{"NT_STATUS_NO_SUCH_ALIAS", NT_STATUS_NO_SUCH_ALIAS},
	{"NT_STATUS_MEMBER_NOT_IN_ALIAS", NT_STATUS_MEMBER_NOT_IN_ALIAS},
	{"NT_STATUS_MEMBER_IN_ALIAS", NT_STATUS_MEMBER_IN_ALIAS},
	{"NT_STATUS_ALIAS_EXISTS", NT_STATUS_ALIAS_EXISTS},
	{"NT_STATUS_LOGON_NOT_GRANTED", NT_STATUS_LOGON_NOT_GRANTED},
	{"NT_STATUS_TOO_MANY_SECRETS", NT_STATUS_TOO_MANY_SECRETS},
	{"NT_STATUS_SECRET_TOO_LONG", NT_STATUS_SECRET_TOO_LONG},
	{"NT_STATUS_INTERNAL_DB_ERROR", NT_STATUS_INTERNAL_DB_ERROR},
	{"NT_STATUS_FULLSCREEN_MODE", NT_STATUS_FULLSCREEN_MODE},
	{"NT_STATUS_TOO_MANY_CONTEXT_IDS", NT_STATUS_TOO_MANY_CONTEXT_IDS},
	{"NT_STATUS_LOGON_TYPE_NOT_GRANTED",
	 NT_STATUS_LOGON_TYPE_NOT_GRANTED},
	{"NT_STATUS_NOT_REGISTRY_FILE", NT_STATUS_NOT_REGISTRY_FILE},
	{"NT_STATUS_NT_CROSS_ENCRYPTION_REQUIRED",
	 NT_STATUS_NT_CROSS_ENCRYPTION_REQUIRED},
	{"NT_STATUS_DOMAIN_CTRLR_CONFIG_ERROR",
	 NT_STATUS_DOMAIN_CTRLR_CONFIG_ERROR},
	{"NT_STATUS_FT_MISSING_MEMBER", NT_STATUS_FT_MISSING_MEMBER},
	{"NT_STATUS_ILL_FORMED_SERVICE_ENTRY",
	 NT_STATUS_ILL_FORMED_SERVICE_ENTRY},
	{"NT_STATUS_ILLEGAL_CHARACTER", NT_STATUS_ILLEGAL_CHARACTER},
	{"NT_STATUS_UNMAPPABLE_CHARACTER", NT_STATUS_UNMAPPABLE_CHARACTER},
	{"NT_STATUS_UNDEFINED_CHARACTER", NT_STATUS_UNDEFINED_CHARACTER},
	{"NT_STATUS_FLOPPY_VOLUME", NT_STATUS_FLOPPY_VOLUME},
	{"NT_STATUS_FLOPPY_ID_MARK_NOT_FOUND",
	 NT_STATUS_FLOPPY_ID_MARK_NOT_FOUND},
	{"NT_STATUS_FLOPPY_WRONG_CYLINDER",
	 NT_STATUS_FLOPPY_WRONG_CYLINDER},
	{"NT_STATUS_FLOPPY_UNKNOWN_ERROR", NT_STATUS_FLOPPY_UNKNOWN_ERROR},
	{"NT_STATUS_FLOPPY_BAD_REGISTERS", NT_STATUS_FLOPPY_BAD_REGISTERS},
	{"NT_STATUS_DISK_RECALIBRATE_FAILED",
	 NT_STATUS_DISK_RECALIBRATE_FAILED},
	{"NT_STATUS_DISK_OPERATION_FAILED",
	 NT_STATUS_DISK_OPERATION_FAILED},
	{"NT_STATUS_DISK_RESET_FAILED", NT_STATUS_DISK_RESET_FAILED},
	{"NT_STATUS_SHARED_IRQ_BUSY", NT_STATUS_SHARED_IRQ_BUSY},
	{"NT_STATUS_FT_ORPHANING", NT_STATUS_FT_ORPHANING},
	{"NT_STATUS_PARTITION_FAILURE", NT_STATUS_PARTITION_FAILURE},
	{"NT_STATUS_INVALID_BLOCK_LENGTH", NT_STATUS_INVALID_BLOCK_LENGTH},
	{"NT_STATUS_DEVICE_NOT_PARTITIONED",
	 NT_STATUS_DEVICE_NOT_PARTITIONED},
	{"NT_STATUS_UNABLE_TO_LOCK_MEDIA", NT_STATUS_UNABLE_TO_LOCK_MEDIA},
	{"NT_STATUS_UNABLE_TO_UNLOAD_MEDIA",
	 NT_STATUS_UNABLE_TO_UNLOAD_MEDIA},
	{"NT_STATUS_EOM_OVERFLOW", NT_STATUS_EOM_OVERFLOW},
	{"NT_STATUS_NO_MEDIA", NT_STATUS_NO_MEDIA},
	{"NT_STATUS_NO_SUCH_MEMBER", NT_STATUS_NO_SUCH_MEMBER},
	{"NT_STATUS_INVALID_MEMBER", NT_STATUS_INVALID_MEMBER},
	{"NT_STATUS_KEY_DELETED", NT_STATUS_KEY_DELETED},
	{"NT_STATUS_NO_LOG_SPACE", NT_STATUS_NO_LOG_SPACE},
	{"NT_STATUS_TOO_MANY_SIDS", NT_STATUS_TOO_MANY_SIDS},
	{"NT_STATUS_LM_CROSS_ENCRYPTION_REQUIRED",
	 NT_STATUS_LM_CROSS_ENCRYPTION_REQUIRED},
	{"NT_STATUS_KEY_HAS_CHILDREN", NT_STATUS_KEY_HAS_CHILDREN},
	{"NT_STATUS_CHILD_MUST_BE_VOLATILE",
	 NT_STATUS_CHILD_MUST_BE_VOLATILE},
	{"NT_STATUS_DEVICE_CONFIGURATION_ERROR",
	 NT_STATUS_DEVICE_CONFIGURATION_ERROR},
	{"NT_STATUS_DRIVER_INTERNAL_ERROR",
	 NT_STATUS_DRIVER_INTERNAL_ERROR},
	{"NT_STATUS_INVALID_DEVICE_STATE", NT_STATUS_INVALID_DEVICE_STATE},
	{"NT_STATUS_IO_DEVICE_ERROR", NT_STATUS_IO_DEVICE_ERROR},
	{"NT_STATUS_DEVICE_PROTOCOL_ERROR",
	 NT_STATUS_DEVICE_PROTOCOL_ERROR},
	{"NT_STATUS_BACKUP_CONTROLLER", NT_STATUS_BACKUP_CONTROLLER},
	{"NT_STATUS_LOG_FILE_FULL", NT_STATUS_LOG_FILE_FULL},
	{"NT_STATUS_TOO_LATE", NT_STATUS_TOO_LATE},
	{"NT_STATUS_NO_TRUST_LSA_SECRET", NT_STATUS_NO_TRUST_LSA_SECRET},
	{"NT_STATUS_NO_TRUST_SAM_ACCOUNT", NT_STATUS_NO_TRUST_SAM_ACCOUNT},
	{"NT_STATUS_TRUSTED_DOMAIN_FAILURE",
	 NT_STATUS_TRUSTED_DOMAIN_FAILURE},
	{"NT_STATUS_TRUSTED_RELATIONSHIP_FAILURE",
	 NT_STATUS_TRUSTED_RELATIONSHIP_FAILURE},
	{"NT_STATUS_EVENTLOG_FILE_CORRUPT",
	 NT_STATUS_EVENTLOG_FILE_CORRUPT},
	{"NT_STATUS_EVENTLOG_CANT_START", NT_STATUS_EVENTLOG_CANT_START},
	{"NT_STATUS_TRUST_FAILURE", NT_STATUS_TRUST_FAILURE},
	{"NT_STATUS_MUTANT_LIMIT_EXCEEDED",
	 NT_STATUS_MUTANT_LIMIT_EXCEEDED},
	{"NT_STATUS_NETLOGON_NOT_STARTED", NT_STATUS_NETLOGON_NOT_STARTED},
	{"NT_STATUS_ACCOUNT_EXPIRED", NT_STATUS_ACCOUNT_EXPIRED},
	{"NT_STATUS_POSSIBLE_DEADLOCK", NT_STATUS_POSSIBLE_DEADLOCK},
	{"NT_STATUS_NETWORK_CREDENTIAL_CONFLICT",
	 NT_STATUS_NETWORK_CREDENTIAL_CONFLICT},
	{"NT_STATUS_REMOTE_SESSION_LIMIT", NT_STATUS_REMOTE_SESSION_LIMIT},
	{"NT_STATUS_EVENTLOG_FILE_CHANGED",
	 NT_STATUS_EVENTLOG_FILE_CHANGED},
	{"NT_STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT",
	 NT_STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT},
	{"NT_STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT",
	 NT_STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT},
	{"NT_STATUS_NOLOGON_SERVER_TRUST_ACCOUNT",
	 NT_STATUS_NOLOGON_SERVER_TRUST_ACCOUNT},
	{"NT_STATUS_DOMAIN_TRUST_INCONSISTENT",
	 NT_STATUS_DOMAIN_TRUST_INCONSISTENT},
	{"NT_STATUS_FS_DRIVER_REQUIRED", NT_STATUS_FS_DRIVER_REQUIRED},
	{"NT_STATUS_NO_USER_SESSION_KEY", NT_STATUS_NO_USER_SESSION_KEY},
	{"NT_STATUS_USER_SESSION_DELETED", NT_STATUS_USER_SESSION_DELETED},
	{"NT_STATUS_RESOURCE_LANG_NOT_FOUND",
	 NT_STATUS_RESOURCE_LANG_NOT_FOUND},
	{"NT_STATUS_INSUFF_SERVER_RESOURCES",
	 NT_STATUS_INSUFF_SERVER_RESOURCES},
	{"NT_STATUS_INVALID_BUFFER_SIZE", NT_STATUS_INVALID_BUFFER_SIZE},
	{"NT_STATUS_INVALID_ADDRESS_COMPONENT",
	 NT_STATUS_INVALID_ADDRESS_COMPONENT},
	{"NT_STATUS_INVALID_ADDRESS_WILDCARD",
	 NT_STATUS_INVALID_ADDRESS_WILDCARD},
	{"NT_STATUS_TOO_MANY_ADDRESSES", NT_STATUS_TOO_MANY_ADDRESSES},
	{"NT_STATUS_ADDRESS_ALREADY_EXISTS",
	 NT_STATUS_ADDRESS_ALREADY_EXISTS},
	{"NT_STATUS_ADDRESS_CLOSED", NT_STATUS_ADDRESS_CLOSED},
	{"NT_STATUS_CONNECTION_DISCONNECTED",
	 NT_STATUS_CONNECTION_DISCONNECTED},
	{"NT_STATUS_CONNECTION_RESET", NT_STATUS_CONNECTION_RESET},
	{"NT_STATUS_TOO_MANY_NODES", NT_STATUS_TOO_MANY_NODES},
	{"NT_STATUS_TRANSACTION_ABORTED", NT_STATUS_TRANSACTION_ABORTED},
	{"NT_STATUS_TRANSACTION_TIMED_OUT",
	 NT_STATUS_TRANSACTION_TIMED_OUT},
	{"NT_STATUS_TRANSACTION_NO_RELEASE",
	 NT_STATUS_TRANSACTION_NO_RELEASE},
	{"NT_STATUS_TRANSACTION_NO_MATCH", NT_STATUS_TRANSACTION_NO_MATCH},
	{"NT_STATUS_TRANSACTION_RESPONDED",
	 NT_STATUS_TRANSACTION_RESPONDED},
	{"NT_STATUS_TRANSACTION_INVALID_ID",
	 NT_STATUS_TRANSACTION_INVALID_ID},
	{"NT_STATUS_TRANSACTION_INVALID_TYPE",
	 NT_STATUS_TRANSACTION_INVALID_TYPE},
	{"NT_STATUS_NOT_SERVER_SESSION", NT_STATUS_NOT_SERVER_SESSION},
	{"NT_STATUS_NOT_CLIENT_SESSION", NT_STATUS_NOT_CLIENT_SESSION},
	{"NT_STATUS_CANNOT_LOAD_REGISTRY_FILE",
	 NT_STATUS_CANNOT_LOAD_REGISTRY_FILE},
	{"NT_STATUS_DEBUG_ATTACH_FAILED", NT_STATUS_DEBUG_ATTACH_FAILED},
	{"NT_STATUS_SYSTEM_PROCESS_TERMINATED",
	 NT_STATUS_SYSTEM_PROCESS_TERMINATED},
	{"NT_STATUS_DATA_NOT_ACCEPTED", NT_STATUS_DATA_NOT_ACCEPTED},
	{"NT_STATUS_NO_BROWSER_SERVERS_FOUND",
	 NT_STATUS_NO_BROWSER_SERVERS_FOUND},
	{"NT_STATUS_VDM_HARD_ERROR", NT_STATUS_VDM_HARD_ERROR},
	{"NT_STATUS_DRIVER_CANCEL_TIMEOUT",
	 NT_STATUS_DRIVER_CANCEL_TIMEOUT},
	{"NT_STATUS_REPLY_MESSAGE_MISMATCH",
	 NT_STATUS_REPLY_MESSAGE_MISMATCH},
	{"NT_STATUS_MAPPED_ALIGNMENT", NT_STATUS_MAPPED_ALIGNMENT},
	{"NT_STATUS_IMAGE_CHECKSUM_MISMATCH",
	 NT_STATUS_IMAGE_CHECKSUM_MISMATCH},
	{"NT_STATUS_LOST_WRITEBEHIND_DATA",
	 NT_STATUS_LOST_WRITEBEHIND_DATA},
	{"NT_STATUS_CLIENT_SERVER_PARAMETERS_INVALID",
	 NT_STATUS_CLIENT_SERVER_PARAMETERS_INVALID},
	{"NT_STATUS_PASSWORD_MUST_CHANGE", NT_STATUS_PASSWORD_MUST_CHANGE},
	{"NT_STATUS_NOT_FOUND", NT_STATUS_NOT_FOUND},
	{"NT_STATUS_NOT_TINY_STREAM", NT_STATUS_NOT_TINY_STREAM},
	{"NT_STATUS_RECOVERY_FAILURE", NT_STATUS_RECOVERY_FAILURE},
	{"NT_STATUS_STACK_OVERFLOW_READ", NT_STATUS_STACK_OVERFLOW_READ},
	{"NT_STATUS_FAIL_CHECK", NT_STATUS_FAIL_CHECK},
	{"NT_STATUS_DUPLICATE_OBJECTID", NT_STATUS_DUPLICATE_OBJECTID},
	{"NT_STATUS_OBJECTID_EXISTS", NT_STATUS_OBJECTID_EXISTS},
	{"NT_STATUS_CONVERT_TO_LARGE", NT_STATUS_CONVERT_TO_LARGE},
	{"NT_STATUS_RETRY", NT_STATUS_RETRY},
	{"NT_STATUS_FOUND_OUT_OF_SCOPE", NT_STATUS_FOUND_OUT_OF_SCOPE},
	{"NT_STATUS_ALLOCATE_BUCKET", NT_STATUS_ALLOCATE_BUCKET},
	{"NT_STATUS_PROPSET_NOT_FOUND", NT_STATUS_PROPSET_NOT_FOUND},
	{"NT_STATUS_MARSHALL_OVERFLOW", NT_STATUS_MARSHALL_OVERFLOW},
	{"NT_STATUS_INVALID_VARIANT", NT_STATUS_INVALID_VARIANT},
	{"NT_STATUS_DOMAIN_CONTROLLER_NOT_FOUND",
	 NT_STATUS_DOMAIN_CONTROLLER_NOT_FOUND},
	{"NT_STATUS_ACCOUNT_LOCKED_OUT", NT_STATUS_ACCOUNT_LOCKED_OUT},
	{"NT_STATUS_HANDLE_NOT_CLOSABLE", NT_STATUS_HANDLE_NOT_CLOSABLE},
	{"NT_STATUS_CONNECTION_REFUSED", NT_STATUS_CONNECTION_REFUSED},
	{"NT_STATUS_GRACEFUL_DISCONNECT", NT_STATUS_GRACEFUL_DISCONNECT},
	{"NT_STATUS_ADDRESS_ALREADY_ASSOCIATED",
	 NT_STATUS_ADDRESS_ALREADY_ASSOCIATED},
	{"NT_STATUS_ADDRESS_NOT_ASSOCIATED",
	 NT_STATUS_ADDRESS_NOT_ASSOCIATED},
	{"NT_STATUS_CONNECTION_INVALID", NT_STATUS_CONNECTION_INVALID},
	{"NT_STATUS_CONNECTION_ACTIVE", NT_STATUS_CONNECTION_ACTIVE},
	{"NT_STATUS_NETWORK_UNREACHABLE", NT_STATUS_NETWORK_UNREACHABLE},
	{"NT_STATUS_HOST_UNREACHABLE", NT_STATUS_HOST_UNREACHABLE},
	{"NT_STATUS_PROTOCOL_UNREACHABLE", NT_STATUS_PROTOCOL_UNREACHABLE},
	{"NT_STATUS_PORT_UNREACHABLE", NT_STATUS_PORT_UNREACHABLE},
	{"NT_STATUS_REQUEST_ABORTED", NT_STATUS_REQUEST_ABORTED},
	{"NT_STATUS_CONNECTION_ABORTED", NT_STATUS_CONNECTION_ABORTED},
	{"NT_STATUS_BAD_COMPRESSION_BUFFER",
	 NT_STATUS_BAD_COMPRESSION_BUFFER},
	{"NT_STATUS_USER_MAPPED_FILE", NT_STATUS_USER_MAPPED_FILE},
	{"NT_STATUS_AUDIT_FAILED", NT_STATUS_AUDIT_FAILED},
	{"NT_STATUS_TIMER_RESOLUTION_NOT_SET",
	 NT_STATUS_TIMER_RESOLUTION_NOT_SET},
	{"NT_STATUS_CONNECTION_COUNT_LIMIT",
	 NT_STATUS_CONNECTION_COUNT_LIMIT},
	{"NT_STATUS_LOGIN_TIME_RESTRICTION",
	 NT_STATUS_LOGIN_TIME_RESTRICTION},
	{"NT_STATUS_LOGIN_WKSTA_RESTRICTION",
	 NT_STATUS_LOGIN_WKSTA_RESTRICTION},
	{"NT_STATUS_IMAGE_MP_UP_MISMATCH", NT_STATUS_IMAGE_MP_UP_MISMATCH},
	{"NT_STATUS_INSUFFICIENT_LOGON_INFO",
	 NT_STATUS_INSUFFICIENT_LOGON_INFO},
	{"NT_STATUS_BAD_DLL_ENTRYPOINT", NT_STATUS_BAD_DLL_ENTRYPOINT},
	{"NT_STATUS_BAD_SERVICE_ENTRYPOINT",
	 NT_STATUS_BAD_SERVICE_ENTRYPOINT},
	{"NT_STATUS_LPC_REPLY_LOST", NT_STATUS_LPC_REPLY_LOST},
	{"NT_STATUS_IP_ADDRESS_CONFLICT1", NT_STATUS_IP_ADDRESS_CONFLICT1},
	{"NT_STATUS_IP_ADDRESS_CONFLICT2", NT_STATUS_IP_ADDRESS_CONFLICT2},
	{"NT_STATUS_REGISTRY_QUOTA_LIMIT", NT_STATUS_REGISTRY_QUOTA_LIMIT},
	{"NT_STATUS_PATH_NOT_COVERED", NT_STATUS_PATH_NOT_COVERED},
	{"NT_STATUS_NO_CALLBACK_ACTIVE", NT_STATUS_NO_CALLBACK_ACTIVE},
	{"NT_STATUS_LICENSE_QUOTA_EXCEEDED",
	 NT_STATUS_LICENSE_QUOTA_EXCEEDED},
	{"NT_STATUS_PWD_TOO_SHORT", NT_STATUS_PWD_TOO_SHORT},
	{"NT_STATUS_PWD_TOO_RECENT", NT_STATUS_PWD_TOO_RECENT},
	{"NT_STATUS_PWD_HISTORY_CONFLICT", NT_STATUS_PWD_HISTORY_CONFLICT},
	{"NT_STATUS_PLUGPLAY_NO_DEVICE", NT_STATUS_PLUGPLAY_NO_DEVICE},
	{"NT_STATUS_UNSUPPORTED_COMPRESSION",
	 NT_STATUS_UNSUPPORTED_COMPRESSION},
	{"NT_STATUS_INVALID_HW_PROFILE", NT_STATUS_INVALID_HW_PROFILE},
	{"NT_STATUS_INVALID_PLUGPLAY_DEVICE_PATH",
	 NT_STATUS_INVALID_PLUGPLAY_DEVICE_PATH},
	{"NT_STATUS_DRIVER_ORDINAL_NOT_FOUND",
	 NT_STATUS_DRIVER_ORDINAL_NOT_FOUND},
	{"NT_STATUS_DRIVER_ENTRYPOINT_NOT_FOUND",
	 NT_STATUS_DRIVER_ENTRYPOINT_NOT_FOUND},
	{"NT_STATUS_RESOURCE_NOT_OWNED", NT_STATUS_RESOURCE_NOT_OWNED},
	{"NT_STATUS_TOO_MANY_LINKS", NT_STATUS_TOO_MANY_LINKS},
	{"NT_STATUS_QUOTA_LIST_INCONSISTENT",
	 NT_STATUS_QUOTA_LIST_INCONSISTENT},
	{"NT_STATUS_FILE_IS_OFFLINE", NT_STATUS_FILE_IS_OFFLINE},
	{"NT_STATUS_NO_MORE_ENTRIES", NT_STATUS_NO_MORE_ENTRIES},
	{"NT_STATUS_MORE_ENTRIES", NT_STATUS_MORE_ENTRIES},
	{"NT_STATUS_SOME_UNMAPPED", NT_STATUS_SOME_UNMAPPED},
	{NULL, 0}
};
