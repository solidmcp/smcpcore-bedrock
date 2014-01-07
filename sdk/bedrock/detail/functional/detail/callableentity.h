
// CallableEntity is the base interface for following callable entities
//  C-Style Callback (Static Function in C++)
//  C++ operator (...)
//  C++ Member Functions
//
#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_FUNCTIONAL_DETAILS_CALLABLEENTITY_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_FUNCTIONAL_DETAILS_CALLABLEENTITY_H
# pragma once

namespace SolidMCP { namespace BedRock {

struct CallableEntityType
{
    enum Code
    {
        kFunction = 0,
        kMemberFunc = 1,
        kOperator = 2,
        kUnknow = 3
    };
};

// -----------------------------------------------------------------
// CallableEntity (Variants = 6)
// -----------------------------------------------------------------

template
<
typename ReturnT,
typename Param1,
typename Param2,
typename Param3,
typename Param4,
typename Param5,
typename Param6
>
class CallableEntity
{
public:

    //typedef ReturnT ReturnT;

    typedef Param1  ParamT; // Please only use for one param case.
    typedef Param1  Param1T;
    typedef Param2  Param2T;
    typedef Param3  Param3T;
    typedef Param4  Param4T;
    typedef Param5  Param5T;
    typedef Param6  Param6T;

    virtual ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6) = 0;
    virtual CallableEntity* Clone() const = 0;
    virtual CallableEntityType::Code Type() const { return CallableEntityType::kUnknow; }

    ReturnT Run(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
    {
        return operator()(p1, p2, p3, p4, p5, p6);
    }

    void invoke(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
    {
        operator()(p1, p2, p3, p4, p5, p6);
    }
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
class CallableEntity<ReturnT, Param1, Param2, Param3, Param4, Param5, NullType>
{
public:

    //typedef ReturnT ReturnT;

    typedef Param1  ParamT; // Please only use for one param case.
    typedef Param1  Param1T;
    typedef Param2  Param2T;
    typedef Param3  Param3T;
    typedef Param4  Param4T;
    typedef Param5  Param5T;

    virtual ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5) = 0;
    virtual CallableEntity* Clone() const = 0;
    virtual CallableEntityType::Code Type() const { return CallableEntityType::kUnknow; }

    ReturnT Run(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
    {
        return operator()(p1, p2, p3, p4, p5);
    }
};


template
<
typename ReturnT,
typename Param1,
typename Param2,
typename Param3,
typename Param4
>
class CallableEntity<ReturnT, Param1, Param2, Param3, Param4, NullType, NullType>
{
public:

    //typedef ReturnT ReturnT;

    typedef Param1  ParamT; // Please only use for one param case.
    typedef Param1  Param1T;
    typedef Param2  Param2T;
    typedef Param3  Param3T;
    typedef Param4  Param4T;

    virtual ReturnT operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4) = 0;
    virtual CallableEntity* Clone() const = 0;
    virtual CallableEntityType::Code Type() const { return CallableEntityType::kUnknow; }


    ReturnT Run(Param1 p1, Param2 p2, Param3 p3, Param4 p4)
    {
        return operator()(p1, p2, p3, p4);
    }
};

template
<
typename ReturnT,
typename Param1,
typename Param2,
typename Param3
>
class CallableEntity<ReturnT, Param1, Param2, Param3, NullType, NullType, NullType>
{
public:

    //typedef ReturnT ReturnT;

    typedef Param1  ParamT; // Please only use for one param case.
    typedef Param1  Param1T;
    typedef Param2  Param2T;
    typedef Param3  Param3T;

    virtual ReturnT operator()(Param1 p1, Param2 p2, Param3 p3) = 0;
    virtual CallableEntity* Clone() const = 0;
    virtual CallableEntityType::Code Type() const { return CallableEntityType::kUnknow; }


    ReturnT Run(Param1 p1, Param2 p2, Param3 p3)
    {
        return operator()(p1, p2, p3);
    }
};

template
<
typename ReturnT,
typename Param1,
typename Param2
>
class CallableEntity<ReturnT, Param1, Param2, NullType, NullType, NullType, NullType>
{
public:

    //typedef ReturnT ReturnT;

    typedef Param1  ParamT; // Please only use for one param case.
    typedef Param1  Param1T;
    typedef Param2  Param2T;

    virtual ReturnT operator()(Param1 p1, Param2 p2) = 0;
    virtual CallableEntity* Clone() const = 0;
    virtual CallableEntityType::Code Type() const { return CallableEntityType::kUnknow; }


    ReturnT Run(Param1 p1, Param2 p2)
    {
        return operator()(p1, p2);
    }
};

template
<
typename ReturnT,
typename Param1

>
class CallableEntity<ReturnT, Param1  , NullType  , NullType  , NullType  , NullType, NullType>
{
public:

    //typedef ReturnT ReturnT;

    typedef Param1  ParamT; // Please only use for one param case.
    typedef Param1  Param1T;

    virtual ReturnT operator()(Param1 p1) = 0;
    virtual CallableEntity* Clone() const = 0;
    virtual CallableEntityType::Code Type() const { return CallableEntityType::kUnknow; }


    ReturnT Run(Param1 p1)
    {
        return operator()(p1);
    }
};

template
<
typename ReturnT
>
class CallableEntity<ReturnT, NullType, NullType, NullType, NullType, NullType, NullType>
{
public:

    //typedef ReturnT ReturnT;

    virtual ReturnT operator()() = 0;
    virtual CallableEntity* Clone() const = 0;

    virtual CallableEntityType::Code Type()
        const
    { return CallableEntityType::kUnknow;
    }


    ReturnT Run()
    {
        return operator()();
    }

    void invoke()
    {
        return operator()();
    }
};


}}

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_FUNCTIONAL_DETAILS_CALLABLEENTITY_H
