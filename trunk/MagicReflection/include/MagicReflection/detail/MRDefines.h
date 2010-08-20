/****************************************************************/
/*!
 @abstract   ￼MRDefines.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

#ifndef __MAGICREFLECTION_MRDEFINES_H__
#define __MAGICREFLECTION_MRDEFINES_H__

//----------------------------------------------------------------
// Macro
//----------------------------------------------------------------
#define MR_DECLARE_DYNAMIC(c)                                                                   \
public:                                                                                         \
    static MR_NS(MRRuntimeClassImpl<c>)   __mr_s_rt_class__;                                    \
    virtual MR_NS(MRRuntimeClass*) __MR_GetRuntimeClass(void) const { return &__mr_s_rt_class__; }

#define MR_IMPLEMENT_DYNAMIC(c)                                                                 \
    MR_NS(MRRuntimeClassImpl<c>) c::__mr_s_rt_class__(#c,NULL);                                 \

#define MR_IMPLEMENT_DYNAMIC_SUBCLASS(subclass, parentclass)                                    \
    MR_NS(MRRuntimeClassImpl<subclass>) subclass::__mr_s_rt_class__(#subclass, &parentclass::__mr_s_rt_class__);
    
#define MR_IMPLEMENT_DYNAMIC_WITH_NAME(c, AliasName)                                            \
    MR_NS(MRRuntimeClassImpl<c>) c::__mr_s_rt_class__(#AliasName,NULL);

#define MR_IMPLEMENT_DYNAMIC_SUBCLASS_WITH_NAME(subclass, parentclass, AliasName)                \
    MR_NS(MRRuntimeClassImpl<subclass>) subclass::__mr_s_rt_class__(#AliasName, &parentclass::__mr_s_rt_class__);

#endif //__MAGICREFLECTION_MRDEFINES_H__
       //eof
