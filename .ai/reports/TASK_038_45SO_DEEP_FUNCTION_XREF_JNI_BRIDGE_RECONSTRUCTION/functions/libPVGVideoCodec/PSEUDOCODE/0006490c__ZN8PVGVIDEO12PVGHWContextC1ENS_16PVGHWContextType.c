// Library: libPVGVideoCodec.so
// Function ID: libPVGVideoCodec::0x6490c
// Recovered Name: _ZN8PVGVIDEO12PVGHWContextC1ENS_16PVGHWContextTypeE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x6490c | Size: 60 bytes | SHA256: eb7abc5e0ed753efbd2f0fc40535e97e899bd526d8a5afe59e3e1207c3f80558
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8PVGVIDEO6PVGRefC2Ev

void _ZN8PVGVIDEO12PVGHWContextC1ENS_16PVGHWContextTypeE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x6490c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x64910 */ stp x20, x19, [sp, #0x10];
    /* 0x64914 */ mov x29, sp;
    /* 0x64918 */ mov w19, w1;
    /* 0x6491c */ mov x20, x0;
    _ZN8PVGVIDEO6PVGRefC2Ev();
    /* 0x64924 */ adrp x8, #0x11a000;
    /* 0x64928 */ ldr x8, [x8, #0xd48];
    /* 0x6492c */ stp xzr, xzr, [x20, #0x38];
    /* 0x64930 */ add x8, x8, #0x10;
    /* 0x64934 */ str x8, [x20];
    return x0;
}
