// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3fc298
// Recovered Name: sub_3fc298
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3fc298 | Size: 124 bytes | SHA256: 79ace78fdb6d12ff5f219a44b87572950a3f35b4c9863033fec0db214e4aeaad
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZdlPv
// Strings referenced:
//   "CLFDenseHairProcessor<%s:%d> all repair hair material path is empty, materialId=%lld"
//   "applyLayer"
//   "iklf"

void sub_3fc298(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0x3fc298 */ ldr x8, [x24, #0x28];
    /* 0x3fc29c */ ldur x9, [x29, #-0x28];
    /* 0x3fc2a0 */ cmp x8, x9;
    /* 0x3fc2a4 */ b.ne #0x3fc7ac;
    /* 0x3fc2a8 */ mov w0, w21;
    /* 0x3fc2ac */ add sp, sp, #0x4d0;
    /* 0x3fc2b0 */ ldp x20, x19, [sp, #0x60];
    /* 0x3fc2b4 */ ldp x22, x21, [sp, #0x50];
    /* 0x3fc2b8 */ ldp x24, x23, [sp, #0x40];
    /* 0x3fc2bc */ ldp x26, x25, [sp, #0x30];
    /* 0x3fc2c0 */ ldp x28, x27, [sp, #0x20];
    return x0;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZdlPv();
}
