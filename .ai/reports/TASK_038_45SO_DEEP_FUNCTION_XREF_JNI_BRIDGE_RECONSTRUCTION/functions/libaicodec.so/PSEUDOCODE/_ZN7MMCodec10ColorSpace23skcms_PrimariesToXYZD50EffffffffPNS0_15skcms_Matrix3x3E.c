// Function: MMCodec::ColorSpace::skcms_PrimariesToXYZD50(float, float, float, float, float, float, float, float, MMCodec::ColorSpace::skcms_Matrix3x3*)
// RVA: 0x18586c, Size: 536 bytes
int64_t _ZN7MMCodec10ColorSpace23skcms_PrimariesToXYZD50EffffffffPNS0_15skcms_Matrix3x3E(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec10ColorSpace22skcms_Matrix3x3_invertEPKNS0_15skcms_Matrix3x3EPS1_(...); // call imported API via PLT at 0x185980
    _ZN7MMCodec10ColorSpace22skcms_Matrix3x3_concatEPKNS0_15skcms_Matrix3x3ES3_(...); // call imported API via PLT at 0x1859f4
    _ZN7MMCodec10ColorSpace19skcms_AdaptToXYZD50EffPNS0_15skcms_Matrix3x3E(...); // call imported API via PLT at 0x185a18
    _ZN7MMCodec10ColorSpace22skcms_Matrix3x3_concatEPKNS0_15skcms_Matrix3x3ES3_(...); // call imported API via PLT at 0x185a30
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x185a80
}
