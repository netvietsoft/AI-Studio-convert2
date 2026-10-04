// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x7175fc
// Recovered Name: sub_7175fc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7175fc | Size: 932 bytes | SHA256: 19a494ad50940cb9d86876564c570b9e70b3adca2afc0323d10bf44c4d3c88b7
// Callers: 0 | Callees: 30 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "res/bodymovin/blur.fs"
//   "res/bodymovin/blur.vs"
//   "tmp"
//   "u_pixelSize"
//   "u_srcTexture"

void sub_7175fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 233 instructions
    /* 0x7175fc */ stp x29, x30, [sp, #0xb0];
    /* 0x717600 */ stp x28, x27, [sp, #0xc0];
    /* 0x717604 */ stp x26, x25, [sp, #0xd0];
    /* 0x717608 */ stp x24, x23, [sp, #0xe0];
    /* 0x71760c */ stp x22, x21, [sp, #0xf0];
    /* 0x717610 */ stp x20, x19, [sp, #0x100];
    /* 0x717614 */ add x29, sp, #0xb0;
    /* 0x717618 */ mrs x8, tpidr_el0;
    /* 0x71761c */ mov x22, x0;
    /* 0x717620 */ mov x0, x1;
    /* 0x717624 */ str x8, [sp, #8];
    sub_d421d0();
    sub_d421f4();
    sub_d41edc();
    sub_d5b06c();
    sub_d80ee8();
    sub_d82eb0();
    sub_d80ee8();
    sub_d82630();
    sub_daf19c();
    sub_daf19c();
    sub_daf008();
    sub_d600a0();
    sub_daf150();
    sub_d60a14();
    sub_d602b0();
    sub_d622d8();
    sub_d44604();
    sub_d42610();
    sub_d7fb90();
    sub_d45160();
    sub_d7fbb4();
    sub_d457d8();
    sub_d424a8();
    sub_d84cf4();
    sub_da2ed4();
    sub_d80558();
    sub_d5c9bc();
    sub_d80558();
    sub_daca1c();
    sub_d5c710();
    sub_daca8c();
    sub_d62370();
    sub_d42610();
    sub_d7fb90();
    sub_d45160();
    sub_d7fbb4();
    sub_d457d8();
    sub_d424a8();
    sub_d84cf4();
    sub_da2ed4();
    sub_d80558();
    sub_d5c9bc();
    sub_d80558();
    sub_daca1c();
    sub_d5c710();
    sub_daca8c();
    sub_d62370();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d7ffbc();
    return x0;
    __stack_chk_fail();
}
