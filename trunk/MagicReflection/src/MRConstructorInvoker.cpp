/****************************************************************/
/*!
 @abstract   ￼MRConstructorInvoker.cpp
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

//----------------------------------------------------------------
// Namespace Dependencies
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_USE;


//----------------------------------------------------------------
// Implementation (MRConstructorInvoker)
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Constructor
 @discussion 
 MRConstructorInvoker object is basically defined as static object.
 in object construction, it creates the single directional list
 to be able to initialize later.
 
 @param  [in]  methodName   name of the method in string
 */
//****************************************************************/
MRConstructorInvoker::MRConstructorInvoker() {
    m_initList = MRRuntimeSystemImpl::s_initListHead_ConstructorInvoker;
    MRRuntimeSystemImpl::s_initListHead_ConstructorInvoker = this;
}

/****************************************************************/
/*!
 @abstract   Destructor
 */
//****************************************************************/
MRConstructorInvoker::~MRConstructorInvoker() {
}


