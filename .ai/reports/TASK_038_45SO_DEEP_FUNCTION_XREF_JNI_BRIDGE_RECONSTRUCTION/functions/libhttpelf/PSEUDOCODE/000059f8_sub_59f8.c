// Library: libhttpelf.so
// Function ID: libhttpelf::0x59f8
// Recovered Name: sub_59f8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x59f8 | Size: 108 bytes | SHA256: 625ea78c90449acc5d3361ba2ba7e2904828259dd492aa4e1f1d032ef7bb32e8
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdaPv

void sub_59f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x59f8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x59fc */ str x19, [sp, #0x10];
    /* 0x5a00 */ mov x29, sp;
    /* 0x5a04 */ mov x19, x0;
    /* 0x5a08 */ ldr x0, [x0];
    /* 0x5a0c */ cbz x0, #0x5a14;
    _ZdaPv();
    /* 0x5a14 */ ldr x0, [x19, #0x10];
    /* 0x5a18 */ cbz x0, #0x5a20;
    _ZdaPv();
    /* 0x5a20 */ ldr x0, [x19, #0x20];
    _ZdaPv();
    _ZdaPv();
    _ZdaPv();
    return x0;
}
