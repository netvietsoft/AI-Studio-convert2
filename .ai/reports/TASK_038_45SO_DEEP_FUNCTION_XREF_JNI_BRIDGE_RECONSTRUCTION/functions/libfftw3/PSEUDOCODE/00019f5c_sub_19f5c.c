// Library: libfftw3.so
// Function ID: libfftw3::0x19f5c
// Recovered Name: sub_19f5c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x19f5c | Size: 364 bytes | SHA256: b91b98a025af243bbea15c7faea8a27263116151a7660ae3359bbf926997cbb1
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: fftwf_mapflags

void sub_19f5c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 91 instructions
    /* 0x19f5c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x19f60 */ stp x22, x21, [sp, #0x10];
    /* 0x19f64 */ stp x20, x19, [sp, #0x20];
    /* 0x19f68 */ mov x29, sp;
    /* 0x19f6c */ mov w22, w3;
    /* 0x19f70 */ mov x19, x2;
    /* 0x19f74 */ mov w21, w1;
    /* 0x19f78 */ mov x20, x0;
    fftwf_mapflags();
    /* 0x19f80 */ ldur x8, [x20, #0xd4];
    /* 0x19f84 */ ubfiz w22, w22, #0x14, #3;
    fftwf_mapflags();
    fftwf_mapflags();
    fftwf_mapflags();
    return x0;
}
