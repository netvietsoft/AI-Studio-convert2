// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92890
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1getObjectTrackingNeedHidden
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92890 | Size: 28 bytes | SHA256: 8b35dd8161c45c323e3a4c0e588e37fd1a61603bfc7681b6adf755127bdb5a0e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar330LayerObjectTrackingInteraction27getObjectTrackingNeedHiddenEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerObjectTrackingInteraction_1getObjectTrackingNeedHidden(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92890 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92894 */ mov x29, sp;
    /* 0x92898 */ mov x0, x2;
    _ZN8mtlabar330LayerObjectTrackingInteraction27getObjectTrackingNeedHiddenEv();
    /* 0x928a0 */ and w0, w0, #1;
    /* 0x928a4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
