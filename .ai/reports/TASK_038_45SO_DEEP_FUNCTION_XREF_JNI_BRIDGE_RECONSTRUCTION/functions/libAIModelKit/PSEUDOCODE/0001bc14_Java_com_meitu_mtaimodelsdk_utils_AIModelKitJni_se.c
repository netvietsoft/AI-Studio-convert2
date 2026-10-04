// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1bc14
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_setGlobalCacheDir
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1bc14 | Size: 212 bytes | SHA256: 706d79e58eb2d0a3954928ee9c7b6a8bceae0927f69679a5ca771a13e23e1db1
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _Z17loadLibraryHandlev, __android_log_print, dlerror, dlsym
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to find SetGlobalCacheDir: %s"
//   "Invalid cache path"
//   "SetGlobalCacheDir"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_setGlobalCacheDir(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x1bc14 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x1bc18 */ stp x22, x21, [sp, #0x10];
    /* 0x1bc1c */ stp x20, x19, [sp, #0x20];
    /* 0x1bc20 */ mov x29, sp;
    /* 0x1bc24 */ mov w21, w3;
    /* 0x1bc28 */ mov x19, x2;
    /* 0x1bc2c */ mov x20, x0;
    _Z17loadLibraryHandlev();
    /* 0x1bc34 */ cbz x0, #0x1bcd8;
    /* 0x1bc38 */ adrp x1, #0x10000;
    /* 0x1bc3c */ add x1, x1, #0xc78;
    dlsym();
    dlerror();
    __android_log_print();
    __android_log_print();
    return x0;
}
