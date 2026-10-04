// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9a628
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Graphics_1createTextureWithOpenGLFormat
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9a628 | Size: 324 bytes | SHA256: 082b3599aca42d404ba6a1313620b29b0dfb2431ac6cd5945b64b40fa3e32163
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZN8mtlabar38Graphics29createTextureWithOpenGLFormatEmjjj
// Strings referenced:
//   "()[B"
//   "BigInteger null"
//   "toByteArray"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Graphics_1createTextureWithOpenGLFormat(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 81 instructions
    /* 0x9a628 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x9a62c */ stp x26, x25, [sp, #0x10];
    /* 0x9a630 */ stp x24, x23, [sp, #0x20];
    /* 0x9a634 */ stp x22, x21, [sp, #0x30];
    /* 0x9a638 */ stp x20, x19, [sp, #0x40];
    /* 0x9a63c */ mov x29, sp;
    /* 0x9a640 */ mov x23, x0;
    /* 0x9a644 */ cbz x4, #0x9a700;
    /* 0x9a648 */ ldr x8, [x23];
    /* 0x9a64c */ mov x0, x23;
    /* 0x9a650 */ mov x1, x4;
    sub_86eb0();
    sub_882c8();
    _ZN8mtlabar38Graphics29createTextureWithOpenGLFormatEmjjj();
    return x0;
}
