// Library: libaicodec.so
// Function ID: libaicodec::0x116d18
// Recovered Name: sub_116d18
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x116d18 | Size: 64 bytes | SHA256: bf112c9675c20e606545f5dac993c96bd85dfe93bf509bdb3d9fdcbab5a186b4
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: native_init()J (table at 0x1ff0c8)
// Calls external APIs: _ZN7MMCodec10MediaParamC1Ev, _ZdlPv, _Znwm

jlong sub_116d18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x116d18 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x116d1c */ stp x20, x19, [sp, #0x10];
    /* 0x116d20 */ mov x29, sp;
    /* 0x116d24 */ mov w0, #0x48;
    _Znwm();
    /* 0x116d2c */ mov x19, x0;
    _ZN7MMCodec10MediaParamC1Ev();
    /* 0x116d34 */ mov x0, x19;
    /* 0x116d38 */ ldp x20, x19, [sp, #0x10];
    /* 0x116d3c */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_1f00ec();
}
