// Library: libfftw3.so
// Function ID: libfftw3::0x1a110
// Recovered Name: fftwf_assertion_failed
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1a110 | Size: 76 bytes | SHA256: c9326ead777561dba11989617c62e374d8911b95ceb21385564de0debc6bf345
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: abort, fflush, fprintf

void fftwf_assertion_failed(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x1a110 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x1a114 */ stp x22, x21, [sp, #0x10];
    /* 0x1a118 */ stp x20, x19, [sp, #0x20];
    /* 0x1a11c */ mov x29, sp;
    /* 0x1a120 */ adrp x22, #0x7d000;
    /* 0x1a124 */ mov x21, x0;
    /* 0x1a128 */ mov x19, x2;
    /* 0x1a12c */ ldr x22, [x22, #0xf48];
    /* 0x1a130 */ mov w20, w1;
    /* 0x1a134 */ add x0, x22, #0x98;
    fflush();
    fprintf();
    abort();
}
