// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x578734
// Recovered Name: sub_578734
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x578734 | Size: 296 bytes | SHA256: d0015888518bbd2a400ba317310f7c356e99c000e3321a694b4a8898df290eac
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeGetLoadedPartControl(J)[J (table at 0x10cdfe8)
// Calls external APIs: _ZdaPv, _Znam

jlong sub_578734(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 74 instructions
    /* 0x578734 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x578738 */ stp x22, x21, [sp, #0x10];
    /* 0x57873c */ stp x20, x19, [sp, #0x20];
    /* 0x578740 */ mov x29, sp;
    /* 0x578744 */ mov x19, x0;
    /* 0x578748 */ cbz x2, #0x578794;
    /* 0x57874c */ mov x0, x2;
    sub_575c5c();
    /* 0x578754 */ ldp x21, x20, [x0];
    /* 0x578758 */ subs x8, x20, x21;
    /* 0x57875c */ asr x22, x8, #3;
    _Znam();
    _ZdaPv();
    return x0;
}
