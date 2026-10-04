// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x940c4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDL3DData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x940c4 | Size: 28 bytes | SHA256: ca333561fa01696f8f88798b0d6151e0dda00bf603a4c890efa4390ac310a5cf
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire19requireFaceDL3DDataEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDL3DData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x940c4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x940c8 */ mov x29, sp;
    /* 0x940cc */ mov x0, x2;
    _ZNK8mtlabar311DataRequire19requireFaceDL3DDataEv();
    /* 0x940d4 */ and w0, w0, #1;
    /* 0x940d8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
