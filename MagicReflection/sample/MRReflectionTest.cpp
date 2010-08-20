/****************************************************************/
/*!
 @abstract   ￼
 @discussion ￼
 
 Created by Hiroki Omae on 2010/08/13.
 Copyright KH2O, Inc. 2010. All rights reserved.
 */
/****************************************************************/

//----------------------------------------------------------------
// File Dependencies
//----------------------------------------------------------------
#include "MagicReflection.h"
#include "MagicReflection_DefineMethod.h"

//----------------------------------------------------------------
// Namespace Dependencies
//----------------------------------------------------------------
MAGICREFLECTION_NAMESPACE_USE;

//----------------------------------------------------------------
// Type Definitions
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Sample Base Class
 */
//****************************************************************/
class BaseClass {
    const char *pString;
public:
    MR_DECLARE_DYNAMIC(BaseClass);
    
    BaseClass() :pString("Hello"){
    }
    BaseClass(const char* str) : pString(str) {
    }
    virtual ~BaseClass() {
    }
    
    void Print(void) {
        printf("BaseClass:%s\n", pString);
    }

    void Print(int x, float f) {
        printf("BaseClass:%s %d, %f\n", pString, x, f);
    }
};

class BaseClass2 {
    const char *pString;
public:
    MR_DECLARE_DYNAMIC(BaseClass2);

    BaseClass2() :pString("World"){
    }
    BaseClass2(const char* str) : pString(str) {
    }
    virtual ~BaseClass2() {        
    }
    
    void Print(void) {
        printf("BaseClass2:%s\n", pString);
    }
};


/****************************************************************/
/*!
 @abstract   Sample Inherited Class
 */
//****************************************************************/
class Inherited : public BaseClass {
public:
    MR_DECLARE_DYNAMIC(Inherited);

    Inherited() {
    }
    ~Inherited(){
    }
    
};


/****************************************************************/
/*!
 @abstract   Sample Inherited Class
 */
//****************************************************************/
class FinalInherited : public Inherited {
public:
    MR_DECLARE_DYNAMIC(FinalInherited);

    FinalInherited() {
    }
    ~FinalInherited(){
    }
};

//----------------------------------------------------------------
// Static Assert test(for debug)
//----------------------------------------------------------------
static void TestAssert() {
//    StaticAssert<MRTL_Length<MR_TL_VOID>::value == 0 > MR_UNIQUENAME(test);
    
    typedef MRMethodTypeConstructor<BaseClass, void, MR_TL_VOID>::MethodType MethodType1;
    typedef void (BaseClass::*MethodType2) (void);
    
//    StaticAssert<MRIsSameType<MethodType1, MethodType2>::value == 1 > MR_UNIQUENAME(test);    
}


//----------------------------------------------------------------
// Macro
//----------------------------------------------------------------
MR_IMPLEMENT_DYNAMIC(BaseClass);
MR_IMPLEMENT_DYNAMIC(BaseClass2);
MR_IMPLEMENT_DYNAMIC_SUBCLASS(Inherited, BaseClass);
MR_IMPLEMENT_DYNAMIC_SUBCLASS(FinalInherited, Inherited);

//MR_IMPLEMENT_DYNAMIC_WITH_NAME(BaseClass, AliasName);
//MR_IMPLEMENT_DYNAMIC_SUBCLASS_WITH_NAME(FinalInherited, Inherited, AliasName);

MR_DEFINE_DYNAMIC_METHOD_0(BaseClass, void, Print);
MR_DEFINE_DYNAMIC_METHOD_2(BaseClass, void, Print, int, float);

MR_DEFINE_DYNAMIC_CONSTRUCTOR_0(BaseClass);
MR_DEFINE_DYNAMIC_CONSTRUCTOR_1(BaseClass, const char*);


//MR_DEFINE_DYNAMIC_METHOD_0(BaseClass, void, Print);
//MR_DEFINE_DYNAMIC_METHOD_1(BaseClass, void, Print, int);
//MR_DEFINE_DYNAMIC_METHOD_2(BaseClass, void, Print, int, int);
//...

//----------------------------------------------------------------
// Implementation 
//----------------------------------------------------------------

/****************************************************************/
/*!
 @abstract   Testing dynamic cast.
 @discussion 
 Base => Inherited (in Inherited) should success
 Base => Base (in Inherited) should success
 Inherited => Base (in Inherited) should success
 Inherited => Inherited (in Inherited) should success

 Base => Inherited (in Base) should fail
 Base => Base (in Base) should success
 
 @param  [in, out]  
 @result
 */
