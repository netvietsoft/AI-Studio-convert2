// Library: libarkernel3.so
// Function ID: libarkernel3::0x7637c0
// Recovered Name: sub_7637c0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7637c0 | Size: 1364 bytes | SHA256: 5a49a50658b5bd4f1d32e922bea4626da68f1b2c34d340c7d3be7876771387cc
// Callers: 0 | Callees: 31 | Imports: 3

// Calls external APIs: _ZNK8mtlabar311DataRequire15requireHandDataEv, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "CommonFilterRenderShader: segment mask texture is invalid for type %d"
//   "bindModel"
//   "fabbyMask"
//   "faceCount"
//   "facePointCount"

void sub_7637c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 341 instructions
    /* 0x7637c0 */ stp x29, x30, [sp, #0x50];
    /* 0x7637c4 */ stp x28, x27, [sp, #0x60];
    /* 0x7637c8 */ stp x26, x25, [sp, #0x70];
    /* 0x7637cc */ stp x24, x23, [sp, #0x80];
    /* 0x7637d0 */ stp x22, x21, [sp, #0x90];
    /* 0x7637d4 */ stp x20, x19, [sp, #0xa0];
    /* 0x7637d8 */ add x29, sp, #0x50;
    /* 0x7637dc */ mrs x26, tpidr_el0;
    /* 0x7637e0 */ mov x19, x0;
    /* 0x7637e4 */ mov w28, w3;
    /* 0x7637e8 */ ldr x8, [x26, #0x28];
    _ZNK8mtlabar311DataRequire15requireHandDataEv();
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a43074();
    sub_a52ec4();
    sub_764964();
    sub_a522e4();
    _ZdlPv();
    sub_69399c();
    sub_69399c();
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c208();
    sub_a5d02c();
    sub_762214();
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a43064();
    sub_a576d8();
    sub_cccfe0();
    sub_a7fc40();
    sub_a82230();
    sub_a7fc40();
    sub_a82200();
    sub_75186c();
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a43054();
    sub_a469bc();
    sub_76377c();
    sub_65e39c();
    sub_a435a8();
    sub_76377c();
    sub_763d14();
    _ZdlPv();
    sub_763e98();
    sub_a435c4();
    sub_763f0c();
    _ZdlPv();
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c208();
    sub_a5d040();
    sub_76377c();
    sub_b568dc();
    sub_69399c();
    sub_762214();
    sub_697cf0();
    return x0;
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
