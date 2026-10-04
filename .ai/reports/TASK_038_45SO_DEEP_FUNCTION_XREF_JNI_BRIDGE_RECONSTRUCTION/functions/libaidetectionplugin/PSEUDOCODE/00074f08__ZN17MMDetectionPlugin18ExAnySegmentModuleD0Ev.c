// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x74f08
// Recovered Name: _ZN17MMDetectionPlugin18ExAnySegmentModuleD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x74f08 | Size: 36 bytes | SHA256: f7c3ff4e9dfd2c5fe8555c35e64fbedc78df4f2e5522d7171bb209309da39d9b
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN17MMDetectionPlugin18ExAnySegmentModuleD1Ev, _ZdlPv

void _ZN17MMDetectionPlugin18ExAnySegmentModuleD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x74f08 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x74f0c */ str x19, [sp, #0x10];
    /* 0x74f10 */ mov x29, sp;
    /* 0x74f14 */ mov x19, x0;
    _ZN17MMDetectionPlugin18ExAnySegmentModuleD1Ev();
    /* 0x74f1c */ mov x0, x19;
    /* 0x74f20 */ ldr x19, [sp, #0x10];
    /* 0x74f24 */ ldp x29, x30, [sp], #0x20;
    /* 0x74f28 */ b #0x799b0;
}
