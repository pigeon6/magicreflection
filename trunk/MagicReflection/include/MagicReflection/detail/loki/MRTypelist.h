/****************************************************************/
/*!
 @abstract   ￼MRTypelist.h
 @discussion ￼ 
 
 File created by Hiroki Omae on 2010/08/19.
 This file is modified from loki-0.17:Typelist.h
 
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
 
 // $Id: Typelist.h 749 2006-10-17 19:49:26Z syntheticpp $
 */
/****************************************************************/
#ifndef __MAGICREFLECTON__LOKI_TYPELIST_INC_
#define __MAGICREFLECTON__LOKI_TYPELIST_INC_

MAGICREFLECTION_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////
// class template Typelist
// The building block of typelists of any length
// Use it through the MR_TL_NN macros
// Defines nested types:
//     Head (first element, a non-typelist type by convention)
//     Tail (second element, can be another typelist)
////////////////////////////////////////////////////////////////////////////////

template <class T, class U>
struct MRTypelist
{
    typedef T Head;
    typedef U Tail;
};


//----------------------------------------------------------------
// Typelist utility algorithms
//----------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_MakeTypelist
// Takes a number of arguments equal to its numeric suffix
// The arguments are type names.
// MRTL_MakeTypelist<T1, T2, ...>::Result
// returns a typelist that is of T1, T2, ...
////////////////////////////////////////////////////////////////////////////////

template
<
typename T1  = MRNullType, typename T2  = MRNullType, typename T3  = MRNullType,
typename T4  = MRNullType, typename T5  = MRNullType, typename T6  = MRNullType,
typename T7  = MRNullType, typename T8  = MRNullType, typename T9  = MRNullType,
typename T10 = MRNullType, typename T11 = MRNullType, typename T12 = MRNullType,
typename T13 = MRNullType, typename T14 = MRNullType, typename T15 = MRNullType,
typename T16 = MRNullType, typename T17 = MRNullType, typename T18 = MRNullType
> 
struct MRTL_MakeTypelist
{
private:
    typedef typename MRTL_MakeTypelist
    <
    T2 , T3 , T4 , 
    T5 , T6 , T7 , 
    T8 , T9 , T10, 
    T11, T12, T13,
    T14, T15, T16, 
    T17, T18
    >
    ::Result TailResult;
    
public:
    typedef MRTypelist<T1, TailResult> Result;
};

