// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5c301c
// Recovered Name: sub_5c301c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5c301c | Size: 868 bytes | SHA256: f383a01a1225e70abe3465fe2705485d0c63205d8d094599d57817562912567a
// Callers: 0 | Callees: 9 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "Blur"
//   "BoldWidth"
//   "Editable"
//   "Enable"
//   "GaussianShadowConfig"

void sub_5c301c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 217 instructions
    /* 0x5c301c */ stp x29, x30, [sp, #0x30];
    /* 0x5c3020 */ stp x22, x21, [sp, #0x40];
    /* 0x5c3024 */ stp x20, x19, [sp, #0x50];
    /* 0x5c3028 */ add x29, sp, #0x30;
    /* 0x5c302c */ mrs x22, tpidr_el0;
    /* 0x5c3030 */ mov x21, x0;
    /* 0x5c3034 */ mov x19, x1;
    /* 0x5c3038 */ ldr x8, [x22, #0x28];
    /* 0x5c303c */ stur x8, [x29, #-8];
    /* 0x5c3040 */ ldr x8, [x0];
    /* 0x5c3044 */ ldr x8, [x8, #0xa8];
    sub_5a8cfc();
    sub_5a8de8();
    sub_5a8de8();
    sub_5cb124();
    sub_5cb47c();
    sub_dad750();
    sub_dad814();
    _ZdlPv();
    sub_5a8de8();
    sub_5cb124();
    sub_5cb47c();
    sub_daca1c();
    sub_daca8c();
    _ZdlPv();
    sub_5a8da0();
    sub_5a8da0();
    return x0;
    __stack_chk_fail();
}
