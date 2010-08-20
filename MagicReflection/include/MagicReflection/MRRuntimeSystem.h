/****************************************************************/
/*!
 @abstract   ￼MRRuntimeSystem.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRRUNTIMESYSTEM_H__
#define __MAGICREFLECTION_MRRUNTIMESYSTEM_H__

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
 @abstract   MagicReflection Runtime System
 @discussion 
 MRRuntimeSystem is the user interface to startup/shutdown MagicReflection.
 It also provides user control for memory management, and gives you some 
 clue about its usage, number of classes, etc.
 
 */
//****************************************************************/
class MagicReflection {
public:
    static void Initialize(void);
    static void Finalize(void);
};


MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRDYNAMICPTR_H__
//eof
