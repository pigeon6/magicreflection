/****************************************************************/
/*!
 @abstract   ￼MRMethod.cpp
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
// Implementation (MRMethod)
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Constructor 
 @param  [in]  methodName   name of the method in string
 */
//****************************************************************/
MRMethod::MRMethod(const mr_char* methodName) :m_methodName(methodName) {
}

/****************************************************************/
/*!
 @abstract   Destructor
 */
//****************************************************************/
MRMethod::~MRMethod() {}


/****************************************************************/
/*!
 @abstract   
 @discussion 
 
 @param  [in, out]  
 @result
 */
//****************************************************************/
void MRMethod::RegisterInvoker(const MRMethodInvoker* pInvoker) {

    // todo: SORT by # of parameters
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
bool MRMethod::Invoke(MRMethodInvocationContext& mic) const {
    
    mr_uint32 nItems = m_invokers.size();
    for (mr_uint32 i = 0; i < nItems; ++i) {
        const MRMethodInvoker* pMI = m_invokers[i];
        
        // TODO: needs fix (optimize, filter out some invoker)
        if(pMI->Invoke(mic)) {
            return true;
        }
    }

    return false;
}


/****************************************************************/
/*!
 @abstract   
 @discussion 
 
 @param  [in, out]  
 @result
 */
//****************************************************************/
const mr_char* MRMethod::GetName(void) const {
    return m_methodName;
}
