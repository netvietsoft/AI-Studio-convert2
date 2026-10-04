// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5e63f0
// Recovered Name: sub_5e63f0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5e63f0 | Size: 556 bytes | SHA256: 723ac4eccff6435a6ff2dadaf710a38740637155f7e4d649aec928c0b87a4465
// Callers: 0 | Callees: 9 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "res/depthMaterial/BlurTexture.fs"
//   "res/depthMaterial/CopyTexture.vs"

void sub_5e63f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 139 instructions
    /* 0x5e63f0 */ stp x29, x30, [sp, #0x60];
    /* 0x5e63f4 */ str x25, [sp, #0x70];
    /* 0x5e63f8 */ stp x24, x23, [sp, #0x80];
    /* 0x5e63fc */ stp x22, x21, [sp, #0x90];
    /* 0x5e6400 */ stp x20, x19, [sp, #0xa0];
    /* 0x5e6404 */ add x29, sp, #0x60;
    /* 0x5e6408 */ mrs x23, tpidr_el0;
    /* 0x5e640c */ mov x19, x0;
    /* 0x5e6410 */ ldr x8, [x23, #0x28];
    /* 0x5e6414 */ stur x8, [x29, #-8];
    /* 0x5e6418 */ ldr x0, [x0, #0x10];
    sub_d60368();
    sub_d622d8();
    sub_5a6eb4();
    sub_58f19c();
    sub_5abbf8();
    memmove();
    sub_5abbf8();
    memmove();
    sub_d5b06c();
    _ZdlPv();
    _ZdlPv();
    sub_d80ee8();
    sub_d82eb0();
    sub_d80ee8();
    sub_d82630();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
