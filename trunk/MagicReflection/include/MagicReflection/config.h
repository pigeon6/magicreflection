/****************************************************************/
/*!
 @abstract   ￼config.h
 @discussion ￼
 This header should be edited to meets users demand.
 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

#ifndef __MAGICREFLECTION_CONFIG_H__
#define __MAGICREFLECTION_CONFIG_H__

//----------------------------------------------------------------
// Configurations
//----------------------------------------------------------------
/*
 Undef if you do not wish MR to be in namespace.
 */
#define MAGICREFLECTION_USE_NAMESPACE

/*
 MR namespace realname
 */
#define MAGICREFLECTION_NAMESPACE_NAME  mr

/*
 define if MR uses STL or not
 */
#define MAGICREFLECTION_USE_STL

//----------------------------------------------------------------
// Settings (based on Configurations)
//----------------------------------------------------------------
#ifdef MAGICREFLECTION_USE_NAMESPACE
#define MAGICREFLECTION_NAMESPACE_BEGIN namespace mr {
#define MAGICREFLECTION_NAMESPACE_END   }
#define MAGICREFLECTION_NAMESPACE_USE   using namespace MAGICREFLECTION_NAMESPACE_NAME
#define MR_NS(x)                        ::mr::x
#else
#define MAGICREFLECTION_NAMESPACE_BEGIN
#define MAGICREFLECTION_NAMESPACE_END
#define MAGICREFLECTION_NAMESPACE_USE   
#define MR_NS(x)                        x
#endif//MAGICREFLECTION_USE_NAMESPACE

#ifdef MAGICREFLECTION_USE_STL
#include <vector>
#define MRVector    std::vector
#else
#error not covered yet. sorry..
#endif//MAGICREFLECTION_USE_STL

#include <assert.h>
#define MAGICREFLECTION_ASSERT(cond)            assert(cond);

#define MR_INLINE                               inline

// max size(in byte) of the object returned by function/method
#define MR_RETURNTYPE_MAXSIZEBYTE               256

// max # of parameters
#define MR_MAX_PARAM_NUM                        15

// creates name with line#
#define MR_UNIQUENAME(name) MR_CONCAT(name,__LINE__)
#define MR_CONCAT(name, name2) MR_CONCAT_(name,name2)
#define MR_CONCAT_(name, name2) name##name2

//----------------------------------------------------------------
// Debug/Nodebug
//----------------------------------------------------------------
#if (!defined(DEBUG) && !defined(_DEBUG)) || defined(NDEBUG)
#define MR_RELEASE
#endif

//----------------------------------------------------------------
// Type Definitions
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

typedef long long               mr_int64;
typedef int                     mr_int32;
typedef short                   mr_int16;
typedef char                    mr_int8;
typedef float                   mr_float32;

typedef unsigned long long      mr_uint64;
typedef unsigned int            mr_uint32;
typedef unsigned short          mr_uint16;
typedef unsigned char           mr_uint8;
typedef double                  mr_float64;

typedef char                    mr_char;
typedef unsigned char           mr_byte;

#if defined(__LP64__)
// LP64: long=64bit, int=32bit (OS X, Linux)
typedef long                    mr_pointer_int;
typedef unsigned long           mr_pointer_uint;
#define MAGICREFLECTION_ARCH_64BIT
#elif defined(__LLP64__) || defined(_WIN64)
// LLP64 machine, long=32bit, int=32bit (Windows)
typedef long long               mr_pointer_int;
typedef unsigned long long      mr_pointer_uint;
#define MAGICREFLECTION_ARCH_64BIT
#else
// 32-bit machine, (Windows, OS X, Linux)
typedef long                    mr_pointer_int;
typedef unsigned long           mr_pointer_uint;
#define MAGICREFLECTION_ARCH_32BIT
#endif

#ifdef MAGICREFLECTION_ARCH_64BIT
#define MR_TID_MASK (0xFFFFFFFFFFFFFFF8LL)
#else
#define MR_TID_MASK (0xFFFFFFF8L)
#endif

typedef mr_pointer_uint         mr_typeid_t;

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_CONFIG_H__
//eof
