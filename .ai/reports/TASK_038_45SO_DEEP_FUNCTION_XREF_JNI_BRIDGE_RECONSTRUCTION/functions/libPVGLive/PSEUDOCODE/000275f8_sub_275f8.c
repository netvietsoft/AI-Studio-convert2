// Library: libPVGLive.so
// Function ID: libPVGLive::0x275f8
// Recovered Name: sub_275f8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x275f8 | Size: 160 bytes | SHA256: 31294e83961509779aa343eeb648c967bfcc11e6e3fc3373520d4bd2f88af98d
// Callers: 2 | Callees: 1 | Imports: 3

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _Znwm, fopen

void sub_275f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 40 instructions
    /* 0x275f8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x275fc */ stp x22, x21, [sp, #0x10];
    /* 0x27600 */ stp x20, x19, [sp, #0x20];
    /* 0x27604 */ mov x29, sp;
    /* 0x27608 */ mov x19, x8;
    /* 0x2760c */ cbz x0, #0x27664;
    /* 0x27610 */ mov x20, x1;
    /* 0x27614 */ cbz x1, #0x27664;
    /* 0x27618 */ mov x1, x20;
    fopen();
    /* 0x27620 */ cbz x0, #0x27664;
    _Znwm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    return x0;
    sub_8c7c4();
}
