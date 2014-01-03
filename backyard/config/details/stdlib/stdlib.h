

#ifndef GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_STDLIB_STDLIB_H
#define GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_STDLIB_STDLIB_H
#pragma once

#include "stdincludes.h"

// After changing the implementation to the next one, there is a build error in StringBuilder
// I have to disable a couple of Append methods. so, let's disable following override for now.

// snprintf / swnprintf
//

 //CodeBlocks
#ifndef snprintf
#    ifdef SMCP_COMPILER_MSVC
#        ifndef _snprintf
#            define snprintf _snprintf
#        else
#            error ("snprintf is not defined. Please include <stdio.h> or <cstdio>")
#        endif
#    else
#        error ("snprintf is not defined.")
#    endif
#endif

#ifndef snwprintf
#    ifdef SMCP_COMPILER_MSVC
#        ifndef _snwprintf
#            define snwprintf _snwprintf
#        else
#            error ("snprintf is not defined. Please include <stdio.h> or <cstdio>")
#        endif
#    else
#        error ("snwprintf is not defined.")
#    endif
#endif


//#if defined(SMCP_PLATFORM_WINDOWS)
//#   define vsnprintf _vsnprintf
//#   define vsnwprintf _vsnwprintf
//#   if SMCP_COMPILER_MSVC >= 1400 //vc8.0
//#       define snwprintf _snwprintf_s
//#       define snprintf _snprintf_s
//#   else
//#       define snprintf _snprintf
//#       define snwprintf _snwprintf
//#   endif
//#else
//#   define vsnwprintf vswprintf
//#   define snwprintf swprintf
//#endif



#if defined(SMCP_COMPILER_MSVC)
#   define wcsicmp _wcsicmp
#   define stricmp _stricmp
#endif

//#define BASE_BINARY BASE_BINARY  =  2,
//BASE_OCTAL   =  8,
//BASE_DECIMAL = 10,
//BASE_HEX     = 16,


//#ifndef csicmp
//#    ifdef SMCP_COMPILER_MSVC
//#        ifndef _snprintf
//#            define strcmp _tcsicmp
//#        else
//#            error ("snprintf is not defined. Please include <stdio.h> or <cstdio>")
//#        endif
//#    else
//#        error ("snprintf is not defined.")
//#    endif
//#endif
//
//#ifndef snwprintf
//#    ifdef SMCP_COMPILER_MSVC
//#        ifndef _snwprintf
//#            define snwprintf _snwprintf
//#        else
//#            error ("snprintf is not defined. Please include <stdio.h> or <cstdio>")
//#        endif
//#    else
//#        error ("snprintf is not defined.")
//#    endif
//#endif

//BEGIN_NAMESPACE_BEDROCK
//
//using ::snprintf;
//
//END_NAMESPACE_BEDROCK


#endif // GUARD_SMCPCORE_BEDROCK_BACKYARD_CONFIG_DETAILS_STDLIB_STDLIB_H
