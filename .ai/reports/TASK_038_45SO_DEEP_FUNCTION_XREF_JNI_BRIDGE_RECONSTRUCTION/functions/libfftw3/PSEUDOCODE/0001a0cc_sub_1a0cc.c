// Library: libfftw3.so
// Function ID: libfftw3::0x1a0cc
// Recovered Name: sub_1a0cc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1a0cc | Size: 68 bytes | SHA256: 6c4a710b3aaccdacd1a42e57e9f3eb5ee085266ffd42b26e0a6314e823c3bb25
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: fftwf_ifree, fftwf_plan_awake, fftwf_plan_destroy_internal, fftwf_problem_destroy

void sub_1a0cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x1a0cc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1a0d0 */ str x19, [sp, #0x10];
    /* 0x1a0d4 */ mov x29, sp;
    /* 0x1a0d8 */ ldr x8, [x0];
    /* 0x1a0dc */ mov x19, x0;
    /* 0x1a0e0 */ mov w1, wzr;
    /* 0x1a0e4 */ mov x0, x8;
    fftwf_plan_awake();
    /* 0x1a0ec */ ldr x0, [x19];
    fftwf_plan_destroy_internal();
    /* 0x1a0f4 */ ldr x0, [x19, #8];
    fftwf_problem_destroy();
    return x0;
}
