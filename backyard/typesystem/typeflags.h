

#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_SAFEENUM_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_SAFEENUM_H

#include "../Config.h"
#include "../Memory/Smart_Ptr.h"
#include "../TypeSystem/Type_Casts.h"


namespace SolidMCP { namespace BedRock {

/// Safe Enum is used to improve type safe of native enum data type in C++:
///   Implicit conversion to an integer
///   Inability to specify the underlying type
///   Scoping issues
/// Note that strongly-typed enum support in C++0x will eliminate the need of this idiom.
/// <example>
/// The following code:
/// <code>
///   struct color_def
///    {
///        enum Type { red, green, blue };
///    };
///    typedef Safe_Enum<color_def> color;
///
///    struct shape_def
///    {
///        enum Type { circle, square, triangle };
///    };
///    typedef Safe_Enum<shape_def, unsigned char> shape; // unsigned char representation
///
///    int Test(void)
///    {
///        color c = color::red;
///        bool flag = (c >= shape::triangle); // Compiler error.
///    }
/// </code>
/// Copied from More C++ Idiom
/// </example>
///
/// \tparam DEF_TYPE The defined type of this enum.
/// \tparam INNER_TYPE The type of this enum.
template<typename DEF_TYPE, typename INNER_TYPE>
class Safe_Enum : public DEF_TYPE
{
    typedef typename DEF_TYPE::Type Type;
    INNER_TYPE val;

public:

    Safe_Enum(Type v) : val(v) {}
    INNER_TYPE Underlying() const { return val; }

    bool operator == (const Safe_Enum & s) const { return this->val == s.val; }
    bool operator != (const Safe_Enum & s) const { return this->val != s.val; }
    bool operator <  (const Safe_Enum & s) const { return this->val <  s.val; }
    bool operator <= (const Safe_Enum & s) const { return this->val <= s.val; }
    bool operator >  (const Safe_Enum & s) const { return this->val >  s.val; }
    bool operator >= (const Safe_Enum & s) const { return this->val >= s.val; }
};


/// Type Mask wrapper
/// \code
/// enum my_flag_type
/// {
///    mf_one   = 1 << 0,
///    mf_two   = 1 << 1,
///    mf_three = 1 << 2
/// };
///
/// SMCP_DECLARE_FLAGS(my_flag_type)
///
/// struct AO
/// {
///    my_flags_type flags;
/// };
/// \endcode
/// \tparam DEF_TYPE The defined type of this enum
/// \tparam INNER_TYPE The type of this enum
template <typename EnumT>
class TypedFlags
{
public:
    typedef EnumT Enum_Type;
    typedef BedRock::UInt32 Storage_Type;

    TypedFlags(EnumT e) : m_value(e) { }
    explicit TypedFlags( Storage_Type s) : m_value(s) { }
    explicit TypedFlags( const Storage_Type& s) : m_value(s.m_value) { }


    TypedFlags & operator = (EnumT e) { m_value = e; return *this; }
    TypedFlags & operator = ( const TypedFlags& f) { m_value = f.m_value; return *this; }

    TypedFlags & operator &= (EnumT e) { m_value &= e; return *this; }

    TypedFlags & operator |= (EnumT e) { m_value |= e; return *this; }
    TypedFlags & operator |= ( TypedFlags s) { m_value |= s; return *this; }

    TypedFlags & operator ^= (EnumT e) { m_value ^= e; return *this; }
    TypedFlags & operator ^= ( TypedFlags s) { m_value ^= s; return *this; }



    TypedFlags operator & (EnumT e) const { return TypedFlags(m_value & e); }

    TypedFlags operator | (EnumT e) const { return TypedFlags(m_value | e); }
    TypedFlags operator | ( TypedFlags s) const { return TypedFlags(m_value | s); }

    TypedFlags operator ^ (EnumT e) const { return TypedFlags(m_value ^ e); }
    TypedFlags operator ^ ( TypedFlags s) const { return TypedFlags(m_value ^ s); }

   // operator EnumT const& () const { return  m_value; }
    inline operator BedRock::UInt32() const { return m_value; }

    void change(bool isSet, Enum_Type e)
    {
        if(isSet)
            m_value |= e;
        else
            m_value &= ~e;

    }

    bool contains(EnumT e) const { return (m_value & e) != 0;}
    bool contains(Storage_Type s) const { return (m_value & e) != 0;}

private:

    Storage_Type m_value;

};


}}

#define SMCP_DECLARE_FLAGS(Flags, EnumT)\
    typedef SolidMCP::BedRock::TypedFlags<EnumT> Flags;

#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_SAFEENUM_H