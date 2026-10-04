// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1bdfc
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_cacheModel
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1bdfc | Size: 276 bytes | SHA256: a1543b44a1766df8dc20f2de17c478957a4a5fbb634bdbf0916d80c4bdbd63b1
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _Z17loadLibraryHandlev, __android_log_print, dlerror, dlsym
// Strings referenced:
//   "AIModelKitJni"
//   "CacheModel"
//   "Failed to find CacheModel: %s"
//   "Failed to get model data from jbyteArray"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_cacheModel(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 69 instructions
    /* 0x1bdfc */ stp x29, x30, [sp, #-0x50]!;
    /* 0x1be00 */ stp x26, x25, [sp, #0x10];
    /* 0x1be04 */ stp x24, x23, [sp, #0x20];
    /* 0x1be08 */ stp x22, x21, [sp, #0x30];
    /* 0x1be0c */ stp x20, x19, [sp, #0x40];
    /* 0x1be10 */ mov x29, sp;
    /* 0x1be14 */ mov w21, w5;
    /* 0x1be18 */ mov w22, w4;
    /* 0x1be1c */ mov w23, w3;
    /* 0x1be20 */ mov x19, x2;
    /* 0x1be24 */ mov x20, x0;
    _Z17loadLibraryHandlev();
    dlsym();
    dlerror();
    __android_log_print();
    __android_log_print();
    return x0;
}
