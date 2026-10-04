// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x6ed50
// Recovered Name: _ZN17MMDetectionPlugin17ExDenseHairModuleD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x6ed50 | Size: 124 bytes | SHA256: dec6c3a7914a29ed8c1ac26293e97b04b5d9ad60e1e2f3e70921ca47bfe49d94
// Callers: 0 | Callees: 1 | Imports: 4

// Calls external APIs: _ZdlPv, vlai_require_set_destroy, vlai_run_result_destroy, vlai_setting_patch_destroy

void _ZN17MMDetectionPlugin17ExDenseHairModuleD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0x6ed50 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x6ed54 */ str x19, [sp, #0x10];
    /* 0x6ed58 */ mov x29, sp;
    /* 0x6ed5c */ adrp x8, #0x83000;
    /* 0x6ed60 */ mov x19, x0;
    /* 0x6ed64 */ ldr x8, [x8, #0x20];
    /* 0x6ed68 */ ldr x0, [x0, #0x38];
    /* 0x6ed6c */ add x8, x8, #0x10;
    /* 0x6ed70 */ str x8, [x19];
    /* 0x6ed74 */ cbz x0, #0x6ed7c;
    vlai_setting_patch_destroy();
    vlai_require_set_destroy();
    vlai_run_result_destroy();
    _ZdlPv();
    return x0;
    sub_3f3a4();
}
