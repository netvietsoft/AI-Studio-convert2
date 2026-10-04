// Function: MMCodec::ColorSpace::ColorSpace::makeRGBFromICCProfile(unsigned char const*, unsigned long, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>> const&)
// RVA: 0x180b9c, Size: 680 bytes
int64_t _ZN7MMCodec10ColorSpace10ColorSpace21makeRGBFromICCProfileEPKhmRKNSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec10ColorSpace11skcms_ParseEPKvmPNS0_16skcms_ICCProfileE(...); // call imported API via PLT at 0x180bcc
    _ZN7MMCodec10ColorSpace18skcms_sRGB_profileEv(...); // call imported API via PLT at 0x180be4
    _ZN7MMCodec10ColorSpace32skcms_ApproximatelyEqualProfilesEPKNS0_16skcms_ICCProfileES3_(...); // call imported API via PLT at 0x180bf4
    _ZN7MMCodec10ColorSpace22skcms_Matrix3x3_invertEPKNS0_15skcms_Matrix3x3EPS1_(...); // call imported API via PLT at 0x180c04
    _ZN7MMCodec10ColorSpace35skcms_sRGB_Inverse_TransferFunctionEv(...); // call imported API via PLT at 0x180c90
    _ZN7MMCodec10ColorSpace32skcms_TRCs_AreApproximateInverseEPKNS0_16skcms_ICCProfileEPKNS0_22skcms_TransferFunctionE(...); // call imported API via PLT at 0x180c9c
    void* g_202010 = (void*)0x202010; // global ref
    _ZN7MMCodec10ColorSpace10ColorSpace7makeRGBERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS0_7details6TMat33IfEENS1_18TransferParametersENS2_8functionIFffEEE(...); // call imported API via PLT at 0x180cec
    _ZN7MMCodec10ColorSpace10ColorSpaceC2ERKS1_(...); // call imported API via PLT at 0x180d14
    return a0;
    (*x8)(...); // indirect call at 0x180d50
    __stack_chk_fail(...); // call imported API via PLT at 0x180d64
    void* g_202010 = (void*)0x202010; // global ref
    _ZN7MMCodec10ColorSpace10ColorSpace7makeRGBERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS0_7details6TMat33IfEENS1_18TransferParametersENS2_8functionIFffEEE(...); // call imported API via PLT at 0x180dc0
    (*x9)(...); // indirect call at 0x180e28
}
