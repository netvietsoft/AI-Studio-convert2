// Library: libarkernel3.so
// Function ID: libarkernel3::0x61f9c0
// Recovered Name: sub_61f9c0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61f9c0 | Size: 528 bytes | SHA256: dd232d97e9301832f1269b4c102e212ba87d9bff3aba7c2a0279c62f30a65f9a
// Callers: 0 | Callees: 10 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "Failed to convert parameter to type 'Vector2'."
//   "Invalid number of parameters (expected 5)."
//   "Vector2"
//   "lua_GPMakeup2D_Judge2LineSegmentIntersect - Failed to match the given 5 parameters to a valid function signature."

void sub_61f9c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 132 instructions
    /* 0x61f9c0 */ stp x29, x30, [sp, #0x40];
    /* 0x61f9c4 */ str x23, [sp, #0x50];
    /* 0x61f9c8 */ stp x22, x21, [sp, #0x60];
    /* 0x61f9cc */ stp x20, x19, [sp, #0x70];
    /* 0x61f9d0 */ add x29, sp, #0x40;
    /* 0x61f9d4 */ mrs x21, tpidr_el0;
    /* 0x61f9d8 */ mov x19, x0;
    /* 0x61f9dc */ ldr x8, [x21, #0x28];
    /* 0x61f9e0 */ stur x8, [x29, #-8];
    sub_b783a0();
    /* 0x61f9e8 */ cmp w0, #5;
    sub_b7868c();
    sub_b7868c();
    sub_b7868c();
    sub_b7868c();
    sub_b7868c();
    sub_b7868c();
    sub_b7868c();
    sub_b7868c();
    sub_b7868c();
    sub_b78de0();
    sub_b79ca8();
    return x0;
    sub_5b0f04();
    sub_5b10ec();
    sub_b78de0();
    sub_b79ca8();
    sub_5b10ec();
    sub_61d7d0();
    sub_601ab4();
    sub_b79080();
    sub_5b10ec();
    sub_106b814();
    __stack_chk_fail();
}
