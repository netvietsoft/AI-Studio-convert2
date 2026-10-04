// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x928ac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1setFirstObjectTrackingData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x928ac | Size: 32 bytes | SHA256: bde3300cdcc9534318035681921c58080c318165a2b3b1a51e03c4e3f41931c4
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar330LayerObjectTrackingInteraction26setFirstObjectTrackingDataERKNS_18ObjectTrackingDataE
// Strings referenced:
//   "mtlabar3::ObjectTrackingData const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1setFirstObjectTrackingData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x928ac */ cbz x4, #0x928bc;
    /* 0x928b0 */ mov x0, x2;
    /* 0x928b4 */ mov x1, x4;
    /* 0x928b8 */ b #0xa2fa0;
    /* 0x928bc */ adrp x2, #0x6d000;
    /* 0x928c0 */ add x2, x2, #0x5c0;
    /* 0x928c4 */ mov w1, #7;
    /* 0x928c8 */ b #0x882c8;
}
