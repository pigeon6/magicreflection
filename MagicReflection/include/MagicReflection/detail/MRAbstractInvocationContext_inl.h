/****************************************************************/
/*!
 @abstract   ￼MRAbstractInvocationContext_inl.h
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/20.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

#ifndef __MAGICREFLECTION_MRABSTRACTINVOCATIONCONTEXT_INL__
#define __MAGICREFLECTION_MRABSTRACTINVOCATIONCONTEXT_INL__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
// Implementation 
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Set parameter
 @discussion 
 SetParameter sets the parameter to pass method/function/constructor
 to invoke.
 
 @param  [in]  n    index of parameter to set. Begins with 0
 @param  [in]  val  the value of parameter to set. 
 @result
 */
//****************************************************************/
template< typename T>
MR_INLINE void MRAbstractInvocationContext::SetParameter(mr_uint32 n, T val) {
    MAGICREFLECTION_ASSERT(n<MR_MAX_PARAM_NUM);
    m_params[n].Set(val);
    m_strictTypes[n] = mr_typeid_static<T>();
    if (n+1 > m_nParams) {
        m_nParams = n+1;
    }
}

template< typename T>
MR_INLINE void MRAbstractInvocationContext::SetParameter(mr_uint32 n, T* val) {
    SetParameter(n, (const T*)val);
}

template< typename T>
MR_INLINE void MRAbstractInvocationContext::SetParameter(mr_uint32 n, const T* val) {
    MAGICREFLECTION_ASSERT(n<MR_MAX_PARAM_NUM);
    m_params[n].Set(val);
    if (val==NULL) {
        m_nullFlag |= (1<<n);
        m_strictTypes[n] = (mr_typeid_t)-1; // (0xffffffffL or 0xffffffffffffffffLL)
        m_looseTypes[n]  = (mr_typeid_t)-1;
    } else {
        m_strictTypes[n] = mr_typeid(val);
        m_looseTypes[n]  = m_strictTypes[n];
    }

    if (n+1 > m_nParams) {
        m_nParams = n+1;
    }
}

MR_INLINE void MRAbstractInvocationContext::SetParameter(mr_uint32 n, const MRDynamicPtr& val) {
    MAGICREFLECTION_ASSERT(n<MR_MAX_PARAM_NUM);    
    m_rtParams[n] = val;
    m_rcFlag |= (1<<n);
    if (!val) {
        m_nullFlag |= (1<<n);
        m_strictTypes[n] = (mr_typeid_t)-1; // (0xffffffffL or 0xffffffffffffffffLL)
        m_looseTypes[n]  = (mr_typeid_t)-1;
    } else {
        m_strictTypes[n] = val.GetRuntimeClass()->GetTypeID();
        m_looseTypes[n]  = m_strictTypes[n];
    }
    if (n+1 > m_nParams) {
        m_nParams = n+1;
    }
}


/****************************************************************/
/*!
 @abstract   Reset Context
 @discussion 
 reset context to initial state to reuse this context object. 
 */
//****************************************************************/
MR_INLINE void MRAbstractInvocationContext::Reset(void) {
    m_rcFlag    = 0;
    m_nullFlag  = 0;
    m_nParams   = 0;
}


/****************************************************************/
/*!
 @abstract   Get parameter
 @discussion 
 GetParamAt retrieves the parameter from this context.
 This method is designed to be used by system and rarely valuable
 to user.
 
 @param  [in]  n    index of parameter to retrieve. Begins with 0
 @result    value in T format.
 */
//****************************************************************/
template<typename T>
MR_INLINE T* MRAbstractInvocationContext::GetParamAt(mr_uint32 n) const {    
    if (m_rcFlag & (1<<n)) {
        // type test should be done already.
        return (T*)m_rtParams[n].GetPtr();
    } else {
        return m_params[n].Get<T>();
    }
}

/****************************************************************/
/*!
 @abstract   Get list of type ids in strict form.
 @discussion 
 GetStrictTypeIDList returns list of typeid of current parameters. 
 This method is designed to be used by system and rarely valuable
 to user.
 */
//****************************************************************/
MR_INLINE const mr_typeid_t* MRAbstractInvocationContext::GetStrictTypeIDList(void) const {
    return &m_strictTypes[0];
}

/****************************************************************/
/*!
 @abstract   Get list of type ids in strict form.
 @discussion 
 GetStrictTypeIDList returns list of typeid of current parameters. 
 This method is designed to be used by system and rarely valuable
 to user.
 */
//****************************************************************/
MR_INLINE const mr_typeid_t* MRAbstractInvocationContext::GetLooseTypeIDList(void) const {
    return &m_looseTypes[0];    
}


MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRABSTRACTINVOCATIONCONTEXT_INL__
