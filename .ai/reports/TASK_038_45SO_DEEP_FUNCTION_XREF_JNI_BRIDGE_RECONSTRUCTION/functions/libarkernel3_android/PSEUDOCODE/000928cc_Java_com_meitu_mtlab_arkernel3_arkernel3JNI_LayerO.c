// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x928cc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1setLastObjectTrackingData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x928cc | Size: 32 bytes | SHA256: 7620680f2360686429aab4ee9a0fb20df9b7c42f4fae32e276b6a98b927a2134
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar330LayerObjectTrackingInteraction25setLastObjectTrackingDataERKNS_18ObjectTrackingDataE
// Strings referenced:
//   "mtlabar3::ObjectTrackingData const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1setLastObjectTrackingData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x928cc */ cbz x4, #0x928dc;
    /* 0x928d0 */ mov x0, x2;
    /* 0x928d4 */ mov x1, x4;
    /* 0x928d8 */ b #0xa2fb0;
    /* 0x928dc */ adrp x2, #0x6d000;
    /* 0x928e0 */ add x2, x2, #0x5c0;
    /* 0x928e4 */ mov w1, #7;
    /* 0x928e8 */ b #0x882c8;
}
