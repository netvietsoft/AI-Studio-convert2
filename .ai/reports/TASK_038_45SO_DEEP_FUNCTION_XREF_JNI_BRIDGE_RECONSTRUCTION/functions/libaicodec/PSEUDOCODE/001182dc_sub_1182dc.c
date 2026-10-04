// Library: libaicodec.so
// Function ID: libaicodec::0x1182dc
// Recovered Name: sub_1182dc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x1182dc | Size: 40 bytes | SHA256: 8cd4931173be0fab866933a2acd44565bfd43c7aba9faa9922e3829601425385
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: setCodecRate(I)V (table at 0x1ff260)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal11getInstanceEv, _ZN7MMCodec13AICodecGlobal23setEncoderOperatingRateEi, _ZdlPv

jlong sub_1182dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x1182dc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1182e0 */ str x19, [sp, #0x10];
    /* 0x1182e4 */ mov x29, sp;
    /* 0x1182e8 */ mov w19, w2;
    _ZN7MMCodec13AICodecGlobal11getInstanceEv();
    /* 0x1182f0 */ mov w1, w19;
    /* 0x1182f4 */ ldr x19, [sp, #0x10];
    /* 0x1182f8 */ ldp x29, x30, [sp], #0x20;
    /* 0x1182fc */ b #0x1f6ad0;
    /* 0x118300 */ b #0x1f4650;
}
