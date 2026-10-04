// Library: libfantasy.so
// Function ID: libfantasy::0xba4a4
// Recovered Name: sub_ba4a4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xba4a4 | Size: 356 bytes | SHA256: 3c8c11e7be67b46a801b1584bc82abad639cb2d13e0e36aa4f3b80bc883c597c
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _Znwm, __stack_chk_fail
// Strings referenced:
//   "/home/meitu/apollo-ws/fantasy/native/Adapter.cpp"
//   "ValidateDeviceDescriptor"
//   "requiredLimits.maxColorAttachmentBytesPerSample (%u) must be less than or equal to the adapter limit (%u)."

void sub_ba4a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 89 instructions
    /* 0xba4a4 */ stp x29, x30, [sp, #0x20];
    /* 0xba4a8 */ str x23, [sp, #0x30];
    /* 0xba4ac */ stp x22, x21, [sp, #0x40];
    /* 0xba4b0 */ stp x20, x19, [sp, #0x50];
    /* 0xba4b4 */ add x29, sp, #0x20;
    /* 0xba4b8 */ mrs x22, tpidr_el0;
    /* 0xba4bc */ mov x21, x1;
    /* 0xba4c0 */ mov x20, x0;
    /* 0xba4c4 */ ldr x9, [x22, #0x28];
    /* 0xba4c8 */ mov x19, x8;
    /* 0xba4cc */ stur x9, [x29, #-8];
    sub_bb61c();
    return x0;
    sub_ba608();
    _Znwm();
    sub_ba608();
    _Znwm();
    __stack_chk_fail();
}
