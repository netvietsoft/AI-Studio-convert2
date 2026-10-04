// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x40052c
// Recovered Name: _ZN12MTImageKitNS24CMTIKHairFlowAIGCRequestD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x40052c | Size: 112 bytes | SHA256: 83c84e189c2d75c18b6bf99005dc1d0546500f81ace22d2350f78ac96a2fbde6
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv

void _ZN12MTImageKitNS24CMTIKHairFlowAIGCRequestD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 28 instructions
    /* 0x40052c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x400530 */ stp x20, x19, [sp, #0x10];
    /* 0x400534 */ mov x29, sp;
    /* 0x400538 */ adrp x8, #0x54b000;
    /* 0x40053c */ mov x19, x0;
    /* 0x400540 */ ldr x8, [x8, #0x188];
    /* 0x400544 */ ldr x20, [x0, #0x10];
    /* 0x400548 */ add x8, x8, #0x10;
    /* 0x40054c */ str x8, [x0];
    /* 0x400550 */ cbz x20, #0x400564;
    /* 0x400554 */ add x1, x20, #8;
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
}
