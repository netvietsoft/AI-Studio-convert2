// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa5e2c8
// Recovered Name: sub_a5e2c8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa5e2c8 | Size: 1120 bytes | SHA256: 10160e2a9d1c566328563fa17e34b0f31fa11bc1c39821911d71fd9ee3e1971a
// Callers: 0 | Callees: 3 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "u_bIsUseColor"
//   "u_matrix"
//   "u_segmentMaskTexture"
//   "u_texture"

void sub_a5e2c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 280 instructions
    /* 0xa5e2c8 */ stp x29, x30, [sp, #0x100];
    /* 0xa5e2cc */ str x28, [sp, #0x110];
    /* 0xa5e2d0 */ stp x20, x19, [sp, #0x120];
    /* 0xa5e2d4 */ add x29, sp, #0x100;
    /* 0xa5e2d8 */ mrs x20, tpidr_el0;
    /* 0xa5e2dc */ mov x19, x0;
    /* 0xa5e2e0 */ ldr x8, [x20, #0x28];
    /* 0xa5e2e4 */ stur x8, [x29, #-0x48];
    sub_a5e728();
    /* 0xa5e2ec */ ldr s2, [x19, #0x224];
    /* 0xa5e2f0 */ ldr s17, [x19, #0x2b0];
    sub_a5d8dc();
    sub_69b76c();
    sub_69b76c();
    return x0;
    __stack_chk_fail();
}
