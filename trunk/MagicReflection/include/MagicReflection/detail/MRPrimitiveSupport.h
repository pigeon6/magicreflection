/****************************************************************/
/*!
 @abstract   ￼MRPrimitiveSupport.h
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/18.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

#ifndef __MAGICREFLECTION_MRPRIMITIVESUPPORT_H__
#define __MAGICREFLECTION_MRPRIMITIVESUPPORT_H__

//----------------------------------------------------------------
// Primitive Support
//----------------------------------------------------------------
/*
 This is the primitive support header for MagicReflection.
 If you want to add any primitive(or POD) type to be supported,
 you can edit 2 part to do it.
 
 1. edit list below to add the type you want to support.
 2. edit list in MRPrimitiveSupport.cpp in the same manner.
 */

#define MR_GET_RUNTIME_CLASS_PRIMITIVE(t)                           \
template <>                                                         \
MR_INLINE const MRRuntimeClass* MRGetRuntimeClass<t>(void) {        \
return &MRRuntimeClassPrimitiveHelper<t>::__mr_s_rt_class__;    \
}

//TODO:
#define MR_DECLARE_PRIMITIVE_SUPPORT_(t)

#define MR_DECLARE_PRIMITIVE_SUPPORT(t)         \
    MR_DECLARE_PRIMITIVE_SUPPORT_(t)            \
    MR_DECLARE_PRIMITIVE_SUPPORT_(const t)      \
    MR_DECLARE_PRIMITIVE_SUPPORT_(t*)           \
    MR_DECLARE_PRIMITIVE_SUPPORT_(const t*)     \
    MR_DECLARE_PRIMITIVE_SUPPORT_(t&)           \
    MR_DECLARE_PRIMITIVE_SUPPORT_(const t&)



//----------------------------------------------------------------
//Primitive Support for runtime class
//----------------------------------------------------------------
MR_DECLARE_PRIMITIVE_SUPPORT(char)
MR_DECLARE_PRIMITIVE_SUPPORT(int)
MR_DECLARE_PRIMITIVE_SUPPORT(short)
MR_DECLARE_PRIMITIVE_SUPPORT(long)
MR_DECLARE_PRIMITIVE_SUPPORT(long long)

MR_DECLARE_PRIMITIVE_SUPPORT(unsigned char)
MR_DECLARE_PRIMITIVE_SUPPORT(unsigned int)
MR_DECLARE_PRIMITIVE_SUPPORT(unsigned short)
MR_DECLARE_PRIMITIVE_SUPPORT(unsigned long)
MR_DECLARE_PRIMITIVE_SUPPORT(unsigned long long)

MR_DECLARE_PRIMITIVE_SUPPORT(float)
MR_DECLARE_PRIMITIVE_SUPPORT(double)

MR_DECLARE_PRIMITIVE_SUPPORT(void*)


#endif //__MAGICREFLECTION_MRPRIMITIVESUPPORT_H__
       //eof
