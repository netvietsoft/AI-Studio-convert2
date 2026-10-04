// Library: libhttpelf.so
// Function ID: libhttpelf::0x5aac
// Recovered Name: sub_5aac
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5aac | Size: 44 bytes | SHA256: 20feb3da3afcb102ccc4495fb3b9524bb427dd71bf9a0dee220ff984a25d3a0e
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

void sub_5aac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x5aac */ stp x29, x30, [sp, #-0x10]!;
    /* 0x5ab0 */ mov x29, sp;
    /* 0x5ab4 */ mov w0, #0x60;
    _Znwm();
    /* 0x5abc */ str wzr, [x0, #0x18];
    /* 0x5ac0 */ str wzr, [x0, #0x28];
    /* 0x5ac4 */ str wzr, [x0, #0x48];
    /* 0x5ac8 */ str wzr, [x0, #0x58];
    /* 0x5acc */ str wzr, [x0, #0x38];
    /* 0x5ad0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
