// Library: libarkernel3.so
// Function ID: libarkernel3::0x83f8c0
// Recovered Name: sub_83f8c0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x83f8c0 | Size: 740 bytes | SHA256: 8e58adb0bc7655265d3a93b21a0c463e35e1f267e290ef5e53e073e82d69ec8c
// Callers: 0 | Callees: 8 | Imports: 4

// Calls external APIs: _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE, _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "Shaders/HairSoft/MTFilter_gradient.fs"
//   "Shaders/HairSoft/MTFilter_gradient.vs"

void sub_83f8c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 185 instructions
    /* 0x83f8c0 */ stp x29, x30, [sp, #0xa0];
    /* 0x83f8c4 */ str x23, [sp, #0xb0];
    /* 0x83f8c8 */ stp x22, x21, [sp, #0xc0];
    /* 0x83f8cc */ stp x20, x19, [sp, #0xd0];
    /* 0x83f8d0 */ add x29, sp, #0xa0;
    /* 0x83f8d4 */ mrs x23, tpidr_el0;
    /* 0x83f8d8 */ mov x19, x0;
    /* 0x83f8dc */ ldr x8, [x23, #0x28];
    /* 0x83f8e0 */ stur x8, [x29, #-8];
    sub_9edd98();
    /* 0x83f8e8 */ adrp x8, #0x1090000;
    _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE();
    sub_5604d4();
    sub_a7fc58();
    sub_560420();
    memmove();
    sub_ccc064();
    sub_560420();
    memmove();
    sub_ccc064();
    sub_a7b38c();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_9eddf8();
    sub_106b814();
    __stack_chk_fail();
}
