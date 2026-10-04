// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x345e94
// Recovered Name: _ZN11LayerFlowNS17CLFDenseHairLayer10getModularEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x345e94 | Size: 296 bytes | SHA256: 4efcc939e5e0817b7c0e2cf1660bc30d8a80f4155c20a22aae91c929033bf8fa
// Callers: 2 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, memcpy

void _ZN11LayerFlowNS17CLFDenseHairLayer10getModularEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 74 instructions
    /* 0x345e94 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x345e98 */ str x23, [sp, #0x10];
    /* 0x345e9c */ stp x22, x21, [sp, #0x20];
    /* 0x345ea0 */ stp x20, x19, [sp, #0x30];
    /* 0x345ea4 */ mov x29, sp;
    /* 0x345ea8 */ ldr w9, [x0, #0x258];
    /* 0x345eac */ cmp w9, #0x28;
    /* 0x345eb0 */ b.ne #0x345f70;
    /* 0x345eb4 */ mov x19, x8;
    /* 0x345eb8 */ mov x8, x0;
    /* 0x345ebc */ mov x21, x0;
    return x0;
    sub_2bc260();
    _Znwm();
    memcpy();
    return x0;
    sub_303354();
    sub_2cbab0();
    sub_526544();
    _ZdlPv();
    _ZdlPv();
    sub_526544();
}
