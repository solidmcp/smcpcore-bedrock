#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_SUFFIX_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_SUFFIX_H
#pragma once

#pragma message("SolidMCP BEDROCK")

#include "support.h"

// Include Guard + pragma once + Redundant Include Guards
//
// #ifndef GUARD_SMCPCORE_BEDROCK_SUFFIX_H
// // MS compatible compilers support #pragma once
// #if defined(_MSC_VER) && (_MSC_VER >= 1020)
// # pragma once
// #endif
// #endif
//
// #if SMCP_NOGUARD(GUARD_SMCPCORE_BEDROCK_SUFFIX_H)
// #include "Suffix.h"
// #endif
//
#define SMCP_NOGUARD(FileGuard) ( !defined(##FileGuard))

//  #if SMCP_COMPILER(MSVC) && SMCP_PLATFORM(WINDOWS)
//  #endif
#define SMCP_COMPILER(name) (defined SMCP_COMPILER_##name && SMCP_COMPILER_##name)
#define SMCP_PLATFORM(name) (defined SMCP_PLATFORM_##name && SMCP_PLATFORM_##name)

//  #define SMCP_ENABLE_SSE3 1
//  #if SMCP_ENABLED(SSE3)
//  #endif
#define SMCP_ENABLED(name) (defined SMCP_ENABLE_##name && SMCP_ENABLE_##name)

// #define SMCP_HAVE_SOLDIER 1
// #if SMCP_HAVE(SOLDIER)
// #endif
#define SMCP_HAVE(name) (defined SMCP_HAVE_##name && SMCP_HAVE_##name)


// Token Concatenation(##)
// The ## preprocessor operator is used to concatenate two tokens into a third valid token:
// #define Glue(a,b) a ## b
// Glue(whole,num) ---> wholenum

// Helper macro SMCP_STRINGIZE:
// Converts the parameter X to a string after macro replacement
// on X has been performed.
//
#define SMCP_STRINGIZE(X) SMCP_DO_STRINGIZE(X)
#define SMCP_DO_STRINGIZE(X) #X

// Helper macro SMCP_JOIN:
// The following piece of macro magic joins the two
// arguments together
//
#define SMCP_JOIN(X, Y ) SMCP_DO_JOIN( X, Y )
#define SMCP_DO_JOIN(X, Y ) X##Y


#define _SMCP_FORCE_WSTRING_(s)       L ## s
#define _SMCP_FORCE_NSTRING_(s)       (s)

#ifdef _UNICODE
#    define _SMCP_FORCE_STRING_(s)        _SMCP_FORCE_WSTRING_(s)
#else
#   ifdef _MBCS
#       define _SMCP_FORCE_STRING_(s)    _SMCP_FORCE_NSTRING_(s)
#   else
//#pragma SMCP_REMINDER("_MBCS/_UNICODE Not Defined, Make MBCS As the default")
#       define _MBCS
#       define _SMCP_FORCE_STRING_(s)    _SMCP_FORCE_NSTRING_(s)
#   endif
#endif


/// _NXTN _NTXW _NXTS    No Translate Narrow/WideString/String
/// _DXTS OR _I18N       Do Translate String

#define _DNTS(s)            _SMCP_FORCE_STRING_(s)    // Do Not Translate SMCP String.
#define _DNTW(s)            _SMCP_FORCE_WSTRING_(s)   // Do Not Translate Wide String.
#define _DNTN(s)            _SMCP_FORCE_NSTRING_(s)   // Do Not Translate Narrow String.


// A heler function for "do nothing"operation
inline void SMCP_NOOP() {}


// Define Code-CodeName Entry conveniently.
//static const CODE_ENTRY CodeNameTable[] =
//{
//    SMCP_MAKE_CODE_ENTRY(CODE_TYPE_1),
//    SMCP_MAKE_CODE_ENTRY(CODE_TYPE_1)
//}
// CodeNameTable[] = { CODE_TYPE_1, _T("CODE_TYPE_1"), CODE_TYPE_2, _T("CODE_TYPE_2") }
//
#define SMCP_MAKE_CODE_ENTRY(code)    { code, _T(#code) }


// Byte Order: Little Endian or Big Endian.
//
#include "./details/byteorder.h"

