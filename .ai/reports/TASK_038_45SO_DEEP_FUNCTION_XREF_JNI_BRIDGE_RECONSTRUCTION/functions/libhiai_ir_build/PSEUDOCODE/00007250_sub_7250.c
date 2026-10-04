// Library: libhiai_ir_build.so
// Function ID: libhiai_ir_build::0x7250
// Recovered Name: sub_7250
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7250 | Size: 48 bytes | SHA256: 9dffb32e72a77a4834a0d4a4052d0941766926d253ece3a55f7c1d713f5a4a24
// Callers: 1 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void sub_7250(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x7250 */ stp x30, x19, [sp, #-0x10]!;
    /* 0x7254 */ mov x19, x0;
    /* 0x7258 */ ldr x0, [x0];
    /* 0x725c */ ldr x8, [x0];
    /* 0x7260 */ cbz x8, #0x7278;
    sub_7280();
    /* 0x7268 */ ldr x8, [x19];
    /* 0x726c */ ldr x0, [x8];
    /* 0x7270 */ ldp x30, x19, [sp], #0x10;
    /* 0x7274 */ b #0x9af0;
    /* 0x7278 */ ldp x30, x19, [sp], #0x10;
    return x0;
}
