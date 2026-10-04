// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92758
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1setEnableObjectTracking
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92758 | Size: 16 bytes | SHA256: 187e750303afdce09d5601e9b417e64cf44a7b55568747684ca5d5e051bee2b7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar330LayerObjectTrackingInteraction23setEnableObjectTrackingEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1setEnableObjectTracking(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x92758 */ tst w4, #0xff;
    /* 0x9275c */ mov x0, x2;
    /* 0x92760 */ cset w1, ne;
    /* 0x92764 */ b #0xa2f10;
}
