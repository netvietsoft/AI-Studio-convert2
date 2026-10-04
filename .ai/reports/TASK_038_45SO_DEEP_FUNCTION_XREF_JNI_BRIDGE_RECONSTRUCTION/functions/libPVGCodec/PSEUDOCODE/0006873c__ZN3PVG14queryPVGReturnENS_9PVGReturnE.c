// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x6873c
// Recovered Name: _ZN3PVG14queryPVGReturnENS_9PVGReturnE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x6873c | Size: 36 bytes | SHA256: d854415938188f2dca776fcc542482339c4bdb2900086c78db6ba631659a9cbf
// Callers: 0 | Callees: 0 | Imports: 0

// Strings referenced:
//   "unknown pvg return"

void _ZN3PVG14queryPVGReturnENS_9PVGReturnE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x6873c */ cmp w0, #0x69;
    /* 0x68740 */ b.ls #0x68750;
    /* 0x68744 */ adrp x0, #0x43000;
    /* 0x68748 */ add x0, x0, #0x92f;
    return x0;
    /* 0x68750 */ nop ;
    /* 0x68754 */ adr x8, #0x1408c0;
    /* 0x68758 */ ldr x0, [x8, w0, uxtw #3];
    return x0;
}
