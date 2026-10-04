// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5c3384
// Recovered Name: sub_5c3384
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5c3384 | Size: 1072 bytes | SHA256: c931a5efd13d57be23d237f60b7f2fb9a3b95cb763a89d58e70b130a50110792
// Callers: 0 | Callees: 11 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "Blur"
//   "BoldWidth"
//   "Editable"
//   "Enable"
//   "GaussianGlowConfig"

void sub_5c3384(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 268 instructions
    /* 0x5c3384 */ stp x29, x30, [sp, #0x30];
    /* 0x5c3388 */ stp x22, x21, [sp, #0x40];
    /* 0x5c338c */ stp x20, x19, [sp, #0x50];
    /* 0x5c3390 */ add x29, sp, #0x30;
    /* 0x5c3394 */ mrs x22, tpidr_el0;
    /* 0x5c3398 */ mov x21, x0;
    /* 0x5c339c */ mov x19, x1;
    /* 0x5c33a0 */ ldr x8, [x22, #0x28];
    /* 0x5c33a4 */ stur x8, [x29, #-8];
    /* 0x5c33a8 */ ldr x8, [x0];
    /* 0x5c33ac */ ldr x8, [x8, #0xa8];
    sub_5a8cfc();
    sub_5c9b38();
    sub_5a8de8();
    sub_5a8de8();
    sub_5cb124();
    sub_5cb47c();
    sub_dad750();
    sub_dad814();
    _ZdlPv();
    sub_5a8de8();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8d1c();
    sub_5cb124();
    sub_5cb47c();
    sub_daca1c();
    sub_daca8c();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
