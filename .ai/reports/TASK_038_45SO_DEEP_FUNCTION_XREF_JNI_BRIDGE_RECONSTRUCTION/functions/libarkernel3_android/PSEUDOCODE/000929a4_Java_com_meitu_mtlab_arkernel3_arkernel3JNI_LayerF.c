// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x929a4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1setFaceTrackingNeedHidden
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x929a4 | Size: 16 bytes | SHA256: 1058886caab535b1574ca206fd3a39f985483259086824b500b34f54678e7a25
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar328LayerFaceTrackingInteraction25setFaceTrackingNeedHiddenEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerFaceTrackingInteraction_1setFaceTrackingNeedHidden(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x929a4 */ tst w4, #0xff;
    /* 0x929a8 */ mov x0, x2;
    /* 0x929ac */ cset w1, ne;
    /* 0x929b0 */ b #0xa3030;
}
