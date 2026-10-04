// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1c1d0
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getNpuVersion
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1c1d0 | Size: 100 bytes | SHA256: a46752613cc04835d42b84d568d8da9f6654bd89349aa0f390455f2b90debb96
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _Z27ensureManisDeviceInfoLoadedv, __android_log_print
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to load Manis device info for NPU version"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getNpuVersion(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x1c1d0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1c1d4 */ str x19, [sp, #0x10];
    /* 0x1c1d8 */ mov x29, sp;
    /* 0x1c1dc */ mov x19, x0;
    _Z27ensureManisDeviceInfoLoadedv();
    /* 0x1c1e4 */ nop ;
    /* 0x1c1e8 */ adr x8, #0x4bee0;
    /* 0x1c1ec */ ldrb w9, [x8];
    /* 0x1c1f0 */ cbz w9, #0x1c1fc;
    /* 0x1c1f4 */ add x1, x8, #0x401;
    /* 0x1c1f8 */ b #0x1c21c;
    __android_log_print();
}
