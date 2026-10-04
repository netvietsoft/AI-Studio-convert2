// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x941a4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHandDataAdditionPose
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x941a4 | Size: 28 bytes | SHA256: 4bdfa14780b0438aee2e09df664f3671eaab04b85195979922d36ae510a9344c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire27requireHandDataAdditionPoseEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHandDataAdditionPose(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x941a4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x941a8 */ mov x29, sp;
    /* 0x941ac */ mov x0, x2;
    _ZNK8mtlabar311DataRequire27requireHandDataAdditionPoseEv();
    /* 0x941b4 */ and w0, w0, #1;
    /* 0x941b8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
