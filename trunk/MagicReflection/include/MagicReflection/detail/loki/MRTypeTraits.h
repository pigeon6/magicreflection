/****************************************************************/
/*!
 @abstract   ￼MRTypeTraits.h
 @discussion ￼ 
 
 File created by Hiroki Omae on 2010/08/19.
 This file is modified from loki-0.17:TypeTraits.h
 
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
 
 // $Id: TypeTraits.h 835 2007-08-02 19:39:02Z syntheticpp $
 */
/****************************************************************/
#ifndef __MAGICREFLECTON__LOKI_TYPETRAITS_INC_
#define __MAGICREFLECTON__LOKI_TYPETRAITS_INC_

#if (defined _MSC_VER) && (_MSC_VER < 1400)
#include <string>
#endif


#ifdef _MSC_VER
#pragma warning( push ) 
#pragma warning( disable : 4180 ) //qualifier applied to function type has no meaning; ignored
#endif

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN


//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// class template MRIsCustomUnsignedInt
// Offers a means to integrate nonstandard built-in unsigned integral types
// (such as unsigned __int64 or unsigned long long int) with the MRTypeTraits 
//     class template defined below.
// Invocation: MRIsCustomUnsignedInt<T> where T is any type
// Defines 'value', an enum that is 1 iff T is a custom built-in unsigned
//     integral type
// Specialize this class template for nonstandard unsigned integral types
//     and define value = 1 in those specializations
////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct MRIsCustomUnsignedInt
{
    enum { value = 0 };
};        

////////////////////////////////////////////////////////////////////////////////
// class template MRIsCustomSignedInt
// Offers a means to integrate nonstandard built-in unsigned integral types
// (such as unsigned __int64 or unsigned long long int) with the MRTypeTraits 
//     class template defined below.
// Invocation: MRIsCustomSignedInt<T> where T is any type
// Defines 'value', an enum that is 1 iff T is a custom built-in signed
//     integral type
// Specialize this class template for nonstandard unsigned integral types
//     and define value = 1 in those specializations
////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct MRIsCustomSignedInt
{
    enum { value = 0 };
};        

////////////////////////////////////////////////////////////////////////////////
// class template MRIsCustomFloat
// Offers a means to integrate nonstandard floating point types with the
//     MRTypeTraits class template defined below.
// Invocation: MRIsCustomFloat<T> where T is any type
// Defines 'value', an enum that is 1 iff T is a custom built-in
//     floating point type
// Specialize this class template for nonstandard unsigned integral types
//     and define value = 1 in those specializations
////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct MRIsCustomFloat
{
    enum { value = 0 };
};        

////////////////////////////////////////////////////////////////////////////////
// Helper types for class template MRTypeTraits defined below
////////////////////////////////////////////////////////////////////////////////
typedef MR_TL_4(unsigned char, unsigned short int,unsigned int, unsigned long int) 
MRTT_StdUnsignedInts;
typedef MR_TL_4(signed char, short int,int, long int) 
MRTT_StdSignedInts;
typedef MR_TL_3(bool, char, wchar_t) 
MRTT_StdOtherInts;
typedef MR_TL_3(float, double, long double) 
MRTT_StdFloats;

/****************************************************************/
/*!
 @abstract   MRTT_AddPointer
 @discussion 
 */
//****************************************************************/
template <typename U> struct MRTT_AddPointer
{
    typedef U* Result;
};

template <typename U> struct MRTT_AddPointer<U&>
{
    typedef U* Result;
};


/****************************************************************/
/*!
 @abstract   MRTT_AddReference
 @discussion 
 */
//****************************************************************/
template <class U> struct MRTT_AddReference
{
    typedef U & Result;
};

template <class U> struct MRTT_AddReference<U &>
{
    typedef U & Result;
};

template <> struct MRTT_AddReference<void>
{
    typedef MRNullType Result;
};


/****************************************************************/
/*!
 @abstract   MRTT_AddParameterType
 @discussion 
 */
//****************************************************************/

template <class U> struct MRTT_AddParameterType
{
    typedef const U & Result;
};

template <class U> struct MRTT_AddParameterType<U &>
{
    typedef U & Result;
};

