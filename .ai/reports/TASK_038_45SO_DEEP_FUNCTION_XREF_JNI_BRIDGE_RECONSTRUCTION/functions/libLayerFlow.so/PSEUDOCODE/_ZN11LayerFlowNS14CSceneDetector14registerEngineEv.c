// Function: LayerFlowNS::CSceneDetector::registerEngine()
// RVA: 0x471d50, Size: 1284 bytes
int64_t _ZN11LayerFlowNS14CSceneDetector14registerEngineEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_engine_create(...); // call PLT API at 0x471d80
    vlai_setting_patch_create(...); // call PLT API at 0x471d90
    vlai_setting_patch_base_setting_patch(...); // call PLT API at 0x471da0
    vlai_base_setting_patch_set_thread_mode(...); // call PLT API at 0x471dac
    vlai_base_setting_patch_set_thread_max(...); // call PLT API at 0x471db8
    vlai_base_setting_patch_set_run_mode(...); // call PLT API at 0x471dc4
    stat(...); // call PLT API at 0x471df4
    const char* str = "iklf";
    const char* str = "sceneDetector<%s:%d> CSceneDetector: vlai_engine_create failed.";
    const char* str = "registerEngine";
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z(...); // call PLT API at 0x471e68
    const char* str = "iklf";
    const char* str = "sceneDetector<%s:%d> CSceneDetector: vlai_setting_patch_create failed.";
    const char* str = "registerEngine";
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z(...); // call PLT API at 0x471e94
    vlai_engine_uninit(...); // call PLT API at 0x471ea4
    vlai_engine_destroy(...); // call PLT API at 0x471eac
    vlai_setting_patch_destroy(...); // call PLT API at 0x471ebc
    _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm(...); // call PLT API at 0x471f28
    sub_2BC260(...); // call internal at 0x471f50
    vlai_setting_patch_model_setting_patch(...); // call PLT API at 0x471f70
    vlai_model_setting_patch_set_directory(...); // call PLT API at 0x471f8c
    vlai_engine_init(...); // call PLT API at 0x471f9c
    const char* str = "iklf";
    const char* str = "sceneDetector<%s:%d> CSceneDetector: vlai_engine_init failed, ret=%d";
    const char* str = "registerEngine";
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z(...); // call PLT API at 0x471fc8
    vlai_engine_uninit(...); // call PLT API at 0x471fd8
    vlai_engine_destroy(...); // call PLT API at 0x471fe0
    vlai_setting_patch_destroy(...); // call PLT API at 0x471ff0
    vlai_require_set_create(...); // call PLT API at 0x471ff8
    vlai_require_set_push(...); // call PLT API at 0x472004
    vlai_require_set_push(...); // call PLT API at 0x472010
    vlai_require_set_push(...); // call PLT API at 0x47201c
    vlai_run_result_make_null(...); // call PLT API at 0x472020
    vlai_engine_preload_with_setting(...); // call PLT API at 0x472034
    vlai_require_set_destroy(...); // call PLT API at 0x472040
    const char* str = "iklf";
    const char* str = "sceneDetector<%s:%d> CSceneDetector: vlai_engine_preload_with_setting failed, ret=%d";
    const char* str = "registerEngine";
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z(...); // call PLT API at 0x47206c
    vlai_engine_uninit(...); // call PLT API at 0x47207c
    vlai_engine_destroy(...); // call PLT API at 0x472084
    vlai_setting_patch_destroy(...); // call PLT API at 0x472094
    _Znwm(...); // call PLT API at 0x472108
    memmove(...); // call PLT API at 0x472128
    const char* str = "iklf";
    const char* str = "sceneDetector<%s:%d> CSceneDetector: model path not found or invalid: %s";
    const char* str = "registerEngine";
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z(...); // call PLT API at 0x47217c
    vlai_engine_uninit(...); // call PLT API at 0x47218c
    vlai_engine_destroy(...); // call PLT API at 0x472194
    vlai_setting_patch_destroy(...); // call PLT API at 0x4721a4
    _ZdlPv(...); // call PLT API at 0x4721c4
    return a0;
    sub_2BC2E0(...); // call internal at 0x472210
    _ZdlPv(...); // call PLT API at 0x472234
    sub_526544(...); // call internal at 0x47224c
    __stack_chk_fail(...); // call PLT API at 0x472250
}
