
// Add #includes of Standard C++/C headers are encouraged to be placed here.
// length of some types on different plateforms are not same, so typedef can be good idea here.
//
#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_LENGTHOF_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_LENGTHOF_H

#include "../Config.h"

namespace SolidMCP { namespace BedRock {

        /// Get the size of specific type in bytes at compile time.
        template<typename T> struct LengthOf { enum{ Value = sizeof(T)};};

        template<> struct LengthOf<BedRock::Int8>   { enum{ Value = 1}; };
        template<> struct LengthOf<BedRock::UInt8>  { enum{ Value = 1}; };

        template<> struct LengthOf<BedRock::Int16>  { enum{ Value = 2}; };
        template<> struct LengthOf<BedRock::UInt16> { enum{ Value = 2}; };

        template<> struct LengthOf<BedRock::Int32>  { enum{ Value = 4}; };
        template<> struct LengthOf<BedRock::UInt32> { enum{ Value = 4}; };

        template<> struct LengthOf<BedRock::Int64>  { enum{ Value = 8}; };
        template<> struct LengthOf<BedRock::UInt64> { enum{ Value = 8}; };

#if(_SMCP_WCHAR_MAX == _SMCP_SHRT_MAX)
        template<> struct LengthOf<BedRock::Utf16Char>  { enum{ Value = 2}; };
#else
        template<> struct LengthOf<BedRock::Utf32Char>  { enum{ Value = 4}; };
#endif

        /// Get the size of specific type in bits at compile time.
        template<typename T> struct BitLenghtOf { enum { Value = 8 * LengthOf<T>::Value}; }; // CHAR_BIT
        ///
        /// Gets the size of an array at run time.
    ///
        /// <example>
        ///     <code>
        ///         static int threeElements[] = { 1, 2, 3 };
        ///         SMCP_ASSERT(ArrayLengthOf(threeElements) == 3);
        ///     </code>
        /// </exmaple>
        template <typename T>
        inline int ArrayLengthOf (T& array)
        {
            return static_cast<int> (sizeof(array) / sizeof(array[0]));
        }

}}

#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_LENGTHOF_H
