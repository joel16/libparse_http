/* Copyright (C) 2019 The uOFW team
   See the file COPYING for copying permission.
*/

#include <common_imp.h>

SCE_MODULE_INFO("SceParseHTTPheader_Library", SCE_MODULE_ATTR_EXCLUSIVE_LOAD | SCE_MODULE_ATTR_EXCLUSIVE_START, 1, 1);
SCE_SDK_VERSION(SDK_VERSION);

#define SCE_PARSE_HTTP_NOT_FOUND        0x80432025 // lui $s2, 0x8043 -> ori $v0, $s2, 0x2025
#define SCE_PARSE_HTTP_INVALID_RESPONSE 0x80432060 // lui $a0, 0x8043 -> ori $v0, $a0, 0x2060

// Internal function prototyes
s32 sub_000003A0(u8 *a0, u32 a1, s32 *a2, s32 *a3);
s32 sub_00000510(u8 *a0, u32 a1, s32 *a2);
s32 sub_0000061C(u8 *a0, u32 a1, u8 **a2, u32 *a3);
s32 sub_000006CC(u8 *a0, u8 *a1, s32 a2);

// Subroutine sceParseHttp_8077A433 - Address 0x00000000
s32 sceParseHttpStatusLine(const u8 *status_line, u32 line_len, u32 *http_major_ver, u32 *http_minor_ver, u32 *response_code, const u8 **reason_phrase, u32 *phrase_len) {
	// References _sceKernelCheckThreadStack (0xD13BDE95)
	return 0;
}

// Subroutine sceParseHttp_AD7BFDEF - Address 0x00000118
s32 sceParseHttpResponseHeader(const u8 *header, u32 header_len, const u8 *field_name, const u8 **field_value, u32 *value_len) {
	return 0;
}

// Subroutine sub_000003A0 - Address 0x000003A0 
s32 sub_000003A0(u8 *a0, u32 a1, s32 *a2, s32 *a3) {
	s32 var0;
	u8 *var1;
	*a2 = 0;
	*a3 = 0;

	s32 var3 = -0x7fbcdfa0;

	if (8 < a1) {
		var0 = sub_000006CC(a0, (u8 *)"HTTP/", 5);
		var3 = -0x7fbcdfa0;

		if (var0 == 0) {
			var3 = -0x7fbcdfa0;

			if ((*(u8 *)((s32)a0[5] + 1) & 4) != 0) {
				var1 = a0 + 5;
				var3 = *a2;
				var0 = 5;

				while(1) {
					*a2 = var3 * 10 + (s32)*var1 + -0x30;
					var1 = a0 + var0 + 1;

					if ((*(u8 *)((s32)*var1 + 1) & 4) == 0) {
						break;
					}

					var3 = *a2;
					var0 = var0 + 1;
				}

				var3 = -0x7fbcdfa0;

				if ((s32)*var1 == 0x2e) {
					var1 = a0 + var0 + 2;
					var3 = -0x7fbcdfa0;

					if ((*(u8 *)((s32)*var1 + 1) & 4) != 0) {
						var3 = *a3;
						var0 = var0 + 2;

						while(1) {
							*a3 = var3 * 10 + (s32)*var1 + -0x30;
							var1 = a0 + var0 + 1;

							if ((*(u8 *)((s32)*var1 + 1) & 4) == 0) {
								break;
							}

							var3 = *a3;
							var0 = var0 + 1;
						}

						var3 = -0x7fbcdfa0;

						if ((s32)*var1 == 0x20) {
							var3 = var0 + 2;
						}
					}
				}
			}
		}
	}

	return var3;
}

// Subroutine sub_00000510 - Address 0x00000510
s32 sub_00000510(u8 *a0, u32 a1, s32 *a2) {
	s32 var0 = 0x80432060;

	if (3 < a1) {
		var0 = 0x80432060;

		if (((*(u8 *)((s32)*a0 + 1) & 4) != 0) && ((*(u8 *)((s32)a0[1] + 1) & 4) != 0)) {
			if ((*(u8 *)((s32)a0[2] + 1) & 4) != 0) {
				var0 = 3;
				*a2 = (s32)*a0 * 100 + (s32)a0[1] * 10 + (s32)a0[2] + -0x14d0;
			}
		}
	}

	return var0;
}

// Subroutine sub_0000061C - Address 0x0000061C
s32 sub_0000061C(u8 *a0, u32 a1, u8 **a2, u32 *a3) {
	  u8 var0 = 0;
	  u8 *var1 = a0;
	  u32 var2 = 0;

	  while(1) {
	  	if (*var1 == '\n') {
	  		if (var2 != 0) {
	  			var0 = var1[-1] == '\r';
	  		}

	  		if (var0) {
	  			*a3 = var2 - 1;
	  		}
	  		else {
	  			*a3 = var2;
	  		}

	  		*a2 = a0;
	  		return var2 + 1;
	  	}

	  	var2 = var2 + 1;

	  	if (a1 < var2)
	  		break;

	  	var1 = a0 + var2;
	  }

	  return -0x7fbcdfa0;
}

// Subroutine sub_000006CC - Address 0x000006CC
s32 sub_000006CC(u8 *a0, u8 *a1, s32 a2) {
	u8 var0;
	s32 var1;
	u8 *var2;
	u8 var3;

	if (a0 == (u8 *)0x0 || a1 == (u8 *)0x0) {
		var1 = 0;

		if ((a0 != a1) && (var1 = -1, a0 != (u8 *)0x0)) {
			var1 = 1;
		}
	}

	else {
		a2 = a2 + -1;
		var1 = 0;

		if (-1 < a2) {
			var3 = *a0;
			var2 = a1 + 1;
			if (var3 == *a1) {
				do {
					a2 = a2 + -1;
					a0 = a0 + 1;

					if (var3 == 0) {
						return 0;
					}

					if (a2 < 0) {
						return 0;
					}

					var0 = *var2;
					var3 = *a0;
					var2 = var2 + 1;
				} while (var3 == var0);
			}

			if (a2 < 0) {
				var1 = 0;
			}
			else {
				var1 = (s32)*a0 - (s32)var2[-1];
			}
		}
	}

	return var1;
}
