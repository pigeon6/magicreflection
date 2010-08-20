/****************************************************************/
/*!
 @abstract   ￼MRRuntimeClass.cpp
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

//----------------------------------------------------------------
// File Dependencies
//----------------------------------------------------------------
#include "MagicReflection.h"
#include "MRRuntimeSystemImpl.h"

//----------------------------------------------------------------
// Namespace Dependencies
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_USE;

//----------------------------------------------------------------
// Implementation (MRRuntimeClass)
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Constructor
 @discussion
 MRRuntimeClass object is basically defined as static object.
 in object construction, it creates the single directional list
 to be able to initialize later.
 */
//****************************************************************/
MRRuntimeClass::MRRuntimeClass(MRRuntimeClass* pClass) : m_pParent(pClass) {
    m_initList = MRRuntimeSystemImpl::s_initListHead_RuntimeClass;
    MRRuntimeSystemImpl::s_initListHead_RuntimeClass = this;    
}

/****************************************************************/
/*!
 @abstract   Destructor
 */
//****************************************************************/
MRRuntimeClass::~MRRuntimeClass() {
}


/****************************************************************/
/*!
 @abstract  Find runtime class instance in the name
 @discussion 
            Finds runtime class in the name of given className.
            Returns NULL if no matching runtime class is found.
 
 @param  [in]  className    name of the class in ascii.
 @result    MRRuntimeClass instance found.
            NULL    no matching class is found.
 */
//****************************************************************/
/*static*/ const MRRuntimeClass* MRRuntimeClass::ForName(const mr_char* className) {
    return MRRuntimeSystemImpl::GetInstance()->FindClass(className);
}

/****************************************************************/
/*!
 @abstract   Check if given class instance castable from caller.
 @discussion 
 Check if given class instance is castable from
 caller instance. If A.IsCastableTo(B) is true,
 casting to B object from A object (static_cast<B*>(pA)) is safe.
 
 If NULL is given, this function always return false
 regardless if the caller is the root class.

 @param  [in]   rt  runtime class instance to test
 @result    true if pClass is the ancestor of the caller.
 */
//****************************************************************/
bool MRRuntimeClass::IsCastableTo(const MRRuntimeClass* pRT) const {
    if (!pRT) {
        return false;
    }

    const MRRuntimeClass* pSrc = this;
    const MRRuntimeClass* pDst = pRT;
    do {
        if (pSrc == pDst) {
            return true;
        }
        pSrc = pSrc->m_pParent;
    } while (pSrc!=NULL);    
    return false;
}


/****************************************************************/
/*!
 @abstract   finds method in given name
 @discussion 
 Finds method in this class that has the given name.
 This method looks up parent class if inherited, and returns
 NULL if no matching method is found.
 
 Because the overloading method is chosen when parameter is given,
 although if you had multiple methods in same name, you will receive only one
 object.
 
 @param  [in]  methodName   name of method to lookup
 @result    valid MRMethod instance.
 NULL if no matching method is found.
 */
//****************************************************************/
const MRMethod* MRRuntimeClass::FindMethod(const char* methodName) const {

    mr_uint32 nItems = m_methodList.size();
    for (mr_uint32 i=0; i<nItems; ++i) {
        const MRMethod* pObj = m_methodList[i];
        if(strcmp(methodName, pObj->GetName()) == 0) {
            return pObj;
        }
    }
        
    // LOOKUP    
    if (m_pParent) {
        return m_pParent->FindMethod(methodName);
    }    
    return NULL;
}


/****************************************************************/
/*!
 @abstract   register runtime method(used by system)
 */
//****************************************************************/
void MRRuntimeClass::RegisterMethod(const MRMethodInvoker* pMethodInvoker) {
    
    mr_uint32 nItems = m_methodList.size();
    MRMethod* pSelectedMethod = NULL;
    const mr_char* pName = pMethodInvoker->GetName();
    
    for (mr_uint32 i=0; i<nItems; ++i) {
        MRMethod* pObj = m_methodList[i];
        if(strcmp(pName, pObj->GetName()) == 0) {
            pSelectedMethod = pObj;
            break;
        }
    }
    
    if (!pSelectedMethod) {
        // TODO: replace new with good memory managements
        pSelectedMethod = new MRMethod(pName);
        // TODO: SORT
        m_methodList.push_back(pSelectedMethod);
    }
    
    pSelectedMethod->RegisterInvoker(pMethodInvoker);    
}


/****************************************************************/
/*!
 @abstract   register runtime constructor(used by system)
 */
//****************************************************************/
void MRRuntimeClass::RegisterConstructor(const MRConstructorInvoker* pConstructor) {
    m_constructor.RegisterInvoker(pConstructor);
}

/****************************************************************/
/*!
 @abstract   get first iterator to MRMethod in this class
 */
//****************************************************************/
MRRuntimeClass::MethodIterator  MRRuntimeClass::MethodBegin(void) const {
    return m_methodList.begin();    
}

/****************************************************************/
/*!
 @abstract   get end of the iterator to MRMethod in this class
 */
//****************************************************************/
MRRuntimeClass::MethodIterator  MRRuntimeClass::MethodEnd(void) const {
    return m_methodList.end();
}
