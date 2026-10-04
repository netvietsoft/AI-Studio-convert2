// Function: sub_6EE04
// RVA: 0x6ee04, Size: 240 bytes
int64_t sub_6EE04(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_run_result_create(...); // call imported API via PLT at 0x6ee14
    vlai_setting_patch_destroy(...); // call imported API via PLT at 0x6ee24
    vlai_setting_patch_create(...); // call imported API via PLT at 0x6ee28
    vlai_require_set_clear(...); // call imported API via PLT at 0x6ee38
    vlai_require_set_push(...); // call imported API via PLT at 0x6ee44
    vlai_engine_session_preload_with_setting(...); // call imported API via PLT at 0x6ee54
    const char* s_30045 = "MTMVCore";
    const char* s_2fa5d = "[%s(%d)]:> AiEngine register %s extra module failed
"; // string xref
    const char* s_30df5 = "registerExtraModule"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x6eeac
    vlai_engine_session_module_unload(...); // call imported API via PLT at 0x6eebc
    vlai_require_set_erase(...); // call imported API via PLT at 0x6eec8
    vlai_engine_apply_setting(...); // call imported API via PLT at 0x6eee0
    vlai_run_result_destroy(...); // call imported API via PLT at 0x6eef0
}
