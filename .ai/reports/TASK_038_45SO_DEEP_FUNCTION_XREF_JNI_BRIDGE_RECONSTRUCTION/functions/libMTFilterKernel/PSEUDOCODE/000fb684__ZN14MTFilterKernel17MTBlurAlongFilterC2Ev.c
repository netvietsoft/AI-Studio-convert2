// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xfb684
// Recovered Name: _ZN14MTFilterKernel17MTBlurAlongFilterC2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xfb684 | Size: 88 bytes | SHA256: 7a2f653a39f8433716e99a6ea57599ffd88b4acee3c17662a0f1bda55351548a
// Callers: 3 | Callees: 3 | Imports: 1

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_

void _ZN14MTFilterKernel17MTBlurAlongFilterC2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 22 instructions
    /* 0xfb684 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xfb688 */ stp x20, x19, [sp, #0x10];
    /* 0xfb68c */ mov x29, sp;
    /* 0xfb690 */ mov x19, x0;
    _ZN14MTFilterKernel19MTTwoPassFilterBaseC2Ev();
    /* 0xfb698 */ nop ;
    /* 0xfb69c */ adr x8, #0x1be7a0;
    /* 0xfb6a0 */ str wzr, [x19, #0xc4];
    /* 0xfb6a4 */ add x8, x8, #0x10;
    /* 0xfb6a8 */ str x8, [x19];
    /* 0xfb6ac */ nop ;
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    return x0;
    _ZN14MTFilterKernel19MTTwoPassFilterBaseD2Ev();
    sub_1b0544();
}
