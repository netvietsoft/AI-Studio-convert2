// Library: libarkernel3.so
// Function ID: libarkernel3::0xa9b088
// Recovered Name: sub_a9b088
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa9b088 | Size: 876 bytes | SHA256: 4bb67ca723f8f40d74750dffbf26021b54250ab4e73c171a4cb38be480c63003
// Callers: 0 | Callees: 3 | Imports: 3

// Calls external APIs: _ZdaPv, _Znam, memset
// Strings referenced:
//   "getRefCropSegmentMask"
//   "mtlabar3"

void sub_a9b088(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 219 instructions
    /* 0xa9b088 */ stp x29, x30, [sp, #0x28];
    /* 0xa9b08c */ str x27, [sp, #0x38];
    /* 0xa9b090 */ stp x26, x25, [sp, #0x40];
    /* 0xa9b094 */ stp x24, x23, [sp, #0x50];
    /* 0xa9b098 */ stp x22, x21, [sp, #0x60];
    /* 0xa9b09c */ stp x20, x19, [sp, #0x70];
    /* 0xa9b0a0 */ add x29, sp, #0x28;
    /* 0xa9b0a4 */ fmov s8, s0;
    /* 0xa9b0a8 */ ldr x27, [x29, #0x58];
    /* 0xa9b0ac */ mov x20, x7;
    /* 0xa9b0b0 */ mov x19, x6;
    _ZdaPv();
    sub_a434a8();
    sub_a434a8();
    sub_cccfe0();
    _Znam();
    memset();
    _Znam();
    sub_b9acb8();
    memset();
    _ZdaPv();
    return x0;
}
