// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa6fbf4
// Recovered Name: sub_a6fbf4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa6fbf4 | Size: 2296 bytes | SHA256: 6e0e6294e7de6cc172a25daa7bbf09d7e1897846ebb461eecd352ed6ae8ba7b2
// Callers: 0 | Callees: 22 | Imports: 5

// Calls external APIs: _ZdlPv, _Znwm, __android_log_print, memmove, memset
// Strings referenced:
//   "BeautyResource/diamond_noise.jpg"
//   "BeautyResource/shimmer_material.jpg"
//   "LipstickMode_Metallight:%dx%d"
//   "arkernel"
//   "use part teeth blur:%d,%d"

void sub_a6fbf4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 574 instructions
    /* 0xa6fbf4 */ ldr x8, [x8, #0x20];
    /* 0xa6fbf8 */ mov x0, x21;
    /* 0xa6fbfc */ mov x1, x19;
    /* 0xa6fc00 */ blr x8;
    /* 0xa6fc04 */ ldr x0, [x19, #0x950];
    /* 0xa6fc08 */ ldr x8, [x0];
    /* 0xa6fc0c */ ldr x8, [x8, #0x50];
    /* 0xa6fc10 */ blr x8;
    /* 0xa6fc14 */ ldr x21, [x19, #0xad0];
    /* 0xa6fc18 */ cbz x21, #0xa6fc2c;
    /* 0xa6fc1c */ mov x0, x21;
    sub_a75cf8();
    _ZdlPv();
    _Znwm();
    sub_a75ce0();
    sub_a75d8c();
    sub_a75d2c();
    sub_63cdec();
    sub_5a6eb4();
    sub_58f19c();
    sub_5abbf8();
    memmove();
    sub_63cdec();
    _ZdlPv();
    _ZdlPv();
    sub_5a6b20();
    _Znwm();
    memset();
    sub_a7c940();
    __android_log_print();
    sub_63cdec();
    sub_5a6eb4();
    sub_58f19c();
    sub_5abbf8();
    memmove();
    sub_63cdec();
    _ZdlPv();
    _ZdlPv();
    sub_5a6eb4();
    sub_58f19c();
    sub_5abbf8();
    memmove();
    sub_63cdec();
    _ZdlPv();
    _ZdlPv();
    sub_570f58();
    sub_a70504();
    _ZdlPv();
    sub_a7fefc();
    sub_a80048();
    sub_c3cd6c();
    sub_6a3a94();
    sub_5a6b20();
    __android_log_print();
    sub_69db64();
    sub_a773e4();
    _ZdlPv();
    _Znwm();
    sub_a773e0();
    sub_c41220();
    sub_c41220();
    sub_a7d250();
    sub_a7d108();
    return x0;
    memset();
    sub_a7c940();
    memset();
    sub_a7c940();
    memset();
    sub_a7c940();
    sub_a7c940();
    memset();
    sub_a7c940();
    memset();
    sub_a7c940();
}
