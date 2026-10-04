// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93f18
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionMouthMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93f18 | Size: 28 bytes | SHA256: 9c2be33ca0aaeca1c7a23b553f4d1a9f3e7abba01e495966782bb898b6253010
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire32requireFaceDataAdditionMouthMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionMouthMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93f18 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93f1c */ mov x29, sp;
    /* 0x93f20 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire32requireFaceDataAdditionMouthMaskEv();
    /* 0x93f28 */ and w0, w0, #1;
    /* 0x93f2c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
