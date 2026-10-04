// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x63c634
// Recovered Name: sub_63c634
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x63c634 | Size: 456 bytes | SHA256: eee3598a0e8f534e8722afb6dfacee74636c8a9c3afd6b006dc33826e78f8269
// Callers: 0 | Callees: 3 | Imports: 3

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   ",needSegmentMask:"
//   "needSegmentMask:"
//   "opacity:%.2f,RGBA:(%.2f,%.2f,%.2f,%.2f)"

void sub_63c634(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 114 instructions
    /* 0x63c634 */ stp x29, x30, [sp, #0x140];
    /* 0x63c638 */ str x28, [sp, #0x150];
    /* 0x63c63c */ stp x22, x21, [sp, #0x160];
    /* 0x63c640 */ stp x20, x19, [sp, #0x170];
    /* 0x63c644 */ add x29, sp, #0x140;
    /* 0x63c648 */ mrs x21, tpidr_el0;
    /* 0x63c64c */ mov x19, x8;
    /* 0x63c650 */ mov x20, x0;
    /* 0x63c654 */ ldr x8, [x21, #0x28];
    /* 0x63c658 */ stur x8, [x29, #-8];
    /* 0x63c65c */ ldr x8, [x0, #0xd10];
    sub_630c04();
    sub_58f19c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    sub_58f19c();
    sub_620acc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
    return x0;
}