// Plateform/Compiler Selecting.Using following Macro in your applications.
// SMCP_PLATFORM_WINDOWS
// SMCP_PLATFORM_MACOSX
// SMCP_PLATFORM_LINUX
#include "./details/selector.h"

// Only support MSVC currently
//
#if !defined(SMCP_COMPILER_MSVC) && !defined(SMCP_COMPILER_GCC) && !defined(SMCP_COMPILER_CLANG)
#    error("Notice: Only working on MSVC, GCC and Clang now, Compatiable? You bet it!")
#endif


// Deal with Pre-processors: Character Set /
//
#include "./details/preprocessor.h"

// Disabled Warnings
//
#if SMCP_ENABLE_DISABLEWARNINGS
#    include "./details/disablewarnings.h"
#endif


// Standard C/C++ Library
//
#include "./details/stdlib/stdlib.h"

// Basic Types
//
#include "./details/basictypes.h"
#include "./details/moretyes.h"

// Debugging Macros or Utilities
//
#include "./details/debugging.h"

// ASCII Table
//
#include "./details/asciitable.h"

// Auto link is a wonderful feature of Boost..
//
#include "./details/autolink.h"


// Architecture Type Selctor
#define SMCP_ARCHITECTURE_32 1
#define SMCP_ARCHITECTURE_64 2
#if defined(__x86_64__) || defined(_M_X64) | defined(__ia64__)
#    define SMCP_ARCHITECTURE_TYPE SMCP_ARCHITECTURE_64
#else
#    define SMCP_ARCHITECTURE_TYPE SMCP_ARCHITECTURE_32
#endif


// Copied from ..\Microsoft Visual Studio 9.0\VC\include\stdlib.h
// Define NULL pointer value
//
#ifndef NULL
#    ifdef __cplusplus
#        define NULL    0
#    else
#        define NULL    ((void *)0)
#    endif
#endif


#define SMCP_THREAD_SUPPORT 0


// An empty Macro
//
#define SMCP_EMPTY_MACRO


/// Workaround for names overridden by defined Macros
/// One known example is max/min:
/// In windows, max/min are defined if you include <windows.h>
/// so, you will encounter problem while using std::max or std::min if you include it before std's <algorithm>
/// In Boost, there is a workaround by adding an empty Macro BOOST_PREVENT_MACRO_SUBSTITUTION  after max or min,
/// so that max and min are not recognized as the ones defined by macors, but std::max/min instead.
/// Just borrow it from boost.
//
#define SMCP_WORKAROUND_NAME_OVERRIDE

/// std::max and std::min are encouraged.
/// if SMCP_USING_STD_MIN is defined, you need to write std::min,  not min only instead.
///
/// How to use:
/// \code
///    double GetMaxValue()
///    {
///        double dA = 20.0;
///        double dB = 30.0;
///
///        SMCP_USING_STD_MAX();
///        return max SMCP_WORKAROUND_NAME_OVERRIDE(dA, dB);
///    }
/// \endcode
#ifndef SMCP_USING_STD_MIN_DECLARATION
#    define SMCP_USING_STD_MIN() using std::min
#else
#    define SMCP_USING_STD_MIN()
#endif

#ifndef SMCP_USING_STD_MAX_DECLARATION
#  define SMCP_USING_STD_MAX() using std::max
#else
#    define SMCP_USING_STD_MAX()
#endif

// If no std::max and std::min in very rare cases, just define similar ones.
// So, we can have a std::max or std::min at any ways.
//
#ifdef SMCP_NO_STD_MIN_MAX
namespace std
{
    template <class _Ty>
    inline const _Tp& min SMCP_WORKAROUND_NAME_OVERRIDE (const _Tp& __a, const _Tp& __b)
    {
        return __b < __a ? __b : __a;
    }
    template <class _Ty>
    inline const _Tp& max SMCP_WORKAROUND_NAME_OVERRIDE (const _Tp& __a, const _Tp& __b)
    {
        return  __a < __b ? __b : __a;
    }
}
#endif

// Default Buffer size
//
#define SMCP_BUFFER_SIZE 16384


// It seems that 125 in Visual Studio is fine for now.
//
#define SMCP_MAX_TEMPLATE_PARAMS 125


