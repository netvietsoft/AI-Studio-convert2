// Library: libMTGif.so
// Function ID: libMTGif::0x8cb4
// Recovered Name: _ZN13FormatConvert18VideoFormatTranserC1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x8cb4 | Size: 300 bytes | SHA256: 25f013ea17571f1fedb2238c3f74f984aa78a282f40fcf7013d67960a4e3d4ca
// Callers: 0 | Callees: 2 | Imports: 4

// Calls external APIs: _ZdlPv, malloc, pthread_cond_init, pthread_mutex_init

void _ZN13FormatConvert18VideoFormatTranserC1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 75 instructions
    /* 0x8cb4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8cb8 */ stp x22, x21, [sp, #0x10];
    /* 0x8cbc */ stp x20, x19, [sp, #0x20];
    /* 0x8cc0 */ mov x29, sp;
    /* 0x8cc4 */ add x19, x0, #0x110;
    /* 0x8cc8 */ mov x20, x0;
    /* 0x8ccc */ str xzr, [x0, #0x120];
    /* 0x8cd0 */ stp x19, x19, [x0, #0x110];
    /* 0x8cd4 */ mov w0, #0x28;
    malloc();
    /* 0x8cdc */ cbz x0, #0x8cf0;
    malloc();
    pthread_cond_init();
    pthread_mutex_init();
    _ZdlPv();
    return x0;
    sub_8de0();
    sub_eda0();
}
