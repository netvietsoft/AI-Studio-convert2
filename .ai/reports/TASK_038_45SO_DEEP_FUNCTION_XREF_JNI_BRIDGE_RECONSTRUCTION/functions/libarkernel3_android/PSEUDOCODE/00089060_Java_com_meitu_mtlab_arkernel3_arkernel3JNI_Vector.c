// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x89060
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorString_1capacity
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x89060 | Size: 32 bytes | SHA256: 08ddbfe5288c47730cbc1dd61f4e5d973988b7dce925633c9e0aa184e13a7172
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorString_1capacity(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x89060 */ ldr x8, [x2, #0x10];
    /* 0x89064 */ ldr x9, [x2];
    /* 0x89068 */ sub x8, x8, x9;
    /* 0x8906c */ mov x9, #-0x5555555555555556;
    /* 0x89070 */ asr x8, x8, #3;
    /* 0x89074 */ movk x9, #0xaaab;
    /* 0x89078 */ mul x0, x8, x9;
    return x0;
}
