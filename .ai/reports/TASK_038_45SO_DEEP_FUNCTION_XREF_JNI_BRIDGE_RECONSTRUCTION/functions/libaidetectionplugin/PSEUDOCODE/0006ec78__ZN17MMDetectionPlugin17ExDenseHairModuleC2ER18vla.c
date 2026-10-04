// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x6ec78
// Recovered Name: _ZN17MMDetectionPlugin17ExDenseHairModuleC2ER18vlai_engine_handleR26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x6ec78 | Size: 216 bytes | SHA256: ee1fdc80d83335a115c6f3b935a527ec20592fe1db73995d954316304910a6a6
// Callers: 0 | Callees: 1 | Imports: 5

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZdlPv, vlai_require_set_create, vlai_run_result_create, vlai_setting_patch_create

void _ZN17MMDetectionPlugin17ExDenseHairModuleC2ER18vlai_engine_handleR26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 54 instructions
    /* 0x6ec78 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x6ec7c */ stp x22, x21, [sp, #0x10];
    /* 0x6ec80 */ stp x20, x19, [sp, #0x20];
    /* 0x6ec84 */ mov x29, sp;
    /* 0x6ec88 */ adrp x8, #0x83000;
    /* 0x6ec8c */ mov x20, x0;
    /* 0x6ec90 */ mov x22, x0;
    /* 0x6ec94 */ ldr x8, [x8, #0x20];
    /* 0x6ec98 */ strh wzr, [x20, #8]!;
    /* 0x6ec9c */ str xzr, [x22, #0x50]!;
    /* 0x6eca0 */ mov x19, x0;
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    vlai_setting_patch_create();
    vlai_require_set_create();
    vlai_run_result_create();
    return x0;
    sub_75c14();
    _ZdlPv();
    _ZdlPv();
    sub_75c14();
}
