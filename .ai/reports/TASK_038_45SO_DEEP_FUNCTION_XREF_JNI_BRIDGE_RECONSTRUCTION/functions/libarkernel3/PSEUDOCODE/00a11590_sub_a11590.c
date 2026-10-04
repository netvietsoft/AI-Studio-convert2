// Library: libarkernel3.so
// Function ID: libarkernel3::0xa11590
// Recovered Name: sub_a11590
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa11590 | Size: 1576 bytes | SHA256: e926c839ffe9899b230e40e041a16031b66b746832dfe009b457b2b4d5f3b2ae
// Callers: 0 | Callees: 25 | Imports: 6

// Calls external APIs: _ZN8mtlabar324ActiveWordColorInterfaceC2Ev, _ZN8mtlabar324ActiveWordStyleInterfaceC2Ev, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZdlPv, memset
// Strings referenced:
//   "BeginTimestamp"
//   "EnableFace"
//   "EndTimestamp"
//   "EndTimestampDisable"
//   "FacePart"

void sub_a11590(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 394 instructions
    /* 0xa11590 */ stp x29, x30, [sp, #0x10];
    /* 0xa11594 */ stp x28, x27, [sp, #0x20];
    /* 0xa11598 */ stp x26, x25, [sp, #0x30];
    /* 0xa1159c */ stp x24, x23, [sp, #0x40];
    /* 0xa115a0 */ stp x22, x21, [sp, #0x50];
    /* 0xa115a4 */ stp x20, x19, [sp, #0x60];
    /* 0xa115a8 */ add x29, sp, #0x10;
    /* 0xa115ac */ sub sp, sp, #0x620;
    /* 0xa115b0 */ mrs x25, tpidr_el0;
    /* 0xa115b4 */ mov w9, #0x3f800000;
    /* 0xa115b8 */ movi v1.2d, #0000000000000000;
    sub_5604d4();
    sub_915f14();
    sub_5cb688();
    memset();
    sub_5b7888();
    _ZN8mtlabar324ActiveWordColorInterfaceC2Ev();
    sub_cc62f4();
    _ZN8mtlabar324ActiveWordColorInterfaceC2Ev();
    sub_cc62f4();
    _ZN8mtlabar324ActiveWordStyleInterfaceC2Ev();
    sub_91cee8();
    sub_5c6858();
    sub_b6a570();
    sub_b67a48();
    sub_b6a500();
    sub_b69ef0();
    sub_b67a80();
    sub_b67904();
    sub_b67a80();
    sub_b6792c();
    sub_b6933c();
    sub_b69344();
    sub_b6933c();
    sub_b67f0c();
    sub_b69344();
    sub_b6933c();
    sub_b67f0c();
    sub_b69344();
    sub_b6933c();
    sub_b67f0c();
    sub_b69344();
    sub_b6933c();
    sub_b68184();
    sub_b69344();
    sub_b6933c();
    sub_b68364();
    _ZdlPv();
    sub_b69344();
    sub_b6933c();
    sub_b67a70();
    sub_b69ef0();
    sub_b67a80();
    sub_b6792c();
    sub_b6933c();
    sub_b69344();
    sub_b6933c();
    sub_b68364();
    _ZdlPv();
    sub_b6854c();
    sub_b68554();
    sub_b6772c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc();
    sub_b69344();
    sub_b6933c();
    sub_b68184();
    sub_b69344();
    sub_b6933c();
    sub_b67b58();
    sub_cccfe0();
}
