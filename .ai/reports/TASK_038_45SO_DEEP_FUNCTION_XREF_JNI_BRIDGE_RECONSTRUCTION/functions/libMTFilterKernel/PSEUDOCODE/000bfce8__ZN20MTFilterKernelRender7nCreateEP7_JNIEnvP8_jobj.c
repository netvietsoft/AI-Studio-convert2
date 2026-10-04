// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbfce8
// Recovered Name: _ZN20MTFilterKernelRender7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbfce8 | Size: 64 bytes | SHA256: 90be9150b0559d3bf5dafa2a4154c760fe083b03ca98207b80a3fe984258e9b9
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x1ca530)
// Calls external APIs: _ZdlPv, _Znwm

jlong _ZN20MTFilterKernelRender7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0xbfce8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbfcec */ stp x20, x19, [sp, #0x10];
    /* 0xbfcf0 */ mov x29, sp;
    /* 0xbfcf4 */ mov w0, #0x18;
    _Znwm();
    /* 0xbfcfc */ mov x19, x0;
    _ZN14MTFilterKernel39MTlabFilterKernelRenderAndroidInterfaceC2Ev();
    /* 0xbfd04 */ mov x0, x19;
    /* 0xbfd08 */ ldp x20, x19, [sp, #0x10];
    /* 0xbfd0c */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_1b0544();
}
