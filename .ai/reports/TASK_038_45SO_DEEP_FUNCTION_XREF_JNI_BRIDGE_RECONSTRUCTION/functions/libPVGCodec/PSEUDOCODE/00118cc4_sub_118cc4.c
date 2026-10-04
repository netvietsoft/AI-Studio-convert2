// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x118cc4
// Recovered Name: sub_118cc4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x118cc4 | Size: 84 bytes | SHA256: ae1e8f9c27f46ccf8693bc46ab78938191e5b754df920ff878279397c39eef0d
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setup()J (table at 0x139fe8)
// Calls external APIs: _Znwm

jlong sub_118cc4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x118cc4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x118cc8 */ mov x29, sp;
    /* 0x118ccc */ mov w0, #0x78;
    _Znwm();
    /* 0x118cd4 */ movi v0.2d, #0000000000000000;
    /* 0x118cd8 */ adrp x8, #0x1e000;
    /* 0x118cdc */ str xzr, [x0, #0x20];
    /* 0x118ce0 */ ldr d1, [x8, #0xd38];
    /* 0x118ce4 */ mov x8, #-0x4010000000000000;
    /* 0x118ce8 */ str wzr, [x0, #0x30];
    /* 0x118cec */ str x8, [x0, #0x38];
    return x0;
}
