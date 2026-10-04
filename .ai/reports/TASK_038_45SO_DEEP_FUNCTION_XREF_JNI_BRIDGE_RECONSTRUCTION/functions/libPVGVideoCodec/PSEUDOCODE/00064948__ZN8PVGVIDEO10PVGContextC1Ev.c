// Library: libPVGVideoCodec.so
// Function ID: libPVGVideoCodec::0x64948
// Recovered Name: _ZN8PVGVIDEO10PVGContextC1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x64948 | Size: 144 bytes | SHA256: 4ec562061f699f8a8ec8cb5d9c518e6bbd5f0f10ea6b178bca937efddf1d5c70
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8PVGVIDEO6PVGRefC2Ev

void _ZN8PVGVIDEO10PVGContextC1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x64948 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x6494c */ str x19, [sp, #0x10];
    /* 0x64950 */ mov x29, sp;
    /* 0x64954 */ mov x19, x0;
    _ZN8PVGVIDEO6PVGRefC2Ev();
    /* 0x6495c */ adrp x8, #0x11a000;
    /* 0x64960 */ movi v0.2d, #0000000000000000;
    /* 0x64964 */ mov w9, #0x3f800000;
    /* 0x64968 */ ldr x8, [x8, #0xd50];
    /* 0x6496c */ str xzr, [x19, #0x58];
    /* 0x64970 */ str w9, [x19, #0x60];
    return x0;
}
