// Library: libarkernel3.so
// Function ID: libarkernel3::0x6601d0
// Recovered Name: sub_6601d0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6601d0 | Size: 1512 bytes | SHA256: a201596d22de4aba5bf6625df6e10e1debd578063ea2fe8e459295a6c2c92e27
// Callers: 0 | Callees: 15 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "3DScene part"
//   "Acceleration"
//   "AccelerationVariance"
//   "AspectForward"
//   "AspectRight"

void sub_6601d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 378 instructions
    /* 0x6601d0 */ stp x29, x30, [sp, #0x10];
    /* 0x6601d4 */ stp x22, x21, [sp, #0x20];
    /* 0x6601d8 */ stp x20, x19, [sp, #0x30];
    /* 0x6601dc */ add x29, sp, #0x10;
    /* 0x6601e0 */ mrs x22, tpidr_el0;
    /* 0x6601e4 */ mov x19, x0;
    /* 0x6601e8 */ ldr x8, [x22, #0x28];
    /* 0x6601ec */ str x8, [sp, #8];
    sub_9b0424();
    /* 0x6601f4 */ adrp x1, #0x1d2000;
    /* 0x6601f8 */ add x1, x1, #0xfac;
    sub_6607b8();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660a78();
    sub_660b80();
    sub_660c7c();
    sub_660b80();
    sub_660b80();
    sub_660b80();
    sub_660b80();
    sub_660b80();
    sub_660b80();
    sub_660b80();
    sub_660c7c();
    sub_660b80();
    sub_660b80();
    sub_660b80();
    sub_660b80();
    sub_660d78();
    sub_660b80();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660b80();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660c7c();
    sub_660b80();
    sub_660b80();
    sub_660c7c();
    sub_660b80();
    sub_660b80();
    sub_660b80();
    sub_660c7c();
    sub_660c7c();
    sub_660b80();
    sub_660b80();
    sub_660b80();
    sub_660e74();
    sub_660e74();
    sub_660f70();
    sub_661078();
    sub_661174();
    sub_661250();
    sub_66134c();
    sub_66134c();
    sub_66134c();
    sub_661250();
    sub_661448();
    sub_661544();
    return x0;
    __stack_chk_fail();
}
