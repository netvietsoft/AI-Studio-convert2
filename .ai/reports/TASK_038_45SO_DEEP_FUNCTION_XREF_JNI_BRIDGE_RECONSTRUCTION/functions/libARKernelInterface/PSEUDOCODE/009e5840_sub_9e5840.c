// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x9e5840
// Recovered Name: sub_9e5840
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9e5840 | Size: 7336 bytes | SHA256: a3d05989a439156a3643ab497a40cf3e329403b44fbaa68e71241fd16fa63db5
// Callers: 0 | Callees: 30 | Imports: 5

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _ZdlPv, __stack_chk_fail, memcmp, sscanf
// Strings referenced:
//   "%f,%f,%f,%f"
//   "AfterCircle"
//   "AfterCircleColorList"
//   "AfterCircleRangeList"
//   "AfterOnce"

void sub_9e5840(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 1834 instructions
    /* 0x9e5840 */ stp x29, x30, [sp, #0x20];
    /* 0x9e5844 */ stp x28, x27, [sp, #0x30];
    /* 0x9e5848 */ stp x26, x25, [sp, #0x40];
    /* 0x9e584c */ stp x24, x23, [sp, #0x50];
    /* 0x9e5850 */ stp x22, x21, [sp, #0x60];
    /* 0x9e5854 */ stp x20, x19, [sp, #0x70];
    /* 0x9e5858 */ add x29, sp, #0x20;
    /* 0x9e585c */ sub sp, sp, #0x2d0;
    /* 0x9e5860 */ mrs x21, tpidr_el0;
    /* 0x9e5864 */ mov x19, x1;
    /* 0x9e5868 */ mov x23, x0;
    sub_61bfa0();
    sub_5a8d04();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_5a8d1c();
    sub_5cb124();
    sub_63c850();
    _ZdlPv();
    _ZdlPv();
    sub_9e74e8();
    _ZdlPv();
    _ZdlPv();
    sub_9e85ec();
    sub_9e8308();
    sub_5a8d04();
    sub_9e7640();
    sub_5a8da0();
    sub_5a8d0c();
    sub_58f19c();
    sscanf();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5b7fa8();
    sub_9e898c();
    _ZdlPv();
    _ZdlPv();
    sub_5b7fa8();
    sub_9e898c();
    _ZdlPv();
    _ZdlPv();
    sub_5b7fa8();
    sub_9e898c();
    _ZdlPv();
    _ZdlPv();
    sub_5b7fa8();
    sub_9e898c();
    _ZdlPv();
    _ZdlPv();
    sub_5cb124();
    sub_9e89e4();
    _ZdlPv();
    _ZdlPv();
    sub_5cb124();
    sub_9e89e4();
    _ZdlPv();
    _ZdlPv();
    sub_5cb124();
    sub_9e89e4();
    _ZdlPv();
    _ZdlPv();
    sub_5cb124();
    sub_9e89e4();
    _ZdlPv();
    _ZdlPv();
    sub_5a8d04();
    sub_5a8d0c();
    sub_58f19c();
    sub_58f19c();
    memcmp();
    _ZdlPv();
    sub_58f19c();
    memcmp();
    _ZdlPv();
    sub_58f19c();
    memcmp();
    _ZdlPv();
    sub_58f19c();
    memcmp();
    _ZdlPv();
    _ZdlPv();
    sub_5a8d1c();
    sub_5b7fa8();
    _ZdlPv();
    sub_68c984();
    sub_5a8f24();
    _ZdlPv();
    sub_68c9bc();
    sub_9e7798();
    sub_9e78d8();
    sub_9e9110();
    sub_9e8298();
    return x0;
    sub_9e8964();
    sub_9e8400();
    sub_9e8400();
    sub_63c83c();
    sub_9e8978();
    sub_9e8978();
    sub_9e8978();
    sub_9e89d0();
    sub_9e8978();
    sub_9e89d0();
    sub_9e89d0();
    sub_9e89d0();
    __stack_chk_fail();
}
