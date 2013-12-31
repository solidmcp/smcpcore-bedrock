
#ifndef GUARD_SMCPCORE_BEDROCK_CONFIG_DISABLEWARNINGS_H
#define GUARD_SMCPCORE_BEDROCK_CONFIG_DISABLEWARNINGS_H


// Avoid "unused parameter" warnings
//
#if !defined(SMCP_COMPILER_MSVC)
   template <typename T> inline void SMCP_REF_PARAMETER_(T& p) { (void)p; }
#  define SMCP_UNREF_PARAMETER(p) SMCP_REF_PARAMETER_(x);
#else
#  define SMCP_UNREF_PARAMETER(p) (void)p;
#endif


// Disable Warnings in Microsoft Visual Studio with #pragma
//
#if defined(SMCP_COMPILER_MSVC)

// Turn off warnings generated by long std templates
// This warns about truncation to 255 characters in debug/browse info
#   pragma warning (disable : 4786)
#   pragma warning (disable : 4503)

// disable: "conversion from 'double' to 'float', possible loss of data
#   pragma warning (disable : 4244)
#   pragma warning (disable : 4305)

// Disable warnings about conversion from size_t to unsigned long and long.
#   pragma warning (disable : 4267)

// disable: "<type> needs to have dll-interface to be used by clients'
// Happens on STL member variables which are not public therefore is ok
#   pragma warning (disable : 4251)

// disable: "non dll-interface class used as base for dll-interface class"
#   pragma warning (disable : 4275)

// _OLD_IOSTREAMS_ARE_DEPRECATED
#   pragma warning ( disable: 4995)

// disable: deprecation warnings when using CRT calls in VC8
#   pragma warning ( disable: 4996)

// Disable: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
#   pragma warning ( disable: 4290)

//Disable:  Returning address of local variable or temporary
#   pragma warning ( disable: 4172)

// Disable: 'specialization' : truncation of constant value
#   pragma warning ( disable: 4309)

// copy ctor couldn't be generated
#   pragma warning ( disable: 4511)

// 'class' : assignment operator could not be generated
#   pragma warning ( disable: 4512 )

// unreferenced inline/local function has been removed
#   pragma warning ( disable: 4514)

// 'type' : forcing value to bool 'true' or 'false' (performance warning)
#   pragma warning ( disable: 4800)

// typedef-name 'identifier1' used as synonym for class-name 'identifier2'
#   pragma warning ( disable: 4097)

// assignment within conditional expression
#   pragma warning ( disable: 4706)

// template-class specialization 'identifier' is already instantiated
#   pragma warning ( disable: 4660)

// 'this' : used in base member initializer list
#   pragma warning ( disable: 4355)

// nonstandard extension used : 'extern' before template explicit instantiation
#   pragma warning ( disable: 4231)

// function not inlin-ed
#   pragma warning ( disable: 4710)

// C++ exception handler used, but unwind semantics are not enabled. Specify -GX
#   pragma warning ( disable: 4530)

// return type for 'type1::operator ->' is 'type2 *'
#   pragma warning ( disable: 4284)

// 'class' : default constructor could not be generated
#   pragma warning ( disable: 4510)

// nonstandard extension used: nameless struct/union
#   pragma warning ( disable: 4201)


// Add any new disabled warnings here
// so that we can know what's happened in compilation message.
#   pragma message("Pre-disabled Warnings: 4786, 4503, 4244, 4305, 4267, 4251, 4275, 4995, 4996, 4290, 4172, 4309, 4511")
#   pragma message("Pre-disabled Warnings: 4512, 4514, 4800, 4097, 4706, 4660, 4355, 4231, 4710, 4530, 4284, 4510, 4201")

#endif


#endif // GUARD_SMCPCORE_BEDROCK_CONFIG_DISABLEWARNINGS_H