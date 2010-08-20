/****************************************************************/
/*!
 @abstract   ￼MRConstructor.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRCONSTRUCTOR_H__
#define __MAGICREFLECTION_MRCONSTRUCTOR_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Dependencies
//----------------------------------------------------------------
class MRConstructorInvoker;
class MRRuntimeConstructionContext;

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Method
 @discussion 
 MRMethod is the representation of an executable method.
 It supports method invocation, overloading.
 
 */
//****************************************************************/
class MRConstructor {
    typedef MRVector<const MRConstructorInvoker*>    ConstructorInvokerList;
    
    ConstructorInvokerList   m_invokers;     ///< list of constructor invokers
public:
    explicit MRConstructor() {}
    ~MRConstructor(){}
    
    void RegisterInvoker(const MRConstructorInvoker* pInvoker);
    MRDynamicPtr Construct(const MRRuntimeConstructionContext& rcc) const;
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRCONSTRUCTOR_H__
       //eof
