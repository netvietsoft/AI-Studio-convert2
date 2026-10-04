// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92880
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1setObjectTrackingNeedHidden
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92880 | Size: 16 bytes | SHA256: 545df788af7a1a7434df650d6de756efcd90df5933193d62be03b8b5947291fc
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar330LayerObjectTrackingInteraction27setObjectTrackingNeedHiddenEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1setObjectTrackingNeedHidden(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x92880 */ tst w4, #0xff;
    /* 0x92884 */ mov x0, x2;
    /* 0x92888 */ cset w1, ne;
    /* 0x9288c */ b #0xa2f80;
}
