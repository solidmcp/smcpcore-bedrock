
#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_BINDENUM_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_BINDENUM_H

#pragma once
#include "../mpl/typelist.h"
#include "../mpl/constanttuple.h"
#include "../status/exception.h"

// --------------------------------------------------------------------------------------------------------
// Bind Enum with Tempalte based solution originated from meta programming
// Enum -- > BINDING_ENUM_TO_VALUE -> EnumTuple -> EnumBinder
// --------------------------------------------------------------------------------------------------------

// EnumBind should not be wrapped in a namespace for it's difficult to explicitly instantiate in other namespaces.
// A Static Assert is need to check if T is enum in the future.
//
template<typename ENUM_TYPE, ENUM_TYPE EV, typename T>
struct EnumBind
{
    typedef ENUM_TYPE ENUM_TYPE;
    typedef T TO_TYPE;
    static T ToValue();
    static ENUM_TYPE ToEnum();
};

// A Macro is used to bind enumerator to value
//
#define BINDING_ENUM_TO_VALUE(ENUMERATOR, VALUE, TOTYPE, TOVALUE)               \
    template<>                                                                  \
struct EnumBind<ENUMERATOR, VALUE, TOTYPE>                                      \
{                                                                               \
    typedef ENUMERATOR ENUM_TYPE;                                               \
    typedef TOTYPE TO_TYPE;                                                     \
    static TOTYPE ToValue()      {return TOVALUE;}                              \
    static ENUMERATOR  ToEnum()  {return VALUE; }                               \
};


// A Macro is used to bind enumerator to string
//
#define BINDING_ENUM_TO_WSTRING(ENUMERATOR, VALUE, TO)                                \
    BINDING_ENUM_TO_VALUE(ENUMERATOR, VALUE, SolidMCP::BedRock::WideString, TO)

#define BINDING_ENUM_TO_NSTRING(ENUMERATOR, VALUE, TOVALUE)                           \
    BINDING_ENUM_TO_VALUE(ENUMERATOR, VALUE, SolidMCP::BedRock::NarrowString, TOVALUE)

#define BINDING_ENUM_TO_BOTH_STRINGS(ENUMERATOR, VALUE, TOVALUE)                                            \
    BINDING_ENUM_TO_VALUE(ENUMERATOR, VALUE, SolidMCP::BedRock::WideString, _SMCP_FORCE_WSTRING_(TOVALUE))  \
    BINDING_ENUM_TO_VALUE(ENUMERATOR, VALUE, SolidMCP::BedRock::NarrowString, _SMCP_FORCE_NSTRING_(TOVALUE))


namespace SolidMCP { namespace BedRock {

typedef Int32 ENUM_TYPE_INTEGER;
template<SMCP_TEMPLATE_CONSTANTELEMENT_PARAMS_DEFAULT(SMCP_MAX_TUPLE_PARAMS, BadContantValue::Value)>
struct EnumTuple : /*public */ConstantTuple<ENUM_TYPE_INTEGER, SMCP_TEMPLATE_SPECIALIZED_CONSTANTELEMENT_PARAMS(SMCP_MAX_TUPLE_PARAMS)>
{
};

template<typename ENUMERATOR, typename TOTYPE>
struct EnumBinding
{
    template<ENUMERATOR enum_type>
    static TOTYPE ToValue()
    {
        typedef EnumBind<ENUMERATOR, enum_type, TOTYPE> EnumBinderT;
        return EnumBinderT::ToValue();
    }

    // Maybe I need to add a comparator here for extensible comparison.
    //
    template<ENUMERATOR enum_type>
    static bool Equals(const TOTYPE& TOVALUE )
    {
        typedef EnumBind<ENUMERATOR, enum_type, TOTYPE> EnumBinderT;
        return EnumBinderT::ToValue() == TOVALUE;
    }
};

template<typename ENUM_TYPE, typename TOTYPE, typename TL>
class EnumBinder
{
    enum { Head = TL::Head,};
    typedef typename TL::Tail Tail;

public:
    static TOTYPE ToValue(const ENUM_TYPE& from)
    {
        if(Head == from)
        {
            return EnumBinding<ENUM_TYPE, TOTYPE>::ToValue<(ENUM_TYPE)Head>();
        }
        else
        {
            return(TOTYPE) EnumBinder<ENUM_TYPE, TOTYPE, Tail>::ToValue(from);
        }
    }

    static ENUM_TYPE ToEnum(const TOTYPE& to)
    {
        if(EnumBinding<ENUM_TYPE, TOTYPE>::Equals<(ENUM_TYPE)Head>(to))
        {
            return (ENUM_TYPE)Head;
        }
        else
        {
            return EnumBinder<ENUM_TYPE, TOTYPE, Tail>::ToEnum(to);
        }
    }

    static bool Equals(const ENUM_TYPE& from, const TOTYPE& to)
    {
        SMCP_TRY_BEGIN()
            return from == ToEnum(to) ? true : false;
        SMCP_TRY_CATCH()
            return false;
        SMCP_TRY_END()
    }
};

template<typename ENUM_TYPE, typename TOTYPE >
class EnumBinder<ENUM_TYPE, TOTYPE, ConstantTuple<ENUM_TYPE_INTEGER> >
{
public:
    static TOTYPE ToValue(const ENUM_TYPE& from)
    {
        SMCP_THROW(BedRock::InvalidTypeException, L"No Mapping found");
    }
    static ENUM_TYPE ToEnum(const TOTYPE& to)
    {
        SMCP_THROW(BedRock::InvalidTypeException, L"No Mapping found");
    }
};

}}

#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_BINDENUM_H