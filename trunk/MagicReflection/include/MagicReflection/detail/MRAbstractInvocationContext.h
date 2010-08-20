/****************************************************************/
/*!
 @abstract   ￼MRAbstractInvocationContext.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/20.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRABSTRACTINVOCATIONCONTEXT_H__
#define __MAGICREFLECTION_MRABSTRACTINVOCATIONCONTEXT_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Dependencies
//----------------------------------------------------------------
class MRMethod;

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Invocation Context
 @discussion 
 MRAbstractInvocationContext is the base class of 
 MRMethodInvocationContext and MRRuntimeConstructionContext.
 
 It does basic stuff to hold given parameter and pass it to
 MethodInvoker/ConstructorInvoker family classes.
 */
//****************************************************************/
class MRAbstractInvocationContext {
    
    MRMightyType    m_params[MR_MAX_PARAM_NUM];       ///< parameters
    MRDynamicPtr    m_rtParams[MR_MAX_PARAM_NUM];     ///< runtime parameters
    mr_typeid_t     m_strictTypes[MR_MAX_PARAM_NUM];  ///< parameter types
    mr_typeid_t     m_looseTypes[MR_MAX_PARAM_NUM];   ///< parameter types
    
    mr_uint32       m_rcFlag;           ///< whether param(n) is dynamic type
    mr_uint32       m_nullFlag;         ///< whether param(n) is null
    mr_uint32       m_nParams;          ///< number of parameters set currently.
    
public:
    explicit MRAbstractInvocationContext(void) : m_rcFlag(0), m_nullFlag(0), m_nParams(0) {}
    ~MRAbstractInvocationContext() {}
    
    template< typename T>
    void SetParameter(mr_uint32 n, T val);
    template< typename T>
    void SetParameter(mr_uint32 n, T* val);
    template< typename T>
    void SetParameter(mr_uint32 n, const T* val);
    void SetParameter(mr_uint32 n, const MRDynamicPtr& val);

    void Reset(void);
    
    template<typename T>
    T* GetParamAt(mr_uint32 n) const;
    const mr_typeid_t* GetStrictTypeIDList(void) const;
    const mr_typeid_t* GetLooseTypeIDList(void) const;
    
    mr_uint32 GetParamNum(void) const {
        return m_nParams;
    }

    mr_uint32 GetRCFlag(void) const {
        return m_rcFlag;
    }

    mr_uint32 GetNullFlag(void) const {
        return m_nullFlag;
    }
    const MRDynamicPtr* GetRCPtrs(void) const {
        return &m_rtParams[0];
    }
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRABSTRACTINVOCATIONCONTEXT_H__
       //eof
