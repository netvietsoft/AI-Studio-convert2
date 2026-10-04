// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5712f0
// Recovered Name: sub_5712f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5712f0 | Size: 296 bytes | SHA256: db03e8afc01d79f62ed0606493d6ebc9a1e15d9d1615b3eb35b04cff38594986
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeGetPartControl(J)[J (table at 0x10cd628)
// Calls external APIs: _ZdaPv, _Znam

jlong sub_5712f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 74 instructions
    /* 0x5712f0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5712f4 */ stp x22, x21, [sp, #0x10];
    /* 0x5712f8 */ stp x20, x19, [sp, #0x20];
    /* 0x5712fc */ mov x29, sp;
    /* 0x571300 */ mov x19, x0;
    /* 0x571304 */ cbz x2, #0x571350;
    /* 0x571308 */ mov x0, x2;
    sub_8922a8();
    /* 0x571310 */ ldp x21, x20, [x0];
    /* 0x571314 */ subs x8, x20, x21;
    /* 0x571318 */ asr x22, x8, #3;
    _Znam();
    _ZdaPv();
    return x0;
}