template <> struct MRTT_AddParameterType<void>
{
    typedef MRNullType Result;
};


/****************************************************************/
/*!
 @abstract   MRTT_IsFunctionPointerRaw
 @discussion 
 */
//****************************************************************/

template <typename T>
struct MRTT_IsFunctionPointerRaw
{enum{result = 0};};

template <typename T>
struct MRTT_IsFunctionPointerRaw<T(*)()> 
{enum {result = 1};};

template <typename T, 
typename P01>
struct MRTT_IsFunctionPointerRaw<T(*)(P01)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10,
                                      P11)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10,
                                      P11, P12)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10,
                                      P11, P12, P13)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10,
                                      P11, P12, P13, P14)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10,
                                      P11, P12, P13, P14, P15)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06, P07, P08, P09, P10, 
                                      P11, P12, P13, P14, P15,
                                      P16)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06, P07, P08, P09, P10, 
                                      P11, P12, P13, P14, P15,
                                      P16, P17)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06, P07, P08, P09, P10, 
                                      P11, P12, P13, P14, P15,
                                      P16, P17, P18)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06, P07, P08, P09, P10, 
                                      P11, P12, P13, P14, P15,
                                      P16, P17, P18, P19)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19, typename P20>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06, P07, P08, P09, P10, 
                                      P11, P12, P13, P14, P15,
                                      P16, P17, P18, P19, P20)> 
{enum {result = 1};};

template <typename T>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      ...)> 
{enum {result = 1};};

template <typename T, 
typename P01>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10,
                                      ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10,
                                      P11, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10,
                                      P11, P12, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10,
                                      P11, P12, P13, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10,
                                      P11, P12, P13, P14, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05,
                                      P06, P07, P08, P09, P10,
                                      P11, P12, P13, P14, P15,
                                      ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06, P07, P08, P09, P10, 
                                      P11, P12, P13, P14, P15,
                                      P16, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06, P07, P08, P09, P10, 
                                      P11, P12, P13, P14, P15,
                                      P16, P17, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06, P07, P08, P09, P10, 
                                      P11, P12, P13, P14, P15,
                                      P16, P17, P18, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06, P07, P08, P09, P10, 
                                      P11, P12, P13, P14, P15,
                                      P16, P17, P18, P19, ...)> 
{enum {result = 1};};

template <typename T, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19, typename P20>
struct MRTT_IsFunctionPointerRaw<T(*)(
                                      P01, P02, P03, P04, P05, 
                                      P06, P07, P08, P09, P10, 
                                      P11, P12, P13, P14, P15,
                                      P16, P17, P18, P19, P20,
                                      ...)> 
{enum {result = 1};};



/****************************************************************/
/*!
 @abstract   MRTT_IsMemberFunctionPointerRaw
 @discussion 
 */
//****************************************************************/

template <typename T>
struct MRTT_IsMemberFunctionPointerRaw
{enum{result = 0};};

template <typename T, typename S>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)()> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(P01)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, P15)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19, typename P20>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, P20)> 
{enum {result = 1};};

template <typename T, typename S>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, P15,
                                                ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, ...)> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19, typename P20>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, P20,
                                                ...)> 
{enum {result = 1};};

// Const versions

template <typename T, typename S>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)() const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(P01) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, P15) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19, typename P20>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, P20) const> 
{enum {result = 1};};

template <typename T, typename S>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, P15,
                                                ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, ...) const> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19, typename P20>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, P20,
                                                ...) const> 
{enum {result = 1};};

// Volatile versions

template <typename T, typename S>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)() volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(P01) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, P15) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19, typename P20>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, P20) volatile> 
{enum {result = 1};};

template <typename T, typename S>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, P15,
                                                ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, ...) volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19, typename P20>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, P20,
                                                ...) volatile> 
{enum {result = 1};};

// Const volatile versions

template <typename T, typename S>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)() const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(P01) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, P15) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19, typename P20>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, P20) const volatile> 
{enum {result = 1};};

template <typename T, typename S>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05,
                                                P06, P07, P08, P09, P10,
                                                P11, P12, P13, P14, P15,
                                                ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, ...) const volatile> 
{enum {result = 1};};

