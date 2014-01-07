
#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPESELECTOR_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPESELECTOR_H

namespace SolidMCP { namespace BedRock {

// TypeSelector is used to select desired type.
// bFirst is True, the 1st type is used.
// bFirst is False, then 2nd type is used instead.,
//
template<bool bFirst, typename Type1, typename Type2>
struct TypeSelector
{
    typedef Type1 Result;
};

template<typename Type1, typename Type2>
struct TypeSelector<false, Type1, Type2>
{
    typedef Type2 Result;
};

}}

#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPESELECTOR_H
