/****************************************************************/
/*!
 @abstract   ￼MRStaticAssert.h
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/20.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

#ifndef __MAGICREFLECTION_MRSTATICASSERT_H__
#define __MAGICREFLECTION_MRSTATICASSERT_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Dependencies
//----------------------------------------------------------------

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Static Assert
 @discussion 
 static assert is assertion checker in compilation time.
 
 */
//****************************************************************/
template<bool b> struct MRStaticAssert;
template<>
struct MRStaticAssert<true> {
    MRStaticAssert(int){}
};

#define MR_STATIC_ASSERT(cond)  MR_NS(MRStaticAssert<(cond)>) MR_UNIQUENAME(__mr_static_assert_failed_) = 0

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRSTATICASSERT_H__
       //eof
