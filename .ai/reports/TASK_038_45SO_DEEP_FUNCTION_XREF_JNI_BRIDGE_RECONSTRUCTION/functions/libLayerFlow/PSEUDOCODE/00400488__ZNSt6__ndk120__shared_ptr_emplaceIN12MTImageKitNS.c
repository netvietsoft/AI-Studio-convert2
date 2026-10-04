// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x400488
// Recovered Name: _ZNSt6__ndk120__shared_ptr_emplaceIN12MTImageKitNS24CMTIKHairFlowAIGCRequestENS_9allocatorIS2_EEED0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x400488 | Size: 52 bytes | SHA256: 35c03303a1c098471b96480a42fbb8a8ee71a75d84eedb26571a5f3721adec48
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZNSt6__ndk119__shared_weak_countD2Ev, _ZdlPv

void _ZNSt6__ndk120__shared_ptr_emplaceIN12MTImageKitNS24CMTIKHairFlowAIGCRequestENS_9allocatorIS2_EEED0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x400488 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x40048c */ str x19, [sp, #0x10];
    /* 0x400490 */ mov x29, sp;
    /* 0x400494 */ adrp x8, #0x54b000;
    /* 0x400498 */ mov x19, x0;
    /* 0x40049c */ ldr x8, [x8, #0x180];
    /* 0x4004a0 */ add x8, x8, #0x10;
    /* 0x4004a4 */ str x8, [x0];
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    /* 0x4004ac */ mov x0, x19;
    /* 0x4004b0 */ ldr x19, [sp, #0x10];
}
