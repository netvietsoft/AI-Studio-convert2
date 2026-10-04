// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x5e594
// Recovered Name: sub_5e594
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5e594 | Size: 52 bytes | SHA256: c0439add146b39d0b1b58d4df56be3d0327ba4d666486fc3d4940356eaaacca0
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: initialiseJUCE(Landroid/content/Context;)V (table at 0x80050)

jlong sub_5e594(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x5e594 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x5e598 */ stp x20, x19, [sp, #0x10];
    /* 0x5e59c */ mov x29, sp;
    /* 0x5e5a0 */ mov x1, x2;
    /* 0x5e5a4 */ mov x19, x2;
    /* 0x5e5a8 */ mov x20, x0;
    sub_5c19c();
    /* 0x5e5b0 */ mov x0, x20;
    /* 0x5e5b4 */ mov x1, x19;
    /* 0x5e5b8 */ ldp x20, x19, [sp, #0x10];
    /* 0x5e5bc */ ldp x29, x30, [sp], #0x20;
}
