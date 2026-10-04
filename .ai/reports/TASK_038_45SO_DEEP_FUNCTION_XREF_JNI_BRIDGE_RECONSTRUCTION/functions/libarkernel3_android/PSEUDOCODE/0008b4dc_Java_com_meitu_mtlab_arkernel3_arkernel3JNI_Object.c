// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b4dc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ObjectTrackingData_1scale_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b4dc | Size: 12 bytes | SHA256: a034a4a4788faa44105edefa58858d3841fc1142e1d72513779958aec3442909
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ObjectTrackingData_1scale_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8b4dc */ cbz x2, #0x8b4e4;
    /* 0x8b4e0 */ str s0, [x2, #0x1c];
    return x0;
}
