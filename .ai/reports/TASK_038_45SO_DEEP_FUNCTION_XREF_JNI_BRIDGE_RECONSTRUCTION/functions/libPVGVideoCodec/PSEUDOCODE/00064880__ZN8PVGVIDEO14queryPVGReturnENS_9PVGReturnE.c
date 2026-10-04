// Library: libPVGVideoCodec.so
// Function ID: libPVGVideoCodec::0x64880
// Recovered Name: _ZN8PVGVIDEO14queryPVGReturnENS_9PVGReturnE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x64880 | Size: 72 bytes | SHA256: 2124c290d6ea3f83386854ce0239250b3719c2d49e96654f864a7e83f282c988
// Callers: 0 | Callees: 0 | Imports: 0

// Strings referenced:
//   "Unknown PVGReturn."

void _ZN8PVGVIDEO14queryPVGReturnENS_9PVGReturnE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x64880 */ cmp w0, #0x3c;
    /* 0x64884 */ b.hi #0x6489c;
    /* 0x64888 */ nop ;
    /* 0x6488c */ adr x8, #0x11fe48;
    /* 0x64890 */ add x8, x8, w0, uxtw #3;
    /* 0x64894 */ ldr x0, [x8];
    return x0;
    /* 0x6489c */ sub w8, w0, #0x51;
    /* 0x648a0 */ cmp w8, #0x18;
    /* 0x648a4 */ b.hi #0x648bc;
    /* 0x648a8 */ nop ;
    return x0;
    return x0;
}
