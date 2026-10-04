// Function: MMDetectionPlugin::AIDetector::unregisterModule()
// RVA: 0x4308c, Size: 216 bytes
int64_t _ZN17MMDetectionPlugin10AIDetector16unregisterModuleEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x430cc
    vlai_engine_unload_require_all(...); // call imported API via PLT at 0x430e4
    _ZN17MMDetectionPlugin16_DetectionOptionD2Ev(...); // call imported API via PLT at 0x430f8
    _ZdlPv(...); // call imported API via PLT at 0x43100
    const char* s_318bf = "_unregisterModules"; // string xref
    const char* s_30045 = "MTMVCore";
    const char* s_31939 = "[%s(%d)]:> [%s]AIDetector not initialized
"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x4314c
    return a0;
}
