// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a104
// Recovered Name: sub_57a104
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a104 | Size: 296 bytes | SHA256: 4fe61c43966682755ed862e67be7d80903a52ad830b0f454d565560a132818ad
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeGetPartControl(J)[J (table at 0x10ce4b0)
// Calls external APIs: _ZdaPv, _Znam

jlong sub_57a104(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 74 instructions
    /* 0x57a104 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x57a108 */ stp x22, x21, [sp, #0x10];
    /* 0x57a10c */ stp x20, x19, [sp, #0x20];
    /* 0x57a110 */ mov x29, sp;
    /* 0x57a114 */ mov x19, x0;
    /* 0x57a118 */ cbz x2, #0x57a164;
    /* 0x57a11c */ mov x0, x2;
    sub_90a85c();
    /* 0x57a124 */ ldp x21, x20, [x0];
    /* 0x57a128 */ subs x8, x20, x21;
    /* 0x57a12c */ asr x22, x8, #3;
    _Znam();
    _ZdaPv();
    return x0;
}
