// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3dfe44
// Recovered Name: _ZNSt6__ndk120__shared_ptr_emplaceIN11LayerFlowNS21CLFDenseHairProcessorENS_9allocatorIS2_EEED0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3dfe44 | Size: 52 bytes | SHA256: d81b4b162a4127f35a40baa159dcc05aa3fc609b1967c53a1f0aa1e2ab640c2b
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZNSt6__ndk119__shared_weak_countD2Ev, _ZdlPv

void _ZNSt6__ndk120__shared_ptr_emplaceIN11LayerFlowNS21CLFDenseHairProcessorENS_9allocatorIS2_EEED0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x3dfe44 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3dfe48 */ str x19, [sp, #0x10];
    /* 0x3dfe4c */ mov x29, sp;
    /* 0x3dfe50 */ adrp x8, #0x54a000;
    /* 0x3dfe54 */ mov x19, x0;
    /* 0x3dfe58 */ ldr x8, [x8, #0xf48];
    /* 0x3dfe5c */ add x8, x8, #0x10;
    /* 0x3dfe60 */ str x8, [x0];
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    /* 0x3dfe68 */ mov x0, x19;
    /* 0x3dfe6c */ ldr x19, [sp, #0x10];
}
