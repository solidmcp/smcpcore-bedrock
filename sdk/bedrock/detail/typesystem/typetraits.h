#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPETRAITS_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPETRAITS_H

#include "Type_Selector.h"
#include "../Text/String.h"
#include "../Status/Static_Assert.h"

// S:\Neutron\3P\OGS\2.7.0.337722\WIN\SDK\Include\Protein\internal\fbxfilesdk\components\Base\Root\awSTL\awtypetraits.h


//#if(defined(__GLIBCXX__) && (__GLIBCXX__ >= 20070724) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || (defined(_MSC_VER) && (_MSC_VER >= 1600))
//#include <type_traits>
//#endif


namespace SolidMCP { namespace BedRock {

template<typename T>
struct Type_Traits
{
    typedef T&    Reference;
    typedef T*    Pointer;
    typedef T    Type;
};


// An Tr1 way to set Integral Constant..
//
template<typename T, T v>
struct Integral_Constant
{
    static const T Value = v;
    typedef T Value_Type;
    typedef Integral_Constant<T, v> Type;
};

template <typename T, T v> const T Integral_Constant<T, v>::Value;


// Boolean
//
typedef Integral_Constant<bool, true>  True_Type;
typedef Integral_Constant<bool, false> False_Type;


// Check if they are same types
//
template<typename T, typename U> struct Equal_Types            : False_Type { };
template<typename T>             struct Equal_Types<T, T>    : True_Type  { };



// Check they are equivalent types
//
template< typename T1, typename T2 >    struct Equivalent_Types                 : False_Type { };
template< typename T >                     struct Equivalent_Types<T, T>            : True_Type  { };
template< typename T >                     struct Equivalent_Types<T&, T>            : True_Type  { };
template< typename T >                     struct Equivalent_Types<T, T&>            : True_Type  { };
template< typename T >                    struct Equivalent_Types<T, const T&>    : True_Type  { };
template< typename T >                     struct Equivalent_Types<const T&, T&>    : True_Type  { };
template< typename T >                     struct Equivalent_Types<T&, const T&>    : True_Type  { };


// Is_Pointer is false except for pointer types.
//
template <typename T> struct Is_Pointer        : False_Type { };
template <typename T> struct Is_Pointer<T*>    : True_Type  { };

template<typename T>struct Is_Const_Pointer               : False_Type{};
template<typename T>struct Is_Const_Pointer<const T*>    : True_Type {};


// Is_Reference is false except for reference types.
//
template<typename T> struct Is_Reference            : False_Type{};
template<typename T> struct Is_Reference<T&>        : True_Type {};
template<typename T> struct Is_Reference<const T&>  : True_Type {};

template<typename T>struct Is_Const_Reference               : False_Type{};
template<typename T>struct Is_Const_Reference<const T &>    : True_Type {};


// Check if it's floating point number
// float, double, long double
//
template <typename T>    struct Is_Floating_Point                    : False_Type { };
template<>                struct Is_Floating_Point<float>                : True_Type  { };
template<>                struct Is_Floating_Point<double>            : True_Type  { };
template<>                struct Is_Floating_Point<long double>        : True_Type  { };


// Is_Integral is false except for the built-in integer types.
//
template <typename T>    struct Is_Integral                          : False_Type{ };
template<>                struct Is_Integral<bool>                    : True_Type { };
template<>                struct Is_Integral<char>                    : True_Type { };
template<>                struct Is_Integral<unsigned char>            : True_Type { };
template<>                struct Is_Integral<signed char>                : True_Type { };

#if defined(SMCP_COMPILER_MSVC)

// wchar_t is not by default a distinct Type from unsigned short in Microsoft C.
// See http://msdn2.microsoft.com/en-us/library/dh8che7s(VS.80).aspx
//
template<>            struct Is_Integral<__wchar_t>                : True_Type { };
#else
template<>            struct Is_Integral<wchar_t>                  : True_Type { };
#endif
template<>            struct Is_Integral<short>                      : True_Type { };
template<>            struct Is_Integral<unsigned short>          : True_Type { };
template<>            struct Is_Integral<int>                      : True_Type { };
template<>            struct Is_Integral<unsigned int>              : True_Type { };
template<>            struct Is_Integral<long>                     : True_Type { };
template<>            struct Is_Integral<unsigned long>             : True_Type { };
template<>            struct Is_Integral<long long>                  : True_Type { };
template<>            struct Is_Integral<unsigned long long>      : True_Type { };


/// Check if it's Arithmetic: Integral or Float Point
//
template<typename T>
struct Is_Arithmetic
    : Integral_Constant
    <
    bool,
    (Is_Integral<T>::Value || Is_Floating_Point<T>::Value)
    >
{ };

template<typename T>
inline bool ArithmeticEqual(T t1, T t2, T tolerance = std::numeric_limits<T>::epsilon())
{
    // Only Arithmetic is allowed.
    SMCP_STATIC_ASSERT(Is_Arithmetic<T>::Value);
    return (fabs(t1 - t2) <= tolerance) ? true : false;
}



// ACSII Type
//




// Remove/Add Pointer and Reference and change back to Type
//
template<typename T> struct Remove_Reference                    { typedef T Type; };
template<typename T> struct Remove_Reference<T&>                { typedef T Type; };

template<typename T> struct Add_Reference                        { typedef T& Type; };
template<typename T> struct Add_Reference<T&>                    { typedef T& Type; };

template<typename T> struct Remove_Pointer                        { typedef T Type; };
template<typename T> struct Remove_Pointer<T*>                    { typedef T Type; };
template<typename T> struct Remove_Pointer<T* const>            { typedef T Type; };
template<typename T> struct Remove_Pointer<T* volatile>            { typedef T Type; };
template<typename T> struct Remove_Pointer<T* const volatile>    { typedef T Type; };

template<typename T>
struct Add_Pointer
{
    typedef typename Remove_Reference<T>::Type Non_Ref_Type;
    typedef Non_Ref_Type* type;
};



// Remove Const / Volate ...
//
template<typename T> struct Remove_Const                        { typedef T Type; };
template<typename T> struct Remove_Const<T const>                { typedef T Type; };

template<typename T> struct Add_Const                            { typedef T const Type; };
template<typename T> struct Add_Const<T const>                    { typedef T const Type; };

template<typename T> struct Remove_Volatile                        { typedef T Type; };
template<typename T> struct Remove_Volatile<T volatile>            { typedef T Type; };

template<typename T> struct Add_Volatile                        { typedef T volatile Type; };
template<typename T> struct Add_Volatile<T volatile>            { typedef T volatile Type; };

template<typename T> struct Remove_Const_Volatile                { typedef typename Remove_Const<typename Remove_Volatile<T>::Type>::Type Type; };
template<typename T> struct Add_Const_Volatile                    { typedef typename Add_Const<typename Add_Volatile<T>::Type>::Type Type;};


// Some other are in tr1:

template<typename T> struct Is_Const                        : False_Type{ };
template<typename T> struct Is_Const<T * const>             : False_Type{ };
template<typename T> struct Is_Const<T * const&>            : False_Type{ };
template<typename T> struct Is_Const<T * const *&>            : False_Type{ };
template<typename T> struct Is_Const<T const>               : True_Type { };
template<typename T> struct Is_Const<T const&>              : True_Type { };
template<typename T> struct Is_Const<T const*>              : True_Type { };
template<typename T> struct Is_Const<T const * const>       : True_Type { };
template<typename T> struct Is_Const<T const * const&>      : True_Type { };
template<typename T> struct Is_Const<T const *&>            : True_Type { };
template<typename T> struct Is_Const<T const * const *&>    : True_Type { };


template<typename T>struct Is_Void  : False_Type { };
template<>struct Is_Void<void>      : True_Type { };

//
//template<typename T>struct is_ref_to_const
//{
//    enum {value = 0};
//};
//template<typename T>struct is_ref_to_const<T const&>
//{
//    enum {value = 1};
//};
//
//template<typename T>struct is_ref_to_pointer
//{
//    enum {value = 0};
//};
//
//template<typename T>struct is_ref_to_pointer<T*&>
//{
//    enum {value = 1};
//};
//
//template<typename T>struct is_ptr
//{
//    enum {value = 0};
//};
//
//template<typename T>struct is_ptr<T*>
//{
//    enum {value = 1};
//};
//
//template<typename T>struct is_ptr_to_const
//{
//    enum {value = 0};
//};
//
//template<typename T>struct is_ptr_to_const<T const*>
//{
//    enum {value = 1};
//};
//template<typename T>struct is_const_ptr_to
//{
//    enum {value = 0};
//};
//
//template<typename T>struct is_const_ptr_to<T *const>
//{
//    enum {value = 1};
//};
//
//template<typename T>struct is_const_ptr_to_const
//{
//    enum {value = 0};
//};
//
//template<typename T>struct is_const_ptr_to_const<T const * const>
//{
//    enum {value = 1};
//};
//
//template<typename T>struct has_qualifiers
//{
//    enum { value = (
//                   is_ref<T>::value
//           + is_ref_to_const<T>::value
//           + is_ref_to_pointer<T>::value
//           + is_ptr<T>::value
//           + is_ptr_to_const<T>::value
//           + is_const_ptr_to<T>::value
//           + is_const_ptr_to_const<T>::value
//           + is_const<T>::value
//                   ) ? 1 : 0 };
//
//};
//
//template<typename T>struct by_reference
//{
//        enum { value = (
//                is_ref<T>::value
//                + is_ref_to_const<T>::value
//                + is_ref_to_pointer<T>::value
//                + is_ptr<T>::value
//                + is_ptr_to_const<T>::value
//                + is_const_ptr_to<T>::value
//                + is_const_ptr_to_const<T>::value
//                ) ? 1 : 0 };
//
//};

// Character Type
//
template<typename T>    struct Is_Char                  : False_Type{ };
template<>              struct Is_Char<char>            : True_Type { };
template<>              struct Is_Char<signed char>     : True_Type { };
template<>              struct Is_Char<unsigned char>   : True_Type { };

template<typename T>    struct Is_WChar                 : False_Type{ };
template<>              struct Is_WChar<wchar_t>        : True_Type { };


template<typename T>    struct Is_WideString                        : False_Type{ };
template<>              struct Is_WideString<WideString>            : True_Type { };
template<>              struct Is_WideString<const WideChar*>        : True_Type { };
template<>              struct Is_WideString<WideChar*>             : True_Type { };

template<typename T>    struct Is_NarrowString                        : False_Type{ };
template<>              struct Is_NarrowString<NarrowString>        : True_Type { };
template<>              struct Is_NarrowString<const NarrowChar*>   : True_Type { };
template<>              struct Is_NarrowString<NarrowChar*>         : True_Type { };

template<typename T>
struct IsCharTypeBase : TypeSelector<
    Is_Char<T>::Value,
    True_Type,
    typename TypeSelector<Is_WChar<T>::Value, True_Type, False_Type>::Result
>::Result
{
};

template<typename T>
struct IsStringTypeBase : TypeSelector<
    Is_NarrowString<T>::Value,
    True_Type,
    typename TypeSelector<Is_WideString<T>::Value, True_Type, False_Type>::Result
>::Result
{
};

template<typename T> struct IsCharType : IsCharTypeBase<T>{ };
template<typename T> struct IsStringType : IsStringTypeBase<T>{ };

template<typename T> struct IsTextTypeBase : TypeSelector<
    IsCharType<T>::Value,
    True_Type,
    typename TypeSelector<IsStringType<T>::Value,True_Type, False_Type>::Result
>::Result
{
};

template<typename T> struct IsTextType : IsTextTypeBase<T>{ };


template<class T>
struct array_to_pointer_decay
{
    typedef T Type;
};

template<class T, std::size_t N>
struct array_to_pointer_decay<T[N]>
{
    typedef const T * Type;
};

//template<typename T>struct has_qualifiers1
//{
//    enum { value = (
//                   if_or<is_ref<T>::value,
//           if_or<is_ref_to_const<T>::value ,
//           if_or<is_ref_to_pointer<T>::value,
//           if_or<is_ptr<T>::value,
//           if_or<is_ptr_to_const<T>::value,
//           if_or<is_const_ptr_to<T>::value,
//           if_or<is_const_ptr_to_const<T>::value,
//           is_const<T>::value
//                   >::value >::value >::value >::value
//                   >::value >::value >::value
//                   ) ? 1 : 0 };
//
//};
//template<typename T>struct constant_remover
//{
//     typedef T  type;
//};
//template<typename T>struct constant_remover<T const>
//{
//     typedef T  type;
//};
//template<typename T>struct constant_remover<T const&>
//{
//     typedef T&  type;
//};
//template<typename T>struct constant_remover<T const*>
//{
//     typedef T*  type;
//};
//template<typename T>struct constant_remover<T const * const>
//{
//        typedef T* const  type;
//};
//template<typename T>struct constant_remover<T* const>
//{
//        typedef T* const  type;
//};
//
//template<typename T>struct remove_const
//{
//     typedef typename constant_remover<T>::type type;
//};
//
///////////////////////////////////////////////////////////////////////////////////////
//
//
//template<typename T>struct all_constant_remover
//{
//        typedef T  type;
//};
//template<typename T>struct all_constant_remover<T const>
//{
//        typedef T  type;
//};
//template<typename T>struct all_constant_remover<T const&>
//{
//        typedef T&  type;
//};
//template<typename T>struct all_constant_remover<T const*>
//{
//        typedef T*  type;
//};
//
//template<typename T>struct all_constant_remover<T const * const>
//{
//        typedef T*  type;
//};
//template<typename T>struct all_constant_remover<T* const>
//{
//        typedef T*  type;
//};
//
//template<typename T>struct remove_all_const
//{
//        typedef typename all_constant_remover<T>::type type;
//};
//
//
//
//template<typename T>struct remove_ref
//{
//   typedef T type;
//};
//template<typename T>struct remove_ref<T&>
//{
//   typedef T type;
//};
//
//template<typename T>struct ptr_remover
//{
//   typedef T type;
//};
//template<typename T>struct ptr_remover<T*>
//{
//   typedef T type;
//};
//
//
//template<typename T>struct remove_ptr
//{
//     typedef typename ptr_remover<T>::type type;
//};
//
//namespace
//{
//                 template<typename Input,template <typename> class Do,
//                                  template <typename> class Test,int result>
//                  struct do_while;
//
//
//                  template<typename Input,template <typename> class Do,
//                                  template <typename> class Test,int result>
//                  struct do_while
//                  {
//                                 typedef typename do_while<typename Do<Input>::type,
//                                                 Do,Test,
//                                                 Test<typename Do<Input>::type>::value >::type type;
//                  };
//
//                  template<typename Input,template <typename>class Do,
//                                  template <typename> class Test >
//                  struct do_while<Input,Do,Test,0>
//                  {
//                                 typedef Input type;
//          };
//
//}
//
//template<typename T>struct remove_all_ptrs
//{
//                                                /// input,   do,     test,     result
//     typedef typename do_while<T,remove_ptr,is_ptr,is_ptr<T>::value >::type type;
//};



/*    static bool IsNumric() {return false;}
static bool IsAlpha() {return false;}*/

//boost sprint
//http://www.google.com/codesearch/p?hl=en#5jiG3hroW30/trunk/boost.mod/src/boost/spirit/home/support/char_class.hpp&q=template%20ASCII%20lang:c++
//typedef make_tag<tag::alnum>::type alnum_type;
//typedef make_tag<tag::alpha>::type alpha_type;
//typedef make_tag<tag::blank>::type blank_type;
//typedef make_tag<tag::cntrl>::type cntrl_type;
//typedef make_tag<tag::digit>::type digit_type;
//typedef make_tag<tag::graph>::type graph_type;
//typedef make_tag<tag::print>::type print_type;
//typedef make_tag<tag::punct>::type punct_type;
//typedef make_tag<tag::space>::type space_type;
//typedef make_tag<tag::xdigit>::type xdigit_type;



template <int nMasks>
struct MasksTraits
{
    enum { Head = nMasks & ~(nMasks - 1) };
    enum { Tail = nMasks & (nMasks - 1) };
    enum { Count = 1 + MasksTraits<Tail>::Count };
};

template <>
struct MasksTraits<0>
{
    enum { Count = 0 };
};


template <int iBit>
struct IndexToMask_
{
    enum { value = 1 << iBit };
};


// Maybe I have to add a base class Object and let IsInstanceOf(ID) as a method.
//
//bool IsInstanceOf(const char* class_name)const throw()
//{
//    if(strcmp("File", class_name)== 0)
//        return true;
//    else
//        return __super::instanceof(class_name);
//}

template<typename Type, typename InstanceType>
inline bool IsInstanceOf(InstanceType const* instance)
{
    SMCP_ASSERT(0 != instance);
    return (0 != dynamic_cast<Type const*>(instance) );
}

template<typename Type, typename InstanceType>
inline Type const* InstanceOf(InstanceType const* instance)
{
    SMCP_ASSERT(0 != instance);
    return dynamic_cast<Type const*>(instance);
}


// This class is an implementation detail for is_convertible, and you
// don't need to know how it works to use is_convertible. For those
// who care: we declare two different functions, one whose argument is
// of type To and one with a variadic argument list. We give them
// return types of different size, so we can use sizeof to trick the
// compiler into telling us which function it would have chosen if we
// had called it with an argument of type From.  See Alexandrescu's
// _Modern C++ Design_ for more details on this sort of trick.
namespace Private
{
    // We give them return types of different size, so we can use sizeof to trick the
    // compiler into telling us which function it would have chosen if we had called it with an argument of type From.
    // See Alexandrescu's Modern C++ Design for more details on this sort of trick
    // Types Small_Type and Big_Type are guaranteed such that sizeof(small_) <
    // sizeof(big_)
    typedef char Small_Type;

