// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88078
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColorA_1capacity
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88078 | Size: 32 bytes | SHA256: d401999684d4619cf7cb66ae784d3e05c877cf69d793f752fd3a1583354626b2
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColorA_1capacity(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x88078 */ ldr x8, [x2, #0x10];
    /* 0x8807c */ ldr x9, [x2];
    /* 0x88080 */ sub x8, x8, x9;
    /* 0x88084 */ mov x9, #-0x3333333333333334;
    /* 0x88088 */ asr x8, x8, #2;
    /* 0x8808c */ movk x9, #0xcccd;
    /* 0x88090 */ mul x0, x8, x9;
    return x0;
}
