
#ifndef GUARD_SMCPCORE_BEDROCK_FUNCTIONAL_COMPARATOR_H
#define GUARD_SMCPCORE_BEDROCK_FUNCTIONAL_COMPARATOR_H
#pragma once


namespace SolidMCP { namespace BedRock {

struct Comparator
{
    // ==
    template<class T1, class T2 = T1>
    struct EqualTo
    {
        bool operator()( const T1& lhs, const T2& rhs ) const
        {
            return static_cast<bool>(lhs == rhs);
        }
    };

    // !=
    template<class T1, class T2 = T1>
    struct NotEqualTo
    {
        bool operator()( const T1& lhs, const T2& rhs ) const
        {
            return static_cast<bool>(lhs != rhs);
        }
    };

    // <
    //
    template<class T1, class T2 = T1>
    struct LessThan
    {
        bool operator()( const T1& lhs, const T2& rhs ) const
        {
            return (lhs < rhs);
        }
    };

    // >
    //
    template<class T1, class T2 = T1>
    struct GreaterThan
    {
        bool operator()( const T1& lhs, const T2& rhs ) const
        {
            return (lhs > rhs);
        }
    };


    // <=
    //
    template<class T1, class T2 = T1>
    struct LessEqualTo
    {
        bool operator()( const T1& lhs, const T2& rhs ) const
        {
            return (lhs <= rhs);
        }
    };

    // >=
    //
    template<class T1, class T2 = T1>
    struct GreaterEqualTo
    {
        bool operator()( const T1& lhs, const T2& rhs ) const
        {
            return (lhs >= rhs);
        }
    };

};


struct Comparable
{
    template<class T1, class T2 = T1>
    struct EqualTo
    {
        T1 lhs;
        EqualTo(const T1& t1) : lhs(t1){}

        bool operator()(const T2& rhs ) const
        {
            return static_cast<bool>(lhs == rhs);
        }
    };


    // !=
    template<class T1, class T2 = T1>
    struct NotEqualTo
    {
        T1 lhs;
        NotEqualTo(const T1& t1) : lhs(t1){}

        bool operator()(const T2& rhs ) const
        {
            return static_cast<bool>(lhs != rhs);
        }
    };

    // <
    //
    template<class T1, class T2 = T1>
    struct LessThan
    {
        T1 lhs;
        LessThan(const T1& t1) : lhs(t1){}

        bool operator()(const T2& rhs ) const
        {
            return (lhs < rhs);
        }
    };

    // >
    //
    template<class T1, class T2 = T1>
    struct GreaterThan
    {
        T1 lhs;
        GreaterThan(const T1& t1) : lhs(t1){}

        bool operator()(const T2& rhs ) const
        {
            return (lhs > rhs);
        }
    };


    // <=
    //
    template<class T1, class T2 = T1>
    struct LessEqualTo
    {
        T1 lhs;
        LessEqualTo(const T1& t1) : lhs(t1){}

        bool operator()(const T2& rhs ) const
        {
            return (lhs <= rhs);
        }
    };

    // >=
    //
    template<class T1, class T2 = T1>
    struct GreaterEqualTo
    {
        T1 lhs;
        GreaterEqualTo(const T1& t1) : lhs(t1){}

        bool operator()(const T2& rhs ) const
        {
            return (lhs >= rhs);
        }
    };
};

}}

#endif // GUARD_SMCPCORE_BEDROCK_FUNCTIONAL_COMPARATOR_H
