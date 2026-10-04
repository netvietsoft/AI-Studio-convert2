// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92784
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1initObjectTracking
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92784 | Size: 32 bytes | SHA256: 3d506e7fc3a62677c48e8bf57eaac7befc1b5a3867b5a6a028cde86144904b28
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar330LayerObjectTrackingInteraction18initObjectTrackingERKNS_18ObjectTrackingDataE
// Strings referenced:
//   "mtlabar3::ObjectTrackingData const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1initObjectTracking(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x92784 */ cbz x4, #0x92794;
    /* 0x92788 */ mov x0, x2;
    /* 0x9278c */ mov x1, x4;
    /* 0x92790 */ b #0xa2f30;
    /* 0x92794 */ adrp x2, #0x6d000;
    /* 0x92798 */ add x2, x2, #0x5c0;
    /* 0x9279c */ mov w1, #7;
    /* 0x927a0 */ b #0x882c8;
}
