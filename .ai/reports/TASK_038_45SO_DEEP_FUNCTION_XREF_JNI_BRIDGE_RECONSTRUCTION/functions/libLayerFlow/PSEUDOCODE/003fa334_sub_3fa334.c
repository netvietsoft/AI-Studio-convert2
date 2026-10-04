// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3fa334
// Recovered Name: sub_3fa334
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3fa334 | Size: 468 bytes | SHA256: 60b221f0f32ae6f5ad09c04eb2d7574c7d6b2630e31b7379731e8b6ad7d66c16
// Callers: 0 | Callees: 0 | Imports: 5

// Calls external APIs: _ZN12MTImageKitNS6FileIO14CheckFileExistEPKc, _ZN12MTImageKitNS6FileIO15ReadFile2StringEPKcRmb, _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _Znwm, memmove
// Strings referenced:
//   "/config.json"
//   "config.json"
//   "iklf"
//   "loadHairDyeConfig"

void sub_3fa334(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 117 instructions
    /* 0x3fa334 */ ldrb w8, [x22];
    /* 0x3fa338 */ cbnz w8, #0x3fa024;
    /* 0x3fa33c */ mov w19, wzr;
    /* 0x3fa340 */ b #0x3fad6c;
    /* 0x3fa344 */ orr x8, x26, #0xf;
    /* 0x3fa348 */ add x24, x8, #1;
    /* 0x3fa34c */ mov x0, x24;
    _Znwm();
    /* 0x3fa354 */ orr x8, x24, #1;
    /* 0x3fa358 */ str x0, [sp, #0x2f0];
    /* 0x3fa35c */ str x8, [sp, #0x2e0];
    memmove();
    _ZN12MTImageKitNS6FileIO14CheckFileExistEPKc();
    _ZN12MTImageKitNS6FileIO15ReadFile2StringEPKcRmb();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _Znwm();
    memmove();
    _ZN12MTImageKitNS6FileIO14CheckFileExistEPKc();
}
