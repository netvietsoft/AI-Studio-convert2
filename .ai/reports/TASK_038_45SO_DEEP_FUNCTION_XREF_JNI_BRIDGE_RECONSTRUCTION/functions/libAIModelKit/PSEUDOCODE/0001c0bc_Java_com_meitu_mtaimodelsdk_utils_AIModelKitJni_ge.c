// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1c0bc
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getApuVersion
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1c0bc | Size: 100 bytes | SHA256: 7aa2cb5142f3f67d6baa8f466b744613f8455c5b02c78bdb0712f23724a3b1f5
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _Z27ensureManisDeviceInfoLoadedv, __android_log_print
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to load Manis device info for APU version"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getApuVersion(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x1c0bc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1c0c0 */ str x19, [sp, #0x10];
    /* 0x1c0c4 */ mov x29, sp;
    /* 0x1c0c8 */ mov x19, x0;
    _Z27ensureManisDeviceInfoLoadedv();
    /* 0x1c0d0 */ nop ;
    /* 0x1c0d4 */ adr x8, #0x4bee0;
    /* 0x1c0d8 */ ldrb w9, [x8];
    /* 0x1c0dc */ cbz w9, #0x1c0e8;
    /* 0x1c0e0 */ add x1, x8, #0x201;
    /* 0x1c0e4 */ b #0x1c108;
    __android_log_print();
}
