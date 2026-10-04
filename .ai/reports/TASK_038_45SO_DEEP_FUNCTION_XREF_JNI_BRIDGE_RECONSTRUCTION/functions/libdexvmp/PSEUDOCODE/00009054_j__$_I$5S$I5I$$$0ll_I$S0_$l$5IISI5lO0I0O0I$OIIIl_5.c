// Library: libdexvmp.so
// Function ID: libdexvmp::0x9054
// Recovered Name: j__$_I$5S$I5I$$$0ll_I$S0_$l$5IISI5lO0I0O0I$OIIIl_50S5$
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x9054 | Size: 28 bytes | SHA256: eb89817290c428846083de5bfb493fed176f5e858314445c6879c9ba4b2682e1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: memset

void j__$_I$5S$I5I$$$0ll_I$S0_$l$5IISI5lO0I0O0I$OIIIl_50S5$(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9054 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9058 */ mov x29, sp;
    /* 0x905c */ mov w1, wzr;
    /* 0x9060 */ mov w2, #0x4020;
    memset();
    /* 0x9068 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
