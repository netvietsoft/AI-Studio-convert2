// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x4004cc
// Recovered Name: _ZN12MTImageKitNS24CMTIKHairFlowAIGCRequestD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x4004cc | Size: 96 bytes | SHA256: b33800662b11ab1354ecbd41f0dad9955c6847e135508be985821170b4e78d15
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv

void _ZN12MTImageKitNS24CMTIKHairFlowAIGCRequestD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 24 instructions
    /* 0x4004cc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x4004d0 */ str x19, [sp, #0x10];
    /* 0x4004d4 */ mov x29, sp;
    /* 0x4004d8 */ adrp x8, #0x544000;
    /* 0x4004dc */ add x8, x8, #0x4b0;
    /* 0x4004e0 */ ldr x19, [x0, #0x10];
    /* 0x4004e4 */ add x8, x8, #0x10;
    /* 0x4004e8 */ str x8, [x0];
    /* 0x4004ec */ cbz x19, #0x400500;
    /* 0x4004f0 */ add x1, x19, #8;
    /* 0x4004f4 */ mov x0, #-1;
    sub_5263e0();
    return x0;
}
