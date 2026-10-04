// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x940e0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDL3DDataAdditionMesh
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x940e0 | Size: 28 bytes | SHA256: 14ce1c202a2b6408af324ad8657984ce2d2f7a8e5f8e1a33cb263c910f389724
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire31requireFaceDL3DDataAdditionMeshEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDL3DDataAdditionMesh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x940e0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x940e4 */ mov x29, sp;
    /* 0x940e8 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire31requireFaceDL3DDataAdditionMeshEv();
    /* 0x940f0 */ and w0, w0, #1;
    /* 0x940f4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
