// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3da8fc
// Recovered Name: _ZNSt6__ndk110shared_ptrIN11LayerFlowNS16CLFBaseProcessorEEaSB8ne180000INS1_21CLFDenseHairProcessorEvEERS3_RKNS0_IT_EE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3da8fc | Size: 132 bytes | SHA256: e4fb65b190ad31159e2b80c4e108284213d4f8578d5d844879485b143dbb8df3
// Callers: 1 | Callees: 2 | Imports: 1

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv

void _ZNSt6__ndk110shared_ptrIN11LayerFlowNS16CLFBaseProcessorEEaSB8ne180000INS1_21CLFDenseHairProcessorEvEERS3_RKNS0_IT_EE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x3da8fc */ stp x29, x30, [sp, #-0x30]!;
    /* 0x3da900 */ stp x22, x21, [sp, #0x10];
    /* 0x3da904 */ stp x20, x19, [sp, #0x20];
    /* 0x3da908 */ mov x29, sp;
    /* 0x3da90c */ ldp x22, x21, [x1];
    /* 0x3da910 */ mov x19, x0;
    /* 0x3da914 */ cbz x21, #0x3da924;
    /* 0x3da918 */ add x1, x21, #8;
    /* 0x3da91c */ mov w0, #1;
    sub_5263b0();
    /* 0x3da924 */ ldr x20, [x19, #8];
    sub_5263e0();
    return x0;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    return x0;
}
