
#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPEMAPPER_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPEMAPPER_H
#pragma once

namespace SolidMCP { namespace BedRock {

// TypeMapper is used for mapping constant value or certain type to type.
// It can be used to perform dispatch at compile time in template code.
// For more details, please refer to Modern C++ Design Section 2.4 and 2.5.
//
template<typename T>
struct Type2Type
{
    typedef T Type;
};

template<int value>
struct Int2Type
{
    enum{Value = value};
};

}}

#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPEMAPPER_H
