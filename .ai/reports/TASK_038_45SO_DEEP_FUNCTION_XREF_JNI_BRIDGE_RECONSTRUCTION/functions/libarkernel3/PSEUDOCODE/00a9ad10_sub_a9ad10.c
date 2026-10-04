// Library: libarkernel3.so
// Function ID: libarkernel3::0xa9ad10
// Recovered Name: sub_a9ad10
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa9ad10 | Size: 748 bytes | SHA256: f043f53bfc3343ae48a505e6c9c35ac581cad3c7e54b30f38f0bfc83a56cfc3c
// Callers: 0 | Callees: 3 | Imports: 3

// Calls external APIs: _ZdaPv, _Znam, memset
// Strings referenced:
//   "MouthMask(%d,%d) not matching textrure size(%d,%d)"
//   "handleSourceSizeSegmentMask"
//   "mtlabar3"

void sub_a9ad10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 187 instructions
    /* 0xa9ad10 */ stp x29, x30, [sp, #0x50];
    /* 0xa9ad14 */ str x25, [sp, #0x60];
    /* 0xa9ad18 */ stp x24, x23, [sp, #0x70];
    /* 0xa9ad1c */ stp x22, x21, [sp, #0x80];
    /* 0xa9ad20 */ stp x20, x19, [sp, #0x90];
    /* 0xa9ad24 */ add x29, sp, #0x50;
    /* 0xa9ad28 */ mov x0, x1;
    /* 0xa9ad2c */ fmov s8, s0;
    /* 0xa9ad30 */ mov w22, w3;
    /* 0xa9ad34 */ mov x19, x2;
    /* 0xa9ad38 */ mov x20, x1;
    sub_a434a8();
    sub_a434a8();
    _ZdaPv();
    sub_cccfe0();
    _Znam();
    memset();
    _Znam();
    sub_b9acb8();
    memset();
    _ZdaPv();
    return x0;
}
