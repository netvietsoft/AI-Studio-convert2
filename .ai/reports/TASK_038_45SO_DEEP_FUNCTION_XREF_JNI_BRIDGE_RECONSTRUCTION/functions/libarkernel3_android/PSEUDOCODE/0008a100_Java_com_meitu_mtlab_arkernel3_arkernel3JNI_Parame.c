// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a100
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1enumeration_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a100 | Size: 12 bytes | SHA256: 25ad10762a3bb731e3def2d21fb09eec438839ab704e465dc26d65ff467d2f7e
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1enumeration_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8a100 */ cbz x2, #0x8a108;
    /* 0x8a104 */ str x4, [x2, #0x10];
    return x0;
}
