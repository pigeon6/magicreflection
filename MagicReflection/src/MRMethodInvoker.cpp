/****************************************************************/
/*!
 @abstract   ￼MRMethodInvoker.cpp
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
// Implementation (MRMethodInvoker)
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Constructor
 @discussion 
 MRMethodInvoker object is basically defined as static object.
 in object construction, it creates the single directional list
 to be able to initialize later. 
 */
//****************************************************************/
MRMethodInvoker::MRMethodInvoker()  {
    m_initList = MRRuntimeSystemImpl::s_initListHead_MethodInvoker;
    MRRuntimeSystemImpl::s_initListHead_MethodInvoker = this;    
}

/****************************************************************/
/*!
 @abstract   Destructor
 */
//****************************************************************/
MRMethodInvoker::~MRMethodInvoker() {}


