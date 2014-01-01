
// Baking TUT and catch into SolidMCP. Both of them are heard only.
// TUT: C++ Template Unit Test Framework
// catch: C++ Automated Test Cases in Headers
//
#ifndef GUARD_SMCPCORE_BEDROCK_TESTSUPPORT_H
#define GUARD_SMCPCORE_BEDROCK_TESTSUPPORT_H

#pragma message("Build a wrapper for TUT and igloo")

// Unit Test Support
// TUT 2009
//
#include "./../backyard/testsupport/tut/tut.h"
#include "./../backyard/testsupport/tut/tut_reporter.h"
#include "./../backyard/testsupport/tut/tut_restartable.h"

// Behavior Test Support
// catch 2003 - 12 - 23
//
#include "./../backyard/testsupport/catch/catch.hpp"

#endif // GUARD_SMCPCORE_BEDROCK_TESTSUPPORT_H