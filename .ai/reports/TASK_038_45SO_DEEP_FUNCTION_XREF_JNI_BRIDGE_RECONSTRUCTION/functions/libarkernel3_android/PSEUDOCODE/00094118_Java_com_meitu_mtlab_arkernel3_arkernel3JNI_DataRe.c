// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94118
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDL3DDataAdditionBlendShapeFactor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94118 | Size: 28 bytes | SHA256: 1b56f79067f745f3af73df7a4d70ecc3532a840c94b43ca3384a9a7545b70a19
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire43requireFaceDL3DDataAdditionBlendShapeFactorEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDL3DDataAdditionBlendShapeFactor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94118 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9411c */ mov x29, sp;
    /* 0x94120 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire43requireFaceDL3DDataAdditionBlendShapeFactorEv();
    /* 0x94128 */ and w0, w0, #1;
    /* 0x9412c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
