// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5c5f08
// Recovered Name: sub_5c5f08
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5c5f08 | Size: 688 bytes | SHA256: fa7c962bf006dfca2f7ef6de1bb12d84925e87e2e819d940267d91383644c305
// Callers: 0 | Callees: 3 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "%.lf,%.lf"
//   "%.lf,%.lf,%.lf,%.lf,%.lf"
//   "Blur"
//   "BoldWidth"
//   "GaussianGlowConfig"

void sub_5c5f08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 172 instructions
    /* 0x5c5f08 */ stp x29, x30, [sp, #0x120];
    /* 0x5c5f0c */ str x28, [sp, #0x130];
    /* 0x5c5f10 */ stp x22, x21, [sp, #0x140];
    /* 0x5c5f14 */ stp x20, x19, [sp, #0x150];
    /* 0x5c5f18 */ add x29, sp, #0x120;
    /* 0x5c5f1c */ mrs x22, tpidr_el0;
    /* 0x5c5f20 */ mov x20, x1;
    /* 0x5c5f24 */ adrp x1, #0x210000;
    /* 0x5c5f28 */ add x1, x1, #0x5ff;
    /* 0x5c5f2c */ ldr x8, [x22, #0x28];
    /* 0x5c5f30 */ stur x8, [x29, #-8];
    sub_5ca07c();
    sub_5bb330();
    sub_58f19c();
    _ZdlPv();
    sub_5bb330();
    sub_58f19c();
    _ZdlPv();
    sub_5bb330();
    sub_58f19c();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
