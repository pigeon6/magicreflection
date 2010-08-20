/****************************************************************/
/*!
 @abstract   ￼MRMethodInvoker.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRMETHODINVOKER_H__
#define __MAGICREFLECTION_MRMETHODINVOKER_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Dependencies
//----------------------------------------------------------------

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Method
 @discussion 
 MRMethod is the representation of an executable method.
 It supports method invocation, overloading.
 
 */
//****************************************************************/
class MRMethodInvoker {
    friend class MRRuntimeSystemImpl;
    
    MRMethodInvoker*   m_initList; ///< initialization chain

protected:
    virtual void _Initialize(void) = 0;
    virtual void _Finalize(void) = 0;
    
public:
    explicit MRMethodInvoker();
    virtual ~MRMethodInvoker();
    
    virtual const mr_char* GetName(void) const = 0;
    virtual bool Invoke(MRMethodInvocationContext& mic) const = 0;
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRMETHODINVOKER_H__
//eof