template<>
struct MRTL_MakeTypelist<>
{
    typedef MRNullType Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_Length
// Computes the length of a typelist
// Invocation (TList is a typelist):
// MRTL_Length<TList>::value
// returns a compile-time constant containing the length of TList, not counting
//     the end terminator (which by convention is MRNullType)
////////////////////////////////////////////////////////////////////////////////

template <class TList> struct MRTL_Length;
template <> struct MRTL_Length<MRNullType>
{
    enum { value = 0 };
};

template <class T, class U>
struct MRTL_Length< MRTypelist<T, U> >
{
    enum { value = 1 + MRTL_Length<U>::value };
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_TypeAt
// Finds the type at a given index in a typelist
// Invocation (TList is a typelist and index is a compile-time integral 
//     constant):
// MRTL_TypeAt<TList, index>::Result
// returns the type in position 'index' in TList
// If you pass an out-of-bounds index, the result is a compile-time error
////////////////////////////////////////////////////////////////////////////////

template <class TList, unsigned int index> struct MRTL_TypeAt;

template <class Head, class Tail>
struct MRTL_TypeAt<MRTypelist<Head, Tail>, 0>
{
    typedef Head Result;
};

template <class Head, class Tail, unsigned int i>
struct MRTL_TypeAt<MRTypelist<Head, Tail>, i>
{
    typedef typename MRTL_TypeAt<Tail, i - 1>::Result Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_TypeAtNonStrict
// Finds the type at a given index in a typelist
// Invocations (TList is a typelist and index is a compile-time integral 
//     constant):
// a) MRTL_TypeAt<TList, index>::Result
// returns the type in position 'index' in TList, or MRNullType if index is 
//     out-of-bounds
// b) MRTL_TypeAt<TList, index, D>::Result
// returns the type in position 'index' in TList, or D if index is out-of-bounds
////////////////////////////////////////////////////////////////////////////////

template <class TList, unsigned int index,
typename DefaultType = MRNullType>
struct MRTL_TypeAtNonStrict
{
    typedef DefaultType Result;
};

template <class Head, class Tail, typename DefaultType>
struct MRTL_TypeAtNonStrict<MRTypelist<Head, Tail>, 0, DefaultType>
{
    typedef Head Result;
};

template <class Head, class Tail, unsigned int i, typename DefaultType>
struct MRTL_TypeAtNonStrict<MRTypelist<Head, Tail>, i, DefaultType>
{
    typedef typename 
    MRTL_TypeAtNonStrict<Tail, i - 1, DefaultType>::Result Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_IndexOf
// Finds the index of a type in a typelist
// Invocation (TList is a typelist and T is a type):
// MRTL_IndexOf<TList, T>::value
// returns the position of T in TList, or MRNullType if T is not found in TList
////////////////////////////////////////////////////////////////////////////////

template <class TList, class T> struct MRTL_IndexOf;

template <class T>
struct MRTL_IndexOf<MRNullType, T>
{
    enum { value = -1 };
};

template <class T, class Tail>
struct MRTL_IndexOf<MRTypelist<T, Tail>, T>
{
    enum { value = 0 };
};

template <class Head, class Tail, class T>
struct MRTL_IndexOf<MRTypelist<Head, Tail>, T>
{
private:
    enum { temp = MRTL_IndexOf<Tail, T>::value };
public:
    enum { value = (temp == -1 ? -1 : 1 + temp) };
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_Append
// Appends a type or a typelist to another
// Invocation (TList is a typelist and T is either a type or a typelist):
// MRTL_Append<TList, T>::Result
// returns a typelist that is TList followed by T and MRNullType-terminated
////////////////////////////////////////////////////////////////////////////////

template <class TList, class T> struct MRTL_Append;

template <> struct MRTL_Append<MRNullType, MRNullType>
{
    typedef MRNullType Result;
};

template <class T> struct MRTL_Append<MRNullType, T>
{
    typedef MRTypelist<T,MRNullType> Result;
};

template <class Head, class Tail>
struct MRTL_Append<MRNullType, MRTypelist<Head, Tail> >
{
    typedef MRTypelist<Head, Tail> Result;
};

template <class Head, class Tail, class T>
struct MRTL_Append<MRTypelist<Head, Tail>, T>
{
    typedef MRTypelist<Head, 
    typename MRTL_Append<Tail, T>::Result>
    Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_Erase
// Erases the first occurence, if any, of a type in a typelist
// Invocation (TList is a typelist and T is a type):
// MRTL_Erase<TList, T>::Result
// returns a typelist that is TList without the first occurence of T
////////////////////////////////////////////////////////////////////////////////

template <class TList, class T> struct MRTL_Erase;

template <class T>                         // Specialization 1
struct MRTL_Erase<MRNullType, T>
{
    typedef MRNullType Result;
};

template <class T, class Tail>             // Specialization 2
struct MRTL_Erase<MRTypelist<T, Tail>, T>
{
    typedef Tail Result;
};

template <class Head, class Tail, class T> // Specialization 3
struct MRTL_Erase<MRTypelist<Head, Tail>, T>
{
    typedef MRTypelist<Head, 
    typename MRTL_Erase<Tail, T>::Result>
    Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_EraseAll
// Erases all first occurences, if any, of a type in a typelist
// Invocation (TList is a typelist and T is a type):
// MRTL_EraseAll<TList, T>::Result
// returns a typelist that is TList without any occurence of T
////////////////////////////////////////////////////////////////////////////////

template <class TList, class T> struct MRTL_EraseAll;
template <class T>
struct MRTL_EraseAll<MRNullType, T>
{
    typedef MRNullType Result;
};
template <class T, class Tail>
struct MRTL_EraseAll<MRTypelist<T, Tail>, T>
{
    // Go all the way down the list removing the type
    typedef typename MRTL_EraseAll<Tail, T>::Result Result;
};
template <class Head, class Tail, class T>
struct MRTL_EraseAll<MRTypelist<Head, Tail>, T>
{
    // Go all the way down the list removing the type
    typedef MRTypelist<Head, 
    typename MRTL_EraseAll<Tail, T>::Result>
    Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_NoDuplicates
// Removes all duplicate types in a typelist
// Invocation (TList is a typelist):
// MRTL_NoDuplicates<TList, T>::Result
////////////////////////////////////////////////////////////////////////////////

template <class TList> struct MRTL_NoDuplicates;

template <> struct MRTL_NoDuplicates<MRNullType>
{
    typedef MRNullType Result;
};

template <class Head, class Tail>
struct MRTL_NoDuplicates< MRTypelist<Head, Tail> >
{
private:
    typedef typename MRTL_NoDuplicates<Tail>::Result L1;
    typedef typename MRTL_Erase<L1, Head>::Result L2;
public:
    typedef MRTypelist<Head, L2> Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_Replace
// Replaces the first occurence of a type in a typelist, with another type
// Invocation (TList is a typelist, T, U are types):
// MRTL_Replace<TList, T, U>::Result
// returns a typelist in which the first occurence of T is replaced with U
////////////////////////////////////////////////////////////////////////////////

template <class TList, class T, class U> struct MRTL_Replace;

template <class T, class U>
struct MRTL_Replace<MRNullType, T, U>
{
    typedef MRNullType Result;
};

template <class T, class Tail, class U>
struct MRTL_Replace<MRTypelist<T, Tail>, T, U>
{
    typedef MRTypelist<U, Tail> Result;
};

template <class Head, class Tail, class T, class U>
struct MRTL_Replace<MRTypelist<Head, Tail>, T, U>
{
    typedef MRTypelist<Head,
    typename MRTL_Replace<Tail, T, U>::Result>
    Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_ReplaceAll
// Replaces all occurences of a type in a typelist, with another type
// Invocation (TList is a typelist, T, U are types):
// MRTL_Replace<TList, T, U>::Result
// returns a typelist in which all occurences of T is replaced with U
////////////////////////////////////////////////////////////////////////////////

template <class TList, class T, class U> struct MRTL_ReplaceAll;

template <class T, class U>
struct MRTL_ReplaceAll<MRNullType, T, U>
{
    typedef MRNullType Result;
};

template <class T, class Tail, class U>
struct MRTL_ReplaceAll<MRTypelist<T, Tail>, T, U>
{
    typedef MRTypelist<U, typename MRTL_ReplaceAll<Tail, T, U>::Result> Result;
};

template <class Head, class Tail, class T, class U>
struct MRTL_ReplaceAll<MRTypelist<Head, Tail>, T, U>
{
    typedef MRTypelist<Head,
    typename MRTL_ReplaceAll<Tail, T, U>::Result>
    Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_Reverse
// Reverses a typelist
// Invocation (TList is a typelist):
// MRTL_Reverse<TList>::Result
// returns a typelist that is TList reversed
////////////////////////////////////////////////////////////////////////////////

template <class TList> struct MRTL_Reverse;

template <>
struct MRTL_Reverse<MRNullType>
{
    typedef MRNullType Result;
};

template <class Head, class Tail>
struct MRTL_Reverse< MRTypelist<Head, Tail> >
{
    typedef typename MRTL_Append<
    typename MRTL_Reverse<Tail>::Result, Head>::Result Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_MostDerived
// Finds the type in a typelist that is the most derived from a given type
// Invocation (TList is a typelist, T is a type):
// MRTL_MostDerived<TList, T>::Result
// returns the type in TList that's the most derived from T
////////////////////////////////////////////////////////////////////////////////

template <class TList, class T> struct MRTL_MostDerived;

template <class T>
struct MRTL_MostDerived<MRNullType, T>
{
    typedef T Result;
};

template <class Head, class Tail, class T>
struct MRTL_MostDerived<MRTypelist<Head, Tail>, T>
{
private:
    typedef typename MRTL_MostDerived<Tail, T>::Result Candidate;
public:
    typedef typename MRSelectType<
    MRSuperSubclass<Candidate,Head>::value,
    Head, Candidate>::Result Result;
};

////////////////////////////////////////////////////////////////////////////////
// class template MRTL_DerivedToFront
// Arranges the types in a typelist so that the most derived types appear first
// Invocation (TList is a typelist):
// MRTL_DerivedToFront<TList>::Result
// returns the reordered TList 
////////////////////////////////////////////////////////////////////////////////

template <class TList> struct MRTL_DerivedToFront;

template <>
struct MRTL_DerivedToFront<MRNullType>
{
    typedef MRNullType Result;
};

template <class Head, class Tail>
struct MRTL_DerivedToFront< MRTypelist<Head, Tail> >
{
private:
    typedef typename MRTL_MostDerived<Tail, Head>::Result
    TheMostDerived;
    typedef typename MRTL_Replace<Tail,
    TheMostDerived, Head>::Result Temp;
    typedef typename MRTL_DerivedToFront<Temp>::Result L;
public:
    typedef MRTypelist<TheMostDerived, L> Result;
};

MAGICREFLECTION_NAMESPACE_END
#endif // __MAGICREFLECTON__LOKI_TYPELIST_INC_
       // eof
