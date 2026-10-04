// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x45220
// Recovered Name: sub_45220
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x45220 | Size: 60 bytes | SHA256: fe326dc5041772b2699e494370dd3e8cae84becf3448068879adce108b456a58
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: setTimeRange(JJ)V (table at 0x7f948)
// Calls external APIs: _ZN3MFX11KKLoudMeter12setTimeRangeEll

jlong sub_45220(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x45220 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x45224 */ stp x20, x19, [sp, #0x10];
    /* 0x45228 */ mov x29, sp;
    /* 0x4522c */ mov x19, x3;
    /* 0x45230 */ mov x20, x2;
    sub_44f2c();
    /* 0x45238 */ cbz x0, #0x45250;
    /* 0x4523c */ mov x1, x20;
    /* 0x45240 */ mov x2, x19;
    /* 0x45244 */ ldp x20, x19, [sp, #0x10];
    /* 0x45248 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
