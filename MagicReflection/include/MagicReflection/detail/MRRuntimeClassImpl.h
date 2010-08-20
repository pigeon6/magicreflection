/****************************************************************/
/*!
 @abstract   ￼MRRuntimeClass.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRRUNTIMECLASSIMPL_H__
#define __MAGICREFLECTION_MRRUNTIMECLASSIMPL_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Dependencies
//----------------------------------------------------------------
class MRMethodInvoker;
class MRConstructorInvoker;

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Standard runtime class Implementation
 @discussion 
 MRRuntimeClassImpl is an actual representation of 
 runtime classes.
 */
//****************************************************************/
template <class T>
class MRRuntimeClassImpl : public MRRuntimeClass {
    
    const mr_char*      m_pName;            ///< name of class
    
protected:
    void _Initialize(void);
    void _Finalize(void);
    
public:
    explicit MRRuntimeClassImpl(const mr_char* name, MRRuntimeClass* pClass);
    
    const MRMethod* FindMethod(const char* methodName) const;
        
    virtual const mr_char* GetName(void) const;    
    virtual mr_typeid_t GetTypeID(void) const;
    virtual MRDynamicPtr CreateInstance(void) const;
    virtual MRDynamicPtr CreateInstance(const MRRuntimeConstructionContext& rcc) const;
    virtual void Delete(const MRDynamicPtr& ptr) const;
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRRUNTIMECLASSIMPL_H__
//eof