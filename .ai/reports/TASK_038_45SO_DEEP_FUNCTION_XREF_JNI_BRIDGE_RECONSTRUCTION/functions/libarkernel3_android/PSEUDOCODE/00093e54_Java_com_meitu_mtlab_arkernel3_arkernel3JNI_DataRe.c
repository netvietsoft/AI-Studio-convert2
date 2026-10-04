// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93e54
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireAnimalData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93e54 | Size: 28 bytes | SHA256: 0bd215796910e61a6323e232f9e2f2f0e95203b2b32ed0cc2ce861b7507b5fa8
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire17requireAnimalDataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireAnimalData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93e54 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93e58 */ mov x29, sp;
    /* 0x93e5c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire17requireAnimalDataEv();
    /* 0x93e64 */ and w0, w0, #1;
    /* 0x93e68 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
