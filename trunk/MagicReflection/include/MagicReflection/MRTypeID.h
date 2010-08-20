/****************************************************************/
/*!
 @abstract   ￼MRTypeID.h
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/18.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRTYPEID_H__
#define __MAGICREFLECTION_MRTYPEID_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Impl typeid functions
//----------------------------------------------------------------

template <typename T>
MR_INLINE mr_typeid_t __mr_typeid_static() {
    static MRRuntimeClass*  __mr_s_tid_ph__;
    return (mr_typeid_t)(&__mr_s_tid_ph__);
}

template <typename T>
MR_INLINE mr_typeid_t _mr_typeid_static() {
    typedef typename MRTypeTraits<T>::PointeeType     PointeeType;
    typedef typename MRTypeTraits<T>::ReferredType    ReferredType;
    typedef typename MRTypeTraits<T>::UnqualifiedType UnqualifiedType;
    
    typedef typename MRSelectType<MRTypeTraits<T>::isReference, ReferredType, UnqualifiedType>::Result T1;
    typedef typename MRSelectType<MRTypeTraits<T>::isPointer,   PointeeType,  T1>::Result OriginalType;
    
    if (MRTypeTraits<T>::isPointer||MRTypeTraits<T>::isReference) {
        return __mr_typeid_static<OriginalType>() + 1;
    } else {
        return __mr_typeid_static<OriginalType>();
    }
}

template <>
MR_INLINE mr_typeid_t _mr_typeid_static<MRNullType>() {
    return 0;
}

template <typename T>
MR_INLINE mr_typeid_t mr_typeid_static() {
    // TODO: remove decoration(const, volatile, *, &, everything) of T
    return _mr_typeid_static<T>();
}

template <typename T>
MR_INLINE mr_typeid_t mr_typeid(const T&) {
    return _mr_typeid_static<T>();
}

MR_INLINE mr_typeid_t mr_typeid(const MRDynamicPtr& ptr) {
    if (ptr) {
        return ptr.GetRuntimeClass()->GetTypeID();
    } else {
        return _mr_typeid_static<MRNullType>();
    }
}


MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRTYPEID_H__
       //eof
