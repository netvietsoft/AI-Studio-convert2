// Library: libARSPM.so
// Function ID: libARSPM::0x16c69c
// Recovered Name: sub_16c69c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x16c69c | Size: 56 bytes | SHA256: 28bcc3a794ae81afc0e6e393abf5992b10ef025d1afc94069021bbbbf5ceee2c
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "SkBlurMaskFilterImpl"

void sub_16c69c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x16c69c */ adrp x0, #0x5f000;
    /* 0x16c6a0 */ add x0, x0, #0x571;
    /* 0x16c6a4 */ nop ;
    /* 0x16c6a8 */ adr x1, #0x16c4e0;
    /* 0x16c6ac */ b #0x15ac60;
    /* 0x16c6b0 */ b #0x4f0a00;
    /* 0x16c6b4 */ nop ;
    /* 0x16c6b8 */ adr x0, #0x16c4e0;
    return x0;
    /* 0x16c6c0 */ adrp x0, #0x5f000;
    /* 0x16c6c4 */ add x0, x0, #0x571;
    return x0;
    return x0;
}
