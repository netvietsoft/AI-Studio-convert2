// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1bb34
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_setEnvVariable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1bb34 | Size: 224 bytes | SHA256: 32990cc0a9bb2377c1e70490e8a13016cd27f39e41e15e1cdd13f8a0ee49cade
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _Z17loadLibraryHandlev, __android_log_print, dlerror, dlsym
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to find SetEnvVariable: %s"
//   "Invalid cache path"
//   "SetEnvVariable"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_setEnvVariable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 56 instructions
    /* 0x1bb34 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x1bb38 */ str x23, [sp, #0x10];
    /* 0x1bb3c */ stp x22, x21, [sp, #0x20];
    /* 0x1bb40 */ stp x20, x19, [sp, #0x30];
    /* 0x1bb44 */ mov x29, sp;
    /* 0x1bb48 */ mov x19, x3;
    /* 0x1bb4c */ mov w21, w2;
    /* 0x1bb50 */ mov x20, x0;
    _Z17loadLibraryHandlev();
    /* 0x1bb58 */ cbz x0, #0x1bc00;
    /* 0x1bb5c */ adrp x1, #0x10000;
    dlsym();
    dlerror();
    __android_log_print();
    __android_log_print();
    return x0;
}
