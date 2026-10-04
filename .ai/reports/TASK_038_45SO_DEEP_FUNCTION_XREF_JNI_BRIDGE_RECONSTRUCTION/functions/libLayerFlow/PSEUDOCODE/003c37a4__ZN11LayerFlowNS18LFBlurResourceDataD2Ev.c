// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3c37a4
// Recovered Name: _ZN11LayerFlowNS18LFBlurResourceDataD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3c37a4 | Size: 144 bytes | SHA256: 211038514e03739cf3321155e99bd751539783afa3f7f2df356d38309ed01ee9
// Callers: 1 | Callees: 1 | Imports: 2

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv

void _ZN11LayerFlowNS18LFBlurResourceDataD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x3c37a4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3c37a8 */ stp x20, x19, [sp, #0x10];
    /* 0x3c37ac */ mov x29, sp;
    /* 0x3c37b0 */ ldrb w8, [x0, #0x40];
    /* 0x3c37b4 */ mov x19, x0;
    /* 0x3c37b8 */ tbz w8, #0, #0x3c37c4;
    /* 0x3c37bc */ ldr x0, [x19, #0x50];
    _ZdlPv();
    /* 0x3c37c4 */ ldr x20, [x19, #0x38];
    /* 0x3c37c8 */ cbz x20, #0x3c37dc;
    /* 0x3c37cc */ add x1, x20, #8;
    sub_5263e0();
    _ZdlPv();
    return x0;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
}
