// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98a54
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VisualAllocator_1acquireBuffer
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98a54 | Size: 404 bytes | SHA256: d143d119d863fa72c7121f40837ee46a7ec1796de3e859b2e71ec6d882869b1b
// Callers: 0 | Callees: 2 | Imports: 0

// Strings referenced:
//   "()[B"
//   "BigInteger null"
//   "toByteArray"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VisualAllocator_1acquireBuffer(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 101 instructions
    /* 0x98a54 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x98a58 */ stp x26, x25, [sp, #0x10];
    /* 0x98a5c */ stp x24, x23, [sp, #0x20];
    /* 0x98a60 */ stp x22, x21, [sp, #0x30];
    /* 0x98a64 */ stp x20, x19, [sp, #0x40];
    /* 0x98a68 */ mov x29, sp;
    /* 0x98a6c */ mov x24, x6;
    /* 0x98a70 */ mov x21, x5;
    /* 0x98a74 */ mov x20, x4;
    /* 0x98a78 */ mov x22, x2;
    /* 0x98a7c */ mov x19, x0;
    sub_86eb0();
    sub_882c8();
    return x0;
}
