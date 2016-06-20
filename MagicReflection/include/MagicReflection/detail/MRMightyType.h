/****************************************************************/
/*!
 @abstract   ￼MRMightyType.h
 @discussion ￼ 
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRMIGHTYTYPE_H__
#define __MAGICREFLECTION_MRMIGHTYTYPE_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Mighty Type
 @discussion 
 Mighty type is the type that holds most of things.
 
 */
//****************************************************************/
class MRMightyType {
    
    union {
        struct  {
            mr_int64    m_int;          ///< integer representation
            mr_uint64   m_uint;         ///< unsigned integer representation
            mr_float64  m_float;        ///< float   representation
            void*       m_ptr;          ///< Pointer representation
        };
        union {                         ///< primitive output holder
            mutable bool        m_out_b;
            mutable mr_int8     m_out_s8;
            mutable mr_uint8    m_out_u8;
            mutable mr_int16    m_out_s16;
            mutable mr_uint16   m_out_u16;
            mutable mr_int32    m_out_s32;
            mutable mr_uint32   m_out_u32;
            mutable mr_float32  m_out_f32;
        };
        
        mr_byte         m_object[MR_RETURNTYPE_MAXSIZEBYTE];  ///< Object representation
    };
    mr_int32            m_type;         ///< ObjectType
    
    enum ObjectType {
        MT_PRIMITIVE,
        MT_OBJECT,
        MT_POINTER,
        MT_REFERENCE,
    };
    
    typedef MR_TL_2(float, double)  FPTypeList;
    typedef MR_TL_6(unsigned char, unsigned short, unsigned int, unsigned long, unsigned long int, unsigned long long)                 
    UnsignedIntTypeList;

    template <typename T>
    struct ObjectTypeHelper {
        typedef MRTypeTraits<T> TT;
        enum {
            value = ( (TT::isArith) ? MT_PRIMITIVE : 
                        ( (TT::isPointer) ? MT_POINTER: ((TT::isReference)? MT_REFERENCE: MT_OBJECT ) 
                        ) 
                    )
        };
    };
    
    template <int ot, typename T>
    struct ObjectTypeSetter;
    
    // Setting primitive values
    template <typename T>
    struct ObjectTypeSetter<(int)MT_PRIMITIVE, T> {
        // to prevent data loss, save in 3 form.
        static void Set(MRMightyType* pObj, T& val) {
            pObj->m_type = MT_PRIMITIVE;
            pObj->m_int   = (mr_int64)val;
            pObj->m_uint  = (mr_uint64)val;            
            pObj->m_float = (mr_float64)val;
        }
    };

    // Setting pointer values
    template <typename T>
    struct ObjectTypeSetter<(int)MT_POINTER, T> {
        static void Set(MRMightyType* pObj, T val) {
            pObj->m_type = MT_POINTER;
            pObj->m_ptr  = (void*)val;
        }
    };

    // Setting reference values
    template <typename T>
    struct ObjectTypeSetter<(int)MT_REFERENCE, T> {
        // parameter given as reference is stored as pointer.
        // hense, pointer and reference are compatible in MR.
        static void Set(MRMightyType* pObj, T& val) {
            pObj->m_type = MT_POINTER;
            pObj->m_ptr  = (void*)&val;
        }
        static void Set(MRMightyType* pObj, const T& val) {
            pObj->m_type = MT_POINTER;
            pObj->m_ptr  = (void*)&val;
        }
    };

    // Copying object value
    template <typename T>
    struct ObjectTypeSetter<(int)MT_OBJECT, T> {
        static void Set(MRMightyType* pObj, const T& val) {
            MR_STATIC_ASSERT(sizeof(T)<=MR_RETURNTYPE_MAXSIZEBYTE);
            
            mr_pointer_uint* pDst = (mr_pointer_uint*)&pObj->m_object[0];
            mr_pointer_uint* pSrc = (mr_pointer_uint*)&val;
            mr_pointer_uint* pEnd = (mr_pointer_uint*)(((mr_byte*)pSrc) + (sizeof(T) - (sizeof(T) % sizeof(mr_pointer_uint))));
            while (pEnd>pSrc) {
                *pDst++ = *pSrc++;
            }
            
            if (0 !=(sizeof(T) % sizeof(mr_pointer_uint)) ) {
                mr_byte* pDst1 = reinterpret_cast<mr_byte*>(pDst);
                mr_byte* pSrc1 = reinterpret_cast<mr_byte*>(pSrc);
                
                switch (sizeof(T) % sizeof(mr_pointer_uint)) {
                    case 7: *pDst1++ = *pSrc1++;
                    case 6: *pDst1++ = *pSrc1++;
                    case 5: *pDst1++ = *pSrc1++;
                    case 4: *pDst1++ = *pSrc1++;
                    case 3: *pDst1++ = *pSrc1++;
                    case 2: *pDst1++ = *pSrc1++;
                    case 1: *pDst1++ = *pSrc1++;
                }
            }
        }
    };
    
