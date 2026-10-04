// Library: libPVGLive.so
// Function ID: libPVGLive::0x27698
// Recovered Name: sub_27698
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x27698 | Size: 140 bytes | SHA256: 422d673fa5beaa81522c16ce96fee9a28c04aba494bec563b3189cd590f4a08b
// Callers: 2 | Callees: 1 | Imports: 2

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _Znwm

void sub_27698(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 35 instructions
    /* 0x27698 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2769c */ stp x22, x21, [sp, #0x10];
    /* 0x276a0 */ stp x20, x19, [sp, #0x20];
    /* 0x276a4 */ mov x29, sp;
    /* 0x276a8 */ mov x19, x8;
    /* 0x276ac */ cbz x0, #0x276f0;
    /* 0x276b0 */ mov x22, x0;
    /* 0x276b4 */ mov w0, #0x30;
    /* 0x276b8 */ mov x21, x1;
    _Znwm();
    /* 0x276c0 */ mov x20, x0;
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    return x0;
    sub_8c7c4();
}
