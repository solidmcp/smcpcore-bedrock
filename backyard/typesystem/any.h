//An Improved Variant Type Based on Member Templates
///http://www.ddj.com/showArticle.jhtml?documentID=cuj0010cacciola&pgno=2
// Boost::Any
// OgreAny.h

#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_ANY_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_ANY_H

#pragma once
#include "../Config.h"
#include "../Memory/Smart_Ptr.h"
#include "../TypeSystem/Type_Casts.h"


namespace SolidMCP { namespace BedRock {

namespace Private
{
    class DataHolder
    {
    public:
        virtual ~DataHolder(){}
    };

    template<typename T>
    class TDataHolder : public DataHolder
    {
    public:
        TDataHolder(const T& data) : m_Data(data){}

    public:
        T  m_Data;
    };
}

class Any
{
public:

    template<typename T>
    Any(const T& data)
    {
        m_pDataHolder = Smart_Ptr<Private::DataHolder>(new Private::TDataHolder<T>(data));
    }

    Any(const Any& right)
    {
        *this = right;
    };

    Any& operator = (const Any& right)
    {
        m_pDataHolder = right.m_pDataHolder;
        return *this;
    };

    //template<typename T>
    //const T& operator()()
    //{
    //    return Any::QueryData(m_pDataHolder)->m_Data;
    //}

    template<typename T>
    const T& GetTarget() const
    {
        return Any::QueryData<T>(m_pDataHolder)->m_Data;
    }

    template<typename T>
    T& GetTarget()
    {
        return Any::QueryData<T>(m_pDataHolder)->m_Data;
    }


    template<typename T>
    void SetTarget(const T& data)
    {
        if(!m_pDataHolder.isNull())
            m_pDataHolder.release();

        m_pDataHolder = Smart_Ptr<Private::DataHolder>(new Private::TDataHolder<T>(data));
    };

private:
    Any() {}

    template<typename T>
    static Private::TDataHolder<T>* QueryData(const Smart_Ptr<Private::DataHolder>& rDataHolder)
    {
        return Dynamic_Cast<Private::TDataHolder<T>* >(rDataHolder.get());
    }

private:

    Smart_Ptr<Private::DataHolder>  m_pDataHolder;
};

}}


#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_ANY_H