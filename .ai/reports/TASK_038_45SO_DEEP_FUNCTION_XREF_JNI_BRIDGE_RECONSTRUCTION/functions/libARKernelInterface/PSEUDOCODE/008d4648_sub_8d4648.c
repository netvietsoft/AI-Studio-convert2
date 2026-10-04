// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x8d4648
// Recovered Name: sub_8d4648
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8d4648 | Size: 1956 bytes | SHA256: afc4f8348514101c64c28f3f61a135313f49d7ce5f08671681c39ee8d96b3662
// Callers: 0 | Callees: 13 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "Ambient"
//   "BSAlpha"
//   "DirectionLight"
//   "HairMatCap"
//   "Metallic"

void sub_8d4648(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 489 instructions
    /* 0x8d4648 */ stp x29, x30, [sp, #0x50];
    /* 0x8d464c */ stp x28, x27, [sp, #0x60];
    /* 0x8d4650 */ stp x26, x25, [sp, #0x70];
    /* 0x8d4654 */ stp x24, x23, [sp, #0x80];
    /* 0x8d4658 */ stp x22, x21, [sp, #0x90];
    /* 0x8d465c */ stp x20, x19, [sp, #0xa0];
    /* 0x8d4660 */ add x29, sp, #0x50;
    /* 0x8d4664 */ mrs x27, tpidr_el0;
    /* 0x8d4668 */ mov x19, x0;
    /* 0x8d466c */ mov x0, x1;
    /* 0x8d4670 */ ldr x8, [x27, #0x28];
    sub_5a8ce4();
    sub_5c9da4();
    sub_624a1c();
    sub_5a8ce4();
    sub_5c9da4();
    sub_624a1c();
    sub_5a8d04();
    sub_5c9da4();
    sub_7baa2c();
    _ZdlPv();
    sub_5a8d04();
    sub_5c9da4();
    sub_6271a8();
    _ZdlPv();
    sub_63c850();
    _ZdlPv();
    sub_5a8d1c();
    sub_5a8ce4();
    sub_8dc174();
    sub_5a8ce4();
    sub_8dc174();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    return x0;
    sub_7baa18();
    sub_63c83c();
    sub_627194();
    __stack_chk_fail();
}
