// Library: libarkernel3.so
// Function ID: libarkernel3::0x69681c
// Recovered Name: sub_69681c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x69681c | Size: 528 bytes | SHA256: 618a7cf5553f9d3c9a4666514679ee1b737ebcaccfed8864daaca1985e7080a9
// Callers: 0 | Callees: 7 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::AnimatedPart]"
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentAnimatedPart]"

void sub_69681c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 132 instructions
    /* 0x69681c */ stp x29, x30, [sp, #0x40];
    /* 0x696820 */ str x23, [sp, #0x50];
    /* 0x696824 */ stp x22, x21, [sp, #0x60];
    /* 0x696828 */ stp x20, x19, [sp, #0x70];
    /* 0x69682c */ add x29, sp, #0x40;
    /* 0x696830 */ mrs x22, tpidr_el0;
    /* 0x696834 */ mov x20, x1;
    /* 0x696838 */ mov x19, x0;
    /* 0x69683c */ ldr x8, [x22, #0x28];
    /* 0x696840 */ stur x8, [x29, #-8];
    /* 0x696844 */ adrp x8, #0x241000;
    sub_655e30();
    sub_a2f61c();
    sub_655fa0();
    _ZdlPv();
    _Znwm();
    sub_696d80();
    sub_6561ac();
    _ZdlPv();
    return x0;
    sub_655f8c();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
