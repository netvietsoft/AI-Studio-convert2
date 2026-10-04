// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3df70c
// Recovered Name: _ZNSt6__ndk120__shared_ptr_emplaceIN11LayerFlowNS16CLFBlurProcessorENS_9allocatorIS2_EEED0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3df70c | Size: 52 bytes | SHA256: 21ea54b44c0f1f37a5ecbbb1632c142c06431e2b315c38664cc204996121a773
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZNSt6__ndk119__shared_weak_countD2Ev, _ZdlPv

void _ZNSt6__ndk120__shared_ptr_emplaceIN11LayerFlowNS16CLFBlurProcessorENS_9allocatorIS2_EEED0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x3df70c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3df710 */ str x19, [sp, #0x10];
    /* 0x3df714 */ mov x29, sp;
    /* 0x3df718 */ adrp x8, #0x54a000;
    /* 0x3df71c */ mov x19, x0;
    /* 0x3df720 */ ldr x8, [x8, #0xea0];
    /* 0x3df724 */ add x8, x8, #0x10;
    /* 0x3df728 */ str x8, [x0];
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    /* 0x3df730 */ mov x0, x19;
    /* 0x3df734 */ ldr x19, [sp, #0x10];
}