template <typename T, typename S, 
typename P01, typename P02, typename P03, typename P04, typename P05,
typename P06, typename P07, typename P08, typename P09, typename P10,
typename P11, typename P12, typename P13, typename P14, typename P15,
typename P16, typename P17, typename P18, typename P19, typename P20>
struct MRTT_IsMemberFunctionPointerRaw<T (S::*)(
                                                P01, P02, P03, P04, P05, 
                                                P06, P07, P08, P09, P10, 
                                                P11, P12, P13, P14, P15,
                                                P16, P17, P18, P19, P20,
                                                ...) const volatile> 
{enum {result = 1};};



////////////////////////////////////////////////////////////////////////////////
// class template MRTypeTraits
//
// Figures out at compile time various properties of any given type
// Invocations (T is a type, MRTypeTraits<T>::Property):
//
// - isPointer       : returns true if T is a pointer type
// - PointeeType     : returns the type to which T points if T is a pointer 
//                     type, MRNullType otherwise
// - isReference     : returns true if T is a reference type
// - ReferredType    : returns the type to which T refers if T is a reference 
//                     type, MRNullType otherwise
// - isMemberPointer : returns true if T is a pointer to member type
// - isStdUnsignedInt: returns true if T is a standard unsigned integral type
// - isStdSignedInt  : returns true if T is a standard signed integral type
// - isStdIntegral   : returns true if T is a standard integral type
// - isStdFloat      : returns true if T is a standard floating-point type
// - isStdArith      : returns true if T is a standard arithmetic type
// - isStdFundamental: returns true if T is a standard fundamental type
// - isUnsignedInt   : returns true if T is a unsigned integral type
// - isSignedInt     : returns true if T is a signed integral type
// - isIntegral      : returns true if T is a integral type
// - isFloat         : returns true if T is a floating-point type
// - isArith         : returns true if T is a arithmetic type
// - isFundamental   : returns true if T is a fundamental type
// - ParameterType   : returns the optimal type to be used as a parameter for 
//                     functions that take Ts
// - isConst         : returns true if T is a const-qualified type
// - NonConstType    : Type with removed 'const' qualifier from T, if any
// - isVolatile      : returns true if T is a volatile-qualified type
// - NonVolatileType : Type with removed 'volatile' qualifier from T, if any
// - UnqualifiedType : Type with removed 'const' and 'volatile' qualifiers from 
//                     T, if any
// - ParameterType   : returns the optimal type to be used as a parameter 
//                       for functions that take 'const T's
//
////////////////////////////////////////////////////////////////////////////////

template <typename T>
class MRTypeTraits
{
private:
    
    template <class U> struct ReferenceTraits
 {
    enum { result = false };
    typedef U ReferredType;
 };
    
    template <class U> struct ReferenceTraits<U&>
 {
    enum { result = true };
    typedef U ReferredType;
 };
    
    template <class U> struct PointerTraits
 {
    enum { result = false };
    typedef MRNullType PointeeType;
 };
    
    template <class U> struct PointerTraits<U*>
 {
    enum { result = true };
    typedef U PointeeType;
 };
    
    template <class U> struct PointerTraits<U*&>
 {
    enum { result = true };
    typedef U PointeeType;
 };
    
    template <class U> struct PToMTraits
 {
    enum { result = false };
 };
    
    template <class U, class V> struct PToMTraits<U V::*>
 {
    enum { result = true };
 };
    
    template <class U, class V> struct PToMTraits<U V::*&>
 {
    enum { result = true };
 };
    
    template <class U> struct FunctionPointerTraits
 {
    enum{ result = MRTT_IsFunctionPointerRaw<U>::result };
 };
    
    template <typename U> struct PToMFunctionTraits
 {
    enum{ result = MRTT_IsMemberFunctionPointerRaw<U>::result };
 };
    
    template <class U> struct UnConst
 {
    typedef U Result;
    enum { isConst = 0 };
 };
    
    template <class U> struct UnConst<const U>
 {
    typedef U Result;
    enum { isConst = 1 };
 };
    
    template <class U> struct UnConst<const U&>
 {
    typedef U& Result;
    enum { isConst = 1 };
 };
    
