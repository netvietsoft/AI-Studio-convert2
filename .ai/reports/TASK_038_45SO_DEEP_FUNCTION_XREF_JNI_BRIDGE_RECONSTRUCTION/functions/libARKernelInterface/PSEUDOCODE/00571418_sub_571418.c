// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x571418
// Recovered Name: sub_571418
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x571418 | Size: 296 bytes | SHA256: 0f305f0e298c4a114a73b0bdc65af7342441831a1225de3729cfd83db3762437
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeGetPlistData(J)[J (table at 0x10cd640)
// Calls external APIs: _ZdaPv, _Znam

jlong sub_571418(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 74 instructions
    /* 0x571418 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x57141c */ stp x22, x21, [sp, #0x10];
    /* 0x571420 */ stp x20, x19, [sp, #0x20];
    /* 0x571424 */ mov x29, sp;
    /* 0x571428 */ mov x19, x0;
    /* 0x57142c */ cbz x2, #0x571478;
    /* 0x571430 */ mov x0, x2;
    sub_892430();
    /* 0x571438 */ ldp x21, x20, [x0];
    /* 0x57143c */ subs x8, x20, x21;
    /* 0x571440 */ asr x22, x8, #3;
    _Znam();
    _ZdaPv();
    return x0;
}
