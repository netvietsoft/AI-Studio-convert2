// Library: libVERenderer.so
// Function ID: libVERenderer::0x38258
// Recovered Name: _ZNK10verenderer7Color3BeqERKS0_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x38258 | Size: 32 bytes | SHA256: ffcdc477f04990bd10252ead70a3a20ade639ff7dbb102b5363390103fff160b
// Callers: 0 | Callees: 0 | Imports: 0


void _ZNK10verenderer7Color3BeqERKS0_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x38258 */ ldrh w8, [x0];
    /* 0x3825c */ ldrh w9, [x1];
    /* 0x38260 */ ldrb w10, [x0, #2];
    /* 0x38264 */ ldrb w11, [x1, #2];
    /* 0x38268 */ cmp w8, w9;
    /* 0x3826c */ ccmp w10, w11, #0, eq;
    /* 0x38270 */ cset w0, eq;
    return x0;
}
