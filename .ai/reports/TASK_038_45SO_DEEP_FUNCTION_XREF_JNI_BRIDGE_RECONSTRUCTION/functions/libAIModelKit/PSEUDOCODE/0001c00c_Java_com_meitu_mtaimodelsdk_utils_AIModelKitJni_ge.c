// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1c00c
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getClDriverVersion
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1c00c | Size: 100 bytes | SHA256: 5365e7ca29e1441b200cd69f9233750e2662503f64d286ad89426ec443788a6b
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _Z27ensureManisDeviceInfoLoadedv, __android_log_print
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to load Manis device info for CL driver version"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getClDriverVersion(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x1c00c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1c010 */ str x19, [sp, #0x10];
    /* 0x1c014 */ mov x29, sp;
    /* 0x1c018 */ mov x19, x0;
    _Z27ensureManisDeviceInfoLoadedv();
    /* 0x1c020 */ nop ;
    /* 0x1c024 */ adr x8, #0x4bee0;
    /* 0x1c028 */ ldrb w9, [x8];
    /* 0x1c02c */ cbz w9, #0x1c038;
    /* 0x1c030 */ add x1, x8, #0x101;
    /* 0x1c034 */ b #0x1c058;
    __android_log_print();
}
