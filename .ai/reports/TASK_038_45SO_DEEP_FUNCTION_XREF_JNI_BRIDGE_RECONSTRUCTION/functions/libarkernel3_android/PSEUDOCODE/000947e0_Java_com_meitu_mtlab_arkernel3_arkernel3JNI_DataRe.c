// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x947e0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DBreastLift
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x947e0 | Size: 28 bytes | SHA256: b134b8f473a97430359a9514f8bd6272079377f99ea4c21aec3f8986e10c78a6
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire27requireBodySlim3DBreastLiftEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DBreastLift(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x947e0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x947e4 */ mov x29, sp;
    /* 0x947e8 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire27requireBodySlim3DBreastLiftEv();
    /* 0x947f0 */ and w0, w0, #1;
    /* 0x947f4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
