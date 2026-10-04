// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x35c1a4
// Recovered Name: _ZNSt6__ndk116__variant_detail5__altILm40E18LFDenseHairModularEC2B8ne180000IJRKS2_EEENS_10in_place_tEDpOT_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x35c1a4 | Size: 280 bytes | SHA256: 05dcf7c70f89e5bad3861ef24a3e9dbed99fa84e23cd0c29aa49e82e0eb05b20
// Callers: 0 | Callees: 3 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, memcpy

void _ZNSt6__ndk116__variant_detail5__altILm40E18LFDenseHairModularEC2B8ne180000IJRKS2_EEENS_10in_place_tEDpOT_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 70 instructions
    /* 0x35c1a4 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x35c1a8 */ str x23, [sp, #0x10];
    /* 0x35c1ac */ stp x22, x21, [sp, #0x20];
    /* 0x35c1b0 */ stp x20, x19, [sp, #0x30];
    /* 0x35c1b4 */ mov x29, sp;
    /* 0x35c1b8 */ ldrb w8, [x2];
    /* 0x35c1bc */ mov x20, x0;
    /* 0x35c1c0 */ mov x22, x2;
    /* 0x35c1c4 */ mov x19, x0;
    /* 0x35c1c8 */ strb w8, [x20], #8;
    /* 0x35c1cc */ mov x8, x2;
    return x0;
    sub_2bc260();
    _Znwm();
    memcpy();
    return x0;
    sub_2cbab0();
    sub_526544();
    _ZdlPv();
    _ZdlPv();
    sub_526544();
}
