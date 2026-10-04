// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58c3e0
// Recovered Name: sub_58c3e0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58c3e0 | Size: 344 bytes | SHA256: 76d08e826a85b4d0112e69a6c4917031a6b0ab4bdb3add2d63ae078f846a641f
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nSetMakeupColorRGBA(J[F)V (table at 0x10d08e0)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "%f %f %f %f"
//   "arkernel"
//   "makeupcolor setMakeupColorRGBA"

jlong sub_58c3e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 86 instructions
    /* 0x58c3e0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x58c3e4 */ stp x22, x21, [sp, #0x10];
    /* 0x58c3e8 */ stp x20, x19, [sp, #0x20];
    /* 0x58c3ec */ mov x29, sp;
    /* 0x58c3f0 */ adrp x22, #0x10c5000;
    /* 0x58c3f4 */ mov x20, x3;
    /* 0x58c3f8 */ mov x19, x2;
    /* 0x58c3fc */ ldr x22, [x22, #0x7a8];
    /* 0x58c400 */ mov x21, x0;
    /* 0x58c404 */ ldr w8, [x22];
    /* 0x58c408 */ cmp w8, #2;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
