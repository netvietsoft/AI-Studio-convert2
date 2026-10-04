// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3df6f8
// Recovered Name: _ZNSt6__ndk120__shared_ptr_emplaceIN11LayerFlowNS16CLFBlurProcessorENS_9allocatorIS2_EEED2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3df6f8 | Size: 20 bytes | SHA256: d7d7dbbd0e7416b4317bae55003cc586c73850eb106444df9b3cf4d5ab227899
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt6__ndk119__shared_weak_countD2Ev

void _ZNSt6__ndk120__shared_ptr_emplaceIN11LayerFlowNS16CLFBlurProcessorENS_9allocatorIS2_EEED2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x3df6f8 */ adrp x8, #0x542000;
    /* 0x3df6fc */ add x8, x8, #0xb98;
    /* 0x3df700 */ add x8, x8, #0x10;
    /* 0x3df704 */ str x8, [x0];
    /* 0x3df708 */ b #0x52a310;
}
