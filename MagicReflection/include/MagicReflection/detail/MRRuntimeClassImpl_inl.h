/****************************************************************/
/*!
 @abstract   ￼MRRuntimeClassImpl_inl.h
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/17.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRRUNTIMECLASSIMPL_INL__
#define __MAGICREFLECTION_MRRUNTIMECLASSIMPL_INL__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
// Implementation 
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Constructor
 @param  [in]  name     class name
 @param  [in]  pClass   parent class instance
 */
//****************************************************************/
template <class T>
MR_INLINE MRRuntimeClassImpl<T>::MRRuntimeClassImpl(const mr_char* name, MRRuntimeClass* pClass) :m_pName(name), MRRuntimeClass(pClass) {    
}

/****************************************************************/
/*!
 @abstract   returns the name of this class.
 */
//****************************************************************/
template <class T>
MR_INLINE const mr_char* MRRuntimeClassImpl<T>::GetName(void) const {
    return m_pName;
}

/****************************************************************/
/*!
 @abstract   returns the name of this class.
 */
//****************************************************************/
template <class T>
MR_INLINE mr_typeid_t MRRuntimeClassImpl<T>::GetTypeID(void) const {
    return mr_typeid_static<T>();
}


/****************************************************************/
/*!
 @abstract   creates instance with default constructor
 */
//****************************************************************/
template <class T>
MR_INLINE MRDynamicPtr MRRuntimeClassImpl<T>::CreateInstance(void) const {
    MRRuntimeConstructionContext rcc;
    return CreateInstance(rcc);
}

/****************************************************************/
/*!
 @abstract   creates instance with given construction parameters
 */
//****************************************************************/
template <class T>
MR_INLINE MRDynamicPtr MRRuntimeClassImpl<T>::CreateInstance(const MRRuntimeConstructionContext& rcc) const {    
    return m_constructor.Construct(rcc);
}


/****************************************************************/
/*!
 @abstract   deletes the object properly.
 */
//****************************************************************/
template <class T>
MR_INLINE void MRRuntimeClassImpl<T>::Delete(const MRDynamicPtr& ptr) const {
    MAGICREFLECTION_ASSERT(ptr.GetRuntimeClass() == this);
    const T* pObj = (const T*)ptr.GetPtr();
        
//    pObj->~T();
    //TODO: better memory management
    delete pObj;
}

/****************************************************************/
/*!
 @abstract   Initialization
 @discussion 
 When system is initialized by MRRuntimeSystem::Initialize()
 this method is called.
 */
//****************************************************************/
template <class T>
void MRRuntimeClassImpl<T>::_Initialize(void) {
    MRRuntimeClass** pTIDHolder = (MRRuntimeClass**)(mr_typeid_static<T>());
    *pTIDHolder = this;
}


/****************************************************************/
/*!
 @abstract   Finalization
 @discussion 
 When system is initialized by MRRuntimeSystem::Finalize()
 this method is called.
 */
//****************************************************************/
template <class T>
void MRRuntimeClassImpl<T>::_Finalize(void) {
}

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRRUNTIMECLASSIMPL_INL__
