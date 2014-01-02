#ifndef GUARD_SMCPCORE_BEDROCK_FUNCTIONAL_DETAILS_MEMBERFUNCPTR_H
#define GUARD_SMCPCORE_BEDROCK_FUNCTIONAL_DETAILS_MEMBERFUNCPTR_H

#pragma once
#include "../../typesystem/nulltype.h"
#include "callableentity.h"

namespace SolidMCP { namespace BedRock {

namespace Private
{

	// ----------------------------------------------
	// Member Function Traits (Variants = 6)
	// ----------------------------------------------

	template
		<
		typename ObjectT,
		typename FuncT,
		typename ReturnT,
		typename Param1 = NullType,
		typename Param2 = NullType,
		typename Param3 = NullType,
		typename Param4 = NullType,
		typename Param5 = NullType,
		typename Param6 = NullType
		>
	class MemberFuncTraits
	{
	public:
		enum { ParamCount = 6 };
		typedef ObjectT ObjectT;
		typedef FuncT FuncT;
		typedef ReturnT (ObjectT::*MemFunc)(Param1, Param2, Param3, Param4, Param5, Param6);
	};


	template
		<
		typename ObjectT,
		typename FuncT,
		typename ReturnT,
		typename Param1,
		typename Param2,
		typename Param3,
		typename Param4,
		typename Param5
		>
	class MemberFuncTraits<ObjectT, FuncT, ReturnT, Param1, Param2, Param3, Param4, Param5, NullType>
	{
	public:
		enum { ParamCount = 5 };
		typedef ObjectT ObjectT;
		typedef FuncT FuncT;
		typedef ReturnT (ObjectT::*MemFunc)(Param1, Param2, Param3, Param4, Param5);
	};


	template
		<
		typename ObjectT,
		typename FuncT,
		typename ReturnT,
		typename Param1,
		typename Param2,
		typename Param3,
		typename Param4
		>
	class MemberFuncTraits<ObjectT, FuncT, ReturnT, Param1, Param2, Param3, Param4, NullType, NullType>
	{
	public:
		enum { ParamCount = 4 };
		typedef ObjectT ObjectT;
		typedef FuncT FuncT;
		typedef ReturnT (ObjectT::*MemFunc)(Param1, Param2, Param3, Param4);
	};


	template
		<
		typename ObjectT,
		typename FuncT,
		typename ReturnT,
		typename Param1,
		typename Param2,
		typename Param3
		>
	class MemberFuncTraits<ObjectT, FuncT, ReturnT, Param1, Param2, Param3, NullType, NullType, NullType>
	{
	public:
		enum { ParamCount = 3 };
		typedef ObjectT ObjectT;
		typedef FuncT FuncT;
		typedef ReturnT (ObjectT::*MemFunc)(Param1, Param2, Param3);
	};


	template
		<
		typename ObjectT,
		typename FuncT,
		typename ReturnT,
		typename Param1,
		typename Param2
		>
	class MemberFuncTraits<ObjectT, FuncT, ReturnT, Param1, Param2, NullType, NullType, NullType, NullType>
	{
	public:
		enum { ParamCount = 2 };
		typedef ObjectT ObjectT;
		typedef FuncT FuncT;
		typedef ReturnT (ObjectT::*MemFunc)(Param1, Param2);
	};

	template
		<
		typename ObjectT,
		typename FuncT,
		typename ReturnT,
		typename Param1
		>
	class MemberFuncTraits<ObjectT, FuncT, ReturnT, Param1, NullType, NullType, NullType, NullType, NullType>
	{
	public:
		enum { ParamCount = 1 };
		typedef ObjectT ObjectT;
		typedef FuncT FuncT;
		typedef ReturnT (ObjectT::*MemFunc)(Param1);
	};

	template
		<
		typename ObjectT,
		typename FuncT,
		typename ReturnT
		>
	class MemberFuncTraits<ObjectT, FuncT, ReturnT, NullType, NullType, NullType, NullType, NullType, NullType>
	{
	public:
		enum { ParamCount = 0 };

		typedef ObjectT ObjectT;
		typedef FuncT FuncT;
		typedef ReturnT (ObjectT::*MemFunc)();
	};



}

// -----------------------------------------------------------------
// MemberFunctor for Member Functions (Variants = 6)
// -----------------------------------------------------------------

template
<
typename ObjectT,
typename FuncT,
typename ReturnT,
typename Param1 = NullType,
typename Param2 = NullType,
typename Param3 = NullType,
typename Param4 = NullType,
typename Param5 = NullType,
typename Param6 = NullType
>
class MemberFunctor  : public CallableEntity<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6>
{
public:
    typedef typename CallableEntity<ReturnT, Param1, Param2, Param3, Param4, Param5, Param6> Base;
	typedef typename Private::MemberFuncTraits<ObjectT, FuncT, ReturnT, Param1, Param2, Param3, Param4, Param5, Param6> FunctionTraits;
	typedef typename FunctionTraits::MemFunc MemFunc;

	typedef typename FunctionTraits::ObjectT ObjectT;
	typedef typename FunctionTraits::FuncT FuncT;

	typedef ReturnT ReturnT;

	typedef Param1  ParamT; // Please only use for one param case.
	typedef Param1  Param1T;
	typedef Param2  Param2T;
	typedef Param3  Param3T;
	typedef Param4  Param4T;
	typedef Param5  Param5T;
	typedef Param6  Param6T;

	enum { ParamCount = FunctionTraits::ParamCount };
    enum { CallableType = CallableEntityType::kMemberFunc};

	// Calls for all specialized case.
	//
	ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
	{
		return ((*m_rObj).*func_ptr)(p1, p2, p3, p4, p5, p6);
	}

	ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
	{
		return (m_rObj.*func_ptr)(p1, p2, p3, p4, p5);
	}

	ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4)
	{
		return (m_rObj.*func_ptr)(p1, p2, p3, p4);
	}

	ReturnT operator()(Param1 p1, Param2 p2, Param3 p3)
	{
		return (m_rObj.*func_ptr)(p1, p2, p3);
	}

	ReturnT operator()(Param1 p1, Param2 p2)
	{
		return (m_rObj.*func_ptr)(p1, p2);
	}

	ReturnT operator()(Param1 p1)
	{
		return ((*m_rObj).*func_ptr)(p1);
	}

	ReturnT operator()()
	{
		return ((*m_rObj).*func_ptr)();
	}


public:

	MemberFunctor(ObjectT* rObj, FuncT func)
	{
		func_ptr = func;
		m_rObj = rObj;
	}

	bool IsValid() const
	{
		return *func_ptr != NULL;
	}

	virtual CallableEntity* Clone() const { return new MemberFunctor(*this);}


	//bool operator == (const Functor& right) const { return func_ptr == right.func_ptr;}
	//bool operator != (const Functor& right) const { return ! operator == (right); }

	//Functor& operator = (const Functor& right)
	//{
	//	if(*this == right) return *this;

	//	func_ptr = right.func_ptr;
	//	return *this;
	//}

        virtual CallableEntityType::Code Type() const
        {
            return static_cast<CallableEntityType::Code>( CallableType);
        }



    void GetObject() const
    {
        return m_rObj;
    }

    const MemFunc& GetMemFunc() const
    {
        return func_ptr;
    }

private:
	MemFunc func_ptr;
	ObjectT* m_rObj;
};



END_NAMESPACE_BEDROCK

#endif // GUARD_SMCPCORE_BEDROCK_FUNCTIONAL_DETAILS_MEMBERFUNCPTR_H
