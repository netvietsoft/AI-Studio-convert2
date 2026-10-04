// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92828
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1setObjectTrackingData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92828 | Size: 32 bytes | SHA256: 2c701f5e7f0294cbc8764ab07d3b0f5ad72041aa75d048888df2422d036c56df
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar330LayerObjectTrackingInteraction21setObjectTrackingDataERKNS_18ObjectTrackingDataE
// Strings referenced:
//   "mtlabar3::ObjectTrackingData const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1setObjectTrackingData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x92828 */ cbz x4, #0x92838;
    /* 0x9282c */ mov x0, x2;
    /* 0x92830 */ mov x1, x4;
    /* 0x92834 */ b #0xa2f50;
    /* 0x92838 */ adrp x2, #0x6d000;
    /* 0x9283c */ add x2, x2, #0x5c0;
    /* 0x92840 */ mov w1, #7;
    /* 0x92844 */ b #0x882c8;
}
