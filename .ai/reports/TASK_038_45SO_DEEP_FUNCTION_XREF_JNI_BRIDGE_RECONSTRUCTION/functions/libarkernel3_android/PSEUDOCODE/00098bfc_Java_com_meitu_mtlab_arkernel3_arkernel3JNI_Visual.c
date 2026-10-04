// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98bfc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VisualAllocator_1releaseBuffer
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98bfc | Size: 20 bytes | SHA256: 2413d125dc9e879825178d5b7545a2d4681b1a117274d13cc5a0f2faa269f470
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VisualAllocator_1releaseBuffer(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x98bfc */ ldr x8, [x2];
    /* 0x98c00 */ mov x0, x2;
    /* 0x98c04 */ mov x1, x4;
    /* 0x98c08 */ ldr x2, [x8, #0x18];
    /* 0x98c0c */ br x2;
}
