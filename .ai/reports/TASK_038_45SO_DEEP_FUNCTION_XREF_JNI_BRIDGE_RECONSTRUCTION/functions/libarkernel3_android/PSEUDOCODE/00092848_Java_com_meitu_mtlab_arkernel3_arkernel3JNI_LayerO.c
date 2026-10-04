// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92848
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1getIsObjectTrackingRunning
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92848 | Size: 28 bytes | SHA256: 66fbcd4ba0e8c2d0255fd5cb4dd3d460a0636ab04f85fb99341352c042e28b20
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar330LayerObjectTrackingInteraction26getIsObjectTrackingRunningEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1getIsObjectTrackingRunning(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92848 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9284c */ mov x29, sp;
    /* 0x92850 */ mov x0, x2;
    _ZN8mtlabar330LayerObjectTrackingInteraction26getIsObjectTrackingRunningEv();
    /* 0x92858 */ and w0, w0, #1;
    /* 0x9285c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
