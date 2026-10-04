// Library: libhiai_ir_build.so
// Function ID: libhiai_ir_build::0x7280
// Recovered Name: sub_7280
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7280 | Size: 72 bytes | SHA256: c6123da906dfad4a65376ad852cd0fc1dff78d4d6f7c9687d780dddf9669533d
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv

void sub_7280(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x7280 */ stp x30, x21, [sp, #-0x20]!;
    /* 0x7284 */ stp x20, x19, [sp, #0x10];
    /* 0x7288 */ ldp x20, x8, [x0];
    /* 0x728c */ mov x19, x0;
    /* 0x7290 */ cmp x8, x20;
    /* 0x7294 */ b.eq #0x72b8;
    /* 0x7298 */ mov x21, x8;
    /* 0x729c */ ldr x0, [x21, #-0x18]!;
    /* 0x72a0 */ cbz x0, #0x72ac;
    /* 0x72a4 */ stur x0, [x8, #-0x10];
    _ZdlPv();
    return x0;
}
