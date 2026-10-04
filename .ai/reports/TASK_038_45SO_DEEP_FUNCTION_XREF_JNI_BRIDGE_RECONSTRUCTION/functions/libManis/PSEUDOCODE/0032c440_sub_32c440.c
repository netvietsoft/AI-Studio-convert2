// Library: libManis.so
// Function ID: libManis::0x32c440
// Recovered Name: sub_32c440
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x32c440 | Size: 76 bytes | SHA256: eb56a07f83784516ab1d62d3f424810bd72d4fd634e5c2845ad25bde3ad12b8e
// Callers: 1 | Callees: 1 | Imports: 0


void sub_32c440(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x32c440 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x32c444 */ stp x20, x19, [sp, #0x10];
    /* 0x32c448 */ mov x29, sp;
    /* 0x32c44c */ mov w19, w1;
    /* 0x32c450 */ sxtw x20, w19;
    /* 0x32c454 */ add x8, x0, x20;
    /* 0x32c458 */ add x0, x8, #8;
    sub_32be50();
    /* 0x32c460 */ cbz x0, #0x32c480;
    /* 0x32c464 */ neg w8, w19;
    /* 0x32c468 */ add x9, x0, x20;
    return x0;
}
