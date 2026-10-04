// Library: libarkernel3.so
// Function ID: libarkernel3::0x7629fc
// Recovered Name: sub_7629fc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7629fc | Size: 2628 bytes | SHA256: c04369732f7a0d20da4050dbb3b3b7a193f6412bfbf77e02d84c5b43270a88c8
// Callers: 0 | Callees: 36 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "CommonFilterRenderShader: shader meta invalid"
//   "CommonFilterRenderShader: shader missing or invalid (%s, %s)"
//   "FSPath"
//   "GenIndex"
//   "GenTextureDirection"

void sub_7629fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 657 instructions
    /* 0x7629fc */ stp x29, x30, [sp, #0xc0];
    /* 0x762a00 */ stp x28, x27, [sp, #0xd0];
    /* 0x762a04 */ stp x26, x25, [sp, #0xe0];
    /* 0x762a08 */ stp x24, x23, [sp, #0xf0];
    /* 0x762a0c */ stp x22, x21, [sp, #0x100];
    /* 0x762a10 */ stp x20, x19, [sp, #0x110];
    /* 0x762a14 */ add x29, sp, #0xc0;
    /* 0x762a18 */ mrs x8, tpidr_el0;
    /* 0x762a1c */ mov x20, x1;
    /* 0x762a20 */ mov x19, x0;
    /* 0x762a24 */ str x8, [sp, #8];
    sub_75f758();
    sub_b693e8();
    sub_b693f0();
    sub_b693e8();
    sub_b68364();
    sub_ccc064();
    _ZdlPv();
    _ZdlPv();
    sub_b693f0();
    sub_b693e8();
    sub_b68364();
    sub_ccc064();
    _ZdlPv();
    _ZdlPv();
    sub_b693f0();
    sub_b693e8();
    sub_b67b58();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b693f0();
    sub_b693e8();
    sub_b67b58();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_6671b4();
    _ZdlPv();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b67f0c();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_763440();
    sub_763538();
    sub_763538();
    sub_b693f0();
    sub_b693e8();
    sub_764594();
    sub_7644f0();
    sub_764560();
    sub_b67a70();
    sub_b69e60();
    sub_b69e68();
    sub_b6792c();
    sub_7674a4();
    sub_767590();
    sub_767e00();
    sub_5600a4();
    sub_75eac0();
    _ZdlPv();
    sub_7674ec();
    sub_7635dc();
    sub_ccc46c();
    sub_ccc46c();
    sub_a7fc58();
    sub_5604d4();
    sub_a7b364();
    _ZdlPv();
    sub_ccc46c();
    sub_ccc46c();
    sub_a6a3d8();
    sub_cccfe0();
    sub_a6a3d8();
    _Znwm();
    sub_a036d8();
    sub_56cab0();
    sub_56cab0();
    sub_56cab0();
    sub_56cab0();
    sub_56cab0();
    sub_ccccbc();
    sub_ccccbc();
    sub_cccfe0();
    _ZdlPv();
    _ZdlPv();
    return x0;
    sub_7644dc();
    _ZdlPv();
    sub_764560();
    _ZdlPv();
    sub_7674ec();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
