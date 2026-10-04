// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3faca4
// Recovered Name: sub_3faca4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3faca4 | Size: 140 bytes | SHA256: 7a1a50c674001658651bdd1f0584f664ae9507e4ea22d1eb8cd6a2cb4da6f146
// Callers: 0 | Callees: 0 | Imports: 6

// Calls external APIs: _ZN12MTImageKitNS12CMTIKManager13processRenderEb, _ZN12MTImageKitNS12CMTIKManager23setDoubleBufferReRenderEb, _ZN12MTImageKitNS15CMTIKHairFilter18hairColorAIRequestEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE, _ZN12MTImageKitNS15CMTIKHairFilter21setDyeHairRenderAlphaEf, _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZdlPv
// Strings referenced:
//   "CLFDenseHairProcessor<%s:%d> hairColorAIRequest error."
//   "applyLayer"

void sub_3faca4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 35 instructions
    /* 0x3faca4 */ add x2, sp, #0x100;
    /* 0x3faca8 */ mov x0, x20;
    /* 0x3facac */ mov w1, w24;
    _ZN12MTImageKitNS15CMTIKHairFilter18hairColorAIRequestEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    /* 0x3facb4 */ ldrb w8, [sp, #0x100];
    /* 0x3facb8 */ mov w24, w0;
    /* 0x3facbc */ tbz w8, #0, #0x3facc8;
    /* 0x3facc0 */ ldr x0, [sp, #0x110];
    _ZdlPv();
    /* 0x3facc8 */ cbz w24, #0x3facf0;
    /* 0x3faccc */ mov x0, x26;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS15CMTIKHairFilter21setDyeHairRenderAlphaEf();
    _ZN12MTImageKitNS12CMTIKManager13processRenderEb();
    _ZN12MTImageKitNS12CMTIKManager23setDoubleBufferReRenderEb();
    _ZdlPv();
}
