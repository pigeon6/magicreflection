/****************************************************************/
/*!
 @abstract   ￼MRConstructorInvokerImpl_inl.h
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/19.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/
#ifndef __MAGICREFLECTION_MRCONSTRUCTORINVOKERIMPL_INL__
#define __MAGICREFLECTION_MRCONSTRUCTORINVOKERIMPL_INL__

//----------------------------------------------------------------
// Namespace
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_BEGIN

//----------------------------------------------------------------
// Implementation 
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   helper class to invoke actual contructor.
 @discussion 
 invocation of actual constructor is different according to number of
 parameters it must have. MRConstructorInvokerHelper handles these
 difference.
 */
//****************************************************************/
template<typename _C, typename _PL>
struct MRConstructorInvokerHelper {
    template<unsigned int nParams, typename C, typename PL>
    struct Operator;
    // There is no generic way of defining this,
    // so there is no default definition.
    
    template<typename C, typename PL>
    struct Operator<0, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {
            //TODO: memory policy
            return new C();
        }
    };
    
    template<typename C, typename PL>
    struct Operator<1, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C(
                         *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0)
                         );
        }
    };
    
    template<typename C, typename PL>
    struct Operator<2, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1>::Result >(1)
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<3, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1>::Result >(1),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2>::Result >(2)
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<4, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0>::Result >(0),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1>::Result >(1),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2>::Result >(2),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3>::Result >(3)
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<5, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 )
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<6, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 )
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<7, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 )
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<8, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 )
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<9, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 )
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<10, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 )
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<11, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10)
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<12, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11)
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<13, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,12>::Result >(12)
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<14, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,12>::Result >(12),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,13>::Result >(13)
                          );    
        }
    };
    
    template<typename C, typename PL>
    struct Operator<15, C, PL> {
        static C* Invoke(const MRRuntimeConstructionContext& rcc) {            
            return new C ( 
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,0 >::Result >(0 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,1 >::Result >(1 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,2 >::Result >(2 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,3 >::Result >(3 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,4 >::Result >(4 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,5 >::Result >(5 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,6 >::Result >(6 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,7 >::Result >(7 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,8 >::Result >(8 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,9 >::Result >(9 ),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,10>::Result >(10),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,11>::Result >(11),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,12>::Result >(12),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,13>::Result >(13),
                          *rcc.template GetParamAt< typename MRTL_TypeAt<PL,14>::Result >(14)
                          );    
        }
    };
    
    typedef Operator<MRTL_Length<_PL>::value, _C,_PL>   OperatorType;
};


/****************************************************************/
/*!
 @abstract   test if this constructor can be called
 */
//****************************************************************/
template<typename C, typename PL>
bool MRConstructorInvokerImpl<C, PL>::_CanConstruct(const MRRuntimeConstructionContext& rcc) const {    
    if(rcc.GetParamNum() != MRTL_Length<PL>::value) {
        return  false;
    }
    if (MRTL_Length<PL>::value == 0) {
        return true;
    }

    mr_uint32 rcFlag   = rcc.GetRCFlag();
    mr_uint32 nullFlag = rcc.GetNullFlag();
    const MRDynamicPtr* pRtParams = rcc.GetRCPtrs();

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
 @abstract   call constructor(overloaded from MRConstructorInvoker)
 */
//****************************************************************/
template<typename C, typename PL>
MRDynamicPtr MRConstructorInvokerImpl<C, PL>::Construct(const MRRuntimeConstructionContext& rcc) const {
    if (_CanConstruct(rcc)) {
        C* pObj = MRConstructorInvokerHelper<C,PL>::OperatorType::Invoke(rcc);    
        return MRDynamicPtr(&C::__mr_s_rt_class__, pObj);
    } else {
        return MRDynamicPtr(NULL, NULL);
    }
}

/****************************************************************/
/*!
 @abstract   Constructor
 */
//****************************************************************/
template<typename C, typename PL>
MRConstructorInvokerImpl<C, PL>::MRConstructorInvokerImpl(void) {
}

/****************************************************************/
/*!
 @abstract   Destructor
 */
//****************************************************************/
template<typename C, typename PL>
MRConstructorInvokerImpl<C, PL>::~MRConstructorInvokerImpl() {}

/****************************************************************/
/*!
 @abstract   Initialization
 @discussion 
 When system is initialized by MRRuntimeSystem::Initialize()
 this method is called.
 */
//****************************************************************/
template<typename C, typename PL>
void MRConstructorInvokerImpl<C, PL>::_Initialize(void) {
    C::__mr_s_rt_class__.RegisterConstructor(this);    
}


/****************************************************************/
/*!
 @abstract   Finalization
 @discussion 
 When system is initialized by MRRuntimeSystem::Finalize()
 this method is called.
 */
//****************************************************************/
template<typename C, typename PL>
void MRConstructorInvokerImpl<C, PL>::_Finalize(void) {
    
}


MAGICREFLECTION_NAMESPACE_END
#endif //__MAGICREFLECTION_MRCONSTRUCTORINVOKERIMPL_INL__
