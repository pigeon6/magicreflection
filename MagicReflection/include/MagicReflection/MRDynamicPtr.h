/****************************************************************/
/*!
 @abstract   ￼MRDynamicPtr.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRDYNAMICPTR_H__
#define __MAGICREFLECTION_MRDYNAMICPTR_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Dependencies
//----------------------------------------------------------------
class MRRuntimeClass;
class MRMethod;

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Dynamic Pointer
 @discussion 
 MRDynamicPtr is a pointer with attributed by MRRuntimeClass.
 
 */
//****************************************************************/
class MRDynamicPtr {
    const MRRuntimeClass      *m_pClass;    ///< runtime class
    void*                      m_pObj;      ///< object
public:
    // for performance reason, default constructor/destructor 
    // does not do anything.
    explicit MRDynamicPtr() {}
    ~MRDynamicPtr() {}

    explicit MRDynamicPtr(const MRRuntimeClass* pRC, void* pObj): m_pClass(pRC), m_pObj(pObj) {}

    MRDynamicPtr& operator=(const MRDynamicPtr& rhs);

    operator bool () const;
    bool operator ! () const;
    bool operator==(const MRDynamicPtr& rhs) const;
    bool operator!=(const MRDynamicPtr& rhs) const;
    bool operator<(const MRDynamicPtr& rhs) const;
    
    const MRRuntimeClass* GetRuntimeClass(void) const;
    void* GetPtr(void);
    const void* GetPtr(void) const;
    const void Delete(void);
    const void SafeDelete(void);
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRDYNAMICPTR_H__
//eof
