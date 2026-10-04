// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5c5878
// Recovered Name: sub_5c5878
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5c5878 | Size: 864 bytes | SHA256: 7488c93602500b065019b93346c4fe3a2490962dd17ed747756971a51f629fbf
// Callers: 0 | Callees: 4 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "%.lf,%.lf,%.lf,%.lf"
//   "%.lf,%.lf,%.lf,%.lf,%.lf"
//   "Blur"
//   "ColorCollection"
//   "GlowConfig"

void sub_5c5878(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 216 instructions
    /* 0x5c5878 */ stp x29, x30, [sp, #0x158];
    /* 0x5c587c */ str x28, [sp, #0x168];
    /* 0x5c5880 */ stp x26, x25, [sp, #0x170];
    /* 0x5c5884 */ stp x24, x23, [sp, #0x180];
    /* 0x5c5888 */ stp x22, x21, [sp, #0x190];
    /* 0x5c588c */ stp x20, x19, [sp, #0x1a0];
    /* 0x5c5890 */ add x29, sp, #0x158;
    /* 0x5c5894 */ mrs x24, tpidr_el0;
    /* 0x5c5898 */ mov x19, x1;
    /* 0x5c589c */ adrp x1, #0x18e000;
    /* 0x5c58a0 */ add x1, x1, #0xa58;
    sub_5ca07c();
    sub_5bb330();
    sub_58f19c();
    _ZdlPv();
    sub_5bb330();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    sub_5ca21c();
    _ZdlPv();
    sub_58f19c();
    sub_5ca21c();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
