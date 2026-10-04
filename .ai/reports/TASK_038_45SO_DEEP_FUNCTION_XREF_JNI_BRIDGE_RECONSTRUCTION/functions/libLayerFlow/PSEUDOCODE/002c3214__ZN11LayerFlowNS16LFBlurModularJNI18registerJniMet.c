// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c3214
// Recovered Name: _ZN11LayerFlowNS16LFBlurModularJNI18registerJniMethodsEP7_JNIEnv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x2c3214 | Size: 220 bytes | SHA256: 06dd7cc6aa3838b909b3b52e1d6348340d9d18897524191d47412d2848be7059
// Callers: 1 | Callees: 0 | Imports: 3

// Calls external APIs: __android_log_print, __stack_chk_fail, memcpy
// Strings referenced:
//   "Can't find class(%s)"
//   "Can't register method for class(%s)"
//   "mtik_"

void _ZN11LayerFlowNS16LFBlurModularJNI18registerJniMethodsEP7_JNIEnv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x2c3214 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2c3218 */ stp x28, x21, [sp, #0x10];
    /* 0x2c321c */ stp x20, x19, [sp, #0x20];
    /* 0x2c3220 */ mov x29, sp;
    /* 0x2c3224 */ sub sp, sp, #0x2f0;
    /* 0x2c3228 */ mrs x21, tpidr_el0;
    /* 0x2c322c */ nop ;
    /* 0x2c3230 */ adr x1, #0x1dceb0;
    /* 0x2c3234 */ ldr x8, [x21, #0x28];
    /* 0x2c3238 */ mov x19, x0;
    /* 0x2c323c */ stur x8, [x29, #-8];
    memcpy();
    __android_log_print();
    return x0;
    __stack_chk_fail();
}
