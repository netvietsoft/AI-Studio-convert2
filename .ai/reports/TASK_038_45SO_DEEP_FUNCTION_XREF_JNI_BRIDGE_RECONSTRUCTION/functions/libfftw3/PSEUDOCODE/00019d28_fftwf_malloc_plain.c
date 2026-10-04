// Library: libfftw3.so
// Function ID: libfftw3::0x19d28
// Recovered Name: fftwf_malloc_plain
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x19d28 | Size: 88 bytes | SHA256: 3a1d493f91d00d7cc6321aa3090422116ce9872c34285015d481ed254b70342d
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: fftwf_assertion_failed, fftwf_kernel_malloc
// Strings referenced:
//   "/Volumes/workspace/Git/tool/fftw/clip/src/alloc.c"

void fftwf_malloc_plain(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 22 instructions
    /* 0x19d28 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x19d2c */ str x19, [sp, #0x10];
    /* 0x19d30 */ mov x29, sp;
    /* 0x19d34 */ cmp x0, #1;
    /* 0x19d38 */ csinc x0, x0, xzr, hi;
    fftwf_kernel_malloc();
    /* 0x19d40 */ cbz x0, #0x19d50;
    /* 0x19d44 */ ldr x19, [sp, #0x10];
    /* 0x19d48 */ ldp x29, x30, [sp], #0x20;
    return x0;
    /* 0x19d50 */ nop ;
    fftwf_assertion_failed();
    return x0;
}
