// For a Non-Derivable class, None of classes can be derived from it..
//
// More details:
// 1. C/C++ Tip #6: Making Classes Non-Derivable
//    It's proven that Shanker's method is not feasiable. So, there was a discussion again.
//    Artical: http://www.ddj.com/cpp/184401394
//    Discussion: http://www.ddj.com/cpp/184401423
//    P.S However, I cannot repro the issue on VS 2008 by testing the code snippt.Why? See  Test_UnDerivable.cpp.
// 2. Another discussion about non-derivable.
//    http://lists.boost.org/Archives/boost/2004/04/63692.php
//
#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_UNDERIVABLE_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_UNDERIVABLE_H
#pragma once

namespace SolidMCP { namespace BedRock {

template<class T> class UnDerivable;

template <typename T>
class UnDerivableBase
{
private:

    friend T; // Must have..
    friend class UnDerivable< T >;

    UnDerivableBase() {}
    UnDerivableBase(const UnDerivableBase&) {}
};

template<typename T>
class UnDerivable : public virtual UnDerivableBase<T >
{
};

}}


#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_UNDERIVABLE_H
