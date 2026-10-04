// Library: libmanis_npu_adapter.so
// Function ID: libmanis_npu_adapter::0x71e30
// Recovered Name: sub_71e30
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x71e30 | Size: 348 bytes | SHA256: 38a4e9628897135284fecee3103f3020bc67083d09b92ce9c297f4ed5a475f17
// Callers: 0 | Callees: 1 | Imports: 9

// Calls external APIs: _ZN2ge5ShapeC1ENSt6__ndk16vectorIlNS1_9allocatorIlEEEE, _ZN2ge5ShapeC1ERKS0_, _ZN2ge5ShapeC1Ev, _ZN2ge5ShapeD1Ev, _ZN2ge5ShapeaSERKS0_, _ZN5mizar8NpuUtils12SetAttrValueERNSt6__ndk110shared_ptrIN4hiai2op5ConstEEEN2ge5ShapeEPKhmNS8_6FormatENS8_8DataTypeE, _ZdlPv, _Znwm, __stack_chk_fail

void sub_71e30(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 87 instructions
    /* 0x71e30 */ stp x29, x30, [sp, #0x50];
    /* 0x71e34 */ stp x26, x25, [sp, #0x60];
    /* 0x71e38 */ stp x24, x23, [sp, #0x70];
    /* 0x71e3c */ stp x22, x21, [sp, #0x80];
    /* 0x71e40 */ stp x20, x19, [sp, #0x90];
    /* 0x71e44 */ add x29, sp, #0x50;
    /* 0x71e48 */ mrs x24, tpidr_el0;
    /* 0x71e4c */ mov x21, x0;
    /* 0x71e50 */ mov w0, #8;
    /* 0x71e54 */ ldr x8, [x24, #0x28];
    /* 0x71e58 */ mov w23, w4;
    _Znwm();
    _ZN2ge5ShapeC1ENSt6__ndk16vectorIlNS1_9allocatorIlEEEE();
    _ZdlPv();
    _ZN2ge5ShapeC1Ev();
    _ZN2ge5ShapeaSERKS0_();
    _ZN2ge5ShapeD1Ev();
    _ZN2ge5ShapeC1ERKS0_();
    _ZN5mizar8NpuUtils12SetAttrValueERNSt6__ndk110shared_ptrIN4hiai2op5ConstEEEN2ge5ShapeEPKhmNS8_6FormatENS8_8DataTypeE();
    _ZN2ge5ShapeD1Ev();
    _ZN2ge5ShapeD1Ev();
    return x0;
    _ZN2ge5ShapeD1Ev();
    _ZN2ge5ShapeD1Ev();
    sub_eb464();
    __stack_chk_fail();
    _ZdlPv();
}
