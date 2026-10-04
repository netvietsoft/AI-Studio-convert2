// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93f34
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionFaceMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93f34 | Size: 28 bytes | SHA256: 8a93abcccaa6d690fec53fd31130ce83814f146ea8564b040436c09174bc7e54
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire31requireFaceDataAdditionFaceMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionFaceMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93f34 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93f38 */ mov x29, sp;
    /* 0x93f3c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire31requireFaceDataAdditionFaceMaskEv();
    /* 0x93f44 */ and w0, w0, #1;
    /* 0x93f48 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
