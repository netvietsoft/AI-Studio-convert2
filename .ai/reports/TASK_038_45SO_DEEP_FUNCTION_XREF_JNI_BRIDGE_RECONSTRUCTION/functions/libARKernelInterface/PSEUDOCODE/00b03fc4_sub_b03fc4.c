// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb03fc4
// Recovered Name: sub_b03fc4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb03fc4 | Size: 2428 bytes | SHA256: d64d8592f95b110d78924312a42c8c6d294972f1c2ac0df1e0af49b4481d85f4
// Callers: 0 | Callees: 9 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "BlurRadius"
//   "Expansion"
//   "FacemeshType"
//   "LocateMethod"
//   "Offset"

void sub_b03fc4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 607 instructions
    /* 0xb03fc4 */ stp x29, x30, [sp, #0xd0];
    /* 0xb03fc8 */ stp x28, x27, [sp, #0xe0];
    /* 0xb03fcc */ stp x26, x25, [sp, #0xf0];
    /* 0xb03fd0 */ stp x24, x23, [sp, #0x100];
    /* 0xb03fd4 */ stp x22, x21, [sp, #0x110];
    /* 0xb03fd8 */ stp x20, x19, [sp, #0x120];
    /* 0xb03fdc */ add x29, sp, #0xd0;
    /* 0xb03fe0 */ mrs x26, tpidr_el0;
    /* 0xb03fe4 */ mov x21, x1;
    /* 0xb03fe8 */ mov x20, x0;
    /* 0xb03fec */ ldr x8, [x26, #0x28];
    sub_886528();
    sub_5a8d0c();
    sub_765510();
    sub_5b7fa8();
    sub_b03b6c();
    _ZdlPv();
    _ZdlPv();
    sub_b04940();
    sub_b03ab4();
    _ZdlPv();
    sub_59e3a4();
    sub_5a8d0c();
    sub_765510();
    sub_5b7fa8();
    _ZdlPv();
    sub_59e3a4();
    sub_5a8d0c();
    sub_765510();
    sub_5cb124();
    _ZdlPv();
    sub_59e3a4();
    sub_5a8d0c();
    sub_765510();
    sub_5cb124();
    _ZdlPv();
    sub_59e3a4();
    sub_5a8d0c();
    sub_765510();
    sub_5cb124();
    _ZdlPv();
    sub_59e3a4();
    sub_5a8d0c();
    sub_765510();
    sub_5cb124();
    _ZdlPv();
    sub_59e3a4();
    return x0;
    __stack_chk_fail();
}
