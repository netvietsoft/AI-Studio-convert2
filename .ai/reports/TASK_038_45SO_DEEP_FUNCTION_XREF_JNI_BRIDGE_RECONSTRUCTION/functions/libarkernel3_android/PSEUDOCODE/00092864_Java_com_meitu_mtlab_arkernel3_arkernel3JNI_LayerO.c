// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92864
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1getIsObjectTrackingDataUseful
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92864 | Size: 28 bytes | SHA256: d8a88f8f0b6f253f3883313a3a63cbf26a67acfeff3628853a8d06a3bf1fd8d3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar330LayerObjectTrackingInteraction29getIsObjectTrackingDataUsefulEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1getIsObjectTrackingDataUseful(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92864 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92868 */ mov x29, sp;
    /* 0x9286c */ mov x0, x2;
    _ZN8mtlabar330LayerObjectTrackingInteraction29getIsObjectTrackingDataUsefulEv();
    /* 0x92874 */ and w0, w0, #1;
    /* 0x92878 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
