// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x8943e4
// Recovered Name: sub_8943e4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8943e4 | Size: 268 bytes | SHA256: d3631d1b6f9217ac1212d5663b0b2e9e56064a41f387295e7794b422c10a9a98
// Callers: 1 | Callees: 2 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "SaveHairMask:%s"
//   "arkernel"
//   "pHairMaskTexture == nullptr:"

void sub_8943e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 67 instructions
    /* 0x8943e4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8943e8 */ str x21, [sp, #0x10];
    /* 0x8943ec */ stp x20, x19, [sp, #0x20];
    /* 0x8943f0 */ mov x29, sp;
    /* 0x8943f4 */ adrp x21, #0x10c5000;
    /* 0x8943f8 */ mov x19, x1;
    /* 0x8943fc */ mov x20, x0;
    /* 0x894400 */ ldr x21, [x21, #0x7a8];
    /* 0x894404 */ ldr w8, [x21];
    /* 0x894408 */ cmp w8, #2;
    /* 0x89440c */ b.gt #0x894454;
    sub_5a6b20();
    __android_log_print();
    sub_c38b3c();
    sub_5a6b20();
    __android_log_print();
    return x0;
}
