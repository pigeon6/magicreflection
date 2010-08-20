/****************************************************************/
/*!
 @abstract   ￼MRMethodInvocationContext.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRMETHODINVOCATIONCONTEXT_H__
#define __MAGICREFLECTION_MRMETHODINVOCATIONCONTEXT_H__

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
 @abstract   Method Invocation Context
 @discussion 
Method invocation context is what you use to invoke method.
It holds all the parameters you pass.
 */
//****************************************************************/
class MRMethodInvocationContext : public MRAbstractInvocationContext {

    MRMightyType    m_retval;           ///< return value
    MRDynamicPtr    m_caller;           ///< caller of method
    const MRMethod* m_pMethod;          ///< calling method    
    mr_typeid_t     m_rtTypeID;         ///< return value type id
    
public:
    explicit MRMethodInvocationContext(const MRDynamicPtr& pObj, const MRMethod* pMethod) : 
    m_caller(pObj), m_pMethod(pMethod) {}
    ~MRMethodInvocationContext() {}
    
    bool Invoke(void);
    MRDynamicPtr& GetCaller(void);
    
    template<typename T>
    T GetReturnValue(void) const;

    template<typename T>
    T* GetReturnValuePtr(void) const;
    
    bool IsReturnValuePrimitive(void) const;
    bool IsReturnValuePtr(void) const;
    bool IsReturnValueObject(void) const;
    bool IsReturnValueVoid(void) const;

    template<typename T>
    void SetReturnValue(const T& val);
    void SetReturnValueVoid();

    mr_typeid_t GetReturnValueTypeID(void) const;
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRDYNAMICPTR_H__
//eof
