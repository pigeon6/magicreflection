/****************************************************************/
/*!
 @abstract   ￼MRMethodInvokerImpl_inl.h
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/19.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRMETHODINVOKERIMPL_INL__
#define __MAGICREFLECTION_MRMETHODINVOKERIMPL_INL__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
// Implementation 
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   helper class to invoke actual method.
 @discussion 
 invocation of actual method is different according to number of
 parameters it must have. MRMethodInvokerHelper handles these
 difference.
 */
//****************************************************************/
template<typename _C, typename _RT, typename _PL, typename _MethodType>
struct MRMethodInvokerHelper {
    template<unsigned int nParams, typename C, typename RT, typename PL, typename MethodType>
    struct Operator;
    // There is no generic way of defining this,
    // so there is no default definition.
    
    //-----------------------------------
    // case: return value is not void
    //-----------------------------------
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<0, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ();    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<1, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( *mic.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0) );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<2, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1>::Result >(1)
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<3, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1>::Result >(1),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2>::Result >(2)
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<4, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1>::Result >(1),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2>::Result >(2),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3>::Result >(3)
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<5, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 )
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<6, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 )
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<7, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 )
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<8, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 )
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<9, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 )
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<10, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 )
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<11, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10)
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<12, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11)
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<13, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,12>::Result >(12)
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<14, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,12>::Result >(12),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,13>::Result >(13)
                             );    
            mic.SetReturnValue(rt);
        }
    };
    
    template<typename C, typename RT, typename PL, typename MethodType>
    struct Operator<15, C, RT, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            RT rt = (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,12>::Result >(12),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,13>::Result >(13),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,14>::Result >(14)
                             );    
            mic.SetReturnValue(rt);
        }
    };


    //-----------------------------------
    // case: return value is void
    //-----------------------------------
    template<typename C, typename PL, typename MethodType>
    struct Operator<0, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ();
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<1, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( *mic.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0) );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<2, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1>::Result >(1)
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<3, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1>::Result >(1),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2>::Result >(2)
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<4, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1>::Result >(1),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2>::Result >(2),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3>::Result >(3)
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<5, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 )
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<6, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 )
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<7, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 )
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<8, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 )
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<9, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 )
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<10, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 )
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<11, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10)
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<12, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11)
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<13, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,12>::Result >(12)
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<14, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,12>::Result >(12),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,13>::Result >(13)
                             );    
            mic.SetReturnValueVoid();
        }
    };
    
    template<typename C, typename PL, typename MethodType>
    struct Operator<15, C, void, PL, MethodType> {
        static void Invoke(MRMethodInvocationContext& mic, MethodType m) {            
            C* pObj = mr_fast_dynamic_cast<C>(mic.GetCaller());
            (pObj->*m) ( 
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,12>::Result >(12),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,13>::Result >(13),
                             *mic.template GetParamAt< typename MRTL_TypeAt<PL,14>::Result >(14)
                             );
            mic.SetReturnValueVoid();
        }
    };
    
    
    typedef Operator<MRTL_Length<_PL>::value, _C,_RT,_PL,_MethodType>   OperatorType;
};



/****************************************************************/
/*!
 @abstract   (private method) test if method can be invoked
 @discussion 
 Test all parameters given to mic, and see if this method can be 
 invoked.
 
 @param  [in]  mic method invocation context
 @result    true if method can be invoked.
 */
