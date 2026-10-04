// Library: libarkernel3.so
// Function ID: libarkernel3::0x84093c
// Recovered Name: sub_84093c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x84093c | Size: 728 bytes | SHA256: 261d33863aa6b8c106865569074a75db0e833b5137259a1b56320631077fee3e
// Callers: 0 | Callees: 8 | Imports: 4

// Calls external APIs: _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE, _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "Shaders/HairSoft/MTFilter_Mix.fs"
//   "Shaders/HairSoft/MTFilter_Mix.vs"

void sub_84093c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 182 instructions
    /* 0x84093c */ stp x29, x30, [sp, #0xa0];
    /* 0x840940 */ str x23, [sp, #0xb0];
    /* 0x840944 */ stp x22, x21, [sp, #0xc0];
    /* 0x840948 */ stp x20, x19, [sp, #0xd0];
    /* 0x84094c */ add x29, sp, #0xa0;
    /* 0x840950 */ mrs x23, tpidr_el0;
    /* 0x840954 */ mov x19, x0;
    /* 0x840958 */ ldr x8, [x23, #0x28];
    /* 0x84095c */ stur x8, [x29, #-8];
    sub_9edd98();
    /* 0x840964 */ adrp x8, #0x1090000;
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
