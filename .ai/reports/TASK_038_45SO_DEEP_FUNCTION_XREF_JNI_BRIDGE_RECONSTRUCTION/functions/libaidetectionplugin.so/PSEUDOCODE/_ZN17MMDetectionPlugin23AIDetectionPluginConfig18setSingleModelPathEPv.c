// Function: MMDetectionPlugin::AIDetectionPluginConfig::setSingleModelPath(void*)
// RVA: 0x4d70c, Size: 388 bytes
int64_t _ZN17MMDetectionPlugin23AIDetectionPluginConfig18setSingleModelPathEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_30045 = "MTMVCore"; // string xref
    const char* s_30507 = "[%s(%d)]:> setSingleModelPath aiEngine:%p key:%s path:%s succeed
"; // string xref
    const char* s_304f4 = "setSingleModelPath"; // string xref
    void* g_82008 = (void*)0x82008; // global ref
    const char* s_30eed = "[%s(%d)]:> setSingleModelPath aiEngine:%p key:%s path:%s failed
"; // string xref
    vlai_model_setting_patch_set_model_path(...); // call imported API via PLT at 0x4d798
    __android_log_print(...); // call imported API via PLT at 0x4d7e8
    const char* s_30045 = "MTMVCore"; // string xref
    const char* s_2fc81 = "[%s(%d)]:> setSingleModelPath aiEngine is nullptr
"; // string xref
    const char* s_304f4 = "setSingleModelPath"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x4d870
    return a0;
}
