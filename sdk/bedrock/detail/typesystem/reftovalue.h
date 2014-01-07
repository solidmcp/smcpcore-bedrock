#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_REFTOVALUE_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_REFTOVALUE_H

namespace SolidMCP { namespace BedRock {

///  Transports a reference as a value
///  Serves to implement the Colvin/Gibbons trick for SmartPtr/ScopeGuard.
/// Copied from LOKI library.
template <class T>
class RefToValue
{
public:

    RefToValue(T& ref)
        : m_ref(ref)
    {
        //...
    }

    RefToValue(const RefToValue& rhs) : m_ref(rhs.m_ref)
    {
        // ...
    }

    operator T& () const
    {
        return m_ref;
    }

private:
    // Disable - not implemented
    RefToValue();
    RefToValue& operator=(const RefToValue&);

    T& m_ref;
};


///  RefToValue creator.
template <class T>
inline RefToValue<T> ByRef(T& t)
{
    return RefToValue<T>(t);
}

}}



#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_REFTOVALUE_H
