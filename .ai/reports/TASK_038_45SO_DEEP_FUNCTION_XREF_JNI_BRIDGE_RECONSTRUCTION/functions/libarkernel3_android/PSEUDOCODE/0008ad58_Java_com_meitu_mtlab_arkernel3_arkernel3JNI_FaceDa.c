// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ad58
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceData_1hasFaceRect
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ad58 | Size: 28 bytes | SHA256: 0e367692ebc2ab196cc2841c1eddd0f0e57669db5a4e10946466ad48eacaa342
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar38FaceData11hasFaceRectEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceData_1hasFaceRect(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8ad58 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8ad5c */ mov x29, sp;
    /* 0x8ad60 */ mov x0, x2;
    _ZNK8mtlabar38FaceData11hasFaceRectEv();
    /* 0x8ad68 */ and w0, w0, #1;
    /* 0x8ad6c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
