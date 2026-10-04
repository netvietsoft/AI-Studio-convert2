// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88678
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColor_1capacity
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88678 | Size: 20 bytes | SHA256: f60f1d75123370cf585e888d20e3a8f701c347e6b99d59015a12543620e009de
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColor_1capacity(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x88678 */ ldr x8, [x2, #0x10];
    /* 0x8867c */ ldr x9, [x2];
    /* 0x88680 */ sub x8, x8, x9;
    /* 0x88684 */ asr x0, x8, #4;
    return x0;
}
