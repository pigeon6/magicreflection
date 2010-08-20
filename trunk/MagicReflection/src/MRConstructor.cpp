/****************************************************************/
/*!
 @abstract   ￼MRConstructor.cpp
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/19.
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
// Implementation (MRConstructor)
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   register constructor invoker
 @param  [in]  pInvoker     invoker object to register
 */
//****************************************************************/
void MRConstructor::RegisterInvoker(const MRConstructorInvoker* pInvoker) {
    m_invokers.push_back(pInvoker);
}


/****************************************************************/
/*!
 @abstract   
 @discussion 
 
 @param  [in, out]  
 @result
 */
//****************************************************************/
MRDynamicPtr MRConstructor::Construct(const MRRuntimeConstructionContext& rcc) const {
    
    mr_uint32 nItems = m_invokers.size();
    for (mr_uint32 i = 0; i < nItems; ++i) {
        const MRConstructorInvoker* pCI = m_invokers[i];
        MRDynamicPtr pObj = pCI->Construct(rcc);
        
        // TODO: needs fix (optimize, filter out some invoker)
        if(pObj) {
            return pObj;
        }
    }
    
    return MRDynamicPtr(NULL,NULL);
}

