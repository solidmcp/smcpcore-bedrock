// Exllent implementation of Functor can be found in Loki and TTL.
// The implementations here are mainly following book "C++ Template".
// However they are so heavy and I'd like to limit the argument count to be in 5
// So, in such a case, we can create a template functor easily.
//
// Basic Implementation of Functor is using C++ callable Entity (operator()) to wrap callback.
//
//      template<typename RT, typename P1>
//      class Functor
//      {
//      public:
//              typedef RT (*pf) (P1);
//
//              RT operator ()(P1 p1)
//              {
//                      (*pf)(p1);
//              };
//      };
//
// But, for different argument, the Functor objects are same.
// That's why Bind concept was introduced into Functor.
// By using Bind, you can bind different value to a functor,
// then the functors are different though they are from same callback.
// It also makes it possible to use Functor for Undo/redo.
//


#ifndef GUARD_SMCPCORE_BEDROCK_FUNCTIONAL_DETAILS_FUNCTOINPTR_H
#define GUARD_SMCPCORE_BEDROCK_FUNCTIONAL_DETAILS_FUNCTOINPTR_H
#pragma once

#include "../../typesystem/nulltype.h"
#include "callableentity.h"

namespace SolidMCP { namespace BedRock {

// -------------------------------------------------
// -------------------------------------------------

// It's the primary template handles maximum number of parameters:
// If you want to extend to a larger param count, just add a specialized one before it.
//
// Because void is not allowed in argument list.
// In the Funtor and TypeList implementation, we can see NullType there,
// In book "C++ Template", a "Unused" class is provided instead.
// In actual, they are quite same.
//
namespace Private
{
    // -----------------------------------------------------------------
    // FunctionTraits for Callbacks (Variants = 6)
    // -----------------------------------------------------------------

    template
        <
        typename ReturnT,
        typename Param1 = NullType,
        typename Param2 = NullType,
        typename Param3 = NullType,
        typename Param4 = NullType,
        typename Param5 = NullType,
        typename Param6 = NullType
        >
    class FunctionTraits
    {
    public:
        enum { ParamCount = 6 };
        typedef ReturnT (*Callback)(Param1, Param2, Param3, Param4, Param5, Param6);
    };


    template
        <
        typename ReturnT,
        typename Param1,
        typename Param2,
        typename Param3,
        typename Param4,
        typename Param5
        >
    class FunctionTraits<ReturnT, Param1, Param2, Param3, Param4, Param5, NullType>
    {
    public:
        enum { ParamCount = 5 };
        typedef ReturnT (*Callback)(Param1, Param2, Param3, Param4, Param5);
    };

    template
        <
        typename ReturnT,
        typename Param1,
        typename Param2,
        typename Param3,
        typename Param4
        >
    class FunctionTraits<ReturnT, Param1, Param2, Param3, Param4, NullType, NullType>
    {
    public:
        enum { ParamCount = 4 };
        typedef ReturnT (*Callback)(Param1, Param2, Param3, Param4);
    };


    template
        <
        typename ReturnT,
        typename Param1,
        typename Param2,
        typename Param3
        >
    class FunctionTraits<ReturnT, Param1, Param2, Param3, NullType, NullType, NullType>
    {
    public:
        enum { ParamCount = 3 };
        typedef ReturnT (*Callback)(Param1, Param2, Param3);
    };

    template
        <
        typename ReturnT,
        typename Param1,
        typename Param2
        >
    class FunctionTraits<ReturnT, Param1, Param2, NullType, NullType, NullType, NullType>
    {
    public:
        enum { ParamCount = 2 };
        typedef ReturnT (*Callback)(Param1, Param2);
    };

    template
        <
        typename ReturnT,
        typename Param1
        >
    class FunctionTraits<ReturnT, Param1, NullType, NullType, NullType, NullType, NullType>
    {
    public:
        enum { ParamCount = 1 };
        typedef ReturnT (*Callback)(Param1);
    };

    template
        <
        typename ReturnT
        >
    class FunctionTraits<ReturnT, NullType, NullType, NullType, NullType, NullType, NullType>
    {
    public:
        enum { ParamCount = 0 };
        typedef ReturnT (*Callback)();
    };
}


// -----------------------------------------------------------------
// FunctionPtr for Callbacks (Variants = 6)
// -----------------------------------------------------------------

template
<
typename ReturnT,
typename Param1 = NullType,
typename Param2 = NullType,
typename Param3 = NullType,
typename Param4 = NullType,
typename Param5 = NullType,
typename Param6 = NullType
>
class FunctionPtr : public CallableEntity<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6>
{
public:

    typedef typename Private::FunctionTraits<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6> FunctionTraits;
    typedef typename FunctionTraits::Callback Callback;

    //typedef ReturnT ReturnT;

    typedef Param1  ParamT; // Please only use for one param case.
    typedef Param1  Param1T;
    typedef Param2  Param2T;
    typedef Param3  Param3T;
    typedef Param4  Param4T;
    typedef Param5  Param5T;
    typedef Param6  Param6T;

    enum { ParamCount = FunctionTraits::ParamCount };
    enum { CallableType = CallableEntityType::kFunction};

    // Calls for all specialized case.
    //
    ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
    {
        return func_ptr(p1, p2, p3, p4, p5, p6);
    }

    ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
    {
        return func_ptr(p1, p2, p3, p4, p5);
    }

    ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4)
    {
        return func_ptr(p1, p2, p3, p4);
    }

    ReturnT operator()(Param1 p1, Param2 p2, Param3 p3)
    {
        return func_ptr(p1, p2, p3);
    }

    ReturnT operator()(Param1 p1, Param2 p2)
    {
        return func_ptr(p1, p2);
    }

    ReturnT operator()(Param1 p1)
    {
        return func_ptr(p1);
    }

    ReturnT operator()()
    {
        return func_ptr(); // Or (*function_ptr)();
    }

public:

    FunctionPtr(Callback call_back) : func_ptr(call_back)
    {
    }


    FunctionPtr(const FunctionPtr& f)
    { this->operator=(f); }

    virtual CallableEntity* Clone() const
    {
        return new FunctionPtr(*this);
    }

    bool IsValid() const
    {
        return *func_ptr != NULL;
    }

    bool operator == (const FunctionPtr& right) const { return func_ptr == right.func_ptr;}
    bool operator != (const FunctionPtr& right) const { return ! operator == (right); }

    FunctionPtr& operator = (const FunctionPtr& right)
    {
        if(*this == right) return *this;

        func_ptr = right.func_ptr;
        return *this;
    }

    Callback GetCallback() const
    {
       return func_ptr;
   }

    virtual CallableEntityType::Code Type() const
    {
        return static_cast<CallableEntityType::Code>( CallableType);
    }

private:
    Callback func_ptr;
};


}}

#endif // GUARD_SMCPCORE_BEDROCK_FUNCTIONAL_DETAILS_FUNCTOINPTR_H
