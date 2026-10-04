// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11a4f4
// Recovered Name: sub_11a4f4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11a4f4 | Size: 60 bytes | SHA256: 774e12593e2ead12aff5c4dce767eb5dfb062472990638939c2a9018d4cf4455
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setup()J (table at 0x13a138)
// Calls external APIs: _Znwm

jlong sub_11a4f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x11a4f4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x11a4f8 */ mov x29, sp;
    /* 0x11a4fc */ mov w0, #0x88;
    _Znwm();
    /* 0x11a504 */ movi v0.2d, #0000000000000000;
    /* 0x11a508 */ mov w8, #0x3f800000;
    /* 0x11a50c */ str xzr, [x0, #0x40];
    /* 0x11a510 */ str w8, [x0, #0x48];
    /* 0x11a514 */ stp q0, q0, [x0];
    /* 0x11a518 */ stp q0, q0, [x0, #0x20];
    /* 0x11a51c */ stp q0, q0, [x0, #0x50];
    return x0;
}
