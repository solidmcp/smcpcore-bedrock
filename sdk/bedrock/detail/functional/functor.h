// Excellent implementation of Functor can be found in Loki and TTL.
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


#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_FUNCTIONAL_FUNCTOR_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_FUNCTIONAL_FUNCTOR_H
#pragma once

#include "../typetystem/nulltype.h"

#include "detail/functionptr.h"
#include "detail/memfuncptr.h"
#include "detail/operptr.h"

namespace SolidMCP { namespace BedRock {

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
class Functor
{
public:
    typedef typename CallableEntity<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6> CallableEntityTraits;

    typedef FunctionPtr<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6> FunctionPtrT;
    typedef MemberFunctor<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6> MemberFunctorT;
    typedef OperFunctor<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6> OperFunctorT;

    typedef ReturnT ReturnT;

    typedef Param1  ParamT; // Please only use for one param case.
    typedef Param1  Param1T;
    typedef Param2  Param2T;
    typedef Param3  Param3T;
    typedef Param4  Param4T;
    typedef Param5  Param5T;
    typedef Param6  Param6T;

    enum { ParamCount = FunctionPtrT::ParamCount};


    // Calls for all specialized case.
    //
    ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
    {
        return m_pCallableEntity(p1, p2, p3, p4, p5, p6);
    }

    ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
    {
        return m_pCallableEntity(p1, p2, p3, p4, p5);
    }

    ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4)
    {
        return m_pCallableEntity(p1, p2, p3, p4);
    }

    ReturnT operator()(Param1 p1, Param2 p2, Param3 p3)
    {
        return m_pCallableEntity(p1, p2, p3);
    }

    ReturnT operator()(Param1 p1, Param2 p2)
    {
        return (*m_pCallableEntity)(p1, p2);
    }

    ReturnT operator()(Param1 p1)
    {
        return (*m_pCallableEntity)(p1);
    }

    ReturnT operator()()
    {
        return (*m_pCallableEntity)(); // Or (*function_ptr)();
    }


    ReturnT Run()
    {
        return m_pCallableEntity->Run();
    }


    CallableEntityTraits* GetCallEntity() const
    {
        return m_pCallableEntity;
    }

    CallableEntityType::Code CallableType() const
    {
        return m_pCallableEntity ? m_pCallableEntity->Type() : CallableEntityType::kUnknow;
    }

public:

    Functor()
        : m_pCallableEntity(NULL)
    {
    }

    Functor(const Functor& rhs)
        : m_pCallableEntity(rhs.m_pCallableEntity->Clone())
    {
    }

    Functor(typename FunctionPtrT::Callback call_back)
        : m_pCallableEntity(new FunctionPtr<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6>(call_back))
    {
    }

    template <typename CALL_BACK>
    Functor(CALL_BACK call_back)
        :m_pCallableEntity(new OperFunctor<CALL_BACK, ReturnT, Param1, Param2, Param3, Param4, Param5, Param6>(&call_back))
    {
    }

    template <typename ObjectT, typename FuncT>
    Functor(ObjectT* rObj, FuncT func)
        : m_pCallableEntity(new MemberFunctor< ObjectT, FuncT, ReturnT,Param1, Param2, Param3, Param4, Param5, Param6>(rObj, func))
    {
    }

    ~Functor()
    {
        delete m_pCallableEntity;
        m_pCallableEntity = NULL;
    }

    bool IsValid() const
    {
        return m_pCallableEntity != NULL;
    }

    bool operator == (const Functor& right) const { return m_pCallableEntity == right.m_pCallableEntity;}
    bool operator != (const Functor& right) const { return ! operator == (right); }

    Functor& operator = (const Functor& right)
    {
        if(*this == right) return *this;

        m_pCallableEntity = right.m_pCallableEntity;
        return *this;
    }

private:
    CallableEntityTraits* m_pCallableEntity;
};



// -------------------------------------------------
// Helper functions to wrap callbacks with Functor
// -------------------------------------------------
// It's the primary template handles maximum number of parameters:
//
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
struct FunctorFactory
{
    typedef Functor<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6> FunctorT;
    static FunctorT Make(typename FunctorT::FunctionPtrT::Callback call_back)
    {
        return FunctorT(call_back);
    }

    template <typename CALL_BACK>
    static FunctorT Make(CALL_BACK call_back)
    {
        return FunctorT(call_back);
    }

    template <typename ObjectT, typename FuncT>
    static FunctorT Make(ObjectT* rObj, FuncT func)
    {
        return FunctorT(rObj, func);
    }
};

}}

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_FUNCTIONAL_FUNCTOR_H