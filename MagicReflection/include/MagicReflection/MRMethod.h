/****************************************************************/
/*!
 @abstract   ￼MRMethod.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRMETHOD_H__
#define __MAGICREFLECTION_MRMETHOD_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Dependencies
//----------------------------------------------------------------
class MRMethodInvoker;
class MRMethodInvocationContext;

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
class MRMethod {
    typedef MRVector<const MRMethodInvoker*>    MethodInvokerList;
    
    MethodInvokerList   m_invokers;     ///< list of method invokers
    const mr_char*      m_methodName;   ///< method name in string
    
public:
    explicit MRMethod(const mr_char* methodName);
    ~MRMethod();
    
    void RegisterInvoker(const MRMethodInvoker* pInvoker);
    bool Invoke(MRMethodInvocationContext& mic) const;
    const mr_char* GetName(void) const;
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRMETHOD_H__
//eof
