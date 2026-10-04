// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3421d4
// Recovered Name: _ZN11LayerFlowNS12CLFBlurLayer10getModularEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3421d4 | Size: 296 bytes | SHA256: 558779b6b0c974281e1125e7ba8975477f2ad8a325884708ae831c9aa5132cfe
// Callers: 4 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, memcpy

void _ZN11LayerFlowNS12CLFBlurLayer10getModularEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 74 instructions
    /* 0x3421d4 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x3421d8 */ stp x24, x23, [sp, #0x10];
    /* 0x3421dc */ stp x22, x21, [sp, #0x20];
    /* 0x3421e0 */ stp x20, x19, [sp, #0x30];
    /* 0x3421e4 */ mov x29, sp;
    /* 0x3421e8 */ ldr w9, [x0, #0x258];
    /* 0x3421ec */ cmp w9, #0x15;
    /* 0x3421f0 */ b.ne #0x3422b0;
    /* 0x3421f4 */ mov x19, x8;
    /* 0x3421f8 */ mov x8, x0;
    /* 0x3421fc */ mov x20, x0;
    sub_2bc260();
    _Znwm();
    memcpy();
    return x0;
    sub_303354();
    sub_2c39b8();
    sub_526544();
    _ZdlPv();
    _ZdlPv();
    sub_526544();
}
