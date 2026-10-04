// Library: libfftw3.so
// Function ID: libfftw3::0x19d94
// Recovered Name: sub_19d94
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x19d94 | Size: 456 bytes | SHA256: 4e4a658aec41d99b86fd893730b184babe709c49d3794bb45f37a8880de4a524
// Callers: 0 | Callees: 1 | Imports: 7

// Calls external APIs: fftwf_get_crude_time, fftwf_malloc_plain, fftwf_mapflags, fftwf_plan_awake, fftwf_plan_destroy_internal, fftwf_problem_destroy, fftwf_the_planner

void sub_19d94(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 114 instructions
    /* 0x19d94 */ stp x29, x30, [sp, #8];
    /* 0x19d98 */ str x27, [sp, #0x18];
    /* 0x19d9c */ stp x26, x25, [sp, #0x20];
    /* 0x19da0 */ stp x24, x23, [sp, #0x30];
    /* 0x19da4 */ stp x22, x21, [sp, #0x40];
    /* 0x19da8 */ stp x20, x19, [sp, #0x50];
    /* 0x19dac */ add x29, sp, #8;
    /* 0x19db0 */ mov x20, x2;
    /* 0x19db4 */ mov w22, w1;
    /* 0x19db8 */ mov w21, w0;
    fftwf_the_planner();
    fftwf_get_crude_time();
    sub_19f5c();
    fftwf_plan_destroy_internal();
    sub_19f5c();
    fftwf_mapflags();
    fftwf_malloc_plain();
    sub_19f5c();
    fftwf_plan_awake();
    fftwf_plan_destroy_internal();
    fftwf_problem_destroy();
    return x0;
}
