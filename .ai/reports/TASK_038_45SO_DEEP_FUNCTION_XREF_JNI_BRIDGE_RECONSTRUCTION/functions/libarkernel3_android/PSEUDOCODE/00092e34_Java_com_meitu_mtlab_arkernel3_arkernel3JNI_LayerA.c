// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92e34
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getLoopState
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92e34 | Size: 28 bytes | SHA256: ba9137eb08a50e12e5e16957bba191a5370dada27a3558e9dd4d292abbacdf80
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction12getLoopStateEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getLoopState(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92e34 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92e38 */ mov x29, sp;
    /* 0x92e3c */ mov x0, x2;
    _ZN8mtlabar325LayerAnimationInteraction12getLoopStateEv();
    /* 0x92e44 */ and w0, w0, #1;
    /* 0x92e48 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
