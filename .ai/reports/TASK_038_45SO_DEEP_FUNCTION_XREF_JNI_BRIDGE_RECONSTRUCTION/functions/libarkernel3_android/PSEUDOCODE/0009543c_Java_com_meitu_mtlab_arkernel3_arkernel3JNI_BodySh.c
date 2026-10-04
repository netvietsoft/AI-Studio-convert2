// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9543c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodyShapingSideEffectState_1overall_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9543c | Size: 20 bytes | SHA256: 28cac96faa18582bbe8ceab1389ac4895747013fb032f15c77e2efd67e943df4
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodyShapingSideEffectState_1overall_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x9543c */ cbz x2, #0x9544c;
    /* 0x95440 */ tst w4, #0xff;
    /* 0x95444 */ cset w8, ne;
    /* 0x95448 */ strb w8, [x2];
    return x0;
}
