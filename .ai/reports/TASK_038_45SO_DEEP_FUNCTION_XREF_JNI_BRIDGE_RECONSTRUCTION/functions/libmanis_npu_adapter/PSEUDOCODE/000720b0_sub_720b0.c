// Library: libmanis_npu_adapter.so
// Function ID: libmanis_npu_adapter::0x720b0
// Recovered Name: sub_720b0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x720b0 | Size: 204 bytes | SHA256: a4dcd3a7a3c9887fc4988d1b3d59e5b3ce5034d7ba1ffd1711aae31df118fdcc
// Callers: 0 | Callees: 1 | Imports: 5

// Calls external APIs: _ZN2ge8Operator7SetAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEONS_9AttrValueE, _ZN2ge9AttrValue10CreateFromEl, _ZN2ge9AttrValueD1Ev, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "src_dtype"

void sub_720b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x720b0 */ stp x29, x30, [sp, #0x40];
    /* 0x720b4 */ stp x20, x19, [sp, #0x50];
    /* 0x720b8 */ add x29, sp, #0x40;
    /* 0x720bc */ mrs x20, tpidr_el0;
    /* 0x720c0 */ mov x19, x0;
    /* 0x720c4 */ mov x0, x1;
    /* 0x720c8 */ ldr x8, [x20, #0x28];
    /* 0x720cc */ stur x8, [x29, #-8];
    /* 0x720d0 */ add x8, sp, #0x18;
    _ZN2ge9AttrValue10CreateFromEl();
    /* 0x720d8 */ adrp x9, #0x55000;
    _ZN2ge8Operator7SetAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEONS_9AttrValueE();
    _ZdlPv();
    _ZN2ge9AttrValueD1Ev();
    return x0;
    _ZdlPv();
    _ZN2ge9AttrValueD1Ev();
    sub_eb464();
    __stack_chk_fail();
}
