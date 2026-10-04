// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3dfe30
// Recovered Name: _ZNSt6__ndk120__shared_ptr_emplaceIN11LayerFlowNS21CLFDenseHairProcessorENS_9allocatorIS2_EEED2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3dfe30 | Size: 20 bytes | SHA256: 42374ff4dc6eccc510b5a7b3b2c65ef3e7e865fa57ce2b17d8ce318359066182
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt6__ndk119__shared_weak_countD2Ev

void _ZNSt6__ndk120__shared_ptr_emplaceIN11LayerFlowNS21CLFDenseHairProcessorENS_9allocatorIS2_EEED2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x3dfe30 */ adrp x8, #0x543000;
    /* 0x3dfe34 */ add x8, x8, #0x228;
    /* 0x3dfe38 */ add x8, x8, #0x10;
    /* 0x3dfe3c */ str x8, [x0];
    /* 0x3dfe40 */ b #0x52a310;
}
