// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x346000
// Recovered Name: _ZN11LayerFlowNS17CLFDenseHairLayer17getMaterialPathByEl
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x346000 | Size: 120 bytes | SHA256: 2fa945d6bbdeb790a7ac4453219a097e175017ed1b53f77672ed858b55f82674
// Callers: 2 | Callees: 0 | Imports: 0


void _ZN11LayerFlowNS17CLFDenseHairLayer17getMaterialPathByEl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0x346000 */ ldr x11, [x0, #0x4e0];
    /* 0x346004 */ cbz x11, #0x346044;
    /* 0x346008 */ add x9, x0, #0x4e0;
    /* 0x34600c */ mov x10, x9;
    /* 0x346010 */ ldr x12, [x11, #0x20];
    /* 0x346014 */ cmp x12, x1;
    /* 0x346018 */ add x12, x11, #8;
    /* 0x34601c */ csel x12, x11, x12, ge;
    /* 0x346020 */ csel x10, x11, x10, ge;
    /* 0x346024 */ ldr x11, [x12];
    /* 0x346028 */ cbnz x11, #0x346010;
    return x0;
    return x0;
}
