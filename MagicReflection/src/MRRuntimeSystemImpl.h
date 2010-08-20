/****************************************************************/
/*!
 @abstract   ￼MRRuntimeSystemImpl.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRRUNTIMESYSTEMIMPL_H__
#define __MAGICREFLECTION_MRRUNTIMESYSTEMIMPL_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Dependencies
//----------------------------------------------------------------
class MRRuntimeClass;

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------
class MRRuntimeSystemImpl {
    
    typedef MRVector<MRRuntimeClass*>   RuntimeClassList;
    
    static MRRuntimeSystemImpl* s_pImpl;
    
    RuntimeClassList    m_rtList;   ///< list of runtime classes

public:
    static MRRuntimeClass*          s_initListHead_RuntimeClass;
    static MRMethodInvoker*         s_initListHead_MethodInvoker;
    static MRConstructorInvoker*    s_initListHead_ConstructorInvoker;
    
    static MRRuntimeSystemImpl* GetInstance(void);
    static void Shutdown(void);

    void Initialize();
    void Finalize();
    
    MRRuntimeClass* FindClass(const mr_char* className);
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRDYNAMICPTR_H__
//eof
