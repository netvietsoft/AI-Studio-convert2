// Library: libarkernel3.so
// Function ID: libarkernel3::0x79ece8
// Recovered Name: sub_79ece8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x79ece8 | Size: 1076 bytes | SHA256: 18b15439a109b0bc71c0468f0a408139114a31db776a153cd48696977aec3e94
// Callers: 0 | Callees: 17 | Imports: 4

// Calls external APIs: _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE, _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "blurOffsetMap+"
//   "gaussian"

void sub_79ece8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 269 instructions
    /* 0x79ece8 */ stp x29, x30, [sp, #0x20];
    /* 0x79ecec */ stp x28, x27, [sp, #0x30];
    /* 0x79ecf0 */ stp x26, x25, [sp, #0x40];
    /* 0x79ecf4 */ stp x24, x23, [sp, #0x50];
    /* 0x79ecf8 */ stp x22, x21, [sp, #0x60];
    /* 0x79ecfc */ stp x20, x19, [sp, #0x70];
    /* 0x79ed00 */ add x29, sp, #0x20;
    /* 0x79ed04 */ sub sp, sp, #0x2a0;
    /* 0x79ed08 */ mrs x8, tpidr_el0;
    /* 0x79ed0c */ mov x23, x1;
    /* 0x79ed10 */ mov x21, x0;
    sub_5604d4();
    _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE();
    sub_5604d4();
    sub_a7fc40();
    sub_5aa23c();
    sub_9fe4f4();
    sub_a00a24();
    sub_a00f28();
    sub_a012b4();
    sub_a01014();
    sub_a012ac();
    sub_a0126c();
    sub_a7fc40();
    sub_a82220();
    _Znwm();
    sub_a00d3c();
    sub_a0179c();
    _ZdlPv();
    sub_a00c0c();
    sub_9fe4f4();
    sub_a00a24();
    sub_a00f28();
    sub_a012b4();
    sub_a01014();
    sub_a012ac();
    sub_a0126c();
    sub_a7fc40();
    sub_a82220();
    _Znwm();
    sub_a00d3c();
    sub_a0179c();
    _ZdlPv();
    sub_a00c0c();
    sub_5ab304();
    _ZdlPv();
    _ZdlPv();
    return x0;
    sub_a00c0c();
    sub_5ab304();
    _ZdlPv();
    sub_562d14();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
