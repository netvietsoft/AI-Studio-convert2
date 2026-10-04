// Library: libarkernel3.so
// Function ID: libarkernel3::0x7a72fc
// Recovered Name: sub_7a72fc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7a72fc | Size: 188 bytes | SHA256: c03d732f235873c1fbca2bfdbcd5ceb89964e2b58cd59733bf75e7eedfe16baa
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::FluffyHairOption]"

void sub_7a72fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x7a72fc */ stp x29, x30, [sp, #0x50];
    /* 0x7a7300 */ str x21, [sp, #0x60];
    /* 0x7a7304 */ stp x20, x19, [sp, #0x70];
    /* 0x7a7308 */ add x29, sp, #0x50;
    /* 0x7a730c */ mrs x20, tpidr_el0;
    /* 0x7a7310 */ mov x19, x0;
    /* 0x7a7314 */ ldr x8, [x20, #0x28];
    /* 0x7a7318 */ stur x8, [x29, #-8];
    sub_655fd4();
    /* 0x7a7320 */ movi v0.2d, #0000000000000000;
    /* 0x7a7324 */ adrp x8, #0x1da000;
    sub_65616c();
    sub_65616c();
    return x0;
    __stack_chk_fail();
}
