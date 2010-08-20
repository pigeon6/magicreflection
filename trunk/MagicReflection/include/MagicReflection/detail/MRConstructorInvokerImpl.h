/****************************************************************/
/*!
 @abstract   ￼MRConstructorInvokerImpl.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRCONSTRUCTORINVOKERIMPL_H__
#define __MAGICREFLECTION_MRCONSTRUCTORINVOKERIMPL_H__

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
 @abstract   MRConstructorInvokerImpl
 @discussion 
 MRConstructorInvokerImpl is the actual implementation that calls
 constructor to Class.
 
 Class      : class type to construct object
 ParamList  : MRTypeList to constructor parameters
 */
//****************************************************************/
template<typename Class, typename ParamList>
class MRConstructorInvokerImpl : public MRConstructorInvoker {

    bool _CanConstruct(const MRRuntimeConstructionContext& mic) const;    
protected:
    void _Initialize(void);
    void _Finalize(void);
    
public:
    explicit MRConstructorInvokerImpl();
    ~MRConstructorInvokerImpl();
    
    MRDynamicPtr Construct(const MRRuntimeConstructionContext& rcc) const;
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRCONSTRUCTORINVOKERIMPL_H__
       //eof
