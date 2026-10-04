// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9447c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceNeckLineMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9447c | Size: 28 bytes | SHA256: f1de77a1de6c3387cb798387d6908ed47df45aac526b99dddee52600078aeec6
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire23requireFaceNeckLineMaskEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceNeckLineMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9447c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94480 */ mov x29, sp;
    /* 0x94484 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire23requireFaceNeckLineMaskEv();
    /* 0x9448c */ and w0, w0, #1;
    /* 0x94490 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
