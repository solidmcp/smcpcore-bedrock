#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_PROMISE_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_PROMISE_H

namespace SolidMCP { namespace BedRock {

// Promise class is used in some cases to tell some inputs are pre-calculated and need no more checking.
// For example,
//        void Rountine(Inputs in)
//        {
//            if(CheckingWithout(in)
//            DoSomething(in);
//        }

//        void Rountine(Promise t, Inputs in)
//        {
//            DoSomething(in);
//        }
//
// If you make sure Inputs in has alrady been checked out of the runtine, why do the checking again?
// The introduction of this Promise class is interesting in such cases.
// Calling Rountine(Promise(), in) if checking has alrady made, why not?
// Though you can use boolean value to replace Promise, while Promise is much more instructive...
//
class Promise {};

template<typename TYPE>
class PromisedType {};

}}

#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_PROMISE_H