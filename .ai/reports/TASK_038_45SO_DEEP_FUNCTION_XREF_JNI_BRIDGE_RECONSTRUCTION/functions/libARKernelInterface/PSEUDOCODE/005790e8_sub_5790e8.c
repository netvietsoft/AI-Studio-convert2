// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5790e8
// Recovered Name: sub_5790e8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5790e8 | Size: 296 bytes | SHA256: 0117264b0dd2c04cd89ced1e0bfbe2e7035b7f15bc777ec4b7fa7c3e1a1ffabb
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeGetParamControl(J)[J (table at 0x10ce228)
// Calls external APIs: _ZdaPv, _Znam

jlong sub_5790e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 74 instructions
    /* 0x5790e8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5790ec */ stp x22, x21, [sp, #0x10];
    /* 0x5790f0 */ stp x20, x19, [sp, #0x20];
    /* 0x5790f4 */ mov x29, sp;
    /* 0x5790f8 */ mov x19, x0;
    /* 0x5790fc */ cbz x2, #0x579148;
    /* 0x579100 */ mov x0, x2;
    sub_8e0aa8();
    /* 0x579108 */ ldp x21, x20, [x0];
    /* 0x57910c */ subs x8, x20, x21;
    /* 0x579110 */ asr x22, x8, #3;
    _Znam();
    _ZdaPv();
    return x0;
}
