// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x42540
// Recovered Name: sub_42540
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x42540 | Size: 364 bytes | SHA256: 73918c447767df328be9e01ba811ee942778bf97d0301c2e24a46254f6ec3885
// Callers: 0 | Callees: 0 | Imports: 6

// Calls external APIs: _ZN17MMDetectionPlugin17ExDenseHairModuleC1ER18vlai_engine_handleR26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEE, _ZN17MMDetectionPlugin18ExAnySegmentModuleC1ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE, _ZN17MMDetectionPlugin21ExColorTransferModuleC1ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE, _ZN17MMDetectionPlugin22PixarAnimateFaceModuleC1ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE, _ZdlPv, _Znwm
// Strings referenced:
//   "AnySegment"
//   "ColorTransfer"
//   "DenseHair"
//   "PixarAnimateFaceModule"

void sub_42540(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 91 instructions
    /* 0x42540 */ ldr x22, [x19, #0x110];
    /* 0x42544 */ stp x9, x25, [x19, #0x110];
    /* 0x42548 */ str x8, [x19, #0x120];
    /* 0x4254c */ cbnz x22, #0x4255c;
    /* 0x42550 */ b #0x42564;
    /* 0x42554 */ stp x13, x25, [x19, #0x110];
    /* 0x42558 */ str x8, [x19, #0x120];
    /* 0x4255c */ mov x0, x22;
    _ZdlPv();
    /* 0x42564 */ str x25, [x19, #0x118];
    /* 0x42568 */ mov w0, #0x70;
    _Znwm();
    _ZN17MMDetectionPlugin17ExDenseHairModuleC1ER18vlai_engine_handleR26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEE();
    _ZdlPv();
    _Znwm();
    _ZN17MMDetectionPlugin21ExColorTransferModuleC1ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    _ZdlPv();
    _Znwm();
    _ZN17MMDetectionPlugin18ExAnySegmentModuleC1ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    _ZdlPv();
    _Znwm();
    _ZN17MMDetectionPlugin22PixarAnimateFaceModuleC1ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    _ZdlPv();
    _ZdlPv();
}
