// Library: libarkernel3.so
// Function ID: libarkernel3::0xb31b88
// Recovered Name: sub_b31b88
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb31b88 | Size: 776 bytes | SHA256: e9054883fd459652446f8f8753f1b5e43f79ebdb52aa1b3b207a79b82cbdbcd9
// Callers: 0 | Callees: 11 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "Blur"
//   "BoldWidth"
//   "GaussianGlowConfig"
//   "GlowExtend"
//   "GlowIntensity"

void sub_b31b88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 194 instructions
    /* 0xb31b88 */ stp x29, x30, [sp, #0x50];
    /* 0xb31b8c */ stp x22, x21, [sp, #0x60];
    /* 0xb31b90 */ stp x20, x19, [sp, #0x70];
    /* 0xb31b94 */ add x29, sp, #0x50;
    /* 0xb31b98 */ mrs x22, tpidr_el0;
    /* 0xb31b9c */ mov x19, x1;
    /* 0xb31ba0 */ mov x21, x0;
    /* 0xb31ba4 */ ldr x8, [x22, #0x28];
    /* 0xb31ba8 */ stur x8, [x29, #-8];
    sub_b6792c();
    sub_b6933c();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b6792c();
    sub_b6933c();
    sub_b340a4();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_592d48();
    sub_cc6288();
    sub_cc6374();
    sub_cc6028();
    _ZdlPv();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b68184();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b67f0c();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b67f0c();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b67f0c();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b67f0c();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b67b58();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_592d48();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
