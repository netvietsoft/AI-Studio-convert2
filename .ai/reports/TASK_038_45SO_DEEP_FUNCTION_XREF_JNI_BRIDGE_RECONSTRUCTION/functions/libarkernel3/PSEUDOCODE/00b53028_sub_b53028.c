// Library: libarkernel3.so
// Function ID: libarkernel3::0xb53028
// Recovered Name: sub_b53028
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb53028 | Size: 1988 bytes | SHA256: f8acf85782796e1fdc952aa70a8ce8dc756d46a53cd74c14636ce59ad6c20909
// Callers: 0 | Callees: 26 | Imports: 4

// Calls external APIs: _ZdlPv, __stack_chk_fail, wgpuTextureCreateView, wgpuTextureGetWidth
// Strings referenced:
//   "u_blur"
//   "u_cutoff"
//   "u_effectType"
//   "u_enableKok"
//   "u_enableStroke"

void sub_b53028(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 497 instructions
    /* 0xb53028 */ stp x29, x30, [sp, #0xa0];
    /* 0xb5302c */ stp x28, x27, [sp, #0xb0];
    /* 0xb53030 */ stp x26, x25, [sp, #0xc0];
    /* 0xb53034 */ stp x24, x23, [sp, #0xd0];
    /* 0xb53038 */ stp x22, x21, [sp, #0xe0];
    /* 0xb5303c */ stp x20, x19, [sp, #0xf0];
    /* 0xb53040 */ add x29, sp, #0xa0;
    /* 0xb53044 */ stp x1, x3, [sp, #0x10];
    /* 0xb53048 */ mrs x8, tpidr_el0;
    /* 0xb5304c */ mov x23, x0;
    /* 0xb53050 */ str x8, [sp, #8];
    sub_b356e8();
    sub_b356e0();
    sub_b356e0();
    sub_b356e8();
    sub_b11980();
    sub_b11914();
    sub_b11640();
    sub_5aa110();
    sub_b11320();
    sub_b11110();
    sub_b11110();
    sub_b11218();
    sub_b11194();
    sub_aa2af4();
    sub_aa5b4c();
    sub_b1129c();
    sub_b11194();
    sub_b11194();
    sub_b11110();
    sub_b11110();
    sub_aa2af4();
    sub_aa5b4c();
    sub_b1129c();
    sub_b11110();
    sub_b11110();
    sub_b11978();
    wgpuTextureGetWidth();
    sub_b11110();
    sub_b11194();
    sub_b356e0();
    sub_b11110();
    sub_b11194();
    sub_b11194();
    sub_b11978();
    wgpuTextureCreateView();
    sub_b11668();
    sub_88b818();
    _ZdlPv();
    sub_b449cc();
    sub_b449cc();
    wgpuTextureCreateView();
    sub_b11668();
    sub_b11668();
    sub_88b818();
    _ZdlPv();
    sub_b449d4();
    sub_b449d4();
    wgpuTextureCreateView();
    sub_b11668();
    sub_b11194();
    sub_a7fc40();
    sub_a82230();
    sub_a7fc40();
    sub_a82200();
    sub_b11668();
    sub_b11194();
    sub_88b818();
    _ZdlPv();
    sub_aa29c8();
    sub_a8aaa8();
    sub_b11648();
    _ZdlPv();
    return x0;
    sub_88b804();
    sub_88b804();
    sub_88b804();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
