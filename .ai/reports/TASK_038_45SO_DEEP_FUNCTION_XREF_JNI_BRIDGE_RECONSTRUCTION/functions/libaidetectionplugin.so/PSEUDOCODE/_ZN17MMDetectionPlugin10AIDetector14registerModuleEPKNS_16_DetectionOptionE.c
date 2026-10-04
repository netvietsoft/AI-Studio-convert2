// Function: MMDetectionPlugin::AIDetector::registerModule(MMDetectionPlugin::_DetectionOption const*)
// RVA: 0x42e48, Size: 580 bytes
int64_t _ZN17MMDetectionPlugin10AIDetector14registerModuleEPKNS_16_DetectionOptionE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNK17MMDetectionPlugin16_DetectionOptionneERKS0_(...); // call imported API via PLT at 0x42ea8
    vlai_run_result_create(...); // call imported API via PLT at 0x42eb0
    vlai_setting_patch_destroy(...); // call imported API via PLT at 0x42ec4
    vlai_setting_patch_create(...); // call imported API via PLT at 0x42ec8
    vlai_require_set_clear(...); // call imported API via PLT at 0x42edc
    vlai_engine_setting(...); // call imported API via PLT at 0x42ee4
    vlai_setting_module_reset(...); // call imported API via PLT at 0x42ee8
    (*x8)(...); // indirect call at 0x42f24
    const char* s_30045 = "MTMVCore";
    const char* s_31939 = "[%s(%d)]:> [%s]AIDetector not initialized
"; // string xref
    const char* s_3106c = "registerModule"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x42f6c
    return a0;
    const char* s_30045 = "MTMVCore";
    const char* s_30135 = "[%s(%d)]:> [%s]AIDetector input parameter invalid
"; // string xref
    const char* s_3106c = "registerModule"; // string xref
    _ZN17MMDetectionPlugin16_DetectionOptionD2Ev(...); // call imported API via PLT at 0x42fe8
    _ZdlPv(...); // call imported API via PLT at 0x42ff0
    _Znwm(...); // call imported API via PLT at 0x42ffc
    _ZN17MMDetectionPlugin16_DetectionOptionC1ERKS0_(...); // call imported API via PLT at 0x43008
    vlai_engine_apply_setting(...); // call imported API via PLT at 0x43014
    vlai_run_result_destroy(...); // call imported API via PLT at 0x4301c
    const char* s_30045 = "MTMVCore";
    const char* s_30aa8 = "[%s(%d)]:> [%s]IDetector's AssertManager/AndroidContext no set
"; // string xref
    const char* s_3106c = "registerModule"; // string xref
    _ZdlPv(...); // call imported API via PLT at 0x4306c
    __stack_chk_fail(...); // call imported API via PLT at 0x43088
}
