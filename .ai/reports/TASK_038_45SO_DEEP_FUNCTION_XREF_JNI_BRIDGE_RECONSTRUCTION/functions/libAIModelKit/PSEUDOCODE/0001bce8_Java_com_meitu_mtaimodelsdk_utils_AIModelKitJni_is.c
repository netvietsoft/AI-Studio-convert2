// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1bce8
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_isModelCached
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1bce8 | Size: 276 bytes | SHA256: 6868f78102daeef861cc1ed7a9ce29772a79c6ee879f372cc74784ea7e579a72
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _Z17loadLibraryHandlev, __android_log_print, dlerror, dlsym
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to find IsModelCached: %s"
//   "Failed to get model data from jbyteArray"
//   "IsModelCached"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_isModelCached(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 69 instructions
    /* 0x1bce8 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x1bcec */ stp x26, x25, [sp, #0x10];
    /* 0x1bcf0 */ stp x24, x23, [sp, #0x20];
    /* 0x1bcf4 */ stp x22, x21, [sp, #0x30];
    /* 0x1bcf8 */ stp x20, x19, [sp, #0x40];
    /* 0x1bcfc */ mov x29, sp;
    /* 0x1bd00 */ mov w21, w5;
    /* 0x1bd04 */ mov w22, w4;
    /* 0x1bd08 */ mov w23, w3;
    /* 0x1bd0c */ mov x19, x2;
    /* 0x1bd10 */ mov x20, x0;
    _Z17loadLibraryHandlev();
    dlsym();
    dlerror();
    __android_log_print();
    __android_log_print();
    return x0;
}
