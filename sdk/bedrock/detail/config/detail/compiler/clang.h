
///////////////////////////////////////////////////////////////////////////////
/// \file  clang.h
/// \brief llvm clang Compiler
///
///////////////////////////////////////////////////////////////////////////////

#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_CLANG_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_CLANG_H
#pragma once

#if !defined(__clang__)
# pragma error("Uncompatiable compiler is detected..")
#endif

#define SMCP_COMPILER_NAME "LLVM clang"

#define SMCP_COMPILER_VERSION       __clang_version__
#define SMCP_COMPILER_VERSION_MINOR __GNUC_MINOR__
#define SMCP_COMPILER_GCC 1

// C++ 11 Support in different compiler
#include "cxx11support.h"

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_CLANG_H