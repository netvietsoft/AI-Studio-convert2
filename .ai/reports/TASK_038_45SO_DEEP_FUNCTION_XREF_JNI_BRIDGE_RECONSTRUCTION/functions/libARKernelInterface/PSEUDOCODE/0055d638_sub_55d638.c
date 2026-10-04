// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55d638
// Recovered Name: sub_55d638
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55d638 | Size: 152 bytes | SHA256: 8d4e9760f0b2fb503f6cf4005eb01b7924bc509fc6374fbd70675408f2ef5f18
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_55d638(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x55d638 */ stp x29, x30, [sp, #0x100];
    /* 0x55d63c */ stp x28, x19, [sp, #0x110];
    /* 0x55d640 */ add x29, sp, #0x100;
    /* 0x55d644 */ stp x3, x4, [x29, #-0x78];
    /* 0x55d648 */ sub x9, x29, #0x78;
    /* 0x55d64c */ mov x10, sp;
    /* 0x55d650 */ stp x5, x6, [x29, #-0x68];
    /* 0x55d654 */ add x10, x10, #0x80;
    /* 0x55d658 */ sub x3, x29, #0x50;
    /* 0x55d65c */ stur x7, [x29, #-0x58];
    /* 0x55d660 */ stp q0, q1, [sp];
    return x0;
    __stack_chk_fail();
}
