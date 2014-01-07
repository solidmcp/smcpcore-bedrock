
///////////////////////////////////////////////////////////////////////////////
/// \file  GCC.h
/// \brief GCC Compiler
///
/// GNU C Version Macros(GCC 4.5.3):
///    __GNUC__ == 4
///    __GNUC_MINOR__ == 5
///    __GNUC_PATCHLEVEL__ == 3
///////////////////////////////////////////////////////////////////////////////

#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_GCC_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_GCC_H
#pragma once

#ifndef __GNUC__
# pragma error("Uncompatiable compiler is detected..")
#endif

#define SMCP_COMPILER_NAME "GNU Compiler Collection"

#define SMCP_COMPILER_VERSION       __GNUC__
#define SMCP_COMPILER_VERSION_MINOR __GNUC_MINOR__
#define SMCP_COMPILER_GCC 1

// C++ 11 Support in different compiler
#include "cxx11support.h"

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_GCC_H