// Library: libarkernel3.so
// Function ID: libarkernel3::0xb2f8c0
// Recovered Name: sub_b2f8c0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb2f8c0 | Size: 716 bytes | SHA256: 0fc566190366c9e195ffa12ace3365b358d08a7c6faf650d52bd041ff0d8188a
// Callers: 0 | Callees: 9 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "Blur"
//   "BoldWidth"
//   "Editable"
//   "Enable"
//   "ORGBA"

void sub_b2f8c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 179 instructions
    /* 0xb2f8c0 */ stp x29, x30, [sp, #0x50];
    /* 0xb2f8c4 */ stp x22, x21, [sp, #0x60];
    /* 0xb2f8c8 */ stp x20, x19, [sp, #0x70];
    /* 0xb2f8cc */ add x29, sp, #0x50;
    /* 0xb2f8d0 */ mrs x22, tpidr_el0;
    /* 0xb2f8d4 */ mov x19, x1;
    /* 0xb2f8d8 */ mov x21, x0;
    /* 0xb2f8dc */ ldr x8, [x22, #0x28];
    /* 0xb2f8e0 */ stur x8, [x29, #-8];
    sub_b6792c();
    sub_b6933c();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b6792c();
    sub_b6933c();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b68184();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b68184();
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
    sub_592d48();
    _ZdlPv();
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
    return x0;
    __stack_chk_fail();
}
