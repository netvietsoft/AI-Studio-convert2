// Function: sub_3FF5C
// RVA: 0x3ff5c, Size: 344 bytes
int64_t sub_3FF5C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_getspecific(...); // call imported API via PLT at 0x3ff90
    _ZN17MMDetectionPlugin9JniHelper8cacheEnvEP7_JavaVM(...); // call imported API via PLT at 0x3ffa8
    (*x8)(...); // indirect call at 0x3ffc4
    (*x8)(...); // indirect call at 0x3ffe8
    const char* s_30045 = "MTMVCore";
    const char* s_2fbbd = "[%s(%d)]:> Failed to find class %s
"; // string xref
    const char* s_3134f = "getMethodInfo"; // string xref
    const char* s_30045 = "MTMVCore";
    const char* s_2feee = "[%s(%d)]:> Failed to find method id of %s
"; // string xref
    const char* s_3134f = "getMethodInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x40088
    (*x8)(...); // indirect call at 0x40098
    return a0;
}
