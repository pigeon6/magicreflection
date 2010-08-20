/****************************************************************/
/*!
 @abstract   ￼MRDynamicPtr_inl.cpp
 @discussion ￼ 
 Inline implementations of MRDynamicPtr
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRDYNAMICPTR_INL__
#define __MAGICREFLECTION_MRDYNAMICPTR_INL__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   copy operator
 @param  [in]  rhs  right hand side of =
 */
//****************************************************************/
MR_INLINE MRDynamicPtr& MRDynamicPtr::operator=(const MRDynamicPtr& rhs) {
    m_pClass = rhs.m_pClass;
    m_pObj   = rhs.m_pObj;
    return *this;
}


/****************************************************************/
/*!
 @abstract   compare operator(==)
 @param  [in]  rhs  right hand side of ==
 */
//****************************************************************/
MR_INLINE bool MRDynamicPtr::operator==(const MRDynamicPtr& rhs) const {
    return m_pObj == rhs.m_pObj;
}

/****************************************************************/
/*!
 @abstract   compare operator(!=)
 @param  [in]  rhs  right hand side of !=
 */
//****************************************************************/
MR_INLINE bool MRDynamicPtr::operator!=(const MRDynamicPtr& rhs) const {
    return m_pObj != rhs.m_pObj;    
}

/****************************************************************/
/*!
 @abstract   operator less(<)
 @param  [in]  rhs  right hand side of <
 */
//****************************************************************/
MR_INLINE bool MRDynamicPtr::operator<(const MRDynamicPtr& rhs) const {
    return m_pObj < rhs.m_pObj;
}

/****************************************************************/
/*!
 @abstract   (obj) returns true if pointer is valid
 */
//****************************************************************/
MR_INLINE MRDynamicPtr::operator bool () const {
    return m_pObj!=NULL;
}

/****************************************************************/
/*!
 @abstract   (!obj) returns true if pointer is invalid
 */
//****************************************************************/
MR_INLINE bool MRDynamicPtr::operator ! () const {
    return m_pObj==NULL;        
}

/****************************************************************/
/*!
 @abstract   returns runtime class of this pointer
 */
//****************************************************************/
MR_INLINE const MRRuntimeClass* MRDynamicPtr::GetRuntimeClass(void) const {
    return m_pClass;
}

/****************************************************************/
/*!
 @abstract   returns pointer to object
 */
//****************************************************************/
MR_INLINE void* MRDynamicPtr::GetPtr(void) {
    return m_pObj;
}

/****************************************************************/
/*!
 @abstract   returns pointer to object(const)
 */
//****************************************************************/
MR_INLINE const void* MRDynamicPtr::GetPtr(void) const {
    return m_pObj;
}

/****************************************************************/
/*!
 @abstract   Deletes this object
 */
//****************************************************************/
MR_INLINE const void MRDynamicPtr::Delete(void) {
    m_pClass->Delete(*this);
}

/****************************************************************/
/*!
 @abstract   Deletes this object if pointer is valid.
 */
//****************************************************************/
MR_INLINE const void MRDynamicPtr::SafeDelete(void) {
    if (m_pObj) {
        m_pClass->Delete(*this);
        m_pObj = NULL;
    }
}

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRDYNAMICPTR_INL__
//eof
