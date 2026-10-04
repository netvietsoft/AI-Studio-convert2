// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1c234
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_apuIsSupport
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1c234 | Size: 76 bytes | SHA256: ab2e85d6aff54c0d3fa9922216bd2c09a0c3499887b7f0cc3e3a718ad1a5876f
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _Z27ensureManisDeviceInfoLoadedv, __android_log_print
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to load Manis device info for APU support"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_apuIsSupport(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x1c234 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1c238 */ mov x29, sp;
    _Z27ensureManisDeviceInfoLoadedv();
    /* 0x1c240 */ adrp x8, #0x4b000;
    /* 0x1c244 */ ldrb w8, [x8, #0xee0];
    /* 0x1c248 */ cbz w8, #0x1c25c;
    /* 0x1c24c */ adrp x8, #0x4c000;
    /* 0x1c250 */ ldrb w0, [x8, #0x3e2];
    /* 0x1c254 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1c25c */ adrp x1, #0x10000;
    __android_log_print();
    return x0;
}
