// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x624fc
// Recovered Name: _ZNSt6__ndk120__shared_ptr_emplaceIN17MMDetectionPlugin13SegmentResultENS_9allocatorIS2_EEED2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x624fc | Size: 20 bytes | SHA256: 54aa2a7b9ed010293e540afffd50eb54cec1fec71782a87053c586ea209f7b55
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt6__ndk119__shared_weak_countD2Ev

void _ZNSt6__ndk120__shared_ptr_emplaceIN17MMDetectionPlugin13SegmentResultENS_9allocatorIS2_EEED2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x624fc */ adrp x8, #0x82000;
    /* 0x62500 */ ldr x8, [x8, #0xf98];
    /* 0x62504 */ add x8, x8, #0x10;
    /* 0x62508 */ str x8, [x0];
    /* 0x6250c */ b #0x7bab0;
}
