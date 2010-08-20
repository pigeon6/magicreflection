/****************************************************************/
/*!
 @abstract   ￼MRDynamicCast.h
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/18.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRDYNAMICCAST_H__
#define __MAGICREFLECTION_MRDYNAMICCAST_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Impl(non dynamic cast functions)
//----------------------------------------------------------------
template <typename T>
MR_INLINE const MRRuntimeClass* MRGetRuntimeClass(void) {
    return *(const MRRuntimeClass**)(mr_typeid_static<T>() & MR_TID_MASK);
}
template <>
MR_INLINE const MRRuntimeClass* MRGetRuntimeClass<MRNullType>(void) {
    return NULL;
}


//----------------------------------------------------------------
//Impl(dynamic cast functions)
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Dynamic Cast(from certain type)
 @discussion 
 test and cast to given type DST from given type SRC.
 Both DST and SRC type must be type of dyanmic class
 which means class has MR_DECL_DYNAMIC() in its definition.
 If DST or SRC were not dynamic class, mr_dynamic_cast can not be compiled.
 
 @param  [in]  pObj pointer to object that perform dynamic cast from.
 @result
 valid pointer in DST* form.
 NULL if cast failed.
 */
//****************************************************************/
template <typename DST, typename SRC>
MR_INLINE DST* mr_dynamic_cast(SRC* pObj) {
    if (pObj==NULL) {
        return NULL;
    }
    const MRRuntimeClass* pSrc = pObj->__MR_GetRuntimeClass();
    
    if(pSrc->IsCastableTo(MRGetRuntimeClass<DST>())){
        return (DST*)pObj;
    } else {
        return NULL;
    }
}

/****************************************************************/
/*!
 @abstract   Dynamic Cast(from MRDynamicPtr)
 @discussion 
    test and cast to given type from MRDynamicPtr.
 
 @param  [in]  pObj pointer to object that perform dynamic cast from.
 @result
            valid pointer in DST* form.
            NULL if cast failed.
 */
//****************************************************************/
template <typename DST>
MR_INLINE DST* mr_dynamic_cast(MRDynamicPtr& pObj) {
    if (!pObj) {
        return NULL;
    }
    const MRRuntimeClass* pSrc = pObj.GetRuntimeClass();
    
    if(pSrc->IsCastableTo(MRGetRuntimeClass<DST>())){
        return (DST*)pObj.GetPtr();
    } else {
        return NULL;
    }
}

template <typename DST>
MR_INLINE const DST* mr_dynamic_cast(const MRDynamicPtr& pObj) {
    if (!pObj) {
        return NULL;
    }
    const MRRuntimeClass* pSrc = pObj.GetRuntimeClass();
    
    if(pSrc->IsCastableTo(MRGetRuntimeClass<DST>())){
        return (const DST*)pObj.GetPtr();
    } else {
        return NULL;
    }
}

//----------------------------------------------------------------
//Impl(fast dynamic cast functions)
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Fast dynamic Cast(from certain type)
 @discussion 
 Fast dynamic cast is mostly equivarent to regular mr_dynamic_cast,
 except that it will be static cast in release mode, and fire assert
 on debug mode when cast failed.
 
 It is useful when you know the cast will success and want to
 avoid checks in production release.
  
 @param  [in]  pObj pointer to object that perform dynamic cast from.
 @result   valid pointer in DST* form.(this function doesn't fail)
 */
//****************************************************************/
template <typename DST, typename SRC>
MR_INLINE DST* mr_fast_dynamic_cast(SRC* pObj) {
    MAGICREFLECTION_ASSERT(pObj!=NULL);
#ifndef MR_RELEASE
    // debug mode
    const MRRuntimeClass* pSrc = pObj->__MR_GetRuntimeClass();    
    MAGICREFLECTION_ASSERT( pSrc->IsCastableTo(MRGetRuntimeClass<DST>()) );    
#endif
    return (DST*)pObj;
}

/****************************************************************/
/*!
 @abstract   Fast Dynamic Cast(from MRDynamicPtr)
 @discussion 
 Fast dynamic cast is mostly equivarent to regular mr_dynamic_cast,
 except that it will be static cast in release mode, and fire assert
 on debug mode when cast failed.
 
 It is useful when you know the cast will success and want to
 avoid checks in production release.
 
 @param  [in]  pObj pointer to object that perform dynamic cast from.
 @result   valid pointer in DST* form. (this function doesn't fail)
 */
//****************************************************************/
template <typename DST>
MR_INLINE DST* mr_fast_dynamic_cast(MRDynamicPtr& pObj) {
    MAGICREFLECTION_ASSERT((bool)pObj);
#ifndef MR_RELEASE
    // debug mode
    const MRRuntimeClass* pSrc = pObj.GetRuntimeClass();
    MAGICREFLECTION_ASSERT( pSrc->IsCastableTo(MRGetRuntimeClass<DST>()) );    
#endif
    return (DST*)pObj.GetPtr();
}

template <typename DST>
MR_INLINE const DST* mr_fast_dynamic_cast(const MRDynamicPtr& pObj) {
    MAGICREFLECTION_ASSERT((bool)pObj);
#ifndef MR_RELEASE
    // debug mode
    const MRRuntimeClass* pSrc = pObj.GetRuntimeClass();
    MAGICREFLECTION_ASSERT( pSrc->IsCastableTo(MRGetRuntimeClass<DST>()) );    
#endif
    return (DST*)pObj.GetPtr();
}



MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRDYNAMICCAST_H__
       //eof
