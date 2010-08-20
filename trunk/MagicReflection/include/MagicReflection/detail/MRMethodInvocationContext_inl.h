/****************************************************************/
/*!
 @abstract   ￼MRMethodInvocationContext_inl.h
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/20.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

#ifndef __MAGICREFLECTION_MRMETHODINVOCATIONCONTEXT_INL__
#define __MAGICREFLECTION_MRMETHODINVOCATIONCONTEXT_INL__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
// Implementation 
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   
 @discussion 
 
 @param  [in, out]  
 @result
 */
//****************************************************************/
MR_INLINE bool MRMethodInvocationContext::Invoke(void) {
    MAGICREFLECTION_ASSERT(m_pMethod!=NULL);
    return m_pMethod->Invoke(*this);
}

/****************************************************************/
/*!
 @abstract   return caller of the method
 */
//****************************************************************/
MR_INLINE MRDynamicPtr& MRMethodInvocationContext::GetCaller(void) {
    return m_caller;
}


/****************************************************************/
/*!
 @abstract   get return value in given type T
 @discussion
 This method retrieves the return value of called method.
 If the method return type were void, return value is undefined.
 
 If you are not sure what the return type is, you can check it 
 through IsReturnType*() method. You can also use GetReturnValueTypeID()
 and see if return value is in certain type you know.
 
 if you try to retrieve return value in wrong format, the result 
 will be undefined. (in debug, MR assertion fails)
 */
//****************************************************************/

template<typename T>
MR_INLINE T MRMethodInvocationContext::GetReturnValue(void) const {
    return *m_retval.Get<T>();
}


/****************************************************************/
/*!
 @abstract   get pointer to return value in given type T
 @discussion
    This method returns the pointer to the return type.
 If you want to retrieve large object, this method may interest
 you. If IsReturnValuePtr() == true and want to retrieve value
 in pointer form, simply use GetReturnValue<T*>() instead.

 If the method return type were void, return value is undefined.
*/
//****************************************************************/
template<typename T>
MR_INLINE T* MRMethodInvocationContext::GetReturnValuePtr(void) const {
    return m_retval.Get<T>();
}

/****************************************************************/
/*!
 @abstract   return whether return value is primitive type
 */
//****************************************************************/
MR_INLINE bool MRMethodInvocationContext::IsReturnValuePrimitive(void) const {
    return m_retval.IsPrimitive();
}

/****************************************************************/
/*!
 @abstract   return whether return value is pointer type
 */
//****************************************************************/
MR_INLINE bool MRMethodInvocationContext::IsReturnValuePtr(void) const {
    return m_retval.IsPointer();
}

/****************************************************************/
/*!
 @abstract   return whether return value is object type
 */
//****************************************************************/
MR_INLINE bool MRMethodInvocationContext::IsReturnValueObject(void) const {
    return m_retval.IsObject();    
}

/****************************************************************/
/*!
 @abstract   return whether return value is void
 */
//****************************************************************/
MR_INLINE bool MRMethodInvocationContext::IsReturnValueVoid(void) const {
    return m_rtTypeID == mr_typeid_static<MRNullType>();
}


/****************************************************************/
/*!
 @abstract   set return value to this context
 @discussion
 Sets return value to this context.
  this method is used by system.
 */
//****************************************************************/
template<typename T>
MR_INLINE void MRMethodInvocationContext::SetReturnValue(const T& val) {
    m_retval.Set<T>(val);
    m_rtTypeID = mr_typeid_static<T>();
}

/****************************************************************/
/*!
 @abstract   set return value to this context as void
 @discussion
 Sets return value to this context as void.
 this method is used by system.
 */
//****************************************************************/
MR_INLINE void MRMethodInvocationContext::SetReturnValueVoid() {
    m_rtTypeID = mr_typeid_static<MRNullType>();
}

/****************************************************************/
/*!
 @abstract   get typeid of return value
 @discussion
 This method returns the typeid of return value.
 */
//****************************************************************/
MR_INLINE mr_typeid_t MRMethodInvocationContext::GetReturnValueTypeID(void) const {
    return m_rtTypeID;
}


MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRMETHODINVOCATIONCONTEXT_INL__