//****************************************************************/
template<typename C, typename RT, typename PL, bool isConst>
MR_INLINE bool MRMethodInvokerImpl<C,RT,PL,isConst>::_CanInvoke(MRMethodInvocationContext& mic) const {

    if(mic.GetParamNum() != MRTL_Length<PL>::value) {
        return  false;
    }
        
    MRDynamicPtr caller = mic.GetCaller();
    if(!mr_dynamic_cast<C>(caller)){
        return false;
    }
    
    if (MRTL_Length<PL>::value == 0) {
        return true;
    }
    
    mr_uint32 rcFlag   = mic.GetRCFlag();
    mr_uint32 nullFlag = mic.GetNullFlag();
    const MRDynamicPtr* pRtParams = mic.GetRCPtrs();
    
    // if rtParam is null, then avoid runtime type check
    rcFlag = rcFlag & (~nullFlag); // turn off rfFlag
    
    // runtime type check
    if (MRTL_Length<PL>::value >0 && (rcFlag&(1<<0 )) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 0 >::Result >(pRtParams[0 ]) ) return false;
    if (MRTL_Length<PL>::value >1 && (rcFlag&(1<<1 )) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 1 >::Result >(pRtParams[1 ]) ) return false;
    if (MRTL_Length<PL>::value >2 && (rcFlag&(1<<2 )) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 2 >::Result >(pRtParams[2 ]) ) return false;
    if (MRTL_Length<PL>::value >3 && (rcFlag&(1<<3 )) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 3 >::Result >(pRtParams[3 ]) ) return false;
    if (MRTL_Length<PL>::value >4 && (rcFlag&(1<<4 )) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 4 >::Result >(pRtParams[4 ]) ) return false;
    if (MRTL_Length<PL>::value >5 && (rcFlag&(1<<5 )) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 5 >::Result >(pRtParams[5 ]) ) return false;
    if (MRTL_Length<PL>::value >6 && (rcFlag&(1<<6 )) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 6 >::Result >(pRtParams[6 ]) ) return false;
    if (MRTL_Length<PL>::value >7 && (rcFlag&(1<<7 )) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 7 >::Result >(pRtParams[7 ]) ) return false;
    if (MRTL_Length<PL>::value >8 && (rcFlag&(1<<8 )) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 8 >::Result >(pRtParams[8 ]) ) return false;
    if (MRTL_Length<PL>::value >9 && (rcFlag&(1<<9 )) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 9 >::Result >(pRtParams[9 ]) ) return false;
    if (MRTL_Length<PL>::value >10&& (rcFlag&(1<<10)) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 10>::Result >(pRtParams[10]) ) return false;
    if (MRTL_Length<PL>::value >11&& (rcFlag&(1<<11)) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 11>::Result >(pRtParams[11]) ) return false;
    if (MRTL_Length<PL>::value >12&& (rcFlag&(1<<12)) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 12>::Result >(pRtParams[12]) ) return false;
    if (MRTL_Length<PL>::value >13&& (rcFlag&(1<<13)) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 13>::Result >(pRtParams[13]) ) return false;
    if (MRTL_Length<PL>::value >14&& (rcFlag&(1<<14)) && mr_dynamic_cast< typename MRTL_TypeAtNonStrict<PL, 14>::Result >(pRtParams[14]) ) return false;
    
    return true;
}

/****************************************************************/
/*!
 @abstract   return method name(overloaded from MRMethodInvoker)
 */
//****************************************************************/
template<typename C, typename RT, typename PL, bool isConst>
const mr_char* MRMethodInvokerImpl<C,RT,PL,isConst>::GetName(void) const {
    return m_pName;
}


/****************************************************************/
/*!
 @abstract   invoke method(overloaded from MRMethodInvoker)
 */
//****************************************************************/
template<typename C, typename RT, typename PL, bool isConst>
bool MRMethodInvokerImpl<C,RT,PL,isConst>::Invoke(MRMethodInvocationContext& mic) const {
    if (_CanInvoke(mic)) {
        MRMethodInvokerHelper<C,RT,PL,MethodType>::OperatorType::Invoke(mic, m_pMethod);
        return true;
    }
    return false;
}

/****************************************************************/
/*!
 @abstract   Constructor
 */
//****************************************************************/
template<typename C, typename RT, typename PL, bool isConst>
MRMethodInvokerImpl<C,RT,PL,isConst>::MRMethodInvokerImpl(const mr_char* pName, MethodType pMethod) : m_pName(pName), m_pMethod(pMethod) {
}

/****************************************************************/
/*!
 @abstract   Destructor
 */
//****************************************************************/
template<typename C, typename RT, typename PL, bool isConst>
MRMethodInvokerImpl<C,RT,PL,isConst>::~MRMethodInvokerImpl() {}

/****************************************************************/
/*!
 @abstract   Initialization
 @discussion 
 When system is initialized by MRRuntimeSystem::Initialize()
 this method is called.
 */
//****************************************************************/
template<typename C, typename RT, typename PL, bool isConst>
void MRMethodInvokerImpl<C,RT,PL,isConst>::_Initialize(void) {
    C::__mr_s_rt_class__.RegisterMethod(this);    
}


/****************************************************************/
/*!
 @abstract   Finalization
 @discussion 
 When system is initialized by MRRuntimeSystem::Finalize()
 this method is called.
 */
//****************************************************************/
template<typename C, typename RT, typename PL, bool isConst>
void MRMethodInvokerImpl<C,RT,PL,isConst>::_Finalize(void) {
}

MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRMETHODINVOKERIMPL_INL__
