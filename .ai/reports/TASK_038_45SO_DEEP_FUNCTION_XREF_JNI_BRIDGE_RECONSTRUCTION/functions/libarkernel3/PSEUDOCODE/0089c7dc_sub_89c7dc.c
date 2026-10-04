// Library: libarkernel3.so
// Function ID: libarkernel3::0x89c7dc
// Recovered Name: sub_89c7dc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x89c7dc | Size: 1548 bytes | SHA256: 5db3f0dc0bd5775062d61aa6483853fdeeefa0fc2bff92f6ed8bf583d9887a06
// Callers: 0 | Callees: 27 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "BlendDarkColor"
//   "BlendIntensity"
//   "BlendLighterColor"
//   "BlendNormal"
//   "BlendSoftLight"

void sub_89c7dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 387 instructions
    /* 0x89c7dc */ stp x29, x30, [sp, #0xb0];
    /* 0x89c7e0 */ stp x28, x27, [sp, #0xc0];
    /* 0x89c7e4 */ stp x26, x25, [sp, #0xd0];
    /* 0x89c7e8 */ stp x24, x23, [sp, #0xe0];
    /* 0x89c7ec */ stp x22, x21, [sp, #0xf0];
    /* 0x89c7f0 */ stp x20, x19, [sp, #0x100];
    /* 0x89c7f4 */ add x29, sp, #0xb0;
    /* 0x89c7f8 */ mrs x21, tpidr_el0;
    /* 0x89c7fc */ mov x19, x0;
    /* 0x89c800 */ ldr x8, [x21, #0x28];
    /* 0x89c804 */ stur x8, [x29, #-0x10];
    sub_910d90();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5627bc();
    _ZdlPv();
    sub_90deac();
    sub_5644ac();
    sub_90e208();
    sub_90e0e8();
    sub_56445c();
    sub_ccc46c();
    sub_88c35c();
    sub_aa2a10();
    sub_aa18fc();
    sub_89cde8();
    sub_89ce7c();
    _Znwm();
    sub_90dd50();
    sub_89b318();
    _ZdlPv();
    sub_90dfe0();
    _Znwm();
    sub_89b420();
    sub_911200();
    sub_89b7b8();
    sub_89e7a4();
    _ZdlPv();
    sub_911200();
    sub_9ae938();
    sub_56ca10();
    return x0;
    sub_86e7f8();
    sub_89e790();
    sub_89b304();
    _ZdlPv();
    _ZdlPv();
    sub_56445c();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
