/****************************************************************/
/*!
 @abstract   ￼MRRuntimeConstructionContext.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRRUNTIMECONSTRUCTIONCONTEXT_H__
#define __MAGICREFLECTION_MRRUNTIMECONSTRUCTIONCONTEXT_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Dependencies
//----------------------------------------------------------------
class MRMethod;

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Runtime Construction Context
 @discussion 
 Runtime construction context is what you use to create object
 with parameters.
 It holds all the parameters you pass to instantiate an object.
 */
//****************************************************************/
class MRRuntimeConstructionContext : public MRAbstractInvocationContext {
public:
    explicit MRRuntimeConstructionContext() {}
    ~MRRuntimeConstructionContext() {}
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRDYNAMICPTR_H__
//eof
