// Library: libmanis_npu_adapter.so
// Function ID: libmanis_npu_adapter::0x71fe0
// Recovered Name: sub_71fe0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x71fe0 | Size: 204 bytes | SHA256: 612f31792e96629be58db7e5f068fcabf0879d78f82c2a4598c17d170ef59f96
// Callers: 0 | Callees: 1 | Imports: 5

// Calls external APIs: _ZN2ge8Operator7SetAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEONS_9AttrValueE, _ZN2ge9AttrValue10CreateFromEb, _ZN2ge9AttrValueD1Ev, _ZdlPv, __stack_chk_fail

void sub_71fe0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x71fe0 */ stp x29, x30, [sp, #0x40];
    /* 0x71fe4 */ stp x20, x19, [sp, #0x50];
    /* 0x71fe8 */ add x29, sp, #0x40;
    /* 0x71fec */ mrs x20, tpidr_el0;
    /* 0x71ff0 */ mov x19, x0;
    /* 0x71ff4 */ mov w0, w1;
    /* 0x71ff8 */ ldr x8, [x20, #0x28];
    /* 0x71ffc */ stur x8, [x29, #-8];
    /* 0x72000 */ add x8, sp, #0x18;
    _ZN2ge9AttrValue10CreateFromEb();
    /* 0x72008 */ nop ;
    _ZN2ge8Operator7SetAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEONS_9AttrValueE();
    _ZdlPv();
    _ZN2ge9AttrValueD1Ev();
    return x0;
    _ZdlPv();
    _ZN2ge9AttrValueD1Ev();
    sub_eb464();
    __stack_chk_fail();
}
