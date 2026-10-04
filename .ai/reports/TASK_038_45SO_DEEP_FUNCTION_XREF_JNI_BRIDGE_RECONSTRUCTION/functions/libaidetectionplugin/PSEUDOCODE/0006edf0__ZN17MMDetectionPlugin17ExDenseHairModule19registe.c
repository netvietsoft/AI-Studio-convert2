// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x6edf0
// Recovered Name: _ZN17MMDetectionPlugin17ExDenseHairModule19registerExtraModuleEPKNS_21_ExtraDetectionOptionE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x6edf0 | Size: 20 bytes | SHA256: 020c70823e223682638b7894c463acdd1a24701b463903a4d21fb98851bbeba2
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN17MMDetectionPlugin17ExDenseHairModule19registerExtraModuleEPKNS_21_ExtraDetectionOptionE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x6edf0 */ strb wzr, [x0, #0x30];
    /* 0x6edf4 */ cbz x1, #0x6ee00;
    /* 0x6edf8 */ ldrb w8, [x1];
    /* 0x6edfc */ tbnz w8, #1, #0x6ee04;
    return x0;
}
