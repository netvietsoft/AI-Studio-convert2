// Library: libarkernel3.so
// Function ID: libarkernel3::0x87a62c
// Recovered Name: sub_87a62c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x87a62c | Size: 1908 bytes | SHA256: 91718568eb2bc87850e65ed3cd96c32e58399680a20b2bb1a506318a124926b0
// Callers: 0 | Callees: 30 | Imports: 7

// Calls external APIs: _ZN5image11DetailImageIhEC2Ejjj, _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE, _ZdaPv, _ZdlPv, _Znam, _Znwm, __stack_chk_fail
// Strings referenced:
//   "BeautyResource/LUT64.jpg"
//   "hair mask"

void sub_87a62c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 477 instructions
    /* 0x87a62c */ stp x29, x30, [sp, #0x30];
    /* 0x87a630 */ stp x28, x27, [sp, #0x40];
    /* 0x87a634 */ stp x26, x25, [sp, #0x50];
    /* 0x87a638 */ stp x24, x23, [sp, #0x60];
    /* 0x87a63c */ stp x22, x21, [sp, #0x70];
    /* 0x87a640 */ stp x20, x19, [sp, #0x80];
    /* 0x87a644 */ add x29, sp, #0x30;
    /* 0x87a648 */ sub sp, sp, #0x210;
    /* 0x87a64c */ mrs x8, tpidr_el0;
    /* 0x87a650 */ mov x22, x2;
    /* 0x87a654 */ mov x21, x1;
    sub_a434b4();
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a43064();
    sub_a576d8();
    sub_a59d1c();
    sub_a59d24();
    _ZN5image11DetailImageIhEC2Ejjj();
    sub_a59d1c();
    sub_a59d24();
    _ZN5image11DetailImageIhEC2Ejjj();
    sub_a435a8();
    _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE();
    sub_ccc19c();
    sub_ccc19c();
    sub_cccc48();
    sub_5600a4();
    _ZdlPv();
    _ZdlPv();
    sub_a7fc4c();
    sub_a7ecc4();
    sub_a59d1c();
    sub_a59d24();
    _ZN5image11DetailImageIhEC2Ejjj();
    sub_a59d24();
    sub_a59d1c();
    sub_a59d24();
    sub_a59d1c();
    _Znwm();
    _Znwm();
    sub_a7fc40();
    sub_a82f08();
    sub_6fcf78();
    sub_703a0c();
    sub_a59d1c();
    sub_a59d24();
    sub_a7fc58();
    sub_87c958();
    sub_d1a564();
    sub_d1a564();
    sub_a59d1c();
    sub_a59d24();
    _Znam();
    sub_d1a564();
    sub_a59d1c();
    sub_a59d24();
    sub_b9aa40();
    sub_d1a564();
    sub_d1a564();
    sub_d1a56c();
    sub_a59d1c();
    sub_a59d24();
    sub_d1a564();
    sub_d1a56c();
    sub_d1a56c();
    sub_d1a56c();
    sub_f64c20();
    sub_a7fc40();
    sub_a82f08();
    sub_6fcf78();
    sub_703a0c();
    sub_a59cac();
    sub_a59cdc();
    sub_a59d1c();
    sub_a59d24();
    sub_a7fc58();
    sub_87c958();
    sub_a59d2c();
    _ZdaPv();
    _ZdlPv();
    _ZdlPv();
    sub_d1a6fc();
    sub_cc02e0();
    _ZdlPv();
    sub_d1a6fc();
    sub_d1a6fc();
    return x0;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_d1a6fc();
    sub_cc02e0();
    _ZdlPv();
    sub_d1a6fc();
    sub_d1a6fc();
    sub_106b814();
    __stack_chk_fail();
}
