// Library: libarkernel3.so
// Function ID: libarkernel3::0x8b84b0
// Recovered Name: sub_8b84b0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8b84b0 | Size: 2184 bytes | SHA256: fe2faa9bb434ca2e31e96c8a85ca8383cc75c5a401bd7a2412a4b572e5dda57e
// Callers: 0 | Callees: 21 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "BLEND_MODE_ADD"
//   "BLEND_MODE_COLOR"
//   "BLEND_MODE_COLOR_BURN"
//   "BLEND_MODE_COLOR_DODGE"
//   "BLEND_MODE_DARKEN"

void sub_8b84b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 546 instructions
    /* 0x8b84b0 */ stp x29, x30, [sp, #0x40];
    /* 0x8b84b4 */ str x21, [sp, #0x50];
    /* 0x8b84b8 */ stp x20, x19, [sp, #0x60];
    /* 0x8b84bc */ add x29, sp, #0x40;
    /* 0x8b84c0 */ mrs x20, tpidr_el0;
    /* 0x8b84c4 */ mov x19, x0;
    /* 0x8b84c8 */ add x21, x0, #0x608;
    /* 0x8b84cc */ ldr x8, [x20, #0x28];
    /* 0x8b84d0 */ stur x8, [x29, #-8];
    /* 0x8b84d4 */ ldr x1, [x0, #0x608];
    /* 0x8b84d8 */ add x0, x0, #0x600;
    sub_5fc608();
    sub_8b97b4();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b97b4();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9800();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b984c();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9898();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b98e4();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9930();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b97b4();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b997c();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b99c8();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9a14();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9930();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b984c();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b984c();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b997c();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9a60();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9aac();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9af8();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9b44();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9aac();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9800();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9b90();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9bdc();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9b44();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9c28();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9b44();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    sub_8b9c74();
    sub_8bba80();
    _ZdlPv();
    _ZdlPv();
    return x0;
    sub_5e15e4();
    sub_106b814();
    __stack_chk_fail();
}
