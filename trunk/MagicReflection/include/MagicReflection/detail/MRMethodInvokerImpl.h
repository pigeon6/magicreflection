/****************************************************************/
/*!
 @abstract   ￼MRMethodInvokerImpl.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRMETHODINVOKERIMPL_H__
#define __MAGICREFLECTION_MRMETHODINVOKERIMPL_H__

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
 @abstract   MethodInvokerImpl
 @discussion 
 MRMethodInvokerImpl is the actual implementation of method invoker.
 
 Class      : invoker class type
 ReturnType : return type of the method
 ParamList  : MRTypeList to method parameters
 */
//****************************************************************/
template<typename Class, typename ReturnType, typename ParamList, bool isConstMethod>
class MRMethodInvokerImpl : public MRMethodInvoker {    
    typedef typename MRSelectType<isConstMethod, 
    typename MRMethodTypeConstructor<Class, ReturnType, ParamList>::ConstMethodType,
    typename MRMethodTypeConstructor<Class, ReturnType, ParamList>::MethodType>::Result MethodType;
        
    MethodType          m_pMethod;          ///< pointer to method(maybe const/not, depends on isConstMethod)
    const mr_char*      m_pName;            ///< name of the method
    
    bool _CanInvoke(MRMethodInvocationContext& mic) const;    

protected:
    void _Initialize(void);
    void _Finalize(void);

public:
    explicit MRMethodInvokerImpl(const mr_char* pName, MethodType pMethod);
    ~MRMethodInvokerImpl();
    
    const mr_char* GetName(void) const;
    bool Invoke(MRMethodInvocationContext& mic) const;
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRMETHODINVOKERIMPL_H__
       //eof
