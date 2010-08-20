/****************************************************************/
/*!
 @abstract   ￼MRTypeManip.h
 @discussion ￼ 
 
 File created by Hiroki Omae on 2010/08/19.
 This file is modified from loki-0.17:TypeManip.h
 
 All namespace and symbol names are modified to
 match MR needs and policies, and avoiding collision to original loki.
 
 based on:
 
 The Loki Library
 Copyright (c) 2001 by Andrei Alexandrescu
 This code accompanies the book:
 Alexandrescu, Andrei. "Modern C++ Design: Generic Programming and Design 
 Patterns Applied". Copyright (c) 2001. Addison-Wesley.
 Permission to use, copy, modify, distribute and sell this software for any 
 purpose is hereby granted without fee, provided that the above copyright 
 notice appear in all copies and that both that copyright notice and this 
 permission notice appear in supporting documentation.
 The author or Addison-Wesley Longman make no representations about the 
 suitability of this software for any purpose. It is provided "as is" 
 without express or implied warranty.
 
 // $Id: TypeManip.h 749 2006-10-17 19:49:26Z syntheticpp $
 */
/****************************************************************/
#ifndef __MAGICREFLECTON__LOKI_TYPEMANIP_INC_
#define __MAGICREFLECTON__LOKI_TYPEMANIP_INC_

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// class template MRInt2Type
// Converts each integral constant into a unique type
// Invocation: MRInt2Type<v> where v is a compile-time constant integral
// Defines 'value', an enum that evaluates to v
////////////////////////////////////////////////////////////////////////////////

template <int v>
struct MRInt2Type
{
    enum { value = v };
};

