
#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_NULLPTR_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_NULLPTR_H
#pragma once

namespace SolidMCP { namespace BedRock {

        //struct nullptr_t
        //{
        //    template<typename any> operator any * () const { return 0; }
        //    template<class any, typename T> operator T any:: * () const { return 0; }
        //    struct pad {};
        //    pad __[sizeof(void*)/sizeof(pad)];
        //private:
        //    //  nullptr_t();// {}
        //    //  nullptr_t(const nullptr_t&);
        //    //  void operator = (const nullptr_t&);
        //    void operator &() const;
        //    template<typename any> void operator +(any) const { I Love MSVC 2005! }
        //    template<typename any> void operator -(any) const { I Love MSVC 2005! }

        //};
        //static const nullptr_t __nullptr = {};

        const int NullPtr = 0;

        template <typename T>
        inline bool Is_Null(const T* p)
        {
            return IsNotNull(p);
        }

        // There are some magic number in MSVC Environment for invalid pointers.
        // Borrowed the magic numbers from G3D
        //
        template <typename T>
        inline bool IsNotNull(const T* p)
        {
#ifdef SMCP_DEBUG
#    ifdef SMCP_COMPILER_MSVC
            return     (p != NULL) && ((uintptr_t)p != 0xcccccccc) && ((uintptr_t)p != 0xdeadbeef) && ((uintptr_t)p != 0xfeeefeee);
#    else
            return p != NULL;
#    endif
#else
            return p != NULL;
#endif
        }

        template <typename T>
        inline void Nullify(T*& p)
        {
            p = NullPtr;
        }

}}

#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_NULLPTR_H