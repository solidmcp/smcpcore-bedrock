
#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_DATAHOLDER_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_DATAHOLDER_H
#pragma once

namespace SolidMCP { namespace BedRock {

struct DataHolderBase {};

template< typename T >
struct DataHolderT : DataHolderBase
{
    enum { const_value = 0 };

    typedef T type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* pointer;
    typedef const T* const_pointer;

    typedef T& return_type;
    typedef const T& const_return_type;
    typedef const T& param_type;

    T d;

    DataHolderT() : d() {}
    DataHolderT( param_type d_ ) : d(d_) {}

    void set( param_type d_ ) { d = d_; }
    const_return_type get() const { return d; }
    return_type get() { return d; }
    const_pointer operator&() const { return &d; }
    pointer operator&() { return &d; }
    const_reference operator*() const { return d; }
    reference operator*() { return d; }
};

template< typename T >
struct DataHolderT< const T > : DataHolderBase
{
    enum { const_value = 1 };

    typedef T type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* pointer;
    typedef const T* const_pointer;

    typedef const T& return_type;
    typedef const T& const_return_type;
    typedef const T& param_type;

    const T d;

    DataHolderT() : d() {}
    DataHolderT( param_type d_ ) : d(d_) {}

    const_return_type get() const { return d; }
    const_pointer operator&() const { return &d; }
    const_reference operator*() const { return d; }
};

template< typename T >
struct DataHolderT<T&> : DataHolderBase
{
    enum { const_value = 0 };

    typedef T type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* pointer;
    typedef const T* const_pointer;

    typedef T& return_type;
    typedef const T& const_return_type;
    typedef T& param_type;

    T& d;

    DataHolderT( param_type d_ ) : d(d_) {}

    void set( param_type d_ ) { d = d_; }
    const_return_type get() const { return d; }
    return_type get() { return d; }
    const_pointer operator&() const { return &d; }
    pointer operator&() { return &d; }
    const_reference operator*() const { return d; }
    reference operator*() { return d; }
};

template< typename T >
struct DataHolderT<const T&> : DataHolderBase
{
    enum { const_value = 0 };

    typedef T type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* pointer;
    typedef const T* const_pointer;

    typedef const T& return_type;
    typedef const T& const_return_type;
    typedef const T& param_type;

    const T& d;

    DataHolderT( param_type d_ ) : d(d_) {}

    void set( param_type d_ ) { d = d_; }
    const_return_type get() const { return d; }
    const_pointer operator&() const { return &d; }
    const_reference operator*() const { return d; }
};

template< typename T >
struct DataHolderT<T*> : DataHolderBase
{
    enum { const_value = 0 };

    typedef T type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* pointer;
    typedef const T* const_pointer;

    typedef T* return_type;
    typedef const T* const_return_type;
    typedef T* param_type;

    T* d;

    DataHolderT() : d(0) {}
    DataHolderT( param_type d_ ) : d(d_) {}

    void set( param_type d_ ) { d = d_; }
    const_return_type get() const { return d; }
    return_type get() { return d; }
    const_pointer operator&() const { return d; }
    pointer operator&() { return d; }
    const_reference operator*() const { return *d; }
    reference operator*() { return *d; }
};

template<>
struct DataHolderT<void*> : DataHolderBase
{
    enum { const_value = 0 };

    typedef void type;
    typedef void* pointer;

    typedef void* return_type;
    typedef void* param_type;

    void* d;

    DataHolderT() : d(0) {}
    DataHolderT( param_type d_ ) : d(d_) {}

    void set( param_type d_ ) { d = d_; }
    return_type get() { return d; }
    pointer operator&() { return d; }
};

template< typename T >
struct DataHolderT<const T*> : DataHolderBase
{
    enum { const_value = 0 };

    typedef T type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* pointer;
    typedef const T* const_pointer;

    typedef const T* return_type;
    typedef const T* const_return_type;
    typedef const T* param_type;

    const T* d;

    DataHolderT() : d(0) {}
    DataHolderT( param_type d_ ) : d(d_) {}

    void set( param_type d_ ) { d = d_; }
    const_return_type get() const { return d; }
    const_pointer operator&() const { return d; }
    const_reference operator*() const { return *d; }
};

}}

#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_DATAHOLDER_H
