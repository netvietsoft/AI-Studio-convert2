// Library: libarkernel3.so
// Function ID: libarkernel3::0x83fdf0
// Recovered Name: sub_83fdf0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x83fdf0 | Size: 744 bytes | SHA256: c3225dbe1fc67c6234450d247468c6932cdb3ff1f9c5cd76014ac55321bbbd21
// Callers: 0 | Callees: 8 | Imports: 4

// Calls external APIs: _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE, _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "Shaders/HairSoft/MTFilter_HairSoftMix.fs"
//   "Shaders/HairSoft/MTFilter_HairSoftMix.vs"

void sub_83fdf0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 186 instructions
    /* 0x83fdf0 */ stp x29, x30, [sp, #0xa0];
    /* 0x83fdf4 */ str x23, [sp, #0xb0];
    /* 0x83fdf8 */ stp x22, x21, [sp, #0xc0];
    /* 0x83fdfc */ stp x20, x19, [sp, #0xd0];
    /* 0x83fe00 */ add x29, sp, #0xa0;
    /* 0x83fe04 */ mrs x23, tpidr_el0;
    /* 0x83fe08 */ mov x19, x0;
    /* 0x83fe0c */ ldr x8, [x23, #0x28];
    /* 0x83fe10 */ stur x8, [x29, #-8];
    sub_9edd98();
    /* 0x83fe18 */ adrp x8, #0x1090000;
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
