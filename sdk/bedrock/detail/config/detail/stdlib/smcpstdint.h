
#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_STDLIB_STDINT_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_STDLIB_STDINT_H
#pragma once

#include <stddef.h>
#include <stdio.h>

#if defined(SMCP_PLATFORM_WINDOWS)

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
// intptr_t and friends are defined in crtdefs.h through stdio.h.

#else

#include <stdint.h>

#endif

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_STDLIB_STDINT_H
