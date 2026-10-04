// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93ea8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionLimitMaxFaceCount
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93ea8 | Size: 28 bytes | SHA256: 1bd382fa39c67c88bf9348d2a62ad921067d5220f45bec8d4780d1516911bffd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire40requireFaceDataAdditionLimitMaxFaceCountEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionLimitMaxFaceCount(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93ea8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93eac */ mov x29, sp;
    /* 0x93eb0 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire40requireFaceDataAdditionLimitMaxFaceCountEv();
    /* 0x93eb8 */ mov w0, w0;
    /* 0x93ebc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
