// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d30c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorAnimationTimeType_1add
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d30c | Size: 224 bytes | SHA256: 4fc00216a8c0200dfd4beb6e142b990161c8eb15e09e4cefe5821ccd3f8d5ed1
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorAnimationTimeType_1add(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 56 instructions
    /* 0x8d30c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8d310 */ str x21, [sp, #0x10];
    /* 0x8d314 */ stp x20, x19, [sp, #0x20];
    /* 0x8d318 */ mov x29, sp;
    /* 0x8d31c */ mov x8, x2;
    /* 0x8d320 */ mov x19, x2;
    /* 0x8d324 */ mov w20, w4;
    /* 0x8d328 */ ldr x10, [x8, #0x10]!;
    /* 0x8d32c */ ldur x9, [x8, #-8];
    /* 0x8d330 */ cmp x9, x10;
    /* 0x8d334 */ b.hs #0x8d344;
    sub_9bb70();
    _ZdlPv();
    return x0;
    sub_9bb5c();
}
