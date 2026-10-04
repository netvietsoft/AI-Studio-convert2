// Library: libfantasy.so
// Function ID: libfantasy::0xba780
// Recovered Name: sub_ba780
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xba780 | Size: 124 bytes | SHA256: 368aa0efed5075c9692a328a533ce9fe970af7489b741151bb2e27fbfc9fe18a
// Callers: 1 | Callees: 0 | Imports: 0


void sub_ba780(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0xba780 */ ldp w8, w10, [x0, #0x10];
    /* 0xba784 */ ldr w9, [x0, #0xd8];
    /* 0xba788 */ stp w8, w9, [x1, #0x38];
    /* 0xba78c */ str w10, [x1, #8];
    /* 0xba790 */ add x10, x0, #0x19;
    /* 0xba794 */ ldrb w8, [x0, #0x18];
    /* 0xba798 */ ldr x9, [x0, #0x28];
    /* 0xba79c */ tst w8, #1;
    /* 0xba7a0 */ csel x8, x10, x9, eq;
    /* 0xba7a4 */ add x10, x0, #0x31;
    /* 0xba7a8 */ str x8, [x1, #0x10];
    return x0;
}
