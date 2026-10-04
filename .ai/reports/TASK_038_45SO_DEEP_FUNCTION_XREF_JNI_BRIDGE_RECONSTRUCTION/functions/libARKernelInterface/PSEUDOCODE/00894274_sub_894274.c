// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x894274
// Recovered Name: sub_894274
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x894274 | Size: 368 bytes | SHA256: 2a1369e0f4846f02b8e363cca3691e317f7db391eb28fbb6815a264cec6785fd
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, __android_log_print, __stack_chk_fail
// Strings referenced:
//   "LoadHairMask:%s"
//   "arkernel"
//   "pHairMaskTexture == nullptr:"

void sub_894274(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 92 instructions
    /* 0x894274 */ stp x29, x30, [sp, #0x20];
    /* 0x894278 */ str x23, [sp, #0x30];
    /* 0x89427c */ stp x22, x21, [sp, #0x40];
    /* 0x894280 */ stp x20, x19, [sp, #0x50];
    /* 0x894284 */ add x29, sp, #0x20;
    /* 0x894288 */ mrs x23, tpidr_el0;
    /* 0x89428c */ adrp x22, #0x10c5000;
    /* 0x894290 */ mov x20, x1;
    /* 0x894294 */ ldr x8, [x23, #0x28];
    /* 0x894298 */ ldr x22, [x22, #0x7a8];
    /* 0x89429c */ mov x19, x0;
    sub_5a6b20();
    __android_log_print();
    sub_c38b3c();
    sub_58f19c();
    _ZdlPv();
    sub_c41788();
    sub_5a6b20();
    __android_log_print();
    return x0;
    __stack_chk_fail();
}
