// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9a4ac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Graphics_1createTextureWithOpenGL
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9a4ac | Size: 316 bytes | SHA256: 40ae69b6e5695f386ea7caf9b921f6aac7714424f0ac626fc3340a8d59b16fb1
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZN8mtlabar38Graphics23createTextureWithOpenGLEmjj
// Strings referenced:
//   "()[B"
//   "BigInteger null"
//   "toByteArray"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Graphics_1createTextureWithOpenGL(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 79 instructions
    /* 0x9a4ac */ stp x29, x30, [sp, #-0x50]!;
    /* 0x9a4b0 */ str x25, [sp, #0x10];
    /* 0x9a4b4 */ stp x24, x23, [sp, #0x20];
    /* 0x9a4b8 */ stp x22, x21, [sp, #0x30];
    /* 0x9a4bc */ stp x20, x19, [sp, #0x40];
    /* 0x9a4c0 */ mov x29, sp;
    /* 0x9a4c4 */ mov x22, x0;
    /* 0x9a4c8 */ cbz x4, #0x9a580;
    /* 0x9a4cc */ ldr x8, [x22];
    /* 0x9a4d0 */ mov x0, x22;
    /* 0x9a4d4 */ mov x1, x4;
    sub_86eb0();
    sub_882c8();
    _ZN8mtlabar38Graphics23createTextureWithOpenGLEmjj();
    return x0;
}
