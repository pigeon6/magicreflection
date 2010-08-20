/****************************************************************/
/*!
 @abstract   ￼MagicReflection_DefineMethod.h
 @discussion ￼
 
 This is the header that should be included only when you define
 dynamic method.
 If you include this header to every source file in your project,
 you may experience significant slowdown in compilation speed.
 
 Created by Hiroki Omae on 2010/08/18.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

#ifndef __MAGICREFLECTION_DEFINEMETHOD_H__
#define __MAGICREFLECTION_DEFINEMETHOD_H__

#include "MagicReflection.h"

//----------------------------------------------------------------
// Macro for Defininig Method/Constructor
//----------------------------------------------------------------
#define MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, parameterTypeList)        \
static MR_NS(MRMethodInvokerImpl)<className, returnType, parameterTypeList, false>      \
MR_UNIQUENAME(__mr_s_method_)(#funcName, &className::funcName);

#define MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, parameterTypeList)  \
static MR_NS(MRMethodInvokerImpl)<className, returnType, parameterTypeList, true>       \
MR_UNIQUENAME(__mr_s_method_)(#funcName, &className::funcName);

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, parameterTypeList)       \
static MR_NS(MRConstructorInvokerImpl)<className, parameterTypeList>      \
MR_UNIQUENAME(__mr_s_ctor_);

// param 0
#define MR_DEFINE_DYNAMIC_METHOD_0(className, returnType, funcName)     \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_VOID)
#define MR_DEFINE_DYNAMIC_METHOD_CONST_0(className, returnType, funcName)     \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_VOID)
#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_0(className)     \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_VOID)

// param 1...
#if (MR_MAX_PARAM_NUM >= 1)
#define MR_DEFINE_DYNAMIC_METHOD_1(className,  returnType, funcName, p0) \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_1(p0))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_1(className,  returnType, funcName, p0) \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_1(p0))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_1(className,  p0) \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_1(p0))
#endif

#if (MR_MAX_PARAM_NUM >= 2)
#define MR_DEFINE_DYNAMIC_METHOD_2(className,  returnType, funcName, p0, p1) \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_2(p0, p1))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_2(className,  returnType, funcName, p0, p1) \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_2(p0, p1))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_2(className,  p0, p1) \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_2(p0, p1))
#endif

#if (MR_MAX_PARAM_NUM >= 3)
#define MR_DEFINE_DYNAMIC_METHOD_3(className,  returnType, funcName, p0, p1, p2) \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_3(p0, p1, p2))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_3(className,  returnType, funcName, p0, p1, p2) \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_3(p0, p1, p2))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_3(className,  p0, p1, p2) \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_3(p0, p1, p2))
#endif

#if (MR_MAX_PARAM_NUM >= 4)
#define MR_DEFINE_DYNAMIC_METHOD_4(className,  returnType, funcName, p0, p1, p2, p3) \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_4(p0, p1, p2, p3))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_4(className,  returnType, funcName, p0, p1, p2, p3) \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_4(p0, p1, p2, p3))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_4(className,  p0, p1, p2, p3) \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_4(p0, p1, p2, p3))
#endif

#if (MR_MAX_PARAM_NUM >= 5)
#define MR_DEFINE_DYNAMIC_METHOD_5(className,  returnType, funcName, p0, p1, p2, p3, p4) \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_5(p0, p1, p2, p3, p4))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_5(className,  returnType, funcName, p0, p1, p2, p3, p4) \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_5(p0, p1, p2, p3, p4))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_5(className,  p0, p1, p2, p3, p4) \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_5(p0, p1, p2, p3, p4))
#endif

#if (MR_MAX_PARAM_NUM >= 6)
#define MR_DEFINE_DYNAMIC_METHOD_6(className,  returnType, funcName, p0, p1, p2, p3, p4, p5) \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_6(p0, p1, p2, p3, p4, p5))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_6(className,  returnType, funcName, p0, p1, p2, p3, p4, p5) \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_6(p0, p1, p2, p3, p4, p5))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_6(className,  p0, p1, p2, p3, p4, p5) \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_6(p0, p1, p2, p3, p4, p5))
#endif

#if (MR_MAX_PARAM_NUM >= 7)
#define MR_DEFINE_DYNAMIC_METHOD_7(className,  returnType, funcName, p0, p1, p2, p3, p4, p5, p6) \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_7(p0, p1, p2, p3, p4, p5, p6))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_7(className,  returnType, funcName, p0, p1, p2, p3, p4, p5, p6) \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_7(p0, p1, p2, p3, p4, p5, p6))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_7(className,  p0, p1, p2, p3, p4, p5, p6) \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_7(p0, p1, p2, p3, p4, p5, p6))
#endif

#if (MR_MAX_PARAM_NUM >= 8)
#define MR_DEFINE_DYNAMIC_METHOD_8(className,  returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7) \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_8(p0, p1, p2, p3, p4, p5, p6, p7))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_8(className,  returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7) \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_8(p0, p1, p2, p3, p4, p5, p6, p7))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_8(className,  p0, p1, p2, p3, p4, p5, p6, p7) \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_8(p0, p1, p2, p3, p4, p5, p6, p7))
#endif

#if (MR_MAX_PARAM_NUM >= 9)
#define MR_DEFINE_DYNAMIC_METHOD_9(className,  returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8) \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_9(p0, p1, p2, p3, p4, p5, p6, p7, p8))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_9(className,  returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8) \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_9(p0, p1, p2, p3, p4, p5, p6, p7, p8))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_9(className,  p0, p1, p2, p3, p4, p5, p6, p7, p8) \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_9(p0, p1, p2, p3, p4, p5, p6, p7, p8))
#endif

#if (MR_MAX_PARAM_NUM >= 10)
#define MR_DEFINE_DYNAMIC_METHOD_10(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)    \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_10(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_10(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)    \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_10(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_10(className, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)    \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_10(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9))
#endif

#if (MR_MAX_PARAM_NUM >= 11)
#define MR_DEFINE_DYNAMIC_METHOD_11(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10)    \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_11(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_11(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10)    \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_11(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_11(className, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10)    \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_11(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10))
#endif

#if (MR_MAX_PARAM_NUM >= 12)
#define MR_DEFINE_DYNAMIC_METHOD_12(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)    \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_12(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_12(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)    \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_12(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_12(className, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)    \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_12(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11))
#endif

#if (MR_MAX_PARAM_NUM >= 13)
#define MR_DEFINE_DYNAMIC_METHOD_13(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)    \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_13(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_13(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)    \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_13(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_13(className, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)    \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_13(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12))
#endif

#if (MR_MAX_PARAM_NUM >= 14)
#define MR_DEFINE_DYNAMIC_METHOD_14(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)    \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_14(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_14(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)    \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_14(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_14(className, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13)    \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_14(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13))
#endif

#if (MR_MAX_PARAM_NUM >= 15)
#define MR_DEFINE_DYNAMIC_METHOD_15(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14)    \
MR_DEFINE_DYNAMIC_METHOD(className, returnType, funcName, MR_TL_15(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14))

#define MR_DEFINE_DYNAMIC_METHOD_CONST_15(className, returnType, funcName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14)    \
MR_DEFINE_DYNAMIC_METHOD_CONST(className, returnType, funcName, MR_TL_15(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14))

#define MR_DEFINE_DYNAMIC_CONSTRUCTOR_15(className, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14)    \
MR_DEFINE_DYNAMIC_CONSTRUCTOR(className, MR_TL_15(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14))
#endif


#endif //__MAGICREFLECTION_DEFINEMETHOD_H__
       //eof
