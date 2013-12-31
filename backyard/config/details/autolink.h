#ifndef GUARD_SMCPCORE_BEDROCK_AUTOLINK_H
#define GUARD_SMCPCORE_BEDROCK_AUTOLINK_H
#pragma once

#if defined(SMCP_LIB_NAME)
#    define SMCP_LIB_FULL_NAME SMCP_STRINGIZE(SMCP_LIB_NAME) ".lib"
#    pragma comment(lib, SMCP_LIB_FULL_NAME)
#    ifdef SMCP_LIB_DIAGNOSTIC
#        pragma message ("Linking to lib file: " SMCP_LIB_FULL_NAME )
#        ifdef SMCP_LIB_DECRIPTION
#            pragma message("Lib Description: " SMCP_LIB_DECRIPTION)
#        else
#            pragma message("Lib Description: No")
#        endif
#    endif
#else
//#    error "Some Macros are needed."
#    pragma message("Some Macros are needed.")
#endif

#if defined(SMCP_LIB_NAME)
#    undef SMCP_LIB_NAME
#endif

#if defined(SMCP_LIB_FULL_NAME)
#    undef SMCP_LIB_FULL_NAME
#endif

#if defined(SMCP_LIB_DIAGNOSTIC)
#    undef SMCP_LIB_DIAGNOSTIC
#endif

#if defined(SMCP_LIB_DESCRIPTION)
#    undef SMCP_LIB_DESCRIPTION
#endif


#endif // GUARD_SMCPCORE_BEDROCK_AUTOLINK_H

