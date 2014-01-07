

#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_CONSTANTS_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_CONSTANTS_H
#pragma once

#include "basictypes.h"

// Size of byte units
// KiloByte KB = 1024;
// MegaByte MB = 1048576;
// GigaByte GB = 1073741824;
// TeraByte TB = 1099511627776;
// PetaByte PB = 1125899906842624;
const BedRock::UInt8 Byte = 1;
const BedRock::UInt16 KB = 1024;
const BedRock::UInt32 MB = KB * KB;
const BedRock::UInt32 GB = KB * KB * KB;
const BedRock::UInt64 TB = KB * KB * KB * KB;
const BedRock::UInt64 PB = KB * KB * KB * KB * KB;

#define MbToBytes(n) (n * 1024) * 1024
#define KbToBytes(n) (n * 1024)


enum BinarySizeUnits
{
    /// Auto-choose a unit such that the result is in the range [0, 1000 or 1024)
    kDefaultBinaryUnits = -1,

    // The first real unit must be 0 for the current implementation!
    kUnitByte,      //  B  1 byte
    kUnitKiloByte,  //  KB 1024/1000 bytes.
    kUnitMegaByte,  //  MB 2^20/10^06 bytes.
    kUnitGigaByte,  //  GB 2^30/10^09 bytes.
    kUnitTeraByte,  //  TB 2^40/10^12 bytes.
    kUnitPetaByte,  //  PB 2^50/10^15 bytes.
    kUnitLastUnit = UnitYottaByte
};

template<typename BinarySizeUnits = UnitLastUnit>
struct BinaryByteUnit;

template<typename BinarySizeUnits = UnitLastUnit>
struct BinaryByteUnit
{
    typedef BedRock::UInt8 Type;
    static const Type Length;
};

#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_CONSTANTS_H
