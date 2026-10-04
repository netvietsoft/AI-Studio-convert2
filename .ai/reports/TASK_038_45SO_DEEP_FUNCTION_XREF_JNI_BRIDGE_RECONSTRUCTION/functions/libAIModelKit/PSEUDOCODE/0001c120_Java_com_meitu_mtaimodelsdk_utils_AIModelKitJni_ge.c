// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1c120
// Recovered Name: Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getQnnVersion
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1c120 | Size: 100 bytes | SHA256: 08d0a4c835a2ee77a18b92f8bc78990484f641ef58a33b60751e008489db55a9
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _Z27ensureManisDeviceInfoLoadedv, __android_log_print
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to load Manis device info for QNN version"

jlong Java_com_meitu_mtaimodelsdk_utils_AIModelKitJni_getQnnVersion(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x1c120 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1c124 */ str x19, [sp, #0x10];
    /* 0x1c128 */ mov x29, sp;
    /* 0x1c12c */ mov x19, x0;
    _Z27ensureManisDeviceInfoLoadedv();
    /* 0x1c134 */ nop ;
    /* 0x1c138 */ adr x8, #0x4bee0;
    /* 0x1c13c */ ldrb w9, [x8];
    /* 0x1c140 */ cbz w9, #0x1c14c;
    /* 0x1c144 */ add x1, x8, #0x301;
    /* 0x1c148 */ b #0x1c16c;
    __android_log_print();
}
