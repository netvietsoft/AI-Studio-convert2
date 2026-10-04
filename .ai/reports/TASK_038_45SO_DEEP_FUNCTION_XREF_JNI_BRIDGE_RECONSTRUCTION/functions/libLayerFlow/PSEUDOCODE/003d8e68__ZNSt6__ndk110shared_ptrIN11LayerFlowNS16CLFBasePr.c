// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3d8e68
// Recovered Name: _ZNSt6__ndk110shared_ptrIN11LayerFlowNS16CLFBaseProcessorEEaSB8ne180000INS1_16CLFBlurProcessorEvEERS3_RKNS0_IT_EE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3d8e68 | Size: 132 bytes | SHA256: 1be90e454dc8dd06383aec1b9f93b7abf5766b306df1c2c8f9871639ea88c265
// Callers: 1 | Callees: 2 | Imports: 1

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv

void _ZNSt6__ndk110shared_ptrIN11LayerFlowNS16CLFBaseProcessorEEaSB8ne180000INS1_16CLFBlurProcessorEvEERS3_RKNS0_IT_EE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x3d8e68 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x3d8e6c */ stp x22, x21, [sp, #0x10];
    /* 0x3d8e70 */ stp x20, x19, [sp, #0x20];
    /* 0x3d8e74 */ mov x29, sp;
    /* 0x3d8e78 */ ldp x22, x21, [x1];
    /* 0x3d8e7c */ mov x19, x0;
    /* 0x3d8e80 */ cbz x21, #0x3d8e90;
    /* 0x3d8e84 */ add x1, x21, #8;
    /* 0x3d8e88 */ mov w0, #1;
    sub_5263b0();
    /* 0x3d8e90 */ ldr x20, [x19, #8];
    sub_5263e0();
    return x0;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    return x0;
}
