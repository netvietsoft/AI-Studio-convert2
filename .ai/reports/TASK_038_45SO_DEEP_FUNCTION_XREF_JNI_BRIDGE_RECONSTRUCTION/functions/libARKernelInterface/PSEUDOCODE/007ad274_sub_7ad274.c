// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x7ad274
// Recovered Name: sub_7ad274
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7ad274 | Size: 1748 bytes | SHA256: d7306a4420a43b080b911d7b41ca37d9d3077d6ae712f966180f1137ec82ffbc
// Callers: 0 | Callees: 6 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "0F"
//   "DebugPartPointSize"
//   "EnableHandRectPrint"
//   "FacePointType"
//   "SegmentType"

void sub_7ad274(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 437 instructions
    /* 0x7ad274 */ stp x29, x30, [sp, #0xf0];
    /* 0x7ad278 */ stp x28, x27, [sp, #0x100];
    /* 0x7ad27c */ stp x26, x25, [sp, #0x110];
    /* 0x7ad280 */ stp x24, x23, [sp, #0x120];
    /* 0x7ad284 */ stp x22, x21, [sp, #0x130];
    /* 0x7ad288 */ stp x20, x19, [sp, #0x140];
    /* 0x7ad28c */ add x29, sp, #0xf0;
    /* 0x7ad290 */ mrs x24, tpidr_el0;
    /* 0x7ad294 */ mov x19, x0;
    /* 0x7ad298 */ ldr x8, [x24, #0x28];
    /* 0x7ad29c */ stur x8, [x29, #-8];
    sub_8dde54();
    _Znwm();
    sub_a043b8();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    return x0;
    sub_7593e8();
    __stack_chk_fail();
}
