//An Improved Variant Type Based on Member Templates
///http://www.ddj.com/showArticle.jhtml?documentID=cuj0010cacciola&pgno=2
// Boost::Any
// OgreAny.h

#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_ANY_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_ANY_H

#pragma once
#include "../config.h"
#include "../memory/smartptr.h"
#include "../typesystem/typecasts.h"


namespace SolidMCP { namespace BedRock {

namespace Backyard
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
        TDataHolder(const T& data) : m_data(data){}

    public:
        T  m_data;
    };
}

class Any
{
public:

    template<typename T>
    Any(const T& data)
    {
        m_pDataHolder = Smart_Ptr<Backyard::DataHolder>(new Backyard::TDataHolder<T>(data));
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
    //    return Any::QueryData(m_pDataHolder)->m_data;
    //}

    template<typename T>
    const T& GetTarget() const
    {
        return Any::QueryData<T>(m_pDataHolder)->m_data;
    }

    template<typename T>
    T& GetTarget()
    {
        return Any::QueryData<T>(m_pDataHolder)->m_data;
    }


    template<typename T>
    void SetTarget(const T& data)
    {
        if(!m_pDataHolder.isNull())
            m_pDataHolder.release();

        m_pDataHolder = Smart_Ptr<Backyard::DataHolder>(new Backyard::TDataHolder<T>(data));
    };

Backyard:
    Any() {}

    template<typename T>
    static Backyard::TDataHolder<T>* QueryData(const Smart_Ptr<Backyard::DataHolder>& rDataHolder)
    {
        return Dynamic_Cast<Backyard::TDataHolder<T>* >(rDataHolder.get());
    }

Backyard:

    Smart_Ptr<Backyard::DataHolder>  m_pDataHolder;
};

}}


#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_ANY_H