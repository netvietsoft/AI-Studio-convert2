// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x35b9d4
// Recovered Name: _ZNSt6__ndk116__variant_detail5__altILm21E13LFBlurModularEC2B8ne180000IJRKS2_EEENS_10in_place_tEDpOT_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x35b9d4 | Size: 280 bytes | SHA256: ac81fa631970562aec08c1cd2bbd40d0772483ee5b3f4c762af24ea7d6836463
// Callers: 0 | Callees: 3 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, memcpy

void _ZNSt6__ndk116__variant_detail5__altILm21E13LFBlurModularEC2B8ne180000IJRKS2_EEENS_10in_place_tEDpOT_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 70 instructions
    /* 0x35b9d4 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x35b9d8 */ stp x24, x23, [sp, #0x10];
    /* 0x35b9dc */ stp x22, x21, [sp, #0x20];
    /* 0x35b9e0 */ stp x20, x19, [sp, #0x30];
    /* 0x35b9e4 */ mov x29, sp;
    /* 0x35b9e8 */ ldrb w8, [x2];
    /* 0x35b9ec */ mov x20, x0;
    /* 0x35b9f0 */ mov x21, x2;
    /* 0x35b9f4 */ mov x19, x0;
    /* 0x35b9f8 */ strb w8, [x20], #8;
    /* 0x35b9fc */ mov x8, x2;
    sub_2bc260();
    _Znwm();
    memcpy();
    return x0;
    sub_2c39b8();
    sub_526544();
    _ZdlPv();
    _ZdlPv();
    sub_526544();
}
