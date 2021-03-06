/****************************************************************/
/*!
 @abstract   ￼MRSequence.h
 @discussion ￼ 
 
 File created by Hiroki Omae on 2010/08/19.
 This file is modified from loki-0.17:MRNullType.h
 
 All namespace and symbol names are modified to
 match MR needs and policies, and avoiding collision to original loki.
 
 based on:
 The Loki Library
 Copyright (c) 2005 by Peter K¸mmel
 Permission to use, copy, modify, distribute and sell this software for any 
 purpose is hereby granted without fee, provided that the above copyright 
 notice appear in all copies and that both that copyright notice and this 
 permission notice appear in supporting documentation.
 The author makes no representations about the 
 suitability of this software for any purpose. It is provided "as is" 
 without express or implied warranty.
 
 // $Id: Sequence.h 768 2006-10-25 20:40:40Z syntheticpp $
 */
/****************************************************************/
#ifndef __MAGICREFLECTON__LOKI_SEQUENCE_INC_
#define __MAGICREFLECTON__LOKI_SEQUENCE_INC_

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

template
<
class T01=MRNullType,class T02=MRNullType,class T03=MRNullType,class T04=MRNullType,class T05=MRNullType,
class T06=MRNullType,class T07=MRNullType,class T08=MRNullType,class T09=MRNullType,class T10=MRNullType,
class T11=MRNullType,class T12=MRNullType,class T13=MRNullType,class T14=MRNullType,class T15=MRNullType,
class T16=MRNullType,class T17=MRNullType,class T18=MRNullType,class T19=MRNullType,class T20=MRNullType
>
struct MRSeq
{
private:
    typedef typename MRSeq< T02, T03, T04, T05, T06, T07, T08, T09, T10,
    T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>::Type 
    TailResult;
public:
    typedef Typelist<T01, TailResult> Type;
};

template<>
struct MRSeq<>
{
    typedef MRNullType Type;
};

MAGICREFLECTION_NAMESPACE_END
#endif // __MAGICREFLECTON__LOKI_SEQUENCE_INC_
       // eof

