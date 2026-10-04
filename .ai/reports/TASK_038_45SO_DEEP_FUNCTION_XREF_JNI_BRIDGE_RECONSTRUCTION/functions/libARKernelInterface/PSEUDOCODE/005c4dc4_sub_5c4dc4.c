// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5c4dc4
// Recovered Name: sub_5c4dc4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5c4dc4 | Size: 352 bytes | SHA256: 164a200f9ee30124e4d4d89cefb7efb2822277ec42f94dc2fe4b876fd458445b
// Callers: 0 | Callees: 3 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "%.lf,%.lf,%.lf,%.lf,%.lf"
//   "Blur"
//   "BoldWidth"
//   "ORGBA"
//   "ShadowConfig"

void sub_5c4dc4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 88 instructions
    /* 0x5c4dc4 */ stp x29, x30, [sp, #0x120];
    /* 0x5c4dc8 */ str x28, [sp, #0x130];
    /* 0x5c4dcc */ stp x22, x21, [sp, #0x140];
    /* 0x5c4dd0 */ stp x20, x19, [sp, #0x150];
    /* 0x5c4dd4 */ add x29, sp, #0x120;
    /* 0x5c4dd8 */ mrs x22, tpidr_el0;
    /* 0x5c4ddc */ mov x19, x1;
    /* 0x5c4de0 */ adrp x1, #0x18e000;
    /* 0x5c4de4 */ add x1, x1, #0xa3a;
    /* 0x5c4de8 */ ldr x8, [x22, #0x28];
    /* 0x5c4dec */ stur x8, [x29, #-8];
    sub_5ca07c();
    sub_5bb330();
    sub_58f19c();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
