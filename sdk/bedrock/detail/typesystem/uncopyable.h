#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_UNCOPYABLE_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_UNCOPYABLE_H

namespace SolidMCP { namespace BedRock {

/// For a Non-copyable class, copy constructor and assign is disabled.
/// See Effective C++ 3rd Edition from Scott Meyers for more details.
class UnCopyable
{
protected:
    UnCopyable(){}
    ~UnCopyable(){}
private:
    UnCopyable(const UnCopyable&){};
    UnCopyable& operator =(const UnCopyable&){}
};

}}

/// You can also use below Macro in some special cases.
/// disallow the copy constructor and operator = functions
/// Example:
/// \code
///    class UnCopyableClass
///    {
///    public:
///        UnCopyableClass(const char* name);
///        ~UnCopyableClass();
///    private:
///        SMCP_DISALLOW_COPY_AND_ASSIGN(UnCopyableClass);
///    };
/// \endcode
#if defined(SMCP_ENABLED_CXX11_DELETE_FUNCTIONS)
#       define SMCP_DISALLOW_COPY_AND_ASSIGN(ClassName)   \
            private:                                       \
            ClassName(const ClassName&) = delete;          \
            ClassName& operator=(const ClassName&) = delete;
#else
#   define SMCP_DISALLOW_COPY_AND_ASSIGN(ClassName)  \
        private:                                     \
        ClassName(const ClassName&);                 \
        void operator = (const ClassName&)
#endif

#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_UNCOPYABLE_H
