
///////////////////////////////////////////////////////////////////////////////
/// \file  VC.h
/// \brief Visual Studio C++ Compiler
///
/// Visual C++ Version Macros:
///    MS VC++ 10.0 _MSC_VER = 1600 (Visual Studio 2010)
///    MS VC++ 9.0  _MSC_VER = 1500
///    MS VC++ 8.0  _MSC_VER = 1400
///    MS VC++ 7.1  _MSC_VER = 1310
///    MS VC++ 7.0  _MSC_VER = 1300
///    MS VC++ 6.0  _MSC_VER = 1200
///    MS VC++ 5.0  _MSC_VER = 1100
///////////////////////////////////////////////////////////////////////////////

#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_VC_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_VC_H
#pragma once

#if !defined(_MSC_VER)
# pragma error("Uncompatiable compiler is detected..")
#endif

#define SMCP_COMPILER_NAME "Microsoft Visual Studio C++"

#define SMCP_COMPILER_VERSION  _MSC_VER
#define SMCP_COMPILER_VERSION_MINOR 0
#define SMCP_COMPILER_MSVC 1

// C++ 11 Support in different compiler
#include "cxx11support.h"

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_VC_H
