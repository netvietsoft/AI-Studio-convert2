// Library: libPVGColorFunctions.so
// Function ID: libPVGColorFunctions::0x20c7c
// Recovered Name: _ZN8PVGCOLOR17PVGColorFunctions7setTypeENS_14PVGProfileTypeE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x20c7c | Size: 32 bytes | SHA256: c6d8d59ae30bbd318a33d823aea7ae7aaa36e5948e94610375433595bafd493d
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN8PVGCOLOR17PVGColorFunctions7setTypeENS_14PVGProfileTypeE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x20c7c */ ldr w8, [x0, #8];
    /* 0x20c80 */ cmp w8, w1;
    /* 0x20c84 */ b.eq #0x20c94;
    /* 0x20c88 */ mov w8, #1;
    /* 0x20c8c */ str w1, [x0, #8];
    /* 0x20c90 */ strb w8, [x0, #0x44];
    /* 0x20c94 */ mov w0, wzr;
    return x0;
}
