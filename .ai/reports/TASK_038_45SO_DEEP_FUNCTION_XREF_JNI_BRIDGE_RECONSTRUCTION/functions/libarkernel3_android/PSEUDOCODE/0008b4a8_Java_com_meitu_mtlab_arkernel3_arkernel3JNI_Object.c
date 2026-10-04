// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b4a8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ObjectTrackingData_1loss_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b4a8 | Size: 20 bytes | SHA256: 159b13f841215d24b38146afc3d412011a432683f15a5ea062ec3420808cc11c
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ObjectTrackingData_1loss_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8b4a8 */ cbz x2, #0x8b4b8;
    /* 0x8b4ac */ tst w4, #0xff;
    /* 0x8b4b0 */ cset w8, ne;
    /* 0x8b4b4 */ strb w8, [x2, #8];
    return x0;
}
