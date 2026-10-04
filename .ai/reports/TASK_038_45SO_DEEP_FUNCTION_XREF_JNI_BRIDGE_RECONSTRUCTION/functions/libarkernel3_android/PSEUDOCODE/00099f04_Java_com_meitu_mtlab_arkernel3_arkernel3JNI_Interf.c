// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99f04
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1getMemoryUsage
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99f04 | Size: 296 bytes | SHA256: f5d0c53cb39d6271244c660521c0f9a903ff0d7c6a189ed3a228f56591894ffd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar39Interface14getMemoryUsageEv
// Strings referenced:
//   "([B)V"
//   "<init>"
//   "java/math/BigInteger"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1getMemoryUsage(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 74 instructions
    /* 0x99f04 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x99f08 */ str x23, [sp, #0x10];
    /* 0x99f0c */ stp x22, x21, [sp, #0x20];
    /* 0x99f10 */ stp x20, x19, [sp, #0x30];
    /* 0x99f14 */ mov x29, sp;
    /* 0x99f18 */ mov x19, x0;
    /* 0x99f1c */ mov x0, x2;
    _ZNK8mtlabar39Interface14getMemoryUsageEv();
    /* 0x99f24 */ ldr x8, [x19];
    /* 0x99f28 */ mov x21, x0;
    /* 0x99f2c */ mov x0, x19;
}
