// Library: libarkernel3.so
// Function ID: libarkernel3::0xb30970
// Recovered Name: sub_b30970
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb30970 | Size: 1348 bytes | SHA256: 25ce8ce80a5bf8236331bfbeedde19b94a511e22ad79454c98857f9bdfa5cb29
// Callers: 0 | Callees: 20 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "Blur"
//   "ColorCollection"
//   "Enable"
//   "GlowConfig"
//   "GlowInAlpha"

void sub_b30970(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 337 instructions
    /* 0xb30970 */ stp x29, x30, [sp, #0x60];
    /* 0xb30974 */ str x25, [sp, #0x70];
    /* 0xb30978 */ stp x24, x23, [sp, #0x80];
    /* 0xb3097c */ stp x22, x21, [sp, #0x90];
    /* 0xb30980 */ stp x20, x19, [sp, #0xa0];
    /* 0xb30984 */ add x29, sp, #0x60;
    /* 0xb30988 */ mrs x24, tpidr_el0;
    /* 0xb3098c */ mov x19, x1;
    /* 0xb30990 */ mov x21, x0;
    /* 0xb30994 */ ldr x8, [x24, #0x28];
    /* 0xb30998 */ stur x8, [x29, #-8];
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
    sub_b67a70();
    sub_cc6028();
    sub_b69ef0();
    sub_b67a80();
    sub_b67b48();
    sub_594074();
    sub_cc6288();
    sub_b093ec();
    sub_cc6028();
    _ZdlPv();
    sub_b69ef0();
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
    sub_592d48();
    _ZdlPv();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b67b58();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b67b58();
    sub_b6792c();
    sub_b69344();
    sub_b6792c();
    sub_b6933c();
    sub_b68364();
    sub_ccc064();
    _ZdlPv();
    _ZdlPv();
    return x0;
    sub_cc6028();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
