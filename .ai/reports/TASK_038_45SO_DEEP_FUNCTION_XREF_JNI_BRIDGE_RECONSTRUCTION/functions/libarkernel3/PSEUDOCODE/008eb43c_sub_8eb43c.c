// Library: libarkernel3.so
// Function ID: libarkernel3::0x8eb43c
// Recovered Name: sub_8eb43c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8eb43c | Size: 240 bytes | SHA256: 510c72fb4108d3b3c325dba2c3a849be5a305cffc91c2f44522fe4d47b74cfec
// Callers: 1 | Callees: 3 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "getBlurRadiusByLipMode"
//   "mode = %d,  a New Mode ? initial it !"
//   "mtlabar3"

void sub_8eb43c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 60 instructions
    /* 0x8eb43c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8eb440 */ str x19, [sp, #0x10];
    /* 0x8eb444 */ mov x29, sp;
    /* 0x8eb448 */ mov w19, w1;
    sub_aa2a10();
    sub_aa18f4();
    /* 0x8eb454 */ and w8, w19, #0xff;
    /* 0x8eb458 */ cmp w8, #3;
    /* 0x8eb45c */ b.le #0x8eb488;
    /* 0x8eb460 */ cmp w8, #5;
    /* 0x8eb464 */ b.le #0x8eb4bc;
    sub_cccfe0();
    return x0;
}
