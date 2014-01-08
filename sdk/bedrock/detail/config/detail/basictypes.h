
// Add #includes of Standard C++/C headers are encouraged to be placed here.
// length of some types on different plateforms are not same, so typedef can be good idea here.
//
#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_BASICTYPES_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_BASICTYPES_H
#pragma once

#include "selector.h"
#include "preprocessor.h"

// limits macros
#include <climits>
#include <cstddef>

// standard int types
#if !defined(SMCP_PLATFORM_WINDOWS)
#   include <stdint.h>
#else
    typedef signed char int8_t;
    typedef unsigned char uint8_t;
    typedef short int16_t;
    typedef unsigned short uint16_t;
    typedef int int32_t;
    typedef unsigned int uint32_t;
    typedef __int64 int64_t;
    typedef unsigned __int64 uint64_t;
#endif


namespace SolidMCP { namespace BedRock {

typedef float Float32;
typedef double Float64;

typedef std::size_t SizeType; // unsigned int
typedef std::size_t IndexType;
static const int InvalidIndex = -1;

// For General usage.
//
typedef int Int;
typedef unsigned int UInt;

typedef long Long;
typedef unsigned long ULong;

#pragma message("Need more investigation for following defines.")
// If use the first implementations, the macros (xx_MAX ..) not found.
// if use the second implementation, ConstantTuple cannot be compiled successfully.

//  8-bit types
#if UCHAR_MAX == 0xff
    typedef signed char Int8;
    typedef unsigned char UInt8;
#else
#    error defaults not correct;
# endif

//#if defined(SMCP_COMPILER_MSVC)
//    typedef __int8 Int8;
//    typedef unsigned __int8 UInt8;
//#else
//    typedef signed char Int8;
//    typedef unsigned char UInt8;
//#endif

//typedef unsigned char    BYTE;
typedef unsigned char Byte;


//  16-bit types
#if USHRT_MAX == 0xffff
    typedef short            Int16;
    typedef unsigned short   UInt16;
#else
#    error defaults not correct;
# endif
//#if defined(SMCP_COMPILER_MSVC)
//    typedef __int16 Int16;
//    typedef unsigned __int16 UInt16;
//#else
//    typedef short            Int16;
//    typedef unsigned short   UInt16;
//#endif

//  32-bit types
//
# if ULONG_MAX == 0xffffffff
        typedef long            Int32;
        typedef unsigned long   UInt32;
# elif UINT_MAX == 0xffffffff
        typedef int             Int32;
        typedef unsigned int    UInt32;
# else
#    error defaults not correct;
# endif



//#if defined(SMCP_COMPILER_MSVC)
//    typedef __int32 Int32;
//    typedef unsigned __int32 UInt32;
//#else
//    typedef signed int Int32;
//    typedef unsigned int UInt32;
//#endif

//  64-bit types
#if defined (SMCP_COMPILER_MSVC)
    typedef __int64              Int64;
    typedef unsigned __int64     UInt64;
#elif defined (SMCP_COMPILER_GCC)
    typedef long long            Int64;
    typedef unsigned long long   UInt64;
#else
#    error No 64-bit integer type defined for this compiler !
#endif


/* LIMIT MACROS */
#define SMCP_INT8_MIN    (-0x7f - 1)
#define SMCP_INT16_MIN   (-0x7fff - 1)
#define SMCP_INT32_MIN   (-0x7fffffff - 1)

#define SMCP_INT8_MAX    0x7f
#define SMCP_INT16_MAX   0x7fff
#define SMCP_INT32_MAX   0x7fffffff
#define SMCP_UINT8_MAX   0xff
#define SMCP_UINT16_MAX  0xffff
#define SMCP_UINT32_MAX  0xffffffff

// unsigned int128
typedef struct
{
    UInt64  lowBits;
    UInt64  highBits;
} UInt128;


}}

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_BASICTYPES_H
