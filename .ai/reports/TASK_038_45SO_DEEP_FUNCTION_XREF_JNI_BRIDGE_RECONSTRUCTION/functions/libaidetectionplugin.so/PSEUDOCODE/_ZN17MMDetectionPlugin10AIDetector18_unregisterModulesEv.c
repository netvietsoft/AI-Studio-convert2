// Function: MMDetectionPlugin::AIDetector::_unregisterModules()
// RVA: 0x411c0, Size: 160 bytes
int64_t _ZN17MMDetectionPlugin10AIDetector18_unregisterModulesEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_engine_unload_require_all(...); // call imported API via PLT at 0x411e0
    _ZN17MMDetectionPlugin16_DetectionOptionD2Ev(...); // call imported API via PLT at 0x411f4
    _ZdlPv(...); // call imported API via PLT at 0x411fc
    const char* s_318bf = "_unregisterModules"; // string xref
    const char* s_30045 = "MTMVCore";
    const char* s_31939 = "[%s(%d)]:> [%s]AIDetector not initialized
"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x41250
    return a0;
}
