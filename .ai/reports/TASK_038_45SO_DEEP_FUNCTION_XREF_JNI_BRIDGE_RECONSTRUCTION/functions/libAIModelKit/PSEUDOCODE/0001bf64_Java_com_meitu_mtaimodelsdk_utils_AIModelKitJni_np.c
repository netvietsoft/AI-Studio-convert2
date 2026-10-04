// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1bf64
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_npuIsSupport
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1bf64 | Size: 76 bytes | SHA256: bb20ea39450bf44121f6b792f5f9487117d0f40c3e890fd42a9f9e2749021720
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _Z27ensureManisDeviceInfoLoadedv, __android_log_print
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to load Manis device info for NPU support"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_npuIsSupport(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x1bf64 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1bf68 */ mov x29, sp;
    _Z27ensureManisDeviceInfoLoadedv();
    /* 0x1bf70 */ adrp x8, #0x4b000;
    /* 0x1bf74 */ ldrb w8, [x8, #0xee0];
    /* 0x1bf78 */ cbz w8, #0x1bf8c;
    /* 0x1bf7c */ adrp x8, #0x4c000;
    /* 0x1bf80 */ ldrb w0, [x8, #0x3e4];
    /* 0x1bf84 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1bf8c */ adrp x1, #0x10000;
    __android_log_print();
    return x0;
}
