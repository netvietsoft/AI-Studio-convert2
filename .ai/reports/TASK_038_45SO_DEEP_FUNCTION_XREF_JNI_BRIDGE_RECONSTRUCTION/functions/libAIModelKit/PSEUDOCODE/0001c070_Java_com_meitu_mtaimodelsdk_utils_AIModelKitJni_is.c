// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1c070
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_isClSupportFp16
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1c070 | Size: 76 bytes | SHA256: 41f5a1346c78757698063414f96c9d04c86480d349fefd4f0007879d129ae4b3
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _Z27ensureManisDeviceInfoLoadedv, __android_log_print
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to load Manis device info for CL FP16 support"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_isClSupportFp16(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x1c070 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1c074 */ mov x29, sp;
    _Z27ensureManisDeviceInfoLoadedv();
    /* 0x1c07c */ adrp x8, #0x4b000;
    /* 0x1c080 */ ldrb w8, [x8, #0xee0];
    /* 0x1c084 */ cbz w8, #0x1c098;
    /* 0x1c088 */ adrp x8, #0x4c000;
    /* 0x1c08c */ ldrb w0, [x8, #0x3e1];
    /* 0x1c090 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1c098 */ adrp x1, #0x10000;
    __android_log_print();
    return x0;
}
