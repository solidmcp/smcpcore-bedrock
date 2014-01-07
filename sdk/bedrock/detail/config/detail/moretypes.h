
#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_MORETYPES_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_MORETYPES_H
#pragma once

#if !defined(GUARD_SMCPCORE_BEDROCK_CONFIG_BASICTYPES_H)
#include "basictypes.h"
#endif


// wchar_t can be 4 bit on Apple, but 2 bit on Windows.
//
#if defined(SMCP_PLATFORM_WINDOWS)
#    define _SMCP_WCHAR_MAX SHRT_MAX
#else
#    if defined(__WCHAR_MAX)
#        define _SMCP_WCHAR_MAX __WCHAR_MAX
#    elif defined(WCHAR_MAX)
#        define _SMCP_WCHAR_MAX WCHAR_MAX
#    endif
#endif


#define _SMCP_SHRT_MAX  SHRT_MAX
#define _SMCP_INT_MAX   INT_MAX

namespace SolidMCP { namespace BedRock {

// The sizeof(whcar_t) is not defined in C++ specification.
//  For wchar_t strings, you have to be aware of whether it is UTF-16 or UTF-32.
// On Windows, it's UTF16.
// On MacOSX, it should be UTF32
#if(_SMCP_WCHAR_MAX == _SMCP_SHRT_MAX)
    typedef char        AsciiChar;  // Utf8
    typedef wchar_t     Utf16Char;  // Utf16
    typedef UInt32      Utf32Char;  // UTF32
#else
    typedef char        AsciiChar;
    typedef UInt16      Utf16Char;
    typedef wchar_t     Utf32Char;
#endif

typedef char        NarrowChar;
typedef wchar_t     WideChar;


struct LongType { typedef Long SignedType; typedef ULong UnsignedType;};

template<size_t size> struct FloatType;
template<> struct FloatType<32> { typedef Float32 Type; };
template<> struct FloatType<64> { typedef Float64 Type; };

template<size_t size> struct IntType;
template<> struct IntType<1> { typedef Int8  SignedType; typedef UInt8  UnsignedType; };
template<> struct IntType<2> { typedef Int16 SignedType; typedef UInt16 UnsignedType; };
template<> struct IntType<4> { typedef Int32 SignedType; typedef UInt32 UnsignedType; };
template<> struct IntType<8> { typedef Int64 SignedType; typedef UInt64 UnsignedType; };

template<typename T> struct Unsigned;
template<> struct Unsigned<Int8>     { typedef UInt8  Type;};
template<> struct Unsigned<Int16>    { typedef UInt16 Type;};
template<> struct Unsigned<Int32>    { typedef UInt32 Type;};
template<> struct Unsigned<Int64>    { typedef UInt64 Type;};
//template<> struct Unsigned<Long>     { typedef ULong Type;};

template<> struct Unsigned<UInt8>    { typedef UInt8  Type;};
template<> struct Unsigned<UInt16>   { typedef UInt16 Type;};
template<> struct Unsigned<UInt32>   { typedef UInt32 Type;};
template<> struct Unsigned<UInt64>   { typedef UInt64 Type;};
//template<> struct Unsigned<ULong>    { typedef ULong Type;};


template<typename T> struct Signed;
template<> struct Signed<Int8>       { typedef Int8  Type;};
template<> struct Signed<Int16>      { typedef Int16 Type;};
template<> struct Signed<Int32>      { typedef Int32 Type;};
template<> struct Signed<Int64>      { typedef Int64 Type;};
//template<> struct Signed<Long>       { typedef Long Type;};

template<> struct Signed<UInt8>      { typedef Int8  Type;};
template<> struct Signed<UInt16>     { typedef Int16 Type;};
template<> struct Signed<UInt32>     { typedef Int32 Type;};
template<> struct Signed<UInt64>     { typedef Int64 Type;};
//template<> struct Signed<ULong>      { typedef Long Type;};


}}


#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_MORETYPES_H