/// Macros for namespace
/// \code
/// #if defined(SMCP_NO_NAMESPACE)
/// #    define SMCP_BEGIN_NAMESPACE(ns)
/// #    define SMCP_END_NAMESPACE(ns)
/// #else
/// #    define SMCP_BEGIN_NAMESPACE(ns) namespace ns {
/// #    define SMCP_END_NAMESPACE(ns)                }
/// #endif
/// \endcode
#if SMCP_ENABLED(NAMESPACE)
#    define SMCP_BEGIN_NAMESPACE(ns) namespace ns {
#    define SMCP_END_NAMESPACE(ns)                }
#    define BEGIN_ANONYMOUS_NAMESPACE  namespace {
#    define END_ANONYMOUS_NAMESPACE              }
#else
#    define SMCP_BEGIN_NAMESPACE(ns)
#    define SMCP_END_NAMESPACE(ns)
#    define BEGIN_ANONYMOUS_NAMESPACE
#    define END_ANONYMOUS_NAMESPACE
#endif



// For c/C++ compatibility.
//
#if SMCP_PLATFORM(MACOSX) //&& !SMCP_PLATFORM(Q_CC_INTEL)
#define SMCP_BEGIN_HEADER              extern "C++" {
#define SMCP_END_HEADER                }
#define SMCP_BEGIN_INCLUDE_HEADER      }
#define SMCP_END_INCLUDE_HEADER        extern "C++" {
#else
#define SMCP_BEGIN_HEADER
#define SMCP_END_HEADER
#define SMCP_BEGIN_INCLUDE_HEADER
#define SMCP_END_INCLUDE_HEADER        extern "C++"
#endif



// -------------------------------------------------------------------------------
// Error Returns
// -------------------------------------------------------------------------------
#define SMCP_ERROR_LEAVE(condition) \
    if(condition) return;

#define SMCP_ERROR_BREAK(condition) \
    if(condition) break;

#define SMCP_ERROR_RETURN(condition, retval) \
    if(condition) return retval;

// -------------------------------------------------------------------------------
// ASSERT Macros
// -------------------------------------------------------------------------------

#if defined(SMCP_ERROR_SYSTEM_READY)
#    define _SMCP_TRACE_ASSERT( condition, msg )              {if(!(condition)){_SMCP_TRACE( assertion, msg, 0 );}}
#else
#    define _SMCP_TRACE_ASSERT( condition, msg )
#endif


#if defined ( SMCP_PLATFORM_WINDOWS )

#define __SMCP_ASSERT__( condition, msg )                                         \
{   bool _b_ = (!!(condition));                                                   \
    _SMCP_TRACE_ASSERT( _b_, msg )                                                \
    (void)( _b_ || (_wassert(msg, _CRT_WIDE(__FILE__), __LINE__), 0) );}

#elif defined ( SMCP_PLATFORM_MACOSX )

