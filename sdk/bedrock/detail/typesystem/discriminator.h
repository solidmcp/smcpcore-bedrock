
#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_DISCRIMINATOR_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_DISCRIMINATOR_H
#pragma once

namespace SolidMCP { namespace BedRock {

    // Class Discriminator is useful if you want to avoid deriving from same class
    // Add a Index there makes things different.
    // More details, please see how to support named functon parameter in chapter 16.5 of "C++ Template" .
    ///How to use:
    //    template<typename Mx = XXXClass, typename My = XXXClass>
    //    class YYYClass : public Discriminator<Mx, 1>,
    //                     public Discriminator<My, 2>
    //    {
    //    };
    //
    template<typename Base, int Index>
    class Discriminator : public Base
    {
    };
}}

#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_DISCRIMINATOR_H