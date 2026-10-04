// Library: libfntvcrash.so
// Function ID: libfntvcrash::0x4ac8
// Recovered Name: sub_4ac8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x4ac8 | Size: 20 bytes | SHA256: c572b233b449e963ec448b04ed6c3ea0da1b77be397f766d3352ad1f7b312cc0
// Callers: 1 | Callees: 0 | Imports: 0


void sub_4ac8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x4ac8 */ bti c;
    /* 0x4acc */ ldr x8, [x0];
    /* 0x4ad0 */ mov w1, wzr;
    /* 0x4ad4 */ ldr x16, [x8, #0x40];
    /* 0x4ad8 */ br x16;
}
