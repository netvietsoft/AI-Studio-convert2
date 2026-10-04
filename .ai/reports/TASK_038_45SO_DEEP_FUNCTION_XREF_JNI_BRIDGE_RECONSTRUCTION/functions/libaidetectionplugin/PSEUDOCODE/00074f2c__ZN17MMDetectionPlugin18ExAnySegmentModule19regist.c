// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x74f2c
// Recovered Name: _ZN17MMDetectionPlugin18ExAnySegmentModule19registerExtraModuleEPKNS_21_ExtraDetectionOptionENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEER24vlai_graphics_env_handlePv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x74f2c | Size: 112 bytes | SHA256: 7af0350ba3f04e96f04b57b41eb729a1d16b48aa1e0b4d3977c23a02090185a5
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: vlai_segment_any_create_handle, vlai_segment_any_init

void _ZN17MMDetectionPlugin18ExAnySegmentModule19registerExtraModuleEPKNS_21_ExtraDetectionOptionENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEER24vlai_graphics_env_handlePv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 28 instructions
    /* 0x74f2c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x74f30 */ str x21, [sp, #0x10];
    /* 0x74f34 */ stp x20, x19, [sp, #0x20];
    /* 0x74f38 */ mov x29, sp;
    /* 0x74f3c */ cbz x1, #0x74f50;
    /* 0x74f40 */ ldrb w8, [x1, #1];
    /* 0x74f44 */ tbz w8, #3, #0x74f50;
    /* 0x74f48 */ ldr x8, [x0, #0x28];
    /* 0x74f4c */ cbz x8, #0x74f60;
    /* 0x74f50 */ ldp x20, x19, [sp, #0x20];
    /* 0x74f54 */ ldr x21, [sp, #0x10];
    return x0;
    vlai_segment_any_create_handle();
}
