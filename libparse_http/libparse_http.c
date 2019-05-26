/* Copyright (C) 2019 The uOFW team
   See the file COPYING for copying permission.
*/

#include <common_imp.h>

SCE_MODULE_INFO("SceParseHTTPheader_Library", SCE_MODULE_ATTR_EXCLUSIVE_LOAD | SCE_MODULE_ATTR_EXCLUSIVE_START, 1, 1);
SCE_SDK_VERSION(SDK_VERSION);

#define SCE_PARSE_HTTP_NOT_FOUND	    0x80432025 // lui $s2, 0x8043 -> ori $v0, $s2, 0x2025
#define SCE_PARSE_HTTP_INVALID_RESPONSE 0x80432060 // lui $a0, 0x8043 -> ori $v0, $a0, 0x2060

// sceParseHttp_8077A433
int sceParseHttpStatusLine(const u8 *status_line, u32 line_len, u32 *http_major_ver, u32 *http_minor_ver, u32 *response_code, const u8 **reason_phrase, u32 *phrase_len) {

}

// sceParseHttp_AD7BFDEF
int sceParseHttpResponseHeader(const u8 *header, u32 header_len, const u8 *field_name, const u8 **field_value, u32 *value_len) {

}
