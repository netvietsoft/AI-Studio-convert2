// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x400328
// Recovered Name: _ZNSt6__ndk120__shared_ptr_emplaceIN12MTImageKitNS25CMTIKWhiteHairAIGCRequestENS_9allocatorIS2_EEED2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x400328 | Size: 20 bytes | SHA256: c6198e0c903f9a36789d542ea4e9b84c5095b79701fb260ee0d1f8dc089f67dd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt6__ndk119__shared_weak_countD2Ev

void _ZNSt6__ndk120__shared_ptr_emplaceIN12MTImageKitNS25CMTIKWhiteHairAIGCRequestENS_9allocatorIS2_EEED2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x400328 */ adrp x8, #0x544000;
    /* 0x40032c */ add x8, x8, #0x410;
    /* 0x400330 */ add x8, x8, #0x10;
    /* 0x400334 */ str x8, [x0];
    /* 0x400338 */ b #0x52a310;
}
