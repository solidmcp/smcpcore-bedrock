
// Baking TUT and catch into SolidMCP. Both of them are header only.
// TUT: C++ Template Unit Test Framework
// catch: C++ Automated Test Cases in Headers

#ifndef GUARD_SMCPCORE_BEDROCK_API_TESTSUPPORT_H
#define GUARD_SMCPCORE_BEDROCK_API_TESTSUPPORT_H
#pragma once

// Unit Test Support
// TUT 2009
//
#include "./detail/testsupport/tut/tut.h"
#include "./detail/testsupport/tut/tut_reporter.h"
#include "./detail/testsupport/tut/tut_restartable.h"

// Behavior Test Support
// catch 2003 - 12 - 23
//
#include "./detail/testsupport/catch/catch.hpp"

#endif // GUARD_SMCPCORE_BEDROCK_API_TESTSUPPORT_H