// Library: libarkernel3.so
// Function ID: libarkernel3::0x8c16bc
// Recovered Name: sub_8c16bc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8c16bc | Size: 284 bytes | SHA256: df218df5e26e5cab906fd189df553b48b832146c3d28b0b60e5edfa9144570d7
// Callers: 0 | Callees: 5 | Imports: 0

// Strings referenced:
//   "EnableSamllFaceReduceAlpha"
//   "FilterColorAlpha"
//   "HairsoftAlpha"
//   "HairsoftAlphaSecond"
//   "MergesrcAlpha"

void sub_8c16bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 71 instructions
    /* 0x8c16bc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8c16c0 */ str x19, [sp, #0x10];
    /* 0x8c16c4 */ mov x29, sp;
    /* 0x8c16c8 */ mov x19, x0;
    sub_90e54c();
    /* 0x8c16d0 */ adrp x1, #0x228000;
    /* 0x8c16d4 */ add x1, x1, #0x162;
    /* 0x8c16d8 */ add x0, x19, #0x80;
    sub_8c17d8();
    /* 0x8c16e0 */ adrp x2, #0x1b9000;
    /* 0x8c16e4 */ add x2, x2, #0x2cc;
    sub_8c19ec();
    sub_8c19ec();
    sub_8c19ec();
    sub_8c19ec();
    sub_8c1ae8();
    sub_8c1be4();
    sub_8c1ae8();
    sub_8c1be4();
    sub_8c19ec();
    sub_8c1ae8();
    sub_8c1ae8();
}
