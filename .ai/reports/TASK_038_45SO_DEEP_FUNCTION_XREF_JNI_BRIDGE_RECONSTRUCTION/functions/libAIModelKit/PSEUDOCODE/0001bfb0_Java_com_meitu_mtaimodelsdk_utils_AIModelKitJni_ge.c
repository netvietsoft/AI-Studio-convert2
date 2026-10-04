// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1bfb0
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getClDeviceVersion
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1bfb0 | Size: 92 bytes | SHA256: 8b579677c917bea871ce9005f14382cc4dabbb86027bb3661bd154ee30956e29
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _Z27ensureManisDeviceInfoLoadedv, __android_log_print
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to load Manis device info for CL device version"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getClDeviceVersion(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x1bfb0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1bfb4 */ str x19, [sp, #0x10];
    /* 0x1bfb8 */ mov x29, sp;
    /* 0x1bfbc */ mov x19, x0;
    _Z27ensureManisDeviceInfoLoadedv();
    /* 0x1bfc4 */ nop ;
    /* 0x1bfc8 */ adr x1, #0x4bee0;
    /* 0x1bfcc */ ldrb w8, [x1], #1;
    /* 0x1bfd0 */ cbnz w8, #0x1bff4;
    /* 0x1bfd4 */ adrp x1, #0x10000;
    /* 0x1bfd8 */ add x1, x1, #0x466;
    __android_log_print();
}