    template <class U> struct UnVolatile
 {
    typedef U Result;
    enum { isVolatile = 0 };
 };
    
    template <class U> struct UnVolatile<volatile U>
 {
    typedef U Result;
    enum { isVolatile = 1 };
 };
    
    template <class U> struct UnVolatile<volatile U&>
 {
    typedef U& Result;
    enum { isVolatile = 1 };
 };
    
public:
    typedef typename UnConst<T>::Result 
    NonConstType;
    typedef typename UnVolatile<T>::Result 
    NonVolatileType;
    typedef typename UnVolatile<typename UnConst<T>::Result>::Result 
    UnqualifiedType;
    typedef typename PointerTraits<UnqualifiedType>::PointeeType 
    PointeeType;
    typedef typename ReferenceTraits<T>::ReferredType 
    ReferredType;
    
    enum { isConst          = UnConst<T>::isConst };
    enum { isVolatile       = UnVolatile<T>::isVolatile };
    enum { isReference      = ReferenceTraits<UnqualifiedType>::result };
    enum { isFunction       = FunctionPointerTraits<typename MRTT_AddPointer<T>::Result >::result };
    enum { isFunctionPointer= FunctionPointerTraits<
        typename ReferenceTraits<UnqualifiedType>::ReferredType >::result };
    enum { isMemberFunctionPointer= PToMFunctionTraits<
        typename ReferenceTraits<UnqualifiedType>::ReferredType >::result };
    enum { isMemberPointer  = PToMTraits<
        typename ReferenceTraits<UnqualifiedType>::ReferredType >::result ||
        isMemberFunctionPointer };
    enum { isPointer        = PointerTraits<
        typename ReferenceTraits<UnqualifiedType>::ReferredType >::result ||
        isFunctionPointer };
    
    enum { isStdUnsignedInt = MRTL_IndexOf<MRTT_StdUnsignedInts, UnqualifiedType>::value >= 0 ||
        MRTL_IndexOf<MRTT_StdUnsignedInts, 
        typename ReferenceTraits<UnqualifiedType>::ReferredType>::value >= 0};
    enum { isStdSignedInt   = MRTL_IndexOf<MRTT_StdSignedInts, UnqualifiedType>::value >= 0 ||
        MRTL_IndexOf<MRTT_StdSignedInts, 
        typename ReferenceTraits<UnqualifiedType>::ReferredType>::value >= 0};
    enum { isStdIntegral    = isStdUnsignedInt || isStdSignedInt ||
        MRTL_IndexOf<MRTT_StdOtherInts, UnqualifiedType>::value >= 0 ||
        MRTL_IndexOf<MRTT_StdOtherInts, 
        typename ReferenceTraits<UnqualifiedType>::ReferredType>::value >= 0};
    enum { isStdFloat       = MRTL_IndexOf<MRTT_StdFloats, UnqualifiedType>::value >= 0 ||
        MRTL_IndexOf<MRTT_StdFloats, 
        typename ReferenceTraits<UnqualifiedType>::ReferredType>::value >= 0};
    enum { isStdArith       = isStdIntegral || isStdFloat };
    enum { isStdFundamental = isStdArith || isStdFloat || MRConversion<T, void>::sameType };
    
    enum { isUnsignedInt    = isStdUnsignedInt || MRIsCustomUnsignedInt<UnqualifiedType>::value };
    enum { isSignedInt      = isStdSignedInt || MRIsCustomSignedInt<UnqualifiedType>::value };
    enum { isIntegral       = isStdIntegral || isUnsignedInt || isSignedInt };
    enum { isFloat          = isStdFloat || MRIsCustomFloat<UnqualifiedType>::value };
    enum { isArith          = isIntegral || isFloat };
    enum { isFundamental    = isStdFundamental || isArith };
    
    typedef typename MRSelectType<isStdArith || isPointer || isMemberPointer, T, 
    typename MRTT_AddParameterType<T>::Result>::Result 
    ParameterType;
};


#ifdef _MSC_VER
#pragma warning( pop )
#endif // _MSC_VER

MAGICREFLECTION_NAMESPACE_END
#endif // __MAGICREFLECTON__LOKI_TYPETRAITS_INC_
       //eof
