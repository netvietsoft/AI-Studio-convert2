// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x62510
// Recovered Name: _ZNSt6__ndk120__shared_ptr_emplaceIN17MMDetectionPlugin13SegmentResultENS_9allocatorIS2_EEED0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x62510 | Size: 52 bytes | SHA256: b0de1ddee3a6a87a2d49a4ff57a3398ba9e730135dac1f86cfec8f4cc217b394
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: _ZN17MMDetectionPlugin13SegmentResultD1Ev, _ZNSt6__ndk119__shared_weak_countD2Ev, _ZdlPv

void _ZNSt6__ndk120__shared_ptr_emplaceIN17MMDetectionPlugin13SegmentResultENS_9allocatorIS2_EEED0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x62510 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x62514 */ str x19, [sp, #0x10];
    /* 0x62518 */ mov x29, sp;
    /* 0x6251c */ adrp x8, #0x82000;
    /* 0x62520 */ mov x19, x0;
    /* 0x62524 */ ldr x8, [x8, #0xf98];
    /* 0x62528 */ add x8, x8, #0x10;
    /* 0x6252c */ str x8, [x0];
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    /* 0x62534 */ mov x0, x19;
    /* 0x62538 */ ldr x19, [sp, #0x10];
}
