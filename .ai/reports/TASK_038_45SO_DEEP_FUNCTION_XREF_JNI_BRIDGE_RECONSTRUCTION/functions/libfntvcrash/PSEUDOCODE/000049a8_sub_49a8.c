// Library: libfntvcrash.so
// Function ID: libfntvcrash::0x49a8
// Recovered Name: sub_49a8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x49a8 | Size: 164 bytes | SHA256: 00fbefda02174f7b169e8298c500ec352d5ebbfa620bcac77e5c86927e512d71
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: memcpy
// Strings referenced:
//   "4O"

void sub_49a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 41 instructions
    /* 0x49a8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x49ac */ stp x20, x19, [sp, #0x10];
    /* 0x49b0 */ mov x29, sp;
    /* 0x49b4 */ adrp x8, #0x11000;
    /* 0x49b8 */ add x8, x8, #0x138;
    /* 0x49bc */ nop ;
    /* 0x49c0 */ adr x9, #0x15800;
    /* 0x49c4 */ mov w2, #0x110;
    /* 0x49c8 */ mov x20, x1;
    /* 0x49cc */ mov x19, x0;
    /* 0x49d0 */ stp x8, x9, [x0], #0x10;
    memcpy();
    sub_5304();
    return x0;
}
