// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x45b328
// Recovered Name: _ZN11LayerFlowNS21LFFormulaRenderPlugin22notifyBlurResourceDataElNS_18LFBlurResourceDataE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x45b328 | Size: 500 bytes | SHA256: 3a2d7471f3640b4b7652fc056dc3ab6b96ad1dabd3167fc4738f1aab60909a07
// Callers: 1 | Callees: 2 | Imports: 5

// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _Znwm, __dynamic_cast
// Strings referenced:
//   "iklf"
//   "notifyBlurResourceData"
//   "renderPluginOH<%s:%d> shopId == 0 or shopErrorCode set %d, unable to notify"

void _ZN11LayerFlowNS21LFFormulaRenderPlugin22notifyBlurResourceDataElNS_18LFBlurResourceDataE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 125 instructions
    /* 0x45b328 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x45b32c */ str x25, [sp, #0x10];
    /* 0x45b330 */ stp x24, x23, [sp, #0x20];
    /* 0x45b334 */ stp x22, x21, [sp, #0x30];
    /* 0x45b338 */ stp x20, x19, [sp, #0x40];
    /* 0x45b33c */ mov x29, sp;
    /* 0x45b340 */ mov x20, x0;
    /* 0x45b344 */ ldr x0, [x0, #8];
    /* 0x45b348 */ mov x21, x2;
    /* 0x45b34c */ mov x19, x1;
    /* 0x45b350 */ cbz x0, #0x45b3bc;
    __dynamic_cast();
    sub_5263b0();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _Znwm();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    sub_5263b0();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
}
