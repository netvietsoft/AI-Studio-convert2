// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x74eb0
// Recovered Name: _ZN17MMDetectionPlugin18ExAnySegmentModuleD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x74eb0 | Size: 88 bytes | SHA256: 28fa3e5299702d9675df429c8a6393d7e7d5f932164d4ed65cadd45ed8c3f29c
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: _ZdlPv, vlai_segment_any_destroy_handle

void _ZN17MMDetectionPlugin18ExAnySegmentModuleD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 22 instructions
    /* 0x74eb0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x74eb4 */ str x19, [sp, #0x10];
    /* 0x74eb8 */ mov x29, sp;
    /* 0x74ebc */ adrp x8, #0x83000;
    /* 0x74ec0 */ mov x19, x0;
    /* 0x74ec4 */ ldr x8, [x8, #0x90];
    /* 0x74ec8 */ ldr x0, [x0, #0x28];
    /* 0x74ecc */ add x8, x8, #0x10;
    /* 0x74ed0 */ str x8, [x19];
    /* 0x74ed4 */ cbz x0, #0x74ee0;
    vlai_segment_any_destroy_handle();
    return x0;
    sub_3f3a4();
}
