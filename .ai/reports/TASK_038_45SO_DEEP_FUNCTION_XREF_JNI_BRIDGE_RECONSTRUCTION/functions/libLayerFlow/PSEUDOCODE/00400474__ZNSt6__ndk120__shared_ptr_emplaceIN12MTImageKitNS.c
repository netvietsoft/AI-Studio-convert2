// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x400474
// Recovered Name: _ZNSt6__ndk120__shared_ptr_emplaceIN12MTImageKitNS24CMTIKHairFlowAIGCRequestENS_9allocatorIS2_EEED2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x400474 | Size: 20 bytes | SHA256: dc0346b5e2bacc386190ea76fed899b5ac21fd20239a7b0c626319cd7571ec4c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt6__ndk119__shared_weak_countD2Ev

void _ZNSt6__ndk120__shared_ptr_emplaceIN12MTImageKitNS24CMTIKHairFlowAIGCRequestENS_9allocatorIS2_EEED2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x400474 */ adrp x8, #0x544000;
    /* 0x400478 */ add x8, x8, #0x460;
    /* 0x40047c */ add x8, x8, #0x10;
    /* 0x400480 */ str x8, [x0];
    /* 0x400484 */ b #0x52a310;
}
