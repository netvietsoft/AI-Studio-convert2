// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x710550
// Recovered Name: sub_710550
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x710550 | Size: 1820 bytes | SHA256: 1e077c43b3b4c0681b572307dec507b7750ec53637ea5de9ea4f6b8ac5b12b7a
// Callers: 0 | Callees: 46 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "MODULATION"
//   "res/bloom/blend.frag"
//   "res/bloom/blend.vert"
//   "res/bloom/blur.frag"
//   "res/bloom/blur.vert"

void sub_710550(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 455 instructions
    /* 0x710550 */ stp x29, x30, [sp, #0x40];
    /* 0x710554 */ stp x28, x27, [sp, #0x50];
    /* 0x710558 */ stp x26, x25, [sp, #0x60];
    /* 0x71055c */ stp x24, x23, [sp, #0x70];
    /* 0x710560 */ stp x22, x21, [sp, #0x80];
    /* 0x710564 */ stp x20, x19, [sp, #0x90];
    /* 0x710568 */ add x29, sp, #0x40;
    /* 0x71056c */ sub sp, sp, #0x1f0;
    /* 0x710570 */ mrs x8, tpidr_el0;
    /* 0x710574 */ mov x19, x0;
    /* 0x710578 */ mov x22, x2;
    sub_dafd30();
    sub_dafd40();
    sub_dafd30();
    sub_dafd40();
    sub_d44604();
    sub_dafab4();
    sub_dafab4();
    sub_d5b06c();
    sub_d80558();
    sub_d5c57c();
    sub_d80558();
    sub_d5c57c();
    sub_d80558();
    sub_d5c57c();
    sub_d80558();
    sub_d5c57c();
    sub_d80558();
    sub_d5c57c();
    sub_d60368();
    sub_d60a14();
    sub_d622d8();
    sub_6e4604();
    sub_daca14();
    sub_6e63b4();
    sub_dacf40();
    sub_daca1c();
    sub_daca1c();
    sub_dad818();
    sub_daf5ec();
    sub_d80558();
    sub_dafaac();
    sub_d5c9bc();
    sub_d80558();
    sub_d5c710();
    sub_d62370();
    sub_dad818();
    sub_daf5ec();
    sub_d80558();
    sub_dafaac();
    sub_d5c9bc();
    sub_d80558();
    sub_d5c710();
    sub_d62370();
    sub_dad818();
    sub_daf5ec();
    sub_d80558();
    sub_dafaac();
    sub_d5c9bc();
    sub_d80558();
    sub_d5c710();
    sub_d62370();
    sub_dad818();
    sub_daf5ec();
    sub_d80558();
    sub_dafaac();
    sub_d5c9bc();
    sub_d80558();
    sub_d5c710();
    sub_d62370();
    sub_d5b06c();
    sub_d80ee8();
    sub_d82630();
    sub_d80ee8();
    sub_d83910();
    sub_d80ee8();
    sub_d8394c();
    sub_dacfa8();
    sub_dacfa8();
    sub_6e4aac();
    sub_6ef09c();
    sub_6efda8();
    sub_d5dbe8();
    sub_d5f204();
    sub_d5dbe8();
    sub_d5f204();
    sub_d5dbfc();
    sub_daf584();
    sub_d80558();
    sub_d5c944();
    sub_d80558();
    sub_dafaac();
    sub_d5c9bc();
    sub_d80558();
    sub_dafaac();
    sub_d5c9bc();
    sub_d80558();
    sub_d5c7c8();
    sub_d80558();
    sub_d5c7c8();
    sub_d80558();
    sub_d5c57c();
    sub_d80558();
    sub_d5c88c();
    sub_db0624();
    sub_d614b4();
    sub_d613c4();
    sub_d613b4();
    sub_d613f4();
    sub_d613ec();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d5dbfc();
    sub_d5dbfc();
    sub_d5dbfc();
    sub_d5dbfc();
    sub_dad0a0();
    sub_dad0a0();
    sub_daca8c();
    sub_daca8c();
    sub_daca8c();
    sub_daf430();
    sub_daf430();
    return x0;
    __stack_chk_fail();
}
