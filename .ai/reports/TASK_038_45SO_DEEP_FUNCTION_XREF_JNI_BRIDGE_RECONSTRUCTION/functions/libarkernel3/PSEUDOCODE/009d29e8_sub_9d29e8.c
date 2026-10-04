// Library: libarkernel3.so
// Function ID: libarkernel3::0x9d29e8
// Recovered Name: sub_9d29e8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9d29e8 | Size: 2732 bytes | SHA256: c95a684bdf4a4c32d7bf29317d7db29a84c86857130cc3d2ad7dd6daa9bcf056
// Callers: 0 | Callees: 41 | Imports: 6

// Calls external APIs: _ZdaPv, _ZdlPv, _Znam, _Znwm, __stack_chk_fail, memset
// Strings referenced:
//   "333333?333333?333333?"
//   "SegmentStrokeObjPart"
//   "a_Position"
//   "a_UV"
//   "s_materialMap"

void sub_9d29e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 683 instructions
    /* 0x9d29e8 */ stp x29, x30, [sp, #0x40];
    /* 0x9d29ec */ stp x28, x27, [sp, #0x50];
    /* 0x9d29f0 */ stp x26, x25, [sp, #0x60];
    /* 0x9d29f4 */ stp x24, x23, [sp, #0x70];
    /* 0x9d29f8 */ stp x22, x21, [sp, #0x80];
    /* 0x9d29fc */ stp x20, x19, [sp, #0x90];
    /* 0x9d2a00 */ add x29, sp, #0x40;
    /* 0x9d2a04 */ sub sp, sp, #0x250;
    /* 0x9d2a08 */ mrs x19, tpidr_el0;
    /* 0x9d2a0c */ ldr x8, [x19, #0x28];
    /* 0x9d2a10 */ stur x8, [x29, #-0x58];
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_9d20b8();
    sub_f687f8();
    sub_601b7c();
    _ZdlPv();
    sub_5945cc();
    _ZdlPv();
    sub_a6e7fc();
    sub_a6e818();
    _Znam();
    memset();
    _Znam();
    memset();
    sub_a59d1c();
    sub_a59d24();
    sub_bbd744();
    sub_bbd718();
    sub_bbd6f8();
    sub_596788();
    sub_596788();
    sub_68ab88();
    sub_a59cac();
    sub_a7fc40();
    sub_a7fc40();
    sub_a82210();
    sub_a59d1c();
    sub_a59d24();
    sub_5edc30();
    sub_9fdf90();
    _Znwm();
    sub_9d36ac();
    sub_9d3bd4();
    sub_9d3a64();
    sub_9d3a64();
    sub_9d3b6c();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_a6e7f4();
    sub_9d3c74();
    _ZdlPv();
    sub_9d3f44();
    sub_9d3f3c();
    sub_9d3a44();
    sub_9d3f34();
    sub_a59cdc();
    sub_9d3a5c();
    sub_a7fc40();
    sub_9d3f68();
    _ZdaPv();
    _ZdaPv();
    sub_5ee85c();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
    sub_5945b8();
    sub_601b68();
    _ZdlPv();
    sub_562d14();
    sub_5ee85c();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
