
///////////////////////////////////////////////////////////////////////////////
/// \file Cxx11Support.h
///
/// \par References:
/// <br> -- <a href="http://en.wikipedia.org/wiki/C%2B%2B0x">C++ 11 on WikipediaM</a>
/// <br> -- <a href="http://msdn.microsoft.com/en-us/library/hh567368.aspx">modern</a>
/// <br> -- <a href="http://gcc.gnu.org/projects/cxx0x.html">C++0x/C++11 Support in GCC</a>
/// <br> -- <a href="http://clang.llvm.org/cxx_status.html">C++98 and C++11 Support in Clang</a>
///////////////////////////////////////////////////////////////////////////////

#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_CXX11SUPPORT_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_CXX11SUPPORT_H
#pragma once

#if defined(SMCP_COMPILER_MSVC) && (SMCP_COMPILER_VERSION >= 1600)
# define SMCP_TR1_SUPPORTED
#endif

// Defaulted and deleted functions
#if defined(SMCP_COMPILER_GCC) && (SMCP_COMPILER_VERSION >= 4) && (SMCP_COMPILER_VERSION_MINOR >= 6)
#define SMCP_ENABLED_CXX11_DELETE_FUNCTIONS 1
#endif

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_COMPILER_CXX11SUPPORT_H