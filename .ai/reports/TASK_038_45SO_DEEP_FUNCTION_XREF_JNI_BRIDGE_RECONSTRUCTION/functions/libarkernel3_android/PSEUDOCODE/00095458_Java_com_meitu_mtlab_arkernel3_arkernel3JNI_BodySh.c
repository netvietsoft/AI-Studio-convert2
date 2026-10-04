// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95458
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodyShapingSideEffectState_1left_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95458 | Size: 20 bytes | SHA256: 14859c5ba1c8e6b47d2e0cf68b7dcfdfc37860379f148977822ab160598ac8b8
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodyShapingSideEffectState_1left_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x95458 */ cbz x2, #0x95468;
    /* 0x9545c */ tst w4, #0xff;
    /* 0x95460 */ cset w8, ne;
    /* 0x95464 */ strb w8, [x2, #1];
    return x0;
}
