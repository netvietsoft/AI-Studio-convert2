// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d23c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorAnimationTimeType_1capacity
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d23c | Size: 20 bytes | SHA256: 6997f64fc8e5f7f1634935466422e4d0ae3ff0665e9fdf4e2ec75ece70fe8e28
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorAnimationTimeType_1capacity(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8d23c */ ldr x8, [x2, #0x10];
    /* 0x8d240 */ ldr x9, [x2];
    /* 0x8d244 */ sub x8, x8, x9;
    /* 0x8d248 */ asr x0, x8, #2;
    return x0;
}
