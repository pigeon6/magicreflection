/****************************************************************/
/*!
 @abstract   ￼MRConstructorInvoker.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRCONSTRUCTORINVOKER_H__
#define __MAGICREFLECTION_MRCONSTRUCTORINVOKER_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Dependencies
//----------------------------------------------------------------
class MRConstructorInvoker;

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Constructor Invoker
 @discussion 
 Constructor Invoker is the base class
 
 */
//****************************************************************/
class MRConstructorInvoker {
    friend class MRRuntimeSystemImpl;

    MRConstructorInvoker*   m_initList; ///< initialization chain
    
protected:
    virtual void _Initialize(void) = 0;
    virtual void _Finalize(void) = 0;

public:
    explicit MRConstructorInvoker();
    virtual ~MRConstructorInvoker();
    
    virtual MRDynamicPtr Construct(const MRRuntimeConstructionContext& rcc) const = 0;
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRCONSTRUCTORINVOKER_H__
       //eof
