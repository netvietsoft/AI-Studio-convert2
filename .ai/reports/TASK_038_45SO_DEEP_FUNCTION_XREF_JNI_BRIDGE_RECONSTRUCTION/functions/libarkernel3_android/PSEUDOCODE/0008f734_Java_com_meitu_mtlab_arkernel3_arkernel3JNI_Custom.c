// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f734
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1getEnableScale
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f734 | Size: 28 bytes | SHA256: e8657f83fa1f99dd9fc5e40060bbfc1ff7dd6e7202241aa29e637ac0108668db
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar324CustomTransformInterface14getEnableScaleEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1getEnableScale(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8f734 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8f738 */ mov x29, sp;
    /* 0x8f73c */ mov x0, x2;
    _ZNK8mtlabar324CustomTransformInterface14getEnableScaleEv();
    /* 0x8f744 */ and w0, w0, #1;
    /* 0x8f748 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
