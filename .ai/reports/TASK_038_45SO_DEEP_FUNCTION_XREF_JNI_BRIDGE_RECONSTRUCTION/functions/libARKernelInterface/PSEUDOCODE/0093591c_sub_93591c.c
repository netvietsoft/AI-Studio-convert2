// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x93591c
// Recovered Name: sub_93591c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x93591c | Size: 524 bytes | SHA256: 22294f9f4646b4650a8b0949e985796252c189173c24d5c575cb92feb3572279
// Callers: 0 | Callees: 5 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "0F"
//   "SegmentType"
//   "pNX"

void sub_93591c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 131 instructions
    /* 0x93591c */ stp x29, x30, [sp, #0x60];
    /* 0x935920 */ stp x24, x23, [sp, #0x70];
    /* 0x935924 */ stp x22, x21, [sp, #0x80];
    /* 0x935928 */ stp x20, x19, [sp, #0x90];
    /* 0x93592c */ add x29, sp, #0x60;
    /* 0x935930 */ mrs x23, tpidr_el0;
    /* 0x935934 */ mov x19, x0;
    /* 0x935938 */ ldr x8, [x23, #0x28];
    /* 0x93593c */ stur x8, [x29, #-8];
    sub_7a0718();
    /* 0x935944 */ mov w20, w0;
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
    sub_7593e8();
}
