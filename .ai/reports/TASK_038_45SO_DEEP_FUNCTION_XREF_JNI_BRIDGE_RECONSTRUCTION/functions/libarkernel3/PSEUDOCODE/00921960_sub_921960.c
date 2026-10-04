// Library: libarkernel3.so
// Function ID: libarkernel3::0x921960
// Recovered Name: sub_921960
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x921960 | Size: 2640 bytes | SHA256: 5e0fb6dca5372b10c3c417476db7b669b7e7906591cfa046243cb618a7c6a768
// Callers: 0 | Callees: 22 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, memcmp
// Strings referenced:
//   "displayFrag"
//   "displayVert"
//   "effectMixFrag"
//   "effectMixVert"
//   "eraserFrag"

void sub_921960(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 660 instructions
    /* 0x921960 */ stp x29, x30, [sp, #0x70];
    /* 0x921964 */ stp x28, x27, [sp, #0x80];
    /* 0x921968 */ stp x26, x25, [sp, #0x90];
    /* 0x92196c */ stp x24, x23, [sp, #0xa0];
    /* 0x921970 */ stp x22, x21, [sp, #0xb0];
    /* 0x921974 */ stp x20, x19, [sp, #0xc0];
    /* 0x921978 */ add x29, sp, #0x70;
    /* 0x92197c */ mrs x8, tpidr_el0;
    /* 0x921980 */ mov x19, x0;
    /* 0x921984 */ add x0, x0, #0x498;
    /* 0x921988 */ str x8, [sp, #0x10];
    sub_92a814();
    sub_92a814();
    sub_a7fc58();
    sub_a7b280();
    _ZdlPv();
    sub_5604d4();
    sub_5604d4();
    sub_a7b690();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5604d4();
    sub_5604d4();
    sub_a7b690();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5604d4();
    sub_5604d4();
    sub_a7b690();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5604d4();
    sub_5604d4();
    sub_a7b690();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5604d4();
    sub_5604d4();
    sub_a7b690();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5604d4();
    sub_5604d4();
    sub_a7b690();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5604d4();
    sub_5604d4();
    sub_a7b690();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5604d4();
    sub_5604d4();
    sub_a7b690();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5604d4();
    sub_5604d4();
    sub_a7b690();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5604d4();
    sub_5604d4();
    sub_a7b690();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_ccc46c();
    sub_a7fc4c();
    sub_a7e5a0();
    sub_cc02e0();
    memcmp();
    sub_ccc46c();
    sub_a7fc4c();
    sub_a7e7e8();
    sub_cc02e0();
    sub_ccc46c();
    sub_a7fc4c();
    sub_aa2af4();
    sub_aa5bd4();
    sub_a6f348();
    sub_cc02e0();
    sub_ccc46c();
    sub_a7fc4c();
    sub_aa2af4();
    sub_aa5bd4();
    sub_a6f348();
    sub_cc02e0();
    sub_ccc46c();
    sub_a7fc4c();
    sub_a7e7e8();
    sub_cc02e0();
    sub_ccc46c();
    sub_a7fc4c();
    sub_a7e7e8();
    sub_cc02e0();
    sub_9223b0();
    sub_9223b0();
    sub_9ae938();
    sub_56cab0();
    sub_56cab0();
    sub_a7fc40();
    sub_5aa23c();
    sub_63c174();
    sub_5ab304();
    sub_a7fc40();
    sub_5aa23c();
    sub_63c174();
    sub_5ab304();
    return x0;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
    sub_562d14();
    sub_562d14();
}
