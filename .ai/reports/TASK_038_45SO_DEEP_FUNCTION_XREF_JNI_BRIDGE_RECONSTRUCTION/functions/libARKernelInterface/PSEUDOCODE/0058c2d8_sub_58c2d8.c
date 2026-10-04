// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58c2d8
// Recovered Name: sub_58c2d8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58c2d8 | Size: 132 bytes | SHA256: 40fcc7c603f5d21b2b3d48e0614d36d63115ff3c88dd61879895d355637c9f31
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nSetMakeupColorAlpha(JI)V (table at 0x10d08b0)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "arkernel"
//   "makeupcolor setMakeupColorAlpha"

jlong sub_58c2d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x58c2d8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58c2dc */ stp x20, x19, [sp, #0x10];
    /* 0x58c2e0 */ mov x29, sp;
    /* 0x58c2e4 */ adrp x8, #0x10c5000;
    /* 0x58c2e8 */ mov w19, w3;
    /* 0x58c2ec */ mov x20, x2;
    /* 0x58c2f0 */ ldr x8, [x8, #0x7a8];
    /* 0x58c2f4 */ ldr w8, [x8];
    /* 0x58c2f8 */ cmp w8, #2;
    /* 0x58c2fc */ b.gt #0x58c328;
    /* 0x58c300 */ adrp x8, #0x1108000;
    sub_5a6b20();
    return x0;
    __android_log_print();
}
