/****************************************************************/
/*!
 @abstract   ￼MRLooseType.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRLOOSETYPE_H__
#define __MAGICREFLECTION_MRLOOSETYPE_H__

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
 @abstract   MRNumber
 @discussion 
 MRNumber is the loose type of number representation.
 it is only used for matching typeid.
 
 */
//****************************************************************/
struct MRNumber {};


/****************************************************************/
/*!
 @abstract   Loose Type
 @discussion 
Loose type is the key to accept compatible types in method invocation.
 
 
 */
//****************************************************************/
template <typename T>
class MRLooseType {
    typedef T Type;
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRLOOSETYPE_H__
       //eof
