// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93fa4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionEyelid
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93fa4 | Size: 28 bytes | SHA256: 88324796ae4574d075660626bffe0af2e0429f37420e525a75fccb232fb7461d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire29requireFaceDataAdditionEyelidEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionEyelid(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93fa4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93fa8 */ mov x29, sp;
    /* 0x93fac */ mov x0, x2;
    _ZNK8mtlabar311DataRequire29requireFaceDataAdditionEyelidEv();
    /* 0x93fb4 */ and w0, w0, #1;
    /* 0x93fb8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
