// Function: JNI_OnUnload
// RVA: 0x440b58, Size: 24 bytes
int64_t JNI_OnUnload(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "mtik_";
    const char* str = "JNI_OnUnload LayerFlow.so detach from system!";
    __android_log_print(...); // call PLT API at 0x440b6c
}
