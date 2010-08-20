/****************************************************************/
/*!
 @abstract   ￼MRRuntimeClass.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRCLASS_H__
#define __MAGICREFLECTION_MRCLASS_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Dependencies
//----------------------------------------------------------------
class MRMethod;
class MRMethodInvoker;
class MRConstructorInvoker;
class MRRuntimeConstructionContext;

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Runtime class presentation
 @discussion 
                MRRuntimeClass is an abstract representation of 
                runtime classes.
                It is inherited by concrete classes, mostly templated.
                
 */
//****************************************************************/
class MRRuntimeClass {
    friend class MRRuntimeSystemImpl;

protected:
    typedef MRVector<MRMethod*> MethodList;
    
    MethodList          m_methodList;       ///< list of methods
    MRConstructor       m_constructor;      ///< constructor
    MRRuntimeClass*     m_pParent;          ///< parent class    
    MRRuntimeClass*     m_initList;         ///< initialization chain

    virtual void _Initialize(void) = 0;
    virtual void _Finalize(void) = 0;
    
public:
    typedef MethodList::const_iterator MethodIterator;
    
    explicit MRRuntimeClass(MRRuntimeClass* pClass);
    virtual ~MRRuntimeClass();
    
    static const MRRuntimeClass* ForName(const mr_char* className);
        
    bool IsCastableTo(const MRRuntimeClass* pClass) const;
    
    const MRMethod* FindMethod(const char* methodName) const;
    void RegisterMethod(const MRMethodInvoker* pMethodInvoker);
    void RegisterConstructor(const MRConstructorInvoker* pConstructor);

    MethodIterator  MethodBegin(void) const;
    MethodIterator  MethodEnd(void) const;
    
    virtual const char* GetName(void) const = 0;
    virtual mr_typeid_t GetTypeID(void) const = 0;
    virtual MRDynamicPtr CreateInstance(void) const = 0;
    virtual MRDynamicPtr CreateInstance(const MRRuntimeConstructionContext& rcc) const =0;
    virtual void Delete(const MRDynamicPtr& ptr) const = 0;
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRCLASS_H__
//eof