// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9a5e8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Graphics_1getOpenGLHandle
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9a5e8 | Size: 32 bytes | SHA256: 7eb54badb16981b1befb5c7b2d0671423c3b1533928c3d3e5f7a945d4b633898
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar38Graphics15getOpenGLHandleEP15WGPUTextureImpl

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Graphics_1getOpenGLHandle(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x9a5e8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9a5ec */ mov x29, sp;
    /* 0x9a5f0 */ mov x1, x4;
    /* 0x9a5f4 */ mov x0, x2;
    _ZN8mtlabar38Graphics15getOpenGLHandleEP15WGPUTextureImpl();
    /* 0x9a5fc */ mov w0, w0;
    /* 0x9a600 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
