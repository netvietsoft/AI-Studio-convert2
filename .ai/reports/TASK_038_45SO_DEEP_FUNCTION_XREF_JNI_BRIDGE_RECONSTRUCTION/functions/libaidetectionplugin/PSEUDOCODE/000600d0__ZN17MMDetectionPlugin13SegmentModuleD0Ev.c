// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x600d0
// Recovered Name: _ZN17MMDetectionPlugin13SegmentModuleD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x600d0 | Size: 36 bytes | SHA256: 5c6c65bd97819227fe8ca166d94bf919031ff42e89b2ff4ca00c824725e9fd14
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN17MMDetectionPlugin13SegmentModuleD1Ev, _ZdlPv

void _ZN17MMDetectionPlugin13SegmentModuleD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x600d0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x600d4 */ str x19, [sp, #0x10];
    /* 0x600d8 */ mov x29, sp;
    /* 0x600dc */ mov x19, x0;
    _ZN17MMDetectionPlugin13SegmentModuleD1Ev();
    /* 0x600e4 */ mov x0, x19;
    /* 0x600e8 */ ldr x19, [sp, #0x10];
    /* 0x600ec */ ldp x29, x30, [sp], #0x20;
    /* 0x600f0 */ b #0x799b0;
}