//****************************************************************/
static void TestDynamicCast() {
    
    BaseClass*  pBase   = new BaseClass();
    BaseClass2* pBase2  = new BaseClass2();
    Inherited*  pInherited = new Inherited();
    
    // BaseClass => Inherited downcasting while object is actually Inherited
    // should success
    if(1){
        BaseClass*  pSrc = pInherited;
        Inherited*  pDst = mr_dynamic_cast<Inherited>(pSrc);
        MAGICREFLECTION_ASSERT(pDst!=NULL);
    }
    
    // BaseClass => BaseClass casting while object is actually Inherited
    // should success
    if(1){
        BaseClass*  pSrc = pInherited;
        BaseClass*  pDst = mr_dynamic_cast<BaseClass>(pSrc);
        MAGICREFLECTION_ASSERT(pDst!=NULL);
    }
    
    // Inherited => Inherited casting while object is actually Inherited
    // should success
    if(1){
        Inherited*  pSrc = pInherited;
        Inherited*  pDst = mr_dynamic_cast<Inherited>(pSrc);
        MAGICREFLECTION_ASSERT(pDst!=NULL);
    }
    
    // Inherited => BaseClass upcasting while object is actually Inherited
    // upcasting should always success
    if(1){
        Inherited*  pSrc = pInherited;
        BaseClass*  pDst = mr_dynamic_cast<BaseClass>(pSrc);
        MAGICREFLECTION_ASSERT(pDst!=NULL);
    }
    
    // BaseClass => Inherited downcasting while object is actually BaseClass
    // should fail
    if(1){
        Inherited* pDst = mr_dynamic_cast<Inherited>(pBase);
        MAGICREFLECTION_ASSERT(pDst==NULL);
    }

    // BaseClass => BaseClass downcasting while object is actually BaseClass
    // should success
    if(1){
        BaseClass* pDst = mr_dynamic_cast<BaseClass>(pBase);
        MAGICREFLECTION_ASSERT(pDst!=NULL);
    }
}


/****************************************************************/
/*!
 @abstract   Test to get typeid
 */
//****************************************************************/
static void TestTypeID(void) {
    
    BaseClass*  pBase   = new BaseClass();
    BaseClass2* pBase2  = new BaseClass2();
    Inherited*  pInherited = new Inherited();
        
    mr_typeid_t id  = mr_typeid(pBase);
    assert(id!=0);
    mr_typeid_t id2 = mr_typeid_static<BaseClass>();
    assert(id2!=0);
    mr_typeid_t id3 = mr_typeid_static<BaseClass*>();    
    assert(id3!=0);

    mr_typeid_t id4 = mr_typeid_static<int>();    
    assert(id4!=0);
}


/****************************************************************/
/*!
 @abstract   Test to create Instance
 */
//****************************************************************/
static void TestInstantiate(void) {

    MRRuntimeConstructionContext rcc;
    const MRRuntimeClass* pRC = MRRuntimeClass::ForName("BaseClass");
    
    rcc.SetParameter(0, "Some Parameter");

    MRDynamicPtr pObj  = pRC->CreateInstance();
    MRDynamicPtr pObj2 = pRC->CreateInstance(rcc);
        
    BaseClass* pBase1 = mr_dynamic_cast<BaseClass>(pObj);
    assert(pBase1!=NULL);
    BaseClass* pBase2 = mr_dynamic_cast<BaseClass>(pObj2);
    assert(pBase2!=NULL);
}


/****************************************************************/
/*!
 @abstract   Test to create Instance
 */
//****************************************************************/
static void TestInvokeMethod(void) {
    
    MRRuntimeConstructionContext rcc;
    const MRRuntimeClass* pRC = MRRuntimeClass::ForName("BaseClass");
    
    MRDynamicPtr pObj = pRC->CreateInstance();
    
    const MRMethod* pMethod = pRC->FindMethod("Print");

    MRMethodInvocationContext mic(pObj, pMethod);
    bool result = mic.Invoke();
    assert(result==true);
}


/****************************************************************/
/*!
 @abstract   main
 */
//****************************************************************/
int main(int argc, char** argv) {
    
    MagicReflection::Initialize();
    
    TestDynamicCast();
    TestTypeID();
    TestInstantiate();
    TestInvokeMethod();

    MagicReflection::Finalize();
    
    return EXIT_SUCCESS;
}

