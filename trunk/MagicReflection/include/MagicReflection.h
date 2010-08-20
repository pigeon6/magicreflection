/****************************************************************/
/*!
 @abstract   ￼MagicReflection.h
 @discussion ￼
            
 This is the only header that user should include for most purposes.
 However, when you define dynamic method, you need to include a separate
 header "MagicReflection_DefineMethod.h>.
 
 Created by Hiroki Omae on 2010/08/18.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

#ifndef __MAGICREFLECTION_H__
#define __MAGICREFLECTION_H__

#include "MagicReflection/config.h" 

#include "MagicReflection/detail/loki/MRNullType.h"
#include "MagicReflection/detail/loki/MRTypeManip.h"
#include "MagicReflection/detail/loki/MRTypelistMacros.h"
#include "MagicReflection/detail/loki/MRTypelist.h"
#include "MagicReflection/detail/loki/MRTypeTraits.h"

#include "MagicReflection/detail/MRStaticAssert.h"
#include "MagicReflection/detail/MRLooseType.h"
#include "MagicReflection/detail/MRMightyType.h"
#include "MagicReflection/detail/MRMethodTypeConstructor.h"
#include "MagicReflection/detail/MRDefines.h"
#include "MagicReflection/MRDynamicPtr.h"
#include "MagicReflection/MRConstructor.h"
#include "MagicReflection/MRRuntimeClass.h"
#include "MagicReflection/MRMethod.h"
#include "MagicReflection/detail/MRMethodInvoker.h"
#include "MagicReflection/detail/MRConstructorInvoker.h"
#include "MagicReflection/MRRuntimeSystem.h"

#include "MagicReflection/detail/MRRuntimeClassImpl.h"
#include "MagicReflection/detail/MRMethodInvokerImpl.h"
#include "MagicReflection/detail/MRConstructorInvokerImpl.h"
#include "MagicReflection/detail/MRAbstractInvocationContext.h"
#include "MagicReflection/MRMethodInvocationContext.h"
#include "MagicReflection/MRRuntimeConstructionContext.h"

#include "MagicReflection/MRTypeID.h"
#include "MagicReflection/MRDynamicCast.h"

//#include "detail/MRPrimitiveSupport.h>

// inline impl
#include "MagicReflection/detail/MRDynamicPtr_inl.h"
#include "MagicReflection/detail/MRRuntimeClassImpl_inl.h"
#include "MagicReflection/detail/MRMethodInvokerImpl_inl.h"
#include "MagicReflection/detail/MRConstructorInvokerImpl_inl.h"

#include "MagicReflection/detail/MRAbstractInvocationContext_inl.h"
#include "MagicReflection/detail/MRMethodInvocationContext_inl.h"
#include "MagicReflection/detail/MRRuntimeConstructionContext_inl.h"

#endif //__MAGICREFLECTION_MRCLASS_H__
//eof