    struct Big_Type
    {
        char dummy[2];
    };


    template <typename From, typename To>
    struct Convert_Helper
    {
        static Small_Type Test(To);
        static Big_Type   Test(...);
        static From MakeT();
    };

    template <typename From, typename To>
    struct _Is_Convertible
    {
        enum{ Value = sizeof(Private::Small_Type) ==
            sizeof(Private::Convert_Helper<From, To>::Test(Private::Convert_Helper<From, To>::MakeT()))};
    };
}

template <typename From, typename To>
struct Is_Convertible : Integral_Constant<bool, Private::_Is_Convertible<From, To>::Value >
{
};


namespace Private
{
    // These two functions should never be used. They are helpers to
    // the is_class template below. They cannot be located inside
    // is_class because doing so causes at least GCC to think that
    // the value of the "value" enumerator is not constant. Placing
    // them out here (for some strange reason) allows the sizeof
    // operator against them to magically be constant. This is
    // important to make the is_class<T>::value idiom zero cost. it
    // evaluates to a constant 1 or 0 depending on whether the
    // parameter T is a class or not (respectively).
    template<typename T> char is_class_helper(void(T::*)());
    template<typename T> double is_class_helper(...);
}

template <typename T>
struct Is_Class
{
    // is_class<> metafunction due to Paul Mensonides (leavings@attbi.com). For
    // more details:
    // http://groups.google.com/groups?hl=en&selm=000001c1cc83%24e154d5e0%247772e50c%40c161550a&rnum=1
public:
    enum { Value = sizeof(char) == sizeof(Private::is_class_helper<T>(0)) };
};



namespace Private
{
    template<typename Base> char base_of_helper(const volatile Base*);
    template<typename Base> double base_of_helper(...);
}

/// is_base_of - Metafunction to determine whether one type is a base class of
/// (or identical to) another type.
template<typename Base, typename Derived>
struct Is_Base_Of
{
    static const bool Value
        = Is_Class<Base>::Value && Is_Class<Derived>::Value &&
        sizeof(char) == sizeof(Private::base_of_helper<Base>((Derived*)0));
};


//        // Implementation construct - do not use
//        template<typename B, typename D>
//        class TIsBaseOf
//        {
//        private:
//            typedef TUint8 TIsDerived;
//
//            class TIsNotDerived
//            {
//                TUint8 iPadding[2];
//            };
//
//
//            static TIsDerived ReturnType(B*);
//            static TIsNotDerived ReturnType(...);
//
//        public:
//
//            enum
//            {
//                EValue = sizeof(ReturnType(static_cast<D*>(0))) == sizeof(TIsDerived) ? 1 : 0
//            };
//        };
//
//
//#define IS_BASE_OF(BaseType, DerivedType) TIsBaseOf<BaseType, DerivedType>::EValue


//#ifdef BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
//        template <class T, class U>
//        struct is_derived_impl
//        {
//            static T x;
//            template <class X>
//            static X* to_pointer(X const&);
//
//            static char test(U const*);
//            typedef char (&no)[2];
//            static no test(...);
//
//            BOOST_STATIC_CONSTANT(bool, value = sizeof(test(to_pointer(x))) == 1);
//        };
//
//        template <class T, class U>
//        struct is_derived
//            : mpl::bool_<is_derived_impl<T,U>::value>
//        {};
//# else
//        template <class T, class U>
//        struct is_derived
//            : is_convertible<
//            typename remove_reference<T>::type*
//            , U const*
//            >
//        {};
//# endif


///** Tests whether the value is derived from the given class.
//* A base class is needed since dynamic_cast checks for an existing traversal
//* from \c derived to \c base.
//* @ingroup grp_constraint
//* @see mockpp::isA
//*/
//template <typename BASE,
//    typename DERIVED>
//class IsInstanceOf : public Constraint<BASE*>
//{
//    typedef BASE*  pBASE;

//public:

//    /** Evaluates the constraint
//    * @param obj the object against which the constraint is evaluated.
//    * @return true:  obj meets the constraint,
//    * @return false if it does not.
//    */
//    virtual bool eval( const pBASE &obj ) const
//    {
//        return dynamic_cast<const DERIVED*>(obj) != 0;
//    }

//    /** Appends the description of this object to the buffer.
//    * @param buffer The buffer that the description is appended to.
//    * @return The current content of the buffer data
//    */
//    virtual String describeTo( String &buffer ) const
//    {
//        buffer += MOCKPP_PCHAR("derived from ")
//            + MOCKPP_GET_STRING(typeid(DERIVED).name());
//        return buffer;
//    }



//    #define AL_DECLARE_CLASS(name, parent)                  \
//public:                                             \
//    static const alkes::ClassID classID() {         \
//        static int class_id = 0;                    \
//        return &class_id;                           \
//    }                                               \
//    static const char* className() {                \
//        const static char* my_name = #name;         \
//        return my_name;                             \
//    }                                               \
//    virtual const char* getClassName() const {      \
//        return className();                         \
//    }                                               \
//    virtual const alkes::ClassID getClassID() const {\
//        return classID();                           \
//    }                                               \
//    virtual bool isInstanceOf(const alkes::ClassID classid) const{\
//        return classid == classID()                 \
//               ? true                               \
//               : parent::isInstanceOf(classid);     \
//    }

/// PointerLikeTypeTraits - This is a traits object that is used to handle
/// pointer types and things that are just wrappers for pointers as a uniform
/// entity.
template <typename T>
class PointerLikeTypeTraits {
    // getAsVoidPointer
    // getFromVoidPointer
    // getNumLowBitsAvailable
};

// Provide PointerLikeTypeTraits for non-cvr pointers.
template<typename T>
class PointerLikeTypeTraits<T*> {
public:
    static inline void *getAsVoidPointer(T* P) { return P; }
    static inline T *getFromVoidPointer(void *P) {
        return static_cast<T*>(P);
    }