#define        __SMCP_ASSERT__( condition, msg )                                  \
{   bool _b_ = (!!(condition));                                                   \
    _SMCP_TRACE_ASSERT( _b_, _CRT_WIDE(#msg) )                                    \
    (void)( _b_ || (__assert(msg, __FILE__, __LINE__), 0) );}


#elif defined ( SMCP_PLATFORM_LINUX )

#define        __SMCP_ASSERT__( condition, msg )                                  \
{   bool _b_ = (!!(condition));                                                   \
    _SMCP_TRACE_ASSERT( _b_, _CRT_WIDE(#msg) )                                    \
    (void)( _b_ || (__assert(msg, __FILE__, __LINE__), 0) );}

#else
#define        __SMCP_ASSERT__( condition, msg )                                  \
{  assert(condition);}
#endif

#define SMCP_ASSERT_TRACE(condition, msg)   do {__SMCP_ASSERT__(condition, msg) ;} while(0)
#define SMCP_ASSERT(condition)              do {assert(condition) ;} while(0)

#define SMCP_ASSERT_LEAVE(condition)            \
    SMCP_ASSERT(condition) ;if( !(condition) ) return;

#define SMCP_ASSERT_BREAK(condition)            \
    SMCP_ASSERT(condition) ;if( !(condition) ) break;

#define SMCP_ASSERT_RETURN(condition, retval)   \
    SMCP_ASSERT((condition)) ; if( !(condition) ) return retval;


/// Deprecated declarations.
/// It generates a warning at compile time
/// \par Usage:
/// For typedef:          typedef SMCP_DEPRECATED int IntType;
/// For classes/structs:  class SMCP_DEPRECATED testMethod{ ... };
/// For methods:          class TestClass { SMCP_DEPRECATED virtual void method() {} };
/// For functions:        template<class T> SMCP_DEPRECATED void templateTestMethod(void) {}
#if defined(SMCP_COMPILER_GCC) && (SMCP_COMPILER_VERSION >= 4)
#define SMCP_DEPRECATED attribute ((deprecated))
#elif defined(SMCP_COMPILER_MSVC) && (SMCP_COMPILER_VERSION >= 1300)
#define SMCP_DEPRECATED declspec(deprecated)
#else
#define SMCP_DEPRECATED
#endif

/// Force Inline: "inline as much as possible"
#if (defined SMCP_COMPILER_MSVC)
#define SMCP_FORCE_INLINE __forceinline
#else
#define SMCP_FORCE_INLINE inline
#endif

/// No inline:
#if (defined SMCP_COMPILER_GCC)
#define SMCP_DONT_INLINE __attribute__((noinline))
#elif (defined SMCP_COMPILER_MSVC)
#define SMCP_DONT_INLINE __declspec(noinline)
#else
#define SMCP_DONT_INLINE
#endif


/// Import/Export macros for C-style APIs
#ifdef __cplusplus
#define SMCP_EXTERN_C extern "C"
#else
#define SMCP_EXTERN_C
#endif



// Miscellaneous..
//
#if defined(SMCP_PLATFORM_WINDOWS)
# define SMCP_WIDE_NEWLINE      L"\r\n"
# define SMCP_NARROW_NEWLINE    "\r\n"
# define SMCP_STDCALL __stdcall
#elif defined(SMCP_PLATFORM_MACOSX)
# define SMCP_WIDE_NEWLINE      L"\n"
# define SMCP_NARROW_NEWLINE    "\n"
# define SMCP_STDCALL
#endif


#if !defined(_MAX_PATH)
# define _MAX_PATH 1024
#endif

#if defined(SMCP_DEBUG)
# define SMCP_BOUNDSCHECKS
#endif



// ----------------------------------------------------------------------------
// Allocators and Deallocators
// ----------------------------------------------------------------------------

// byte block memory allocator
//
#ifndef SMCP_ALLOC_MEMORY
#define SMCP_ALLOC_MEMORY( primitive_type, bytes )  \
    (primitive_type*) new primitive_type[bytes]
#endif

// byte block memory deallocator
//
#ifndef SMCP_FREE_MEMORY
#define SMCP_FREE_MEMORY( pointer ) \
    delete [] pointer; pointer = NULL;
#endif

// object memory allocator
//
#ifndef SMCP_ALLOC_OBJECT
#define SMCP_ALLOC_OBJECT( object_type ) \
    new object_type
#endif

// Object memory deallocator
//
#ifndef SMCP_FREE_OBJECT
#define SMCP_FREE_OBJECT( pointer )  \
    delete pointer; pointer = NULL;
#endif


// ----------------------------------------------------------------------------
// Memory Functions
// ----------------------------------------------------------------------------

// Compare Memory
//
#ifndef SMCP_COMPARE_MEMORY
#define SMCP_COMPARE_MEMORY( a, b, bytes )   \
    ::memcmp( (const void*)a, (const void*)b, bytes )
#endif

// Move Memory
//
#ifndef SMCP_MOVE_MEMORY
#define SMCP_MOVE_MEMORY( a, b, bytes )   \
    ::memmove( (const void*)a, (const void*)b, bytes )
#endif

// Copy Memory
//
#ifndef SMCP_COPY_MEMORY
#define SMCP_COPY_MEMORY( dest, src, bytes ) \
    ::memcpy( (void*)dest, (const void*)src, bytes )
#endif

// Fill Memory
//
#ifndef SMCP_FILL_MEMORY
#define SMCP_FILL_MEMORY( dest, fill, bytes ) \
    ::memset( (void*)dest, (const void*)src, bytes )
#endif

// Zero Memory
//
#ifndef SMCP_ZERO_MEMORY
#define SMCP_ZERO_MEMORY( pointer, bytes )   \
    ::memset( (void*)pointer, 0, bytes )
#endif


// ----------------------------------------------------------------------------
// String Functions
// ----------------------------------------------------------------------------

// compare ascii strings
//
#ifndef SMCP_COMPARE_ASCII_STRINGS
#define SMCP_COMPARE_ASCII_STRINGS( a, b )   \
    ::strcmp( a, b )
#endif

// compare wide strings
//
#ifndef SMCP_COMPARE_WIDE_STRINGS
#define SMCP_COMPARE_WIDE_STRINGS( a, b )           \
    ::wcscmp( a, b )
#endif

// compare ascii strings
//
#ifndef SMCP_COMPARE_ASCII_STRINGS_NOCASE
#define SMCP_COMPARE_ASCII_STRINGS_NOCASE( a, b )   \
    ::strcasecmp( a, b )
#endif

// compare wide strings
//
#ifndef SMCP_COMPARE_WIDE_STRINGS_NOCASE
#define SMCP_COMPARE_WIDE_STRINGS_NOCASE( a, b )     \
    ::wcsicmp( a, b )
#endif

// compare at most n characters in ascii strings
//
#ifndef SMCP_COMPARE_ASCII_STRINGS_NCHARS
#define SMCP_COMPARE_ASCII_STRINGS_NCHARS( a, b, n )   \
    ::strncmp( a, b, n )
#endif

// compare atmost n characters in wide strings
//
#ifndef SMCP_COMPARE_WIDE_STRINGS_NCHARS
#define SMCP_COMPARE_WIDE_STRINGS_NCHARS( a, b, n )   \
    ::wcsncmp( a, b, n )
#endif


// calculate length of ascii string
//
#ifndef SMCP_ASCII_STRING_LENGTH
#define SMCP_ASCII_STRING_LENGTH( s )    \
    ::strlen( s )
#endif

// calculate length of wide string in wchar_t
//
#ifndef SMCP_WIDE_STRING_LENGTH
#define SMCP_WIDE_STRING_LENGTH( s )    \
    ::wcslen( s )
#endif

// copy ascii strings
//
#ifndef SMCP_ASCII_STRING_COPY
#define SMCP_ASCII_STRING_COPY( a, b )    \
    ::strcpy(a, b)
#endif

// copy wide strings
//
#ifndef SMCP_WIDE_STRING_COPY
#define SMCP_WIDE_STRING_COPY( a, b )    \
    ::wcscpy(a, b)
#endif

// copy ascii strings with a given length
//
#ifndef SMCP_ASCII_STRING_COPY_LENGTH
#define SMCP_ASCII_STRING_COPY_LENGTH( a, b, n )    \
    ::strncpy(a, b, n)
#endif

// copy wide strings with a given length
//
#ifndef SMCP_WIDE_STRING_COPY_LENGTH
#define SMCP_WIDE_STRING_COPY_LENGTH( a, b, n )    \
    ::wcsncpy(a, b, n)
#endif

// concatenate ascii strings
//
#ifndef SMCP_ASCII_STRING_CONCATENATE
#define SMCP_ASCII_STRING_CONCATENATE( a, b )    \
    ::strcat(a, b)
#endif

// concatenate wide strings
//
#ifndef SMCP_WIDE_STRING_CONCATENATE
#define SMCP_WIDE_STRING_CONCATENATE( a, b )    \
    ::wcscat(a, b)
#endif

// tokenize ascii strings
//
#ifndef SMCP_ASCII_STRING_TOKENIZE
#define SMCP_ASCII_STRING_TOKENIZE( str, delim, state )    \
    ::strtok_r(str, delim, state)
#endif

// tokenize wide strings
//
#ifndef SMCP_WIDE_STRING_TOKENIZE
#define SMCP_WIDE_STRING_TOKENIZE( str, delim, state )    \
    ::wcstok(str, delim, state)
#endif

// Wide String length in bytes
//
#ifndef SMCP_WIDE_STRING_LENGTH_IN_BYTES
#define SMCP_WIDE_STRING_LENGTH_IN_BYTES( s )    \
    (::wcslen( s ) * sizeof(wchar_t))
#endif

// printf / scanf macros
//
#ifndef SMCP_COMPILER_MSVC
#    define SMCP_SWPRINTF   swprintf_s
#    define SMCP_SPRINTF    _snprintf
#    define SMCP_SWSCANF    swscanf_s
#else
#    define SMCP_SWPRINTF   swprintf
#    define SMCP_SPRINTF    snprintf
#    define SMCP_SWSCANF    swscanf
#endif


#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_SUFFIX_H