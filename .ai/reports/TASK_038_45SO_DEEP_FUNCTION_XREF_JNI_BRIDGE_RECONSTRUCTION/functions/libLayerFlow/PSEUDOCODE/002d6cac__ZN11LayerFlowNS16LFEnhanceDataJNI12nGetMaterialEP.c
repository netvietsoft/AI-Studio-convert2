// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6cac
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI12nGetMaterialEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6cac | Size: 168 bytes | SHA256: c6ee2a816ee8c0ea513f827d545810a40c161e70a1582b7dca535d0e23321e69
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetMaterial(J)Lcom/layer/flow/datas/LFEnhanceData$SkinWhiteningMaterial; (table at 0x535fa8)
// Calls external APIs: _Znwm
// Strings referenced:
//   "(JZ)V"
//   "<init>"
//   "com/layer/flow/datas/LFEnhanceData$SkinWhiteningMaterial"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI12nGetMaterialEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x2d6cac */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d6cb0 */ stp x22, x21, [sp, #0x10];
    /* 0x2d6cb4 */ stp x20, x19, [sp, #0x20];
    /* 0x2d6cb8 */ mov x29, sp;
    /* 0x2d6cbc */ ldr x8, [x0];
    /* 0x2d6cc0 */ adrp x1, #0x1e4000;
    /* 0x2d6cc4 */ add x1, x1, #0xa2d;
    /* 0x2d6cc8 */ mov x19, x0;
    /* 0x2d6ccc */ mov x20, x2;
    /* 0x2d6cd0 */ ldr x8, [x8, #0x30];
    /* 0x2d6cd4 */ blr x8;
    _Znwm();
    return x0;
}
