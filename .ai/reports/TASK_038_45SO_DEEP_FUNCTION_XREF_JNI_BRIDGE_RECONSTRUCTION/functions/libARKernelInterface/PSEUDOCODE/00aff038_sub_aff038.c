// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xaff038
// Recovered Name: sub_aff038
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xaff038 | Size: 660 bytes | SHA256: 447f5bc5a6f618d5cd2a55758f73816c9279672293246a03336a4099a4780334
// Callers: 0 | Callees: 13 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "DefaultSize"
//   "MaskBlurNumber"
//   "MaskBlurRange"
//   "MaskConfig"

void sub_aff038(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 165 instructions
    /* 0xaff038 */ stp x29, x30, [sp, #0x100];
    /* 0xaff03c */ stp x28, x23, [sp, #0x110];
    /* 0xaff040 */ stp x22, x21, [sp, #0x120];
    /* 0xaff044 */ stp x20, x19, [sp, #0x130];
    /* 0xaff048 */ add x29, sp, #0x100;
    /* 0xaff04c */ mrs x22, tpidr_el0;
    /* 0xaff050 */ mov x20, x0;
    /* 0xaff054 */ mov x0, x1;
    /* 0xaff058 */ ldr x8, [x22, #0x28];
    /* 0xaff05c */ mov x19, x1;
    /* 0xaff060 */ stur x8, [x29, #-8];
    sub_5b7fa8();
    sub_5cb9b8();
    _ZdlPv();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    sub_5a8d1c();
    sub_68c86c();
    sub_5a8f24();
    sub_68c87c();
    sub_742ec0();
    sub_7435b8();
    sub_57688c();
    sub_5a4830();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_92ae44();
    return x0;
    __stack_chk_fail();
}
