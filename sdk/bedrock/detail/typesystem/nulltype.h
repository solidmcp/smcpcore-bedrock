#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_NULLTYPE_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_NULLTYPE_H

namespace SolidMCP { namespace BedRock {

// It's also borrowed from Modern C++ Design
// As in Loki, it's used as a placeholder for "no type here"
// At many time, we need such a class for templated classes.
// Because void is not allowed in argument list.
// In the Funtor and TypeList implementation, we can see NullType there,
//
class NullType {};

}}

#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_NULLTYPE_H