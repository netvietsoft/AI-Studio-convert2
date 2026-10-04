// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93fdc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAddition3DFA
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93fdc | Size: 28 bytes | SHA256: 4cf42ab0d9e2b2b9a28c01812a3638b07e5233cf460536442fcf26e9c0770ff5
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire27requireFaceDataAddition3DFAEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAddition3DFA(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93fdc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93fe0 */ mov x29, sp;
    /* 0x93fe4 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire27requireFaceDataAddition3DFAEv();
    /* 0x93fec */ and w0, w0, #1;
    /* 0x93ff0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
