// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88c08
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorPoint2F_1clear
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88c08 | Size: 12 bytes | SHA256: f91c2fcfb02c7bd913645ffaa91273e1859fc5d592f8733fcdfb764a76402a75
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorPoint2F_1clear(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x88c08 */ ldr x8, [x2];
    /* 0x88c0c */ str x8, [x2, #8];
    return x0;
}
