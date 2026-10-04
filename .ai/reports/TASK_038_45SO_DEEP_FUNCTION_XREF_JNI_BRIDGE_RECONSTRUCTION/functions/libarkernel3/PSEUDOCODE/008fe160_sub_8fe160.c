// Library: libarkernel3.so
// Function ID: libarkernel3::0x8fe160
// Recovered Name: sub_8fe160
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8fe160 | Size: 260 bytes | SHA256: 299768f078ea39b4e77e9ba593889924a42f507c6ecf418665cf42c7bebd2159
// Callers: 1 | Callees: 3 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "getBlurRadiusByLipMode"
//   "mode = %d,  a New Mode ? initial it !"
//   "mtlabar3"

void sub_8fe160(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 65 instructions
    /* 0x8fe160 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8fe164 */ str x19, [sp, #0x10];
    /* 0x8fe168 */ mov x29, sp;
    /* 0x8fe16c */ mov w19, w1;
    sub_aa2a10();
    sub_aa18f4();
    /* 0x8fe178 */ and w8, w19, #0xff;
    /* 0x8fe17c */ cmp w8, #4;
    /* 0x8fe180 */ b.le #0x8fe1a8;
    /* 0x8fe184 */ cmp w8, #7;
    /* 0x8fe188 */ b.gt #0x8fe1d0;
    sub_cccfe0();
    return x0;
}
