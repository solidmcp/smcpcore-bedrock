#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPECAST_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPECAST_H

#include "../Config.h"
#include "../Status/Static_Assert.h"
#include "../Status/Exception.h"
#include "../TypeSystem/Type_Traits.h"


namespace SolidMCP { namespace BedRock {

        // Static Cast:
        // Safe Static Cast is extremely important in Geometric Modeling.
        // espcially the case of mapping data to a much larger space.
        // For example, in Autodesk Inventor DWF, the datas are mapped to 2~31.
        //
        // Do strict numeric check in debug mode.
        //
        template<typename To, typename From>
        To Static_Cast(const From& from)
        {
            // Should skip static_cast if they are same type
            // Using static type check here because partial specialization of method or funcation is disallowed.
            //
            if(Equal_Types<From, To>::Value)
                return from;

#ifdef SMCP_DEBUG

            // Check if it's Sepecified and bounded first.
            //
            bool bToBounded = std::numeric_limits<To>::is_specialized && std::numeric_limits<To>::is_bounded;
            if(bToBounded)
            {
                bool bToSigned   = std::numeric_limits<To>::is_signed;
                bool bFromSigned = std::numeric_limits<From>::is_signed;
                To tolerance = std::numeric_limits<To>::epsilon();

                bool bSafeCast = false;
                if(bFromSigned && bToSigned)
                {
                    // To::Min  < From < To::Max
                    //
                    To min_val = std::numeric_limits<To>::min SMCP_WORKAROUND_NAME_OVERRIDE ();
                    To max_val = std::numeric_limits<To>::max SMCP_WORKAROUND_NAME_OVERRIDE ();
                    bool diff = from >= min_val;

                    bSafeCast = (std::numeric_limits<To>::min SMCP_WORKAROUND_NAME_OVERRIDE () <= (from + tolerance) || (from - tolerance) <= std::numeric_limits<To>::max SMCP_WORKAROUND_NAME_OVERRIDE ());
                    SMCP_ASSERT(bSafeCast);
                }
                else if(bFromSigned && !bToSigned)
                {
                    // 0 < From < To::Max
                    //
                    bSafeCast = 0 <= (from + tolerance) && (from - tolerance) <= std::numeric_limits<To>::max SMCP_WORKAROUND_NAME_OVERRIDE ();
                    SMCP_ASSERT(bSafeCast);

                }
                else // !bToSigned && !bToSigned || !bToSigned && bToSigned
                {
                    // From < To::Max
                    //
                    bSafeCast = (from - tolerance) <= std::numeric_limits<To>::max SMCP_WORKAROUND_NAME_OVERRIDE ();
                    SMCP_ASSERT(bSafeCast);
                }

                if(!bSafeCast)
                    SMCP_THROW(OverflowException, L"Bad Static Cast : Overflowed" );
            }

#endif
            return static_cast<To>(from);
        }


        // Reinterpret_Cast
        //
        template <class To, class From>
        To Reinterpret_Cast(From from)
        {
            SMCP_STATIC_ASSERT(sizeof(From) == sizeof(To));
            return reinterpret_cast<To>(from);
        }


        // Dynamic_Cast
        //
        template<typename To, typename From>
        inline To Dynamic_Cast(From* from)
        {
            SMCP_ASSERT(from != NULL);
            To to = dynamic_cast<To>(from);
            if(to == NULL )
            {
                SMCP_THROW(BadCastException, L"Bad Dynamic Cast" );
            }

            return to;
        }


        // Dynamic Cast
        //
        template<typename To, typename From>
        inline To Dynamic_Cast(From& from)
        {
            SMCP_STATIC_ASSERT(Is_Reference<To>::Value);
            SMCP_ASSERT(from != NULL);

            From tmpFrom = from;

            To* tmpTo = NULL;
            try
            {
                To to = dynamic_cast<To>(from);
                tmpFrom = &to;
            }
            catch(std::bad_cast&)
            {
                // No idea to return NULL as pointer, so bad_cast exception is thrown
            }

            if( tmpFrom == NULL )
                SMCP_THROW(BadCastException, L"Bad Dynamic Cast" );

            return *tmpFrom;
        }



        // Down_Cast
        // Test dynamic_cast on debug build only for optimization.
        //
        template<typename To, typename From>
        inline To Down_Cast(From* from)
        {
            SMCP_ASSERT(from != NULL || Dynamic_Cast<To>(from) != NULL);
            return static_cast<To*>(from);
        }

        // Implicit_Cast
        //
        template<typename To, typename From>
        inline To Implicit_Cast(const From& from)
        {
            return from;
        }


        // Bit_Cast
        //
        template <class To, class From>
        inline To Bit_Cast(const From& from)
        {
            SMCP_STATIC_ASSERT(sizeof(From) == sizeof(To));

            To to;
            ::memcpy(&to, &from, sizeof(to));
            return to;
        }

}}


#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_TYPECAST_H
