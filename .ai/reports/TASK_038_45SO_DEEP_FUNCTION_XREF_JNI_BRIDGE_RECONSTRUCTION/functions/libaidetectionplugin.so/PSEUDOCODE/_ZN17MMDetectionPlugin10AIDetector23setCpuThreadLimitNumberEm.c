// Function: MMDetectionPlugin::AIDetector::setCpuThreadLimitNumber(unsigned long)
// RVA: 0x43190, Size: 152 bytes
int64_t _ZN17MMDetectionPlugin10AIDetector23setCpuThreadLimitNumberEm(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_setting_patch_base_setting_patch(...); // call imported API via PLT at 0x431b4
    vlai_base_setting_patch_set_thread_max(...); // call imported API via PLT at 0x431c0
    vlai_base_setting_patch_set_thread_mode(...); // call imported API via PLT at 0x431dc
    const char* s_305ce = "setCpuThreadLimitNumber"; // string xref
    const char* s_30045 = "MTMVCore";
    const char* s_31939 = "[%s(%d)]:> [%s]AIDetector not initialized
"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x43220
    return a0;
}
