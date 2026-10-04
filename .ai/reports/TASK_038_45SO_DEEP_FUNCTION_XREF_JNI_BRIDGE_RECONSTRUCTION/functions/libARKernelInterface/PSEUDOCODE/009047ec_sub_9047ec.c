// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x9047ec
// Recovered Name: sub_9047ec
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9047ec | Size: 828 bytes | SHA256: 0c5e88679cca62c6561b79eff1a7b6222bd888ffea8649df20c03971ecaa5549
// Callers: 0 | Callees: 5 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "AppearGradualTime"
//   "Degree"
//   "DisableDisapperGradualWhenDistinguishFaces"
//   "DisappearGradualTime"
//   "EnableHairDynamicSubDiv"

void sub_9047ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 207 instructions
    /* 0x9047ec */ stp x29, x30, [sp, #0x20];
    /* 0x9047f0 */ str x27, [sp, #0x30];
    /* 0x9047f4 */ stp x26, x25, [sp, #0x40];
    /* 0x9047f8 */ stp x24, x23, [sp, #0x50];
    /* 0x9047fc */ stp x22, x21, [sp, #0x60];
    /* 0x904800 */ stp x20, x19, [sp, #0x70];
    /* 0x904804 */ add x29, sp, #0x20;
    /* 0x904808 */ mrs x22, tpidr_el0;
    /* 0x90480c */ mov x19, x0;
    /* 0x904810 */ mov x20, x1;
    /* 0x904814 */ ldr x8, [x22, #0x28];
    sub_58f19c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    sub_61d798();
    _ZdlPv();
    return x0;
    sub_59c568();
    __stack_chk_fail();
}
