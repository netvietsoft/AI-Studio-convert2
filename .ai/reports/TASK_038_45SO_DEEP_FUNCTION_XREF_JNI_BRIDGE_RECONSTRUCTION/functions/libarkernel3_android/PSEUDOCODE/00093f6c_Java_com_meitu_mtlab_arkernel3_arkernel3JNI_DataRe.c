// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93f6c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionGender
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93f6c | Size: 28 bytes | SHA256: e13902be6b16340f24ba39243818446f65a5b1bbc65202dc408c46b7f51c8d6b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire29requireFaceDataAdditionGenderEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionGender(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93f6c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93f70 */ mov x29, sp;
    /* 0x93f74 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire29requireFaceDataAdditionGenderEv();
    /* 0x93f7c */ and w0, w0, #1;
    /* 0x93f80 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