    template <int ot, typename _T>
    struct ObjectTypeGetter;
    
    // Getting primitive values
    template <typename _T>
    struct ObjectTypeGetter<(int)MT_PRIMITIVE, _T> {
        
        // note, int n is just placeholder to force
        // _PrimSelect to define in partial specialization.
        template <int n, typename __T>
        struct _PrimSelect {
            static mr_pointer_int* Get(const MRMightyType *pObj) {   return (mr_pointer_int*)&pObj->m_int; };
        };
#define __MR_PRIMSELECT_VARIANT(type, storage, val) \
        template <int n> struct _PrimSelect<n,type> {  \
            static type* Get(const MRMightyType *pObj) {   pObj->storage = pObj->val;  return &pObj->storage; };\
        }
#define __MR_PRIMSELECT_VARIANT_2(type, storage) \
        template <int n> struct _PrimSelect<n, type> {  \
        static type* Get(const MRMightyType *pObj) {   return const_cast<type*>(&pObj->storage); };\
        }
        
        __MR_PRIMSELECT_VARIANT(bool,     m_out_b,      m_int!=0);
        __MR_PRIMSELECT_VARIANT(mr_int8,  m_out_s8,     m_int);
        __MR_PRIMSELECT_VARIANT(mr_int16, m_out_s16,    m_int);
        __MR_PRIMSELECT_VARIANT(mr_int32, m_out_s32,    m_int);
        __MR_PRIMSELECT_VARIANT(mr_uint8,  m_out_u8,    m_uint);
        __MR_PRIMSELECT_VARIANT(mr_uint16, m_out_u16,   m_uint);
        __MR_PRIMSELECT_VARIANT(mr_uint32, m_out_u32,   m_uint);
        __MR_PRIMSELECT_VARIANT(mr_float32, m_out_f32,  m_float);
        __MR_PRIMSELECT_VARIANT_2(mr_int64,     m_int);
        __MR_PRIMSELECT_VARIANT_2(mr_uint64,    m_uint);
        __MR_PRIMSELECT_VARIANT_2(mr_float64,   m_float);

#undef __MR_PRIMSELECT_VARIANT
#undef __MR_PRIMSELECT_VARIANT_2        
        
        static _T* Get(const MRMightyType* pObj) {
            MAGICREFLECTION_ASSERT(MT_PRIMITIVE == pObj->m_type);
            return _PrimSelect<0, _T>::Get(pObj);
        }
    };
    
    // Setting pointer values
    template <typename T>
    struct ObjectTypeGetter<(int)MT_POINTER, T> {
        // note: T is pointer type, so T* is pointer to pointer type(U**).
        static T* Get(const MRMightyType* pObj) {
            MAGICREFLECTION_ASSERT(MT_POINTER == pObj->m_type);
            return (T*)&(pObj->m_ptr);
        }
    };
    
    // Setting reference values
    template <typename T>
    struct ObjectTypeGetter<(int)MT_REFERENCE, T> {
        static T* Get(const MRMightyType* pObj) {
            MAGICREFLECTION_ASSERT(MT_POINTER == pObj->m_type);
            return (T*)(pObj->m_ptr);
        }
    };
    
    // Setting reference values
    template <typename T>
    struct ObjectTypeGetter<(int)MT_OBJECT, T> {
        static const T* Get(const MRMightyType* pObj) {
            MAGICREFLECTION_ASSERT(MT_OBJECT == pObj->m_type);
            return (T*)(&pObj->m_object[0]);
        }
    };
    
public:
    template <typename T>
    void Set(T& val) {
        ObjectTypeSetter<ObjectTypeHelper<T>::value, T>::Set(this, val);
    }
    
    template <typename T>
    T* Get(void) const {
        return ObjectTypeGetter<ObjectTypeHelper<T>::value, T>::Get(this);
    }    
    
    bool IsPrimitive(void) const {
        return m_type == MT_PRIMITIVE;
    }
    bool IsPointer(void) const {
        return m_type == MT_POINTER;
    }
    bool IsObject(void) const {
        return m_type == MT_OBJECT;
    }
};

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRDYNAMICPTR_H__
       //eof
