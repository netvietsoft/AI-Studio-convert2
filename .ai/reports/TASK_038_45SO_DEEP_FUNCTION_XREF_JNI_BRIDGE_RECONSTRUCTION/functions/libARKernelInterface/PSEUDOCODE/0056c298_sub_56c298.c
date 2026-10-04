// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56c298
// Recovered Name: sub_56c298
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56c298 | Size: 348 bytes | SHA256: 7ae37055267f3e6634fd7db1191befc3eececebcbd112f6e4b4f220ec1f66b79
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: nativeSetFaceHairMask(JILjava/nio/ByteBuffer;II)V (table at 0x10cd2c8)
// Calls external APIs: _Znam, __android_log_print, memcpy
// Strings referenced:
//   "arkernel"
//   "nullptr == jHairHairMaskData:%d"

jlong sub_56c298(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 87 instructions
    /* 0x56c298 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x56c29c */ str x25, [sp, #0x10];
    /* 0x56c2a0 */ stp x24, x23, [sp, #0x20];
    /* 0x56c2a4 */ stp x22, x21, [sp, #0x30];
    /* 0x56c2a8 */ stp x20, x19, [sp, #0x40];
    /* 0x56c2ac */ mov x29, sp;
    /* 0x56c2b0 */ cbz x2, #0x56c3ac;
    /* 0x56c2b4 */ cmp w3, #0x13;
    /* 0x56c2b8 */ b.gt #0x56c3ac;
    /* 0x56c2bc */ sxtw x22, w3;
    /* 0x56c2c0 */ cbz x4, #0x56c348;
    _Znam();
    memcpy();
    return x0;
}
