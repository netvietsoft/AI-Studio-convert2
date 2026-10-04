// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x45f3d8
// Recovered Name: _ZNSt6__ndk120__shared_ptr_emplaceIN11LayerFlowNS18LFBlurResourceDataENS_9allocatorIS2_EEED0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x45f3d8 | Size: 52 bytes | SHA256: b420d444bed7ba888d809ec951b0437a5a332316256976c991106549690e91a7
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZNSt6__ndk119__shared_weak_countD2Ev, _ZdlPv

void _ZNSt6__ndk120__shared_ptr_emplaceIN11LayerFlowNS18LFBlurResourceDataENS_9allocatorIS2_EEED0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x45f3d8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x45f3dc */ str x19, [sp, #0x10];
    /* 0x45f3e0 */ mov x29, sp;
    /* 0x45f3e4 */ adrp x8, #0x54b000;
    /* 0x45f3e8 */ mov x19, x0;
    /* 0x45f3ec */ ldr x8, [x8, #0x558];
    /* 0x45f3f0 */ add x8, x8, #0x10;
    /* 0x45f3f4 */ str x8, [x0];
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    /* 0x45f3fc */ mov x0, x19;
    /* 0x45f400 */ ldr x19, [sp, #0x10];
}
