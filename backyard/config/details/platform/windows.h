#ifndef GUARD_SMCPCORE_BEDROCK_CONFIG_PLATFORM_WINDOWS_H
#define GUARD_SMCPCORE_BEDROCK_CONFIG_PLATFORM_WINDOWS_H
#pragma once

#define SMCP_PLATFORM_NAME_WIN32 "Microsoft Windows 32 bit"
#define SMCP_PLATFORM_NAME_AMD64 "Microsoft Windows 64 bit (AMD)"
#define SMCP_PLATFORM_NAME_IA64  "Microsoft Windows 64 bit (Itanium)"

#if defined  _M_IX86
#    define SMCP_PLATFORM_NAME SMCP_PLATFORM_NAME_WIN32
#elif   _M_AMD64
#    define SMCP_PLATFORM_NAME SMCP_PLATFORM_NAME_AMD64
#elif   _M_IA64
#    define SMCP_PLATFORM_NAME SMCP_PLATFORM_NAME_IA64
#else
#    error "Unknown Architecture detected"
#endif

#pragma message(SMCP_PLATFORM_NAME)


#define SMCP_PLATFORM_WINDOWS 1

#endif // GUARD_SMCPCORE_BEDROCK_CONFIG_PLATFORM_WINDOWS_H
