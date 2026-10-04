// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3eae74
// Recovered Name: _ZN11LayerFlowNS16CLFBlurProcessor10applyLayerEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3eae74 | Size: 324 bytes | SHA256: 092587bb9f0d342152283c149dcde51e0662de634e8ce790c510f08946ebbe1f
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, __dynamic_cast
// Strings referenced:
//   "CLFBlurProcessor<%s:%d> layer is nullptr, return false."
//   "CLFBlurProcessor<%s:%d> mtikManager is nullptr, return false."
//   "applyLayer"
//   "formulaRenderPlugin"
//   "iklf"

void _ZN11LayerFlowNS16CLFBlurProcessor10applyLayerEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 81 instructions
    /* 0x3eae74 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x3eae78 */ stp x28, x27, [sp, #0x10];
    /* 0x3eae7c */ stp x26, x25, [sp, #0x20];
    /* 0x3eae80 */ stp x24, x23, [sp, #0x30];
    /* 0x3eae84 */ stp x22, x21, [sp, #0x40];
    /* 0x3eae88 */ stp x20, x19, [sp, #0x50];
    /* 0x3eae8c */ mov x29, sp;
    /* 0x3eae90 */ sub sp, sp, #0x1e0;
    /* 0x3eae94 */ mrs x24, tpidr_el0;
    /* 0x3eae98 */ mov x19, x0;
    /* 0x3eae9c */ ldr x8, [x24, #0x28];
    __dynamic_cast();
    sub_5263b0();
    _ZNK11LayerFlowNS14CLFFormulaShop10findPluginENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    __dynamic_cast();
    sub_5263b0();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
}
