// Library: libVERenderer.so
// Function ID: libVERenderer::0x38278
// Recovered Name: _ZNK10verenderer7Color3BeqERKNS_7Color4BE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x38278 | Size: 72 bytes | SHA256: e3e030f846d3f98c3b70043e04ace4abce5877c84201f210dacd71bfa02900ec
// Callers: 0 | Callees: 0 | Imports: 0


void _ZNK10verenderer7Color3BeqERKNS_7Color4BE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x38278 */ ldrb w8, [x0];
    /* 0x3827c */ ldrb w9, [x1];
    /* 0x38280 */ cmp w8, w9;
    /* 0x38284 */ b.ne #0x382b8;
    /* 0x38288 */ ldrb w8, [x0, #1];
    /* 0x3828c */ ldrb w9, [x1, #1];
    /* 0x38290 */ cmp w8, w9;
    /* 0x38294 */ b.ne #0x382b8;
    /* 0x38298 */ ldrb w8, [x0, #2];
    /* 0x3829c */ ldrb w9, [x1, #2];
    /* 0x382a0 */ cmp w8, w9;
    return x0;
    return x0;
}
