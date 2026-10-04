// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1bf10
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getManisXpuApiVersion
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1bf10 | Size: 84 bytes | SHA256: 9287522f4d54f73f4138ffba6a7dee58f589afb3ffcff61a0facf09d118ce217
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _Z17loadLibraryHandlev, __android_log_print, dlerror, dlsym
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to find ManisXpuApiVersion: %s"
//   "ManisXpuApiVersion"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getManisXpuApiVersion(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x1bf10 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1bf14 */ mov x29, sp;
    _Z17loadLibraryHandlev();
    /* 0x1bf1c */ cbz x0, #0x1bf58;
    /* 0x1bf20 */ adrp x1, #0x10000;
    /* 0x1bf24 */ add x1, x1, #0x162;
    dlsym();
    /* 0x1bf2c */ cbz x0, #0x1bf38;
    /* 0x1bf30 */ ldp x29, x30, [sp], #0x10;
    /* 0x1bf34 */ br x0;
    dlerror();
    __android_log_print();
    return x0;
}
