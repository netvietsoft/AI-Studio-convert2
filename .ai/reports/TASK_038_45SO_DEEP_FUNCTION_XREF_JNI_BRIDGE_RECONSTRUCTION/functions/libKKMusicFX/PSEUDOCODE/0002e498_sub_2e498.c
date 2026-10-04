// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x2e498
// Recovered Name: sub_2e498
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e498 | Size: 28 bytes | SHA256: 1abcc5edd2ebd281295e5ec5718d9a2e4efc5dbdbd0a465e4e586600ea1b85a0
// Callers: 3 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void sub_2e498(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x2e498 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2e49c */ mov x29, sp;
    /* 0x2e4a0 */ nop ;
    /* 0x2e4a4 */ adr x0, #0x16e91;
    sub_2e3e4();
    return x0;
    /* 0x2e4b0 */ b #0x7a870;
}
