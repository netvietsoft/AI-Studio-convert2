// Library: libarkernel3.so
// Function ID: libarkernel3::0x8c01f4
// Recovered Name: sub_8c01f4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8c01f4 | Size: 192 bytes | SHA256: 65cc7e320c83d6a777134c6246d81b225d33a469bcf2a5e4823f503166f20111
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::MakeupHairPart]"

void sub_8c01f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 48 instructions
    /* 0x8c01f4 */ stp x29, x30, [sp, #0x50];
    /* 0x8c01f8 */ str x21, [sp, #0x60];
    /* 0x8c01fc */ stp x20, x19, [sp, #0x70];
    /* 0x8c0200 */ add x29, sp, #0x50;
    /* 0x8c0204 */ mrs x20, tpidr_el0;
    /* 0x8c0208 */ mov x19, x0;
    /* 0x8c020c */ ldr x8, [x20, #0x28];
    /* 0x8c0210 */ stur x8, [x29, #-8];
    sub_655fd4();
    /* 0x8c0218 */ movi v0.2d, #0000000000000000;
    /* 0x8c021c */ adrp x8, #0x1da000;
    sub_65616c();
    sub_65616c();
    return x0;
    __stack_chk_fail();
    return x0;
}
