// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x336d30
// Recovered Name: _ZNSt6__ndk16vectorI13DenseHairInfoNS_9allocatorIS1_EEE18__assign_with_sizeB8ne180000IPS1_S6_EEvT_T0_l
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x336d30 | Size: 312 bytes | SHA256: 2bb519161060c7f9b07f9b71b18e6c5bfdf7680902906eb9736acd464897f8a5
// Callers: 5 | Callees: 1 | Imports: 4

// Calls external APIs: _ZdlPv, _Znwm, memcpy, memmove

void _ZNSt6__ndk16vectorI13DenseHairInfoNS_9allocatorIS1_EEE18__assign_with_sizeB8ne180000IPS1_S6_EEvT_T0_l(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 78 instructions
    /* 0x336d30 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x336d34 */ str x23, [sp, #0x10];
    /* 0x336d38 */ stp x22, x21, [sp, #0x20];
    /* 0x336d3c */ stp x20, x19, [sp, #0x30];
    /* 0x336d40 */ mov x29, sp;
    /* 0x336d44 */ ldr x8, [x0, #0x10];
    /* 0x336d48 */ ldr x21, [x0];
    /* 0x336d4c */ mov x20, x2;
    /* 0x336d50 */ mov x19, x0;
    /* 0x336d54 */ sub x9, x8, x21;
    /* 0x336d58 */ cmp x3, x9, asr #5;
    _ZdlPv();
    _Znwm();
    memcpy();
    memmove();
    memmove();
    return x0;
    sub_2cbab0();
}
