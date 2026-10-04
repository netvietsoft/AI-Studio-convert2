// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x74e50
// Recovered Name: _ZN17MMDetectionPlugin18ExAnySegmentModuleC2ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x74e50 | Size: 96 bytes | SHA256: 7419b0e5265363cab0d7c8e753b5b7fb2a684fe353706587f7bbc979edc3023c
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZdlPv

void _ZN17MMDetectionPlugin18ExAnySegmentModuleC2ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 24 instructions
    /* 0x74e50 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x74e54 */ stp x20, x19, [sp, #0x10];
    /* 0x74e58 */ mov x29, sp;
    /* 0x74e5c */ adrp x8, #0x83000;
    /* 0x74e60 */ mov x19, x0;
    /* 0x74e64 */ mov x20, x0;
    /* 0x74e68 */ ldr x8, [x8, #0x90];
    /* 0x74e6c */ strb wzr, [x0, #0x20];
    /* 0x74e70 */ strh wzr, [x20, #8]!;
    /* 0x74e74 */ add x8, x8, #0x10;
    /* 0x74e78 */ stp xzr, xzr, [x0, #0x28];
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    return x0;
    _ZdlPv();
    sub_75c14();
}
