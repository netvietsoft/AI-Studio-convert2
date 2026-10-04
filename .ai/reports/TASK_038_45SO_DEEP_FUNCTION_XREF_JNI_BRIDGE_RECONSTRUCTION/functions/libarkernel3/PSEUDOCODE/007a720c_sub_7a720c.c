// Library: libarkernel3.so
// Function ID: libarkernel3::0x7a720c
// Recovered Name: sub_7a720c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7a720c | Size: 188 bytes | SHA256: 7794a4de4f46fdf8d09b5790afbf7692133c6736cfd8f195b811b48bab505c2e
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::FaceLiftFluffyHairPart::SliderControlParameter]"

void sub_7a720c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x7a720c */ stp x29, x30, [sp, #0x50];
    /* 0x7a7210 */ str x21, [sp, #0x60];
    /* 0x7a7214 */ stp x20, x19, [sp, #0x70];
    /* 0x7a7218 */ add x29, sp, #0x50;
    /* 0x7a721c */ mrs x20, tpidr_el0;
    /* 0x7a7220 */ mov x19, x0;
    /* 0x7a7224 */ ldr x8, [x20, #0x28];
    /* 0x7a7228 */ stur x8, [x29, #-8];
    sub_655fd4();
    /* 0x7a7230 */ movi v0.2d, #0000000000000000;
    /* 0x7a7234 */ adrp x8, #0x1a1000;
    sub_65616c();
    sub_65616c();
    return x0;
    __stack_chk_fail();
}
