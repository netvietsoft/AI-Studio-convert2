// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cb978
// Recovered Name: _ZN11LayerFlowNS24LFEffectDenseHairDataJNI18registerJniMethodsEP7_JNIEnv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x2cb978 | Size: 312 bytes | SHA256: da23dabc3ef46a2084879911d02b7a1db983297533c195ca4e103ec3807f2752
// Callers: 1 | Callees: 0 | Imports: 2

// Calls external APIs: __stack_chk_fail, memcpy
// Strings referenced:
//   "com/layer/flow/datas/LFEffectDenseHairData$DenseHairInfo"
//   "com/layer/flow/datas/LFEffectDenseHairData$DenseHairModular"

void _ZN11LayerFlowNS24LFEffectDenseHairDataJNI18registerJniMethodsEP7_JNIEnv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 78 instructions
    /* 0x2cb978 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2cb97c */ str x28, [sp, #0x10];
    /* 0x2cb980 */ stp x22, x21, [sp, #0x20];
    /* 0x2cb984 */ stp x20, x19, [sp, #0x30];
    /* 0x2cb988 */ mov x29, sp;
    /* 0x2cb98c */ sub sp, sp, #0x1c0;
    /* 0x2cb990 */ mrs x22, tpidr_el0;
    /* 0x2cb994 */ mov x19, x0;
    /* 0x2cb998 */ adrp x1, #0x533000;
    /* 0x2cb99c */ add x1, x1, #0x7e0;
    /* 0x2cb9a0 */ ldr x8, [x22, #0x28];
    memcpy();
    return x0;
    __stack_chk_fail();
}
