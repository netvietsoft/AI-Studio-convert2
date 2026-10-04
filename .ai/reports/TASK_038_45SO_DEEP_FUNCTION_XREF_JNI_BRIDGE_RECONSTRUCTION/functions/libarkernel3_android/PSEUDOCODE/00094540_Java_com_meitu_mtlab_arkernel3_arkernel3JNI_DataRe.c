// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94540
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyAdditionJoint
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94540 | Size: 28 bytes | SHA256: 4ff1e5c83bff1595fe87950b010f637b11312a041186a6432f25d047c100f218
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire24requireBodyAdditionJointEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyAdditionJoint(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94540 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94544 */ mov x29, sp;
    /* 0x94548 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire24requireBodyAdditionJointEv();
    /* 0x94550 */ and w0, w0, #1;
    /* 0x94554 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
