// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb075f4
// Recovered Name: sub_b075f4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb075f4 | Size: 888 bytes | SHA256: c0ed739f120937943a1a1558100906c11ddf84416c8ddc9b2e3a885762abb088
// Callers: 0 | Callees: 8 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "BrushFileInfo"
//   "BrushFilePath"
//   "FabbyMaskType"
//   "FilterType"
//   "MaterialDistance"

void sub_b075f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 222 instructions
    /* 0xb075f4 */ stp x29, x30, [sp, #0x30];
    /* 0xb075f8 */ str x23, [sp, #0x40];
    /* 0xb075fc */ stp x22, x21, [sp, #0x50];
    /* 0xb07600 */ stp x20, x19, [sp, #0x60];
    /* 0xb07604 */ add x29, sp, #0x30;
    /* 0xb07608 */ mrs x23, tpidr_el0;
    /* 0xb0760c */ mov x21, x1;
    /* 0xb07610 */ mov x19, x0;
    /* 0xb07614 */ ldr x8, [x23, #0x28];
    /* 0xb07618 */ stur x8, [x29, #-8];
    sub_61bfa0();
    sub_5a8de8();
    sub_5b7fa8();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8d1c();
    return x0;
    __stack_chk_fail();
}
