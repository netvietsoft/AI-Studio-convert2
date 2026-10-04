// Function: JNI_OnUnload
// RVA: 0x40ae0, Size: 68 bytes
int64_t JNI_OnUnload(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_30045 = "MTMVCore";
    const char* s_3056b = "[%s(%d)]:> [hrs] JNI_OnUnload
"; // string xref
    const char* s_3091d = "JNI_OnUnload"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x40b1c
    return a0;
}
