// Library: libffmpeg.so
// Function ID: libffmpeg::0x212118
// Recovered Name: sub_212118
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x212118 | Size: 72 bytes | SHA256: 79b9a96d415d31ca1c2370b75fd079e6934588c594739462f9768d377374a988
// Callers: 1 | Callees: 0 | Imports: 0


void sub_212118(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x212118 */ ldrb w8, [x0];
    /* 0x21211c */ cmp w8, #0x28;
    /* 0x212120 */ b.ne #0x21215c;
    /* 0x212124 */ add x8, x0, #2;
    /* 0x212128 */ ldurb w9, [x8, #-1];
    /* 0x21212c */ and w10, w9, #0xffffffdf;
    /* 0x212130 */ sub w10, w10, #0x41;
    /* 0x212134 */ cmp w10, #0x1a;
    /* 0x212138 */ b.lo #0x21214c;
    /* 0x21213c */ sub w10, w9, #0x30;
    /* 0x212140 */ cmp w9, #0x5f;
    return x0;
}
