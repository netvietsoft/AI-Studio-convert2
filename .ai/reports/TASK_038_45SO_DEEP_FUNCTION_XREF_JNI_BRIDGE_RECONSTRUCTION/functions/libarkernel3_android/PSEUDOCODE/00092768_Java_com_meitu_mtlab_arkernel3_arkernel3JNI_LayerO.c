// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92768
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1getEnableObjectTracking
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92768 | Size: 28 bytes | SHA256: 7ed298d99e02fc7702b6427a0497e3dee005fb25984810f846b07307647c2608
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar330LayerObjectTrackingInteraction23getEnableObjectTrackingEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1getEnableObjectTracking(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92768 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9276c */ mov x29, sp;
    /* 0x92770 */ mov x0, x2;
    _ZN8mtlabar330LayerObjectTrackingInteraction23getEnableObjectTrackingEv();
    /* 0x92778 */ and w0, w0, #1;
    /* 0x9277c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
