// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56b0bc
// Recovered Name: sub_56b0bc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56b0bc | Size: 296 bytes | SHA256: 85ae2fa9323c95d83d1b6d31a486c55955b24c372ad1cd1d347988477c155a86
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetFacialInterPoint(JI[F)V (table at 0x10cd0b8)
// Calls external APIs: __android_log_print, memcpy
// Strings referenced:
//   "ARKernelFaceInterface::SetFacialInterPoint: data len = %d , face point count = %d"
//   "arkernel"

jlong sub_56b0bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 74 instructions
    /* 0x56b0bc */ stp x29, x30, [sp, #-0x30]!;
    /* 0x56b0c0 */ stp x22, x21, [sp, #0x10];
    /* 0x56b0c4 */ stp x20, x19, [sp, #0x20];
    /* 0x56b0c8 */ mov x29, sp;
    /* 0x56b0cc */ cbz x2, #0x56b1d4;
    /* 0x56b0d0 */ mov w22, w3;
    /* 0x56b0d4 */ cmp w3, #0x13;
    /* 0x56b0d8 */ b.hi #0x56b1d4;
    /* 0x56b0dc */ ldr x8, [x0];
    /* 0x56b0e0 */ mov x1, x4;
    /* 0x56b0e4 */ mov x19, x4;
    sub_5a6b20();
    memcpy();
    __android_log_print();
    return x0;
}
