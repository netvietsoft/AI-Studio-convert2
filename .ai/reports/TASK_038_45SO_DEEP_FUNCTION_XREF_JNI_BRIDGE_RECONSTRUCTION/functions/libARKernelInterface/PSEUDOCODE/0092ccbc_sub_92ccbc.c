// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x92ccbc
// Recovered Name: sub_92ccbc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x92ccbc | Size: 2156 bytes | SHA256: 16b839e17d62eeb7dda27db10ebded0b273721fe2072f4730cbd47b2f4820732
// Callers: 0 | Callees: 10 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "2P5DVersion"
//   "BPPath"
//   "BPRequire"
//   "EnableBodyBeautyBGFilling"
//   "EnableBodySlim3DAbundantBreast"

void sub_92ccbc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 539 instructions
    /* 0x92ccbc */ str x24, [sp, #0x18];
    /* 0x92ccc0 */ adrp x24, #0x236000;
    /* 0x92ccc4 */ add x24, x24, #0x4c9;
    /* 0x92ccc8 */ cbz x28, #0x92cd5c;
    /* 0x92cccc */ mov x0, x28;
    _ZdlPv();
    /* 0x92ccd4 */ b #0x92cd5c;
    /* 0x92ccd8 */ mov x0, xzr;
    /* 0x92ccdc */ add x9, x0, x24, lsl #3;
    /* 0x92cce0 */ mov x24, x9;
    /* 0x92cce4 */ str x25, [x24], #8;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5b7fa8();
    sub_932ab4();
    sub_932c8c();
    _ZdlPv();
    sub_68c06c();
    _ZdlPv();
    sub_5a8d1c();
    sub_68c87c();
    return x0;
    __stack_chk_fail();
    sub_7593e8();
}
