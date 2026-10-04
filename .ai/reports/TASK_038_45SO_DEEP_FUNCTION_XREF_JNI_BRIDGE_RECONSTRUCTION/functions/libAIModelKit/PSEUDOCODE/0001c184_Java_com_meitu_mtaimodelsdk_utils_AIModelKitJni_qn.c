// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1c184
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_qnnIsSupport
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1c184 | Size: 76 bytes | SHA256: bb9dc230c34317dbb718dae4f0d73ef89bbc0021b2ae82732e430de048a920b3
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _Z27ensureManisDeviceInfoLoadedv, __android_log_print
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to load Manis device info for QNN support"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_qnnIsSupport(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x1c184 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1c188 */ mov x29, sp;
    _Z27ensureManisDeviceInfoLoadedv();
    /* 0x1c190 */ adrp x8, #0x4b000;
    /* 0x1c194 */ ldrb w8, [x8, #0xee0];
    /* 0x1c198 */ cbz w8, #0x1c1ac;
    /* 0x1c19c */ adrp x8, #0x4c000;
    /* 0x1c1a0 */ ldrb w0, [x8, #0x3e3];
    /* 0x1c1a4 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1c1ac */ adrp x1, #0x10000;
    __android_log_print();
    return x0;
}
