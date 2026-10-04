// Function: MMDetectionPlugin::AIDetector::~AIDetector()
// RVA: 0x40f98, Size: 552 bytes
int64_t _ZN17MMDetectionPlugin10AIDetectorD2Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_82010 = (void*)0x82010; // global ref
    vlai_engine_unload_require_all(...); // call imported API via PLT at 0x40fd4
    _ZN17MMDetectionPlugin16_DetectionOptionD2Ev(...); // call imported API via PLT at 0x40fe8
    _ZdlPv(...); // call imported API via PLT at 0x40ff0
    const char* s_318bf = "_unregisterModules"; // string xref
    const char* s_30045 = "MTMVCore";
    const char* s_31939 = "[%s(%d)]:> [%s]AIDetector not initialized
"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x4103c
    (*x8)(...); // indirect call at 0x4104c
    _ZN17MMDetectionPlugin16_DetectionOptionD2Ev(...); // call imported API via PLT at 0x4105c
    _ZdlPv(...); // call imported API via PLT at 0x41064
    vlai_setting_patch_destroy(...); // call imported API via PLT at 0x41074
    vlai_require_set_destroy(...); // call imported API via PLT at 0x41084
    vlai_run_result_destroy(...); // call imported API via PLT at 0x41094
    (*x8)(...); // indirect call at 0x410c8
    (*x8)(...); // indirect call at 0x410ec
    (*x8)(...); // indirect call at 0x41104
    (*x8)(...); // indirect call at 0x4111c
    (*x8)(...); // indirect call at 0x41134
    vlai_engine_release_session(...); // call imported API via PLT at 0x41148
    vlai_engine_destroy(...); // call imported API via PLT at 0x41158
    vlai_destroy_graphics_env(...); // call imported API via PLT at 0x41168
    _ZdlPv(...); // call imported API via PLT at 0x4117c
    _ZdlPv(...); // call imported API via PLT at 0x4118c
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x411b8
    sub_3F3A4(...); // call internal func at 0x411bc
}
