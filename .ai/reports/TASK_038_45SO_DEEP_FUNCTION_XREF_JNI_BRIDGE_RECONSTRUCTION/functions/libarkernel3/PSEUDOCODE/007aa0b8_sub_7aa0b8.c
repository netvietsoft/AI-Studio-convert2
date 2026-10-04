// Library: libarkernel3.so
// Function ID: libarkernel3::0x7aa0b8
// Recovered Name: sub_7aa0b8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7aa0b8 | Size: 3036 bytes | SHA256: 26dcc95baaf520d86e6442cdcde3aa00d22ddaf3ca6054bd35cb439f0dd3270e
// Callers: 0 | Callees: 12 | Imports: 3

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "None"
//   "kFaceliftControl_FaceForehead"
//   "kFaceliftControl_FluffyHair"
//   "kFaceliftControl_Hairline"
//   "kFaceliftControl_RoundHead"

void sub_7aa0b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 759 instructions
    /* 0x7aa0b8 */ stp x29, x30, [sp, #0xb0];
    /* 0x7aa0bc */ stp x22, x21, [sp, #0xc0];
    /* 0x7aa0c0 */ stp x20, x19, [sp, #0xd0];
    /* 0x7aa0c4 */ add x29, sp, #0xb0;
    /* 0x7aa0c8 */ mrs x20, tpidr_el0;
    /* 0x7aa0cc */ mov x19, x0;
    /* 0x7aa0d0 */ ldr x8, [x20, #0x28];
    /* 0x7aa0d4 */ stur x8, [x29, #-0x18];
    /* 0x7aa0d8 */ ldrb w8, [x0, #0x518];
    /* 0x7aa0dc */ ldr x9, [x0, #0x520];
    /* 0x7aa0e0 */ lsr x10, x8, #1;
    sub_667230();
    sub_5938d4();
    _ZdlPv();
    sub_7aac94();
    sub_73f468();
    _ZdlPv();
    sub_7aac94();
    sub_73f468();
    _ZdlPv();
    sub_7aac94();
    sub_73f468();
    _ZdlPv();
    sub_594074();
    sub_594438();
    _ZdlPv();
    sub_667230();
    sub_5938d4();
    _ZdlPv();
    sub_7aac94();
    sub_73f468();
    _ZdlPv();
    sub_7aac94();
    sub_73f468();
    _ZdlPv();
    sub_594074();
    sub_5604d4();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_5a704c();
    sub_705d4c();
    sub_7b25d0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5604d4();
    sub_594074();
    sub_594438();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_5a704c();
    sub_705d4c();
    sub_7b25d0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5604d4();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_5a704c();
    sub_705d4c();
    sub_7b25d0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_7aac94();
    sub_73f468();
    _ZdlPv();
    sub_7aac94();
    sub_73f468();
    _ZdlPv();
    sub_594074();
    sub_594438();
    _ZdlPv();
    sub_7aac94();
    sub_73f468();
    _ZdlPv();
    sub_594074();
    sub_594438();
    _ZdlPv();
    sub_594074();
    sub_594438();
    _ZdlPv();
    return x0;
    _ZdlPv();
    sub_7aaec0();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