    /// Note, we assume here that malloc returns objects at least 4-byte aligned.
    /// However, this may be wrong, or pointers may be from something other than
    /// malloc.  In this case, you should specialize this template to reduce this.
    ///
    /// All clients should use assertions to do a run-time check to ensure that
    /// this is actually true.
    enum { NumLowBitsAvailable = 2 };
};

// Provide PointerLikeTypeTraits for const pointers.
template<typename T>
class PointerLikeTypeTraits<const T*> {
    typedef PointerLikeTypeTraits<T*> NonConst;

public:
    static inline const void *getAsVoidPointer(const T* P) {
        return NonConst::getAsVoidPointer(const_cast<T*>(P));
    }
    static inline const T *getFromVoidPointer(const void *P) {
        return NonConst::getFromVoidPointer(const_cast<void*>(P));
    }
    enum { NumLowBitsAvailable = NonConst::NumLowBitsAvailable };
};

// Provide PointerLikeTypeTraits for uintptr_t.
template<>
class PointerLikeTypeTraits<uintptr_t> {
public:
    static inline void *getAsVoidPointer(uintptr_t P) {
        return reinterpret_cast<void*>(P);
    }
    static inline uintptr_t getFromVoidPointer(void *P) {
        return reinterpret_cast<uintptr_t>(P);
    }
    // No bits are available!
    enum { NumLowBitsAvailable = 0 };
};




}}


#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPETRAITS_H