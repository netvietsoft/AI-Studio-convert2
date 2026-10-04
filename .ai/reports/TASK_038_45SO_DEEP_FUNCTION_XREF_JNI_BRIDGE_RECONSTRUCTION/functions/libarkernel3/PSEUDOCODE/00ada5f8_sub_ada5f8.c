// Library: libarkernel3.so
// Function ID: libarkernel3::0xada5f8
// Recovered Name: sub_ada5f8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xada5f8 | Size: 1292 bytes | SHA256: 97513c71b2d190fc70e93118e5c8d0bd41abbcddc0580d8a685c5e39691838ec
// Callers: 0 | Callees: 8 | Imports: 4

// Calls external APIs: _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE, _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "GaussianGlowSubLayer shader prepare failed: blur=%d, blend=%d"
//   "MODULATION"
//   "mtlabar3"
//   "prepare"
//   "res/bloom/blend.frag"

void sub_ada5f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 323 instructions
    /* 0xada5f8 */ stp x29, x30, [sp, #0xa0];
    /* 0xada5fc */ str x23, [sp, #0xb0];
    /* 0xada600 */ stp x22, x21, [sp, #0xc0];
    /* 0xada604 */ stp x20, x19, [sp, #0xd0];
    /* 0xada608 */ add x29, sp, #0xa0;
    /* 0xada60c */ mrs x23, tpidr_el0;
    /* 0xada610 */ mov x19, x0;
    /* 0xada614 */ ldr x8, [x23, #0x28];
    /* 0xada618 */ stur x8, [x29, #-8];
    /* 0xada61c */ str x1, [x0, #0x80];
    /* 0xada620 */ mov w0, wzr;
    _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE();
    sub_5604d4();
    sub_a7fc58();
    sub_560420();
    memmove();
    sub_ccc064();
    sub_560420();
    memmove();
    sub_ccc064();
    sub_5604d4();
    sub_a7b364();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_a7fc58();
    sub_560420();
    memmove();
    sub_ccc064();
    sub_560420();
    memmove();
    sub_ccc064();
    sub_5604d4();
    sub_a7b364();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_a6a3d8();
    sub_a6a3d8();
    sub_a6a3d8();
    sub_a6a3d8();
    sub_cccfe0();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
