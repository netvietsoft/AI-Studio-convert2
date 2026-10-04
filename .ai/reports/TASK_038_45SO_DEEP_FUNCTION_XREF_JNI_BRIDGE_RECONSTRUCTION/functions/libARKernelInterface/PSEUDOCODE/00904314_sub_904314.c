// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x904314
// Recovered Name: sub_904314
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x904314 | Size: 1240 bytes | SHA256: f20a4a0d7443c86198a57aa0a4e34c46c3ff83026f1386365d9cfcfd63de385e
// Callers: 0 | Callees: 4 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "AppearGradualTime"
//   "Debug"
//   "Degree"
//   "DisableDisapperGradualWhenDistinguishFaces"
//   "DisappearGradualTime"

void sub_904314(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 310 instructions
    /* 0x904314 */ stp x29, x30, [sp, #0x20];
    /* 0x904318 */ str x23, [sp, #0x30];
    /* 0x90431c */ stp x22, x21, [sp, #0x40];
    /* 0x904320 */ stp x20, x19, [sp, #0x50];
    /* 0x904324 */ add x29, sp, #0x20;
    /* 0x904328 */ mrs x23, tpidr_el0;
    /* 0x90432c */ mov x21, x1;
    /* 0x904330 */ mov x20, x0;
    /* 0x904334 */ ldr x8, [x23, #0x28];
    /* 0x904338 */ stur x8, [x29, #-8];
    sub_61bfa0();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8da0();
    sub_5a8da0();
    sub_5cb124();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