////////////////////////////////////////////////////////////////////////////////
// class template MRType2Type
// Converts each type into a unique, insipid type
// Invocation MRType2Type<T> where T is a type
// Defines the type OriginalType which maps back to T
////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct MRType2Type
{
    typedef T OriginalType;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRSelectType
// Selects one of two types based upon a boolean constant
// Invocation: MRSelectType<flag, T, U>::Result
// where:
// flag is a compile-time boolean constant
// T and U are types
// Result evaluates to T if flag is true, and to U otherwise.
////////////////////////////////////////////////////////////////////////////////

template <bool flag, typename T, typename U>
struct MRSelectType
{
    typedef T Result;
};
template <typename T, typename U>
struct MRSelectType<false, T, U>
{
    typedef U Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRIsSameType
// Return true iff two given types are the same
// Invocation: SameType<T, U>::value
// where:
// T and U are types
// Result evaluates to true iff U == T (types equal)
////////////////////////////////////////////////////////////////////////////////

template <typename T, typename U>
struct MRIsSameType
{
    enum { value = false };
};

template <typename T>
struct MRIsSameType<T,T>
{
    enum { value = true };
};

////////////////////////////////////////////////////////////////////////////////
// Helper types Small and Big - guarantee that sizeof(Small) < sizeof(Big)
////////////////////////////////////////////////////////////////////////////////

    template <class T, class U>
    struct MRTM_Private_ConversionHelper
 {
    typedef char Small;
    struct Big { char dummy[2]; };
    static Big   Test(...);
    static Small Test(U);
    static T MakeT();
 };

////////////////////////////////////////////////////////////////////////////////
// class template MRConversion
// Figures out the conversion relationships between two types
// Invocations (T and U are types):
// a) MRConversion<T, U>::exists
// returns (at compile time) true if there is an implicit conversion from T
// to U (example: Derived to Base)
// b) MRConversion<T, U>::exists2Way
// returns (at compile time) true if there are both conversions from T
// to U and from U to T (example: int to char and back)
// c) MRConversion<T, U>::sameType
// returns (at compile time) true if T and U represent the same type
//
// Caveat: might not work if T and U are in a private inheritance hierarchy.
////////////////////////////////////////////////////////////////////////////////

template <class T, class U>
struct MRConversion
{
    typedef MRTM_Private_ConversionHelper<T, U> H;
#ifndef __MWERKS__
    enum { exists = sizeof(typename H::Small) == sizeof((H::Test(H::MakeT()))) };
#else
    enum { exists = false };
#endif
    enum { exists2Way = exists && MRConversion<U, T>::exists };
    enum { sameType = false };
};

template <class T>
struct MRConversion<T, T>    
{
    enum { exists = 1, exists2Way = 1, sameType = 1 };
};

template <class T>
struct MRConversion<void, T>    
{
    enum { exists = 0, exists2Way = 0, sameType = 0 };
};

template <class T>
struct MRConversion<T, void>    
{
    enum { exists = 0, exists2Way = 0, sameType = 0 };
};

template <>
struct MRConversion<void, void>    
{
public:
    enum { exists = 1, exists2Way = 1, sameType = 1 };
};

////////////////////////////////////////////////////////////////////////////////
// class template MRSuperSubclass
// Invocation: MRSuperSubclass<B, D>::value where B and D are types. 
// Returns true if B is a public base of D, or if B and D are aliases of the 
// same type.
//
// Caveat: might not work if T and U are in a private inheritance hierarchy.
////////////////////////////////////////////////////////////////////////////////

template <class T, class U>
struct MRSuperSubclass
{
    enum { value = (MR_NS(MRConversion)<const volatile U*, const volatile T*>::exists &&
                    !MR_NS(MRConversion)<const volatile T*, const volatile void*>::sameType) };
    
    // Dummy enum to make sure that both classes are fully defined.
    enum{ dontUseWithIncompleteTypes = ( sizeof (T) == sizeof (U) ) };
};

template <>
struct MRSuperSubclass<void, void> 
{
    enum { value = false };
};

template <class U>
struct MRSuperSubclass<void, U> 
{
    enum { value = (MR_NS(MRConversion)<const volatile U*, const volatile void*>::exists &&
                    !MR_NS(MRConversion)<const volatile void*, const volatile void*>::sameType) };
    
    // Dummy enum to make sure that both classes are fully defined.
    enum{ dontUseWithIncompleteTypes = ( 0 == sizeof (U) ) };
};

template <class T>
struct MRSuperSubclass<T, void> 
{
    enum { value = (MR_NS(MRConversion)<const volatile void*, const volatile T*>::exists &&
                    !MR_NS(MRConversion)<const volatile T*, const volatile void*>::sameType) };
    
    // Dummy enum to make sure that both classes are fully defined.
    enum{ dontUseWithIncompleteTypes = ( sizeof (T) == 0 ) };
};

////////////////////////////////////////////////////////////////////////////////
// class template MRSuperSubclassStrict
// Invocation: MRSuperSubclassStrict<B, D>::value where B and D are types. 
// Returns true if B is a public base of D.
//
// Caveat: might not work if T and U are in a private inheritance hierarchy.
////////////////////////////////////////////////////////////////////////////////

template<class T,class U>
struct MRSuperSubclassStrict
{
    enum { value = (MR_NS(MRConversion)<const volatile U*, const volatile T*>::exists &&
                    !MR_NS(MRConversion)<const volatile T*, const volatile void*>::sameType &&
                    !MR_NS(MRConversion)<const volatile T*, const volatile U*>::sameType) };
    
    // Dummy enum to make sure that both classes are fully defined.
    enum{ dontUseWithIncompleteTypes = ( sizeof (T) == sizeof (U) ) };
};

template<>
struct MRSuperSubclassStrict<void, void> 
{
    enum { value = false };
};

template<class U>
struct MRSuperSubclassStrict<void, U> 
{
    enum { value = (MR_NS(MRConversion)<const volatile U*, const volatile void*>::exists &&
                    !MR_NS(MRConversion)<const volatile void*, const volatile void*>::sameType &&
                    !MR_NS(MRConversion)<const volatile void*, const volatile U*>::sameType) };
    
    // Dummy enum to make sure that both classes are fully defined.
    enum{ dontUseWithIncompleteTypes = ( 0 == sizeof (U) ) };
};

template<class T>
struct MRSuperSubclassStrict<T, void> 
{
    enum { value = (MR_NS(MRConversion)<const volatile void*, const volatile T*>::exists &&
                    !MR_NS(MRConversion)<const volatile T*, const volatile void*>::sameType &&
                    !MR_NS(MRConversion)<const volatile T*, const volatile void*>::sameType) };
    
    // Dummy enum to make sure that both classes are fully defined.
    enum{ dontUseWithIncompleteTypes = ( sizeof (T) == 0 ) };
};


////////////////////////////////////////////////////////////////////////////////
// macro SUPERSUBCLASS
// Invocation: SUPERSUBCLASS(B, D) where B and D are types. 
// Returns true if B is a public base of D, or if B and D are aliases of the 
// same type.
//
// Caveat: might not work if T and U are in a private inheritance hierarchy.
// Deprecated: Use MRSuperSubclass class template instead.
////////////////////////////////////////////////////////////////////////////////

#define LOKI_SUPERSUBCLASS(T, U) \
MR_NS(MRSuperSubclass)<T,U>::value

////////////////////////////////////////////////////////////////////////////////
// macro SUPERSUBCLASS_STRICT
// Invocation: SUPERSUBCLASS(B, D) where B and D are types. 
// Returns true if B is a public base of D.
//
// Caveat: might not work if T and U are in a private inheritance hierarchy.
// Deprecated: Use MRSuperSubclassStrict class template instead.
////////////////////////////////////////////////////////////////////////////////

#define LOKI_SUPERSUBCLASS_STRICT(T, U) \
MR_NS(MRSuperSubclassStrict)<T,U>::value

MAGICREFLECTION_NAMESPACE_END
#endif // __MAGICREFLECTON__LOKI_TYPEMANIP_INC_
       // eof

