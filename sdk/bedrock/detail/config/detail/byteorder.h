#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_BYTEORDER_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_BYTEORDER_H
#pragma once

// Byte Order
#define SMCP_LITTLE_ENDIAN      1234
#define SMCP_BIG_ENDIAN         4321

// 1.
// IA64 and AMD64 are
// IA-64: Itanium
// AMD X64  == X86-64
// __i386__ == X86-32
//
// 2. Not all PowerPC are Big Endian. It can be Little or Big Endian
// 3. For other untouched plateform, just make it as Big Endian
//

#ifndef SMCP_BYTE_ORDER

#    if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64)
#        define SMCP_BYTE_ORDER  SMCP_LITTLE_ENDIAN
#    endif
#    if defined(__i386__) || defined(__x86_64__) || defined( __amd64__ ) || defined(__ia64__) || defined(__alpha__)
#        define SMCP_BYTE_ORDER  SMCP_LITTLE_ENDIAN
#    endif
#    if (defined( __POWERPC__ ) || defined( __powerpc__ ) || defined (__ppc__)) && defined(__LITTLE_ENDIAN__)
#        define SMCP_BYTE_ORDER  SMCP_LITTLE_ENDIAN
#    endif

#    if !defined(SMCP_BYTE_ORDER)
#        pragma message("Using Big Endian. Please make sure current plateform is handled correctly.")
#        define SMCP_BYTE_ORDER  SMCP_BIG_ENDIAN
#    endif
#endif


//#if defined(SMCP_LITTLE_ENDIAN)
//#   define LOBYTE(w) ((BYTE)(w))
//#   define HIBYTE(w) ((BYTE)(((WORD)(w) >> 8) & 0xFF))
//#   define LOWORD(ul) (WORD(DWORD(ul) & 0xffff))
//#   define HIWORD(ul) (WORD(DWORD(ul) >> 16))
//#   define MAKELONG(low, high) ((LONG) (((WORD) (low)) | ((DWORD) ((WORD) (high))) << 16))
//#   define MAKEWORD(low, high) ((WORD)((((WORD)(high)) << 8) | ((BYTE)(low))))
//#elif defined(SMCP_BIG_ENDIAN)
//#   define HIBYTE(w) ((BYTE)(w))
//#   define LOBYTE(w) ((BYTE)(((WORD)(w) >> 8) & 0xFF))
//#   define HIWORD(ul) (WORD(DWORD(ul) & 0xffff))
//#   define LOWORD(ul) (WORD(DWORD(ul) >> 16))
//#   define MAKELONG(low, high) ((LONG) (((WORD) (high)) | ((DWORD) ((WORD) (low))) << 16))
//#   define MAKEWORD(low, high) ((WORD)((((WORD)(low)) << 8) | ((BYTE)(high))))
//#else
//#   error "Neither SMCP_LITTLE_ENDIAN and SMCP_BIG_ENDIAN are not defined."
//#endif



#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_BYTEORDER_H