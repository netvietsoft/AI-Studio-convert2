// Library: libarkernel3.so
// Function ID: libarkernel3::0x696d84
// Recovered Name: sub_696d84
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x696d84 | Size: 192 bytes | SHA256: 8382aad389b1d1889a87c19b7821c4de4ae5ff28d5a617362bb0d72a629ad003
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentAnimatedPart]"

void sub_696d84(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 48 instructions
    /* 0x696d84 */ stp x29, x30, [sp, #0x50];
    /* 0x696d88 */ str x21, [sp, #0x60];
    /* 0x696d8c */ stp x20, x19, [sp, #0x70];
    /* 0x696d90 */ add x29, sp, #0x50;
    /* 0x696d94 */ mrs x20, tpidr_el0;
    /* 0x696d98 */ mov x19, x0;
    /* 0x696d9c */ ldr x8, [x20, #0x28];
    /* 0x696da0 */ stur x8, [x29, #-8];
    sub_655fd4();
    /* 0x696da8 */ movi v0.2d, #0000000000000000;
    /* 0x696dac */ adrp x8, #0x241000;
    sub_65616c();
    sub_65616c();
    return x0;
    __stack_chk_fail();
    return x0;
}
