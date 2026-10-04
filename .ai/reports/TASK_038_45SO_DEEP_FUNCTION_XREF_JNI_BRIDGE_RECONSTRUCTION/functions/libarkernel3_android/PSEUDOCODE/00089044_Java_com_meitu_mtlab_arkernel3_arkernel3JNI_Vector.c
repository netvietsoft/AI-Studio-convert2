// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x89044
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorString_1size
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x89044 | Size: 28 bytes | SHA256: 546c220f65ecd6e3e478eb129a08fb5f4c633095d6f434dffa1ad0c7e18d0f84
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorString_1size(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x89044 */ ldp x9, x8, [x2];
    /* 0x89048 */ sub x8, x8, x9;
    /* 0x8904c */ mov x9, #-0x5555555555555556;
    /* 0x89050 */ asr x8, x8, #3;
    /* 0x89054 */ movk x9, #0xaaab;
    /* 0x89058 */ mul x0, x8, x9;
    return x0;
}
