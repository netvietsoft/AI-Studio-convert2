// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5c5cf8
// Recovered Name: sub_5c5cf8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5c5cf8 | Size: 524 bytes | SHA256: f49a80d4db7895b63eaca8b0a6c686ece3fd4e26af8a73ecb59765c3d614af92
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "%.lf,%.lf"
//   "%.lf,%.lf,%.lf,%.lf,%.lf"
//   "Blur"
//   "BoldWidth"
//   "Editable"

void sub_5c5cf8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 131 instructions
    /* 0x5c5cf8 */ stp x29, x30, [sp, #0x120];
    /* 0x5c5cfc */ str x28, [sp, #0x130];
    /* 0x5c5d00 */ stp x22, x21, [sp, #0x140];
    /* 0x5c5d04 */ stp x20, x19, [sp, #0x150];
    /* 0x5c5d08 */ add x29, sp, #0x120;
    /* 0x5c5d0c */ mrs x22, tpidr_el0;
    /* 0x5c5d10 */ mov x19, x1;
    /* 0x5c5d14 */ adrp x1, #0x23b000;
    /* 0x5c5d18 */ add x1, x1, #0x650;
    /* 0x5c5d1c */ ldr x8, [x22, #0x28];
    /* 0x5c5d20 */ stur x8, [x29, #-8];
    sub_5bb330();
    sub_58f19c();
    _ZdlPv();
    sub_5bb330();
    sub_58f19c();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
