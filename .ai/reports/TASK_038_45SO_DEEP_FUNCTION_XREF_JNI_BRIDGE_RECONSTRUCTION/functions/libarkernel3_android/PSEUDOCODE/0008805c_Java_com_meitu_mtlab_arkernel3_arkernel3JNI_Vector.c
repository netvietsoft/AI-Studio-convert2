// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8805c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColorA_1size
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8805c | Size: 28 bytes | SHA256: 9558e38c507cd0501f01ed684b9178c0991edc0b384618a134a15dff4101f0c4
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColorA_1size(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8805c */ ldp x9, x8, [x2];
    /* 0x88060 */ sub x8, x8, x9;
    /* 0x88064 */ mov x9, #-0x3333333333333334;
    /* 0x88068 */ asr x8, x8, #2;
    /* 0x8806c */ movk x9, #0xcccd;
    /* 0x88070 */ mul x0, x8, x9;
    return x0;
}
