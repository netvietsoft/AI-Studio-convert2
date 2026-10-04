// Function: MMCodec::AndroidMediaEncoder::_initKeyValue()
// RVA: 0xf1afc, Size: 416 bytes
int64_t _ZN7MMCodec19AndroidMediaEncoder13_initKeyValueEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    _ZN7MMCodec14AndroidEncoder13_initKeyValueEv(...); // call imported API via PLT at 0xf1b30
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xf1b38
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0xf1b50
    const char* s_82ebe = "<init>"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0xf1b78
    const char* s_674e0 = "signalEndOfInputStream"; // string xref
    const char* s_8596b = "()I"; // string xref
    (*x8)(...); // indirect call at 0xf1ba8
    const char* s_7c8ed = "mSurface"; // string xref
    const char* s_90c1c = "Landroid/view/Surface;"; // string xref
    (*x8)(...); // indirect call at 0xf1bd8
    return a0;
    const char* s_8af8f = "_initKeyValue"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6a972 = "[%s(%d)]:> %s:: getEnv error!"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf1c44
    const char* s_8af8f = "_initKeyValue"; // string xref
    const char* s_8593b = "%s/MTMV_AICodec: [%s(%d)]:> %s:: getEnv error!
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf1c84
    return a0;
}
