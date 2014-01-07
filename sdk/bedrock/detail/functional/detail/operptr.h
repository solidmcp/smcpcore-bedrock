
#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_FUNCTIONAL_DETAILS_OPERPTR_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_FUNCTIONAL_DETAILS_OPERPTR_H
#pragma once

#include "../../typesystem/nulltype.h"
#include "callableentity.h"
#include "functionptr.h"

namespace SolidMCP { namespace BedRock {

// -----------------------------------------------------------------
// OperFunctor for C++ operator(...) (Variants = 6)
// -----------------------------------------------------------------

template
<
typename ObjectT,
typename ReturnT,
typename Param1 = NullType,
typename Param2 = NullType,
typename Param3 = NullType,
typename Param4 = NullType,
typename Param5 = NullType,
typename Param6 = NullType
>
class OperFunctor  : public CallableEntity<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6>
{
public:
	typedef typename CallableEntity<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6> Base;
	typedef typename Private::FunctionTraits<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6> FunctionTraits;
	typedef typename FunctionTraits::Callback Callback;

	typedef typename ObjectT ObjectT;


	typedef ReturnT ReturnT;

	typedef Param1  ParamT; // Please only use for one param case.
	typedef Param1  Param1T;
	typedef Param2  Param2T;
	typedef Param3  Param3T;
	typedef Param4  Param4T;
	typedef Param5  Param5T;
	typedef Param6  Param6T;

	enum { ParamCount = FunctionTraits::ParamCount };
	enum { CallableType = CallableEntityType::kOperator};

	// Calls for all specialized case.
	//
	ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
	{
		return (*m_rObj)(p1, p2, p3, p4, p5, p6);
	}

	ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
	{
		return (*m_rObj)(p1, p2, p3, p4, p5);
	}

	ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4)
	{
		return (*m_rObj)(p1, p2, p3, p4);
	}

	ReturnT operator()(Param1 p1, Param2 p2, Param3 p3)
	{
		return (*m_rObj)(p1, p2, p3);
	}

	ReturnT operator()(Param1 p1, Param2 p2)
	{
		return (*m_rObj)(p1, p2);
	}

	ReturnT operator()(Param1 p1)
	{
		return (*m_rObj)(p1);
	}

	ReturnT operator()()
	{
		return (*m_rObj)(); // Or (*function_ptr)();
	}


public:

	OperFunctor(ObjectT* rObj)
	{
		m_rObj = rObj;
	}

	virtual CallableEntity* Clone() const
	{
		return new OperFunctor(*this);
	}

	bool IsValid() const
	{
		return m_rObj != NULL;
	}

	ObjectT* GetOjbect()
	{
		return m_rObj;
	};

	virtual CallableEntityType::Code Type() const
	{
		return static_cast<CallableEntityType::Code>( CallableType);
	}

	//bool operator == (const Functor& right) const { return func_ptr == right.func_ptr;}
	//bool operator != (const Functor& right) const { return ! operator == (right); }

	//Functor& operator = (const Functor& right)
	//{
	//	if(*this == right) return *this;

	//	func_ptr = right.func_ptr;
	//	return *this;
	//}

private:
	ObjectT* m_rObj;
};


}}

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_FUNCTIONAL_DETAILS_OPERPTR_H