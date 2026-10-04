// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x657f70
// Recovered Name: sub_657f70
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x657f70 | Size: 1564 bytes | SHA256: e41def90ecedafd00968f27c4646f88530e756b7e297def3ee2e9f46997d641b
// Callers: 0 | Callees: 8 | Imports: 6

// Calls external APIs: _ZdaPv, _Znam, _Znwm, __android_log_print, __stack_chk_fail, memset
// Strings referenced:
//   "ARMakeupadaptMLPModel::CreateMakeupAdaptMask: Failed to blur mask texture"
//   "ARMakeupadaptMLPModel::CreateMakeupAdaptMask: Failed to create new texture for blurred mask"
//   "ARMakeupadaptMLPModel::CreateMakeupAdaptMask: Failed to create texture object"
//   "ARMakeupadaptMLPModel::CreateMakeupAdaptMask: Failed to load blurred data to texture"
//   "ARMakeupadaptMLPModel::CreateMakeupAdaptMask: Failed to load mask data to texture"

void sub_657f70(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 391 instructions
    /* 0x657f70 */ stp x29, x30, [sp, #0x20];
    /* 0x657f74 */ stp x26, x25, [sp, #0x30];
    /* 0x657f78 */ stp x24, x23, [sp, #0x40];
    /* 0x657f7c */ stp x22, x21, [sp, #0x50];
    /* 0x657f80 */ stp x20, x19, [sp, #0x60];
    /* 0x657f84 */ add x29, sp, #0x20;
    /* 0x657f88 */ mrs x25, tpidr_el0;
    /* 0x657f8c */ mov w20, w1;
    /* 0x657f90 */ ldr x8, [x25, #0x28];
    /* 0x657f94 */ stur x8, [x29, #-8];
    /* 0x657f98 */ tbnz w1, #0x1f, #0x658274;
    _Znam();
    memset();
    sub_c41220();
    _ZdaPv();
    _Znwm();
    sub_6a39ec();
    sub_6a3ea8();
    sub_6a3e24();
    sub_69add8();
    _Znam();
    sub_c40e68();
    sub_c41220();
    _ZdaPv();
    sub_65858c();
    sub_c40e68();
    sub_5a6b20();
    sub_5a6b20();
    __android_log_print();
    __android_log_print();
    sub_5a6b20();
    sub_5a6b20();
    __android_log_print();
    _ZdaPv();
    __android_log_print();
    sub_5a6b20();
    sub_5a6b20();
    __android_log_print();
    __android_log_print();
    _ZdaPv();
    sub_c40e68();
    return x0;
    __stack_chk_fail();
}
