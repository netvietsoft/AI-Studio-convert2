// Function: MMDetectionPlugin::AIDetectionPluginConfig::getVlaiVersion()
// RVA: 0x4d4f4, Size: 216 bytes
int64_t _ZN17MMDetectionPlugin23AIDetectionPluginConfig14getVlaiVersionEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_get_version(...); // call imported API via PLT at 0x4d528
    const char* s_30045 = "MTMVCore"; // string xref
    const char* s_30d6f = "[%s(%d)]:> vlai version:%s
"; // string xref
    const char* s_309b1 = "getVlaiVersion"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x4d550
    vlai_get_version(...); // call imported API via PLT at 0x4d554
    strlen(...); // call imported API via PLT at 0x4d55c
    _Znwm(...); // call imported API via PLT at 0x4d58c
    memmove(...); // call imported API via PLT at 0x4d5ac
    return a0;
    sub_403DC(...); // call internal func at 0x4d5c8
}
