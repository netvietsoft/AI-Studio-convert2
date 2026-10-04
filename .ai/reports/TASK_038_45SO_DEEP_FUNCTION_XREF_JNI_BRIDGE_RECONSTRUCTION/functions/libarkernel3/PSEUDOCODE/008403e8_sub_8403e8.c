// Library: libarkernel3.so
// Function ID: libarkernel3::0x8403e8
// Recovered Name: sub_8403e8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8403e8 | Size: 744 bytes | SHA256: 19c96cb956824fee4675251ec475533411eeac42ef77c4cd3bd7b376b4d0b63a
// Callers: 0 | Callees: 8 | Imports: 4

// Calls external APIs: _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE, _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "Shaders/HairSoft/MTFilter_PsSoftLightr.fs"
//   "Shaders/HairSoft/MTFilter_PsSoftLightr.vs"

void sub_8403e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 186 instructions
    /* 0x8403e8 */ stp x29, x30, [sp, #0xa0];
    /* 0x8403ec */ str x23, [sp, #0xb0];
    /* 0x8403f0 */ stp x22, x21, [sp, #0xc0];
    /* 0x8403f4 */ stp x20, x19, [sp, #0xd0];
    /* 0x8403f8 */ add x29, sp, #0xa0;
    /* 0x8403fc */ mrs x23, tpidr_el0;
    /* 0x840400 */ mov x19, x0;
    /* 0x840404 */ ldr x8, [x23, #0x28];
    /* 0x840408 */ stur x8, [x29, #-8];
    sub_9edd98();
    /* 0x840410 */ adrp x8, #0x1090000;
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
