/****************************************************************/
/*!
 @abstract   ￼MRRuntimeSystem.cpp
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/20.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

//----------------------------------------------------------------
// File Dependencies
//----------------------------------------------------------------
#include "MagicReflection.h"
#include "MRRuntimeSystemImpl.h"
#include <string.h>

//----------------------------------------------------------------
// Namespace Dependencies
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_USE;

//----------------------------------------------------------------
// Static values
//----------------------------------------------------------------
MRRuntimeSystemImpl*    MRRuntimeSystemImpl::s_pImpl = 0;
MRRuntimeClass*         MRRuntimeSystemImpl::s_initListHead_RuntimeClass = 0;
MRMethodInvoker*        MRRuntimeSystemImpl::s_initListHead_MethodInvoker = 0;
MRConstructorInvoker*   MRRuntimeSystemImpl::s_initListHead_ConstructorInvoker = 0;

//----------------------------------------------------------------
// Implementation (MRRuntimeSystemImpl)
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Singleton Instance
 */
//****************************************************************/
/*static*/ MRRuntimeSystemImpl* MRRuntimeSystemImpl::GetInstance(void) {
    if (!s_pImpl) {
        //TODO: memory
        s_pImpl = new MRRuntimeSystemImpl();
    }    
    return s_pImpl;
}

/****************************************************************/
/*!
 @abstract   Finalize system and shutdown.
 */
//****************************************************************/

void MRRuntimeSystemImpl::Shutdown(void) {
    if(s_pImpl) {
        s_pImpl->Finalize();
        delete s_pImpl;
        s_pImpl = NULL;
    }
}

/****************************************************************/
/*!
 @abstract   Initialization Process
 */
//****************************************************************/
void MRRuntimeSystemImpl::Initialize() {

    // initialize all runtime classes
    MRRuntimeClass* pRT = s_initListHead_RuntimeClass;
    while (pRT) {
        pRT->_Initialize();
        m_rtList.push_back(pRT);
        pRT = pRT->m_initList;
    }

    // initialize all constructor invokers
    MRConstructorInvoker* pCI = s_initListHead_ConstructorInvoker;
    while (pCI) {
        pCI->_Initialize();
        pCI = pCI->m_initList;
    }

    // initialize all method invokers
    MRMethodInvoker* pMI = s_initListHead_MethodInvoker;
    while (pMI) {
        pMI->_Initialize();
        pMI = pMI->m_initList;
    }
}


/****************************************************************/
/*!
 @abstract   Finalization Process
 */
//****************************************************************/
void MRRuntimeSystemImpl::Finalize() {
    
    // initialize all runtime classes
    MRRuntimeClass* pRT = s_initListHead_RuntimeClass;
    while (pRT) {
        pRT->_Finalize();
        pRT = pRT->m_initList;
    }
    
    // initialize all constructor invokers
    MRConstructorInvoker* pCI = s_initListHead_ConstructorInvoker;
    while (pCI) {
        pCI->_Finalize();
        pCI = pCI->m_initList;
    }
    
    // initialize all method invokers
    MRMethodInvoker* pMI = s_initListHead_MethodInvoker;
    while (pMI) {
        pMI->_Finalize();
        pMI = pMI->m_initList;
    }
}


/****************************************************************/
/*!
 @abstract   find runtime class
 */
//****************************************************************/
MRRuntimeClass* MRRuntimeSystemImpl::FindClass(const mr_char* className) {
    
    mr_uint32 nItems = m_rtList.size();
    for(mr_uint32 i=0; i< nItems; ++i) {
        MRRuntimeClass* pRT = m_rtList[i];
        if(strcmp(className, pRT->GetName()) == 0) {
            return pRT;
        }
    }
    
    return NULL;
}


//----------------------------------------------------------------
// Implementation (MRRuntimeSystem)
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Initialize MagicReflection
 @discussion 
 this function initializes MagicReflection system.
 Be sure that this function is called after you entered main().
 
 If you do not initialize MagicReflection, no services work
 except for typeid related functions.
 */
//****************************************************************/
/*static*/ void MagicReflection::Initialize(void) {
    MRRuntimeSystemImpl* pSystem = MRRuntimeSystemImpl::GetInstance();    
    pSystem->Initialize();
}

/****************************************************************/
/*!
 @abstract   Finalize MagicReflection
 @discussion 
 this function finalizes MagicReflection system, and release
 all used memory.
 Be sure that this function is called after you entered main().
 */
//****************************************************************/
/*static*/ void MagicReflection::Finalize(void) {
    MRRuntimeSystemImpl::Shutdown();
}
