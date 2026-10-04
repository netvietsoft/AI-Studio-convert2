// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x12048c
// Recovered Name: sub_12048c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x12048c | Size: 64 bytes | SHA256: 2f67479576d28f097324c968f451bbbc4bc4b73f81f4ca4a882b668f0b6ddd00
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: native_setup()J (table at 0x13a6b8)
// Calls external APIs: _ZN3PVG15PVGMediaEntriesC1Ev, _ZdlPv, _Znwm

jlong sub_12048c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x12048c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x120490 */ stp x20, x19, [sp, #0x10];
    /* 0x120494 */ mov x29, sp;
    /* 0x120498 */ mov w0, #0x160;
    _Znwm();
    /* 0x1204a0 */ mov x19, x0;
    _ZN3PVG15PVGMediaEntriesC1Ev();
    /* 0x1204a8 */ mov x0, x19;
    /* 0x1204ac */ ldp x20, x19, [sp, #0x10];
    /* 0x1204b0 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_12eab4();
}
