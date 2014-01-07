#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_SELECTOR_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_SELECTOR_H
#pragma once

// Platform Selector
//

// Microsoft Windows
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64)
#	define SMCP_PLATFORM_HEADER "platform/windows.h"

// Apple Macintosh
#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
#  define SMCP_PLATFORM_HEADER "plateform/macosx.h"

// Linux System
#elif defined(__linux__) || defined (linux) || defined (__linux)
#  define SMCP_PLATFORM_HEADER "plateform/linux.h"

// Unsupported Plateforms
//
#else
#	error("It's not on the schedule of SolidMCP at all.")
#endif


// Compiler Selector
//
//# if defined(__GNUC__) && !defined(__llvm__)
//  // gcc
//# elif defined(__llvm__) && !defined(__clang__)
//    //llvm gcc
//# elif defined(__clang__)
//    clang
//# elif defined(_MSC_VER)
//    vc
//# else
//    return str("unsupported");
//# endif

// Microsoft Visual Studio C++
//
#if defined(_MSC_VER)
#  define SMCP_COMPILER_HEADER "compiler/VC.h"

#elif defined(__clang__)
#  define SMCP_COMPILER_HEADER "compiler/clang.h"

// Gnu Compiler Collection
//
#elif defined(__GNUC__)
#  define SMCP_COMPILER_HEADER "compiler/GCC.h"

// Unsupported Compilers
//
#else
#	error("It's not on the schedule of SolidMCP")
#endif


#if defined(SMCP_COMPILER_HEADER)
#	include SMCP_COMPILER_HEADER
#endif


#if defined(SMCP_PLATFORM_HEADER)
#	include SMCP_PLATFORM_HEADER
#endif


#define PRAGMA_MESSAGE SMCP_COMPILER_NAME "  Version " SMCP_STRINGIZE(SMCP_COMPILER_VERSION)
#pragma message(PRAGMA_MESSAGE)
#undef PRAGMA_MESSAGE

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_SELECTOR_H