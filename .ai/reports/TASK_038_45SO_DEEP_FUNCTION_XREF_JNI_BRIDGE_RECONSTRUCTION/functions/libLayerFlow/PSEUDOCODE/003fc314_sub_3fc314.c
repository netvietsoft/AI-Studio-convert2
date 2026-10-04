// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3fc314
// Recovered Name: sub_3fc314
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3fc314 | Size: 124 bytes | SHA256: 6617cc84dab78072e3f90088c0287452afe1d34c0208fb2c35a8f94e04682c6d
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z
// Strings referenced:
//   "CLFDenseHairProcessor<%s:%d> Unknown hair operation type:%d"
//   "applyLayer"
//   "iklf"

void sub_3fc314(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0x3fc314 */ adrp x0, #0x1d9000;
    /* 0x3fc318 */ add x0, x0, #0x93c;
    /* 0x3fc31c */ adrp x2, #0x1d1000;
    /* 0x3fc320 */ add x2, x2, #0x8c;
    /* 0x3fc324 */ adrp x3, #0x1ce000;
    /* 0x3fc328 */ add x3, x3, #0xbb0;
    /* 0x3fc32c */ mov w1, #5;
    /* 0x3fc330 */ mov w4, #0x1d0;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    /* 0x3fc338 */ ldr x24, [sp, #0x50];
    /* 0x3fc33c */ mov w21, wzr;
    sub_2bc2f4();
    sub_2bc2e0();
    sub_2bc2e0();
}
