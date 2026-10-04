// Library: libARSPM.so
// Function ID: libARSPM::0x2e570c
// Recovered Name: sub_2e570c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e570c | Size: 608 bytes | SHA256: 5262f2b1fb4b22361914b8517a783913210f8e908478f9f8edd491d67f4afb1b
// Callers: 0 | Callees: 8 | Imports: 0

// Strings referenced:
//   "RoundRect Blur Mask"

void sub_2e570c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 152 instructions
    /* 0x2e570c */ ldr x0, [sp, #0x100];
    /* 0x2e5710 */ adrp x8, #0x516000;
    /* 0x2e5714 */ ldr w19, [x8, #0x5e0];
    /* 0x2e5718 */ cmp x0, x27;
    /* 0x2e571c */ b.eq #0x2e5724;
    sub_2666f8();
    /* 0x2e5724 */ mov w0, #0xb;
    /* 0x2e5728 */ mov w1, #4;
    /* 0x2e572c */ sub x26, x29, #0x90;
    sub_14e8ac();
    /* 0x2e5734 */ mov w8, #0xaaab;
    sub_3f2364();
    sub_2ffbc0();
    sub_172d18();
    sub_312a04();
    sub_3120e4();
    sub_4ecb10();
    sub_4ecb10();
}
