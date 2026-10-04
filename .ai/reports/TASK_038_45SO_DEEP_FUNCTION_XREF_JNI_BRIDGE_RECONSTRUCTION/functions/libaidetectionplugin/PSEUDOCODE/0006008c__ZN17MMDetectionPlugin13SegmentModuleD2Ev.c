// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x6008c
// Recovered Name: _ZN17MMDetectionPlugin13SegmentModuleD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x6008c | Size: 24 bytes | SHA256: 597ba5f008b79501cc74472d55e19d8ad03e042c8a834c408a4a412f11a74dbd
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN17MMDetectionPlugin13SegmentModuleD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x6008c */ adrp x9, #0x82000;
    /* 0x60090 */ ldr x9, [x9, #0xf90];
    /* 0x60094 */ ldr x8, [x0, #0x48];
    /* 0x60098 */ add x9, x9, #0x10;
    /* 0x6009c */ str x9, [x0];
    /* 0x600a0 */ cbz x8, #0x600cc;
}
