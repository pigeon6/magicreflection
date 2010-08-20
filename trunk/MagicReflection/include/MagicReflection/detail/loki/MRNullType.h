/****************************************************************/
/*!
 @abstract   ￼MRNullType.h
 @discussion ￼ 
 
 File created by Hiroki Omae on 2010/08/19.
 This file is modified from loki-0.17:NullType.h

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
 
 // $Id: NullType.h 751 2006-10-17 19:50:37Z syntheticpp $
 */
/****************************************************************/

#ifndef __MAGICREFLECTON__LOKI_NULLTYPE_INC_
#define __MAGICREFLECTON__LOKI_NULLTYPE_INC_

MAGICREFLECTION_NAMESPACE_BEGIN

/****************************************************************/
/*!
 @abstract   Null Type
 @discussion 
 MRNullType is the type that means NULL(there is no valid type)

 original comment:
     class NullType
     Used as a placeholder for "no type here"
     Useful as an end marker in typelists 
 
 */
//****************************************************************/
class MRNullType {};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTON__LOKI_NULLTYPE_INC_
       //eof
