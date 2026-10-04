// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x4525c
// Recovered Name: sub_4525c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x4525c | Size: 36 bytes | SHA256: 6aacd9c521de44361ff56c2d7342c89b1e9efb33cae1bcb1874293056d5267d7
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: calculateAndWaitLUFS()F (table at 0x7f960)
// Calls external APIs: _ZN3MFX11KKLoudMeter20calculateAndWaitLUFSEv

jlong sub_4525c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x4525c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x45260 */ mov x29, sp;
    sub_44f2c();
    /* 0x45268 */ cbz x0, #0x45274;
    /* 0x4526c */ ldp x29, x30, [sp], #0x10;
    /* 0x45270 */ b #0x7af10;
    /* 0x45274 */ movi d0, #0000000000000000;
    /* 0x45278 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
