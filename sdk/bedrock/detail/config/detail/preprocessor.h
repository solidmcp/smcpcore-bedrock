
#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_PREPROCESSOR_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_PREPROCESSOR_H
#pragma once


#ifndef __func__
#define __func__ __FUNCTION__
#endif


// Unicode or MBCS
//
#if defined(UNICODE) || defined(_UNICODE) || defined(SMCP_UNICODE)
#    define CHARACTER_SET "Unicode"
#    ifndef SMCP_UNICODE
#        define SMCP_UNICODE       // Internal Unicode flag used in SolidMCP
#    endif
#    ifndef UNICODE
#        define UNICODE            // UNICODE is used by Windows headers
#    endif
#    ifndef _UNICODE
#        define _UNICODE           // _UNICODE is used by C-runtime/MFC headers
#    endif
#else
#    define CHARACTER_SET "Non-Unicode(MBCS)"
#endif


// Debug Flag
//
#if defined(DEBUG) || defined(_DEBUG)
#    define BUILD_CONFIGURATON "Debug"
#    ifndef SMCP_DEBUG
#        define SMCP_DEBUG    // Internal debug flag used in SolidMCP
#    endif
#    ifndef DEBUG
#        define DEBUG         // _DEBUGUNICODE is used by Windows headers
#    endif
#    ifndef _DEBUG
#        define _DEBUG        // _UNICODE is used by C-runtime/MFC headers
#    endif
#else
#    define BUILD_CONFIGURATON "Optimize"
#endif

// useful ctor/dtor macros for utility classes
#define SMCP_UTILITY_CLASS(ClassName)   \
    private:     \
    ClassName(); \
    ClassName(const ClassName & other); \
    ~ClassName(); \
    ClassName & operator=(const ClassName & other);\


#define PRAGMA_MESSAGE CHARACTER_SET "/" SMCP_STRINGIZE(BUILD_CONFIGURATON)
#pragma message(PRAGMA_MESSAGE)
#undef PRAGMA_MESSAGE

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_PREPROCESSOR_H
