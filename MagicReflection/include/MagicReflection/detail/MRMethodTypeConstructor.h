/****************************************************************/
/*!
 @abstract   ￼MRMethodTypeConstructor.h
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/19.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

#ifndef __MAGICREFLECTION_MRMETHODTYPECONSTRUCTOR_H__
#define __MAGICREFLECTION_MRMETHODTYPECONSTRUCTOR_H__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
//Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Method type constructor (hidden detail)
 @discussion 
 MRMethodTypeConstructor is a simple helper class to create
 method type from given types.
 
 Method type is something like
 int (SomeClass::*SomeMethodType)(int, float, ...).
 
 Although this class looks very gimmicky, what it actually does is 
 just typedef.
 */
//****************************************************************/
template <typename Class, typename ReturnType, typename ParamList>
class MRMethodTypeConstructor {
public:
    
    template<unsigned int nParam, typename C, typename RT, typename PL>
    struct ConstructorHelper;
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<0, C, RT, PL> {
        typedef RT (C::*MethodType)   (void);
        typedef RT (C::*ConstMethodType) (void) const;
    };
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<1, C, RT, PL> {
        typedef RT (C::*MethodType) (typename MRTL_TypeAt<PL,0>::Result);
        typedef RT (C::*ConstMethodType) (typename MRTL_TypeAt<PL, 0>::Result) const;
    };
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<2, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result) const;
    };
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<3, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result) const;
    };

    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<4, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result) const;
    };

    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<5, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result,
                                  typename MRTL_TypeAt<PL, 4>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result,
                                       typename MRTL_TypeAt<PL, 4>::Result) const;
    };
        
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<6, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result,
                                  typename MRTL_TypeAt<PL, 4>::Result,
                                  typename MRTL_TypeAt<PL, 5>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result,
                                       typename MRTL_TypeAt<PL, 4>::Result,
                                       typename MRTL_TypeAt<PL, 5>::Result) const;
    };
    
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<7, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result,
                                  typename MRTL_TypeAt<PL, 4>::Result,
                                  typename MRTL_TypeAt<PL, 5>::Result,
                                  typename MRTL_TypeAt<PL, 6>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result,
                                       typename MRTL_TypeAt<PL, 4>::Result,
                                       typename MRTL_TypeAt<PL, 5>::Result,
                                       typename MRTL_TypeAt<PL, 6>::Result) const;
    };
    
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<8, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result,
                                  typename MRTL_TypeAt<PL, 4>::Result,
                                  typename MRTL_TypeAt<PL, 5>::Result,
                                  typename MRTL_TypeAt<PL, 6>::Result,
                                  typename MRTL_TypeAt<PL, 7>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result,
                                       typename MRTL_TypeAt<PL, 4>::Result,
                                       typename MRTL_TypeAt<PL, 5>::Result,
                                       typename MRTL_TypeAt<PL, 6>::Result,
                                       typename MRTL_TypeAt<PL, 7>::Result) const;
    };
    
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<9, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result,
                                  typename MRTL_TypeAt<PL, 4>::Result,
                                  typename MRTL_TypeAt<PL, 5>::Result,
                                  typename MRTL_TypeAt<PL, 6>::Result,
                                  typename MRTL_TypeAt<PL, 7>::Result,
                                  typename MRTL_TypeAt<PL, 8>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result,
                                       typename MRTL_TypeAt<PL, 4>::Result,
                                       typename MRTL_TypeAt<PL, 5>::Result,
                                       typename MRTL_TypeAt<PL, 6>::Result,
                                       typename MRTL_TypeAt<PL, 7>::Result,
                                       typename MRTL_TypeAt<PL, 8>::Result) const;
    };
    
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<10, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result,
                                  typename MRTL_TypeAt<PL, 4>::Result,
                                  typename MRTL_TypeAt<PL, 5>::Result,
                                  typename MRTL_TypeAt<PL, 6>::Result,
                                  typename MRTL_TypeAt<PL, 7>::Result,
                                  typename MRTL_TypeAt<PL, 8>::Result,
                                  typename MRTL_TypeAt<PL, 9>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result,
                                       typename MRTL_TypeAt<PL, 4>::Result,
                                       typename MRTL_TypeAt<PL, 5>::Result,
                                       typename MRTL_TypeAt<PL, 6>::Result,
                                       typename MRTL_TypeAt<PL, 7>::Result,
                                       typename MRTL_TypeAt<PL, 8>::Result,
                                       typename MRTL_TypeAt<PL, 9>::Result) const;
    };
    
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<11, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result,
                                  typename MRTL_TypeAt<PL, 4>::Result,
                                  typename MRTL_TypeAt<PL, 5>::Result,
                                  typename MRTL_TypeAt<PL, 6>::Result,
                                  typename MRTL_TypeAt<PL, 7>::Result,
                                  typename MRTL_TypeAt<PL, 8>::Result,
                                  typename MRTL_TypeAt<PL, 9>::Result,
                                  typename MRTL_TypeAt<PL, 10>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result,
                                       typename MRTL_TypeAt<PL, 4>::Result,
                                       typename MRTL_TypeAt<PL, 5>::Result,
                                       typename MRTL_TypeAt<PL, 6>::Result,
                                       typename MRTL_TypeAt<PL, 7>::Result,
                                       typename MRTL_TypeAt<PL, 8>::Result,
                                       typename MRTL_TypeAt<PL, 9>::Result,
                                       typename MRTL_TypeAt<PL, 10>::Result) const;
    };
    
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<12, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result,
                                  typename MRTL_TypeAt<PL, 4>::Result,
                                  typename MRTL_TypeAt<PL, 5>::Result,
                                  typename MRTL_TypeAt<PL, 6>::Result,
                                  typename MRTL_TypeAt<PL, 7>::Result,
                                  typename MRTL_TypeAt<PL, 8>::Result,
                                  typename MRTL_TypeAt<PL, 9>::Result,
                                  typename MRTL_TypeAt<PL, 10>::Result,
                                  typename MRTL_TypeAt<PL, 11>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result,
                                       typename MRTL_TypeAt<PL, 4>::Result,
                                       typename MRTL_TypeAt<PL, 5>::Result,
                                       typename MRTL_TypeAt<PL, 6>::Result,
                                       typename MRTL_TypeAt<PL, 7>::Result,
                                       typename MRTL_TypeAt<PL, 8>::Result,
                                       typename MRTL_TypeAt<PL, 9>::Result,
                                       typename MRTL_TypeAt<PL, 10>::Result,
                                       typename MRTL_TypeAt<PL, 11>::Result) const;
    };
    
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<13, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result,
                                  typename MRTL_TypeAt<PL, 4>::Result,
                                  typename MRTL_TypeAt<PL, 5>::Result,
                                  typename MRTL_TypeAt<PL, 6>::Result,
                                  typename MRTL_TypeAt<PL, 7>::Result,
                                  typename MRTL_TypeAt<PL, 8>::Result,
                                  typename MRTL_TypeAt<PL, 9>::Result,
                                  typename MRTL_TypeAt<PL, 10>::Result,
                                  typename MRTL_TypeAt<PL, 11>::Result,
                                  typename MRTL_TypeAt<PL, 12>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result,
                                       typename MRTL_TypeAt<PL, 4>::Result,
                                       typename MRTL_TypeAt<PL, 5>::Result,
                                       typename MRTL_TypeAt<PL, 6>::Result,
                                       typename MRTL_TypeAt<PL, 7>::Result,
                                       typename MRTL_TypeAt<PL, 8>::Result,
                                       typename MRTL_TypeAt<PL, 9>::Result,
                                       typename MRTL_TypeAt<PL, 10>::Result,
                                       typename MRTL_TypeAt<PL, 11>::Result,
                                       typename MRTL_TypeAt<PL, 12>::Result) const;
    };
    
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<14, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result,
                                  typename MRTL_TypeAt<PL, 4>::Result,
                                  typename MRTL_TypeAt<PL, 5>::Result,
                                  typename MRTL_TypeAt<PL, 6>::Result,
                                  typename MRTL_TypeAt<PL, 7>::Result,
                                  typename MRTL_TypeAt<PL, 8>::Result,
                                  typename MRTL_TypeAt<PL, 9>::Result,
                                  typename MRTL_TypeAt<PL, 10>::Result,
                                  typename MRTL_TypeAt<PL, 11>::Result,
                                  typename MRTL_TypeAt<PL, 12>::Result,
                                  typename MRTL_TypeAt<PL, 13>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result,
                                       typename MRTL_TypeAt<PL, 4>::Result,
                                       typename MRTL_TypeAt<PL, 5>::Result,
                                       typename MRTL_TypeAt<PL, 6>::Result,
                                       typename MRTL_TypeAt<PL, 7>::Result,
                                       typename MRTL_TypeAt<PL, 8>::Result,
                                       typename MRTL_TypeAt<PL, 9>::Result,
                                       typename MRTL_TypeAt<PL, 10>::Result,
                                       typename MRTL_TypeAt<PL, 11>::Result,
                                       typename MRTL_TypeAt<PL, 12>::Result,
                                       typename MRTL_TypeAt<PL, 13>::Result) const;
    };
    
    
    template<typename C, typename RT, typename PL>
    struct ConstructorHelper<15, C, RT, PL> {
        typedef RT (C::*MethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                  typename MRTL_TypeAt<PL, 1>::Result,
                                  typename MRTL_TypeAt<PL, 2>::Result,
                                  typename MRTL_TypeAt<PL, 3>::Result,
                                  typename MRTL_TypeAt<PL, 4>::Result,
                                  typename MRTL_TypeAt<PL, 5>::Result,
                                  typename MRTL_TypeAt<PL, 6>::Result,
                                  typename MRTL_TypeAt<PL, 7>::Result,
                                  typename MRTL_TypeAt<PL, 8>::Result,
                                  typename MRTL_TypeAt<PL, 9>::Result,
                                  typename MRTL_TypeAt<PL, 10>::Result,
                                  typename MRTL_TypeAt<PL, 11>::Result,
                                  typename MRTL_TypeAt<PL, 12>::Result,
                                  typename MRTL_TypeAt<PL, 13>::Result,
                                  typename MRTL_TypeAt<PL, 14>::Result);
        typedef RT (C::*ConstMethodType)(typename MRTL_TypeAt<PL, 0>::Result, 
                                       typename MRTL_TypeAt<PL, 1>::Result,
                                       typename MRTL_TypeAt<PL, 2>::Result,
                                       typename MRTL_TypeAt<PL, 3>::Result,
                                       typename MRTL_TypeAt<PL, 4>::Result,
                                       typename MRTL_TypeAt<PL, 5>::Result,
                                       typename MRTL_TypeAt<PL, 6>::Result,
                                       typename MRTL_TypeAt<PL, 7>::Result,
                                       typename MRTL_TypeAt<PL, 8>::Result,
                                       typename MRTL_TypeAt<PL, 9>::Result,
                                       typename MRTL_TypeAt<PL, 10>::Result,
                                       typename MRTL_TypeAt<PL, 11>::Result,
                                       typename MRTL_TypeAt<PL, 12>::Result,
                                       typename MRTL_TypeAt<PL, 13>::Result,
                                       typename MRTL_TypeAt<PL, 14>::Result) const;
    };

    typedef typename ConstructorHelper<MRTL_Length<ParamList>::value, Class, ReturnType, ParamList>::MethodType MethodType;
    typedef typename ConstructorHelper<MRTL_Length<ParamList>::value, Class, ReturnType, ParamList>::ConstMethodType ConstMethodType;
};
    MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRDYNAMICPTR_H__
       //eof
