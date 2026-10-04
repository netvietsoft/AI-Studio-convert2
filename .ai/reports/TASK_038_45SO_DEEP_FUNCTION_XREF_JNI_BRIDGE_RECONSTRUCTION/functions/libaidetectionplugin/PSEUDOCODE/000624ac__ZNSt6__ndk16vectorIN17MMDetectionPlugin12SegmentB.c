// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x624ac
// Recovered Name: _ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE12emplace_backIJRS2_EEEvDpOT_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x624ac | Size: 80 bytes | SHA256: 6dd6d91f9cd06da3dc6a04d30ad6ced1369750f78d6a0797e8ec9fab41938548
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: _ZN17MMDetectionPlugin12SegmentBlockC1ERKS0_, _ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJRS2_EEEPS2_DpOT_

void _ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE12emplace_backIJRS2_EEEvDpOT_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x624ac */ stp x29, x30, [sp, #-0x20]!;
    /* 0x624b0 */ stp x20, x19, [sp, #0x10];
    /* 0x624b4 */ mov x29, sp;
    /* 0x624b8 */ ldp x20, x8, [x0, #8];
    /* 0x624bc */ mov x19, x0;
    /* 0x624c0 */ cmp x20, x8;
    /* 0x624c4 */ b.hs #0x624dc;
    /* 0x624c8 */ mov x0, x20;
    _ZN17MMDetectionPlugin12SegmentBlockC1ERKS0_();
    /* 0x624d0 */ add x0, x20, #0x50;
    /* 0x624d4 */ str x0, [x19, #8];
    _ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJRS2_EEEPS2_DpOT_();
    return x0;
    sub_75c14();
}
