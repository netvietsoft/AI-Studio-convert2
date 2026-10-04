// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x2e3e4
// Recovered Name: sub_2e3e4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e3e4 | Size: 80 bytes | SHA256: 2accb9102d7648ec741e1b2c14cdaabb24575bc6bb5d4c0c2b9a924acd79b3bc
// Callers: 9 | Callees: 2 | Imports: 3

// Calls external APIs: __cxa_allocate_exception, __cxa_free_exception, __cxa_throw

void sub_2e3e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x2e3e4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e3e8 */ stp x20, x19, [sp, #0x10];
    /* 0x2e3ec */ mov x29, sp;
    /* 0x2e3f0 */ mov x20, x0;
    /* 0x2e3f4 */ mov w0, #0x10;
    __cxa_allocate_exception();
    /* 0x2e3fc */ mov x19, x0;
    /* 0x2e400 */ mov x1, x20;
    sub_2e434();
    /* 0x2e408 */ adrp x1, #0x81000;
    /* 0x2e40c */ adrp x2, #0x81000;
    __cxa_throw();
    __cxa_free_exception();
    sub_76b64();
}
