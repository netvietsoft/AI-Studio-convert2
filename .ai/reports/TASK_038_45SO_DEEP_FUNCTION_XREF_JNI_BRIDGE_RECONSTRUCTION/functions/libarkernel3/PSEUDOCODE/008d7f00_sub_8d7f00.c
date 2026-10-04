// Library: libarkernel3.so
// Function ID: libarkernel3::0x8d7f00
// Recovered Name: sub_8d7f00
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8d7f00 | Size: 2288 bytes | SHA256: 68e28052391810973492e4041121125f7a49b051df576d18d8517120569eb7c6
// Callers: 1 | Callees: 46 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "s_makeupAdaptMask"
//   "u_enableMakeupAdapt"
//   "u_makeupAdaptRect"
//   "u_makeupSpecifyFactor"
//   "u_maskSampler"

void sub_8d7f00(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 572 instructions
    /* 0x8d7f00 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x8d7f04 */ stp x28, x27, [sp, #0x10];
    /* 0x8d7f08 */ stp x26, x25, [sp, #0x20];
    /* 0x8d7f0c */ stp x24, x23, [sp, #0x30];
    /* 0x8d7f10 */ stp x22, x21, [sp, #0x40];
    /* 0x8d7f14 */ stp x20, x19, [sp, #0x50];
    /* 0x8d7f18 */ mov x29, sp;
    /* 0x8d7f1c */ sub sp, sp, #0x1c0;
    /* 0x8d7f20 */ mrs x28, tpidr_el0;
    /* 0x8d7f24 */ mov x20, x0;
    /* 0x8d7f28 */ mov x21, x4;
    sub_a59d14();
    sub_8d87f0();
    sub_cc451c();
    sub_aa2af4();
    sub_cc451c();
    sub_a7fc88();
    sub_9fe5a4();
    sub_a76b9c();
    sub_8d7814();
    sub_9d3f44();
    sub_9d3f34();
    sub_a434b4();
    sub_66f754();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_a69bbc();
    sub_aa2a10();
    sub_aa1c78();
    sub_a59d1c();
    sub_a59d24();
    sub_a43a4c();
    sub_a43a54();
    sub_a43a94();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_a7fc40();
    sub_a82238();
    sub_9d3c74();
    _ZdlPv();
    sub_5604d4();
    sub_a59cc4();
    sub_9d3c74();
    _ZdlPv();
    sub_5604d4();
    sub_9d3c74();
    _ZdlPv();
    sub_a7fc40();
    sub_a82238();
    sub_a69bbc();
    sub_aa2a10();
    sub_aa1934();
    sub_aa2a10();
    sub_aa191c();
    sub_5604d4();
    sub_9d3c74();
    _ZdlPv();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_9d3c74();
    _ZdlPv();
    sub_a59d1c();
    sub_a59d24();
    sub_9d3f5c();
    sub_9d3f54();
    sub_a59cdc();
    sub_9d3a5c();
    sub_a7fc40();
    sub_9d3f68();
    sub_703a0c();
    return x0;
    sub_aa2a4c();
    sub_a98948();
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a5c178();
    sub_a43054();
    sub_a5c178();
    sub_a43054();
    sub_a4725c();
    sub_a4ee84();
    sub_d1a5a4();
    sub_a7fc40();
    sub_a82f08();
    sub_a59d1c();
    sub_a59d24();
    sub_d1a6fc();
    sub_d1a6fc();
    _ZdlPv();
    _ZdlPv();
    sub_703a0c();
    sub_106b814();
    __stack_chk_fail();
}
