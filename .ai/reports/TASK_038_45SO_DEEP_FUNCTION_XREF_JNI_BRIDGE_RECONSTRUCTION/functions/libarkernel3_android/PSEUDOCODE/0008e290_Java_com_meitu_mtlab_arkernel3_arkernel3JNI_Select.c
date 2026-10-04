// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e290
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionAnimationInterface_1getDisplayInASRTime
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e290 | Size: 28 bytes | SHA256: c51a9102809d4eba46cadb9b1f9411b7b00727ec93d2dec6ccc7ba307124b10f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327SelectionAnimationInterface19getDisplayInASRTimeEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionAnimationInterface_1getDisplayInASRTime(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8e290 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8e294 */ mov x29, sp;
    /* 0x8e298 */ mov x0, x2;
    _ZNK8mtlabar327SelectionAnimationInterface19getDisplayInASRTimeEv();
    /* 0x8e2a0 */ and w0, w0, #1;
    /* 0x8e2a4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
