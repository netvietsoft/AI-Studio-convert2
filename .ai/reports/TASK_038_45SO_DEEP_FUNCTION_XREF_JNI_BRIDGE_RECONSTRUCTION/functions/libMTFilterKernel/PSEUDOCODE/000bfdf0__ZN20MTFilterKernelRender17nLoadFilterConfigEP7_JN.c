// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbfdf0
// Recovered Name: _ZN20MTFilterKernelRender17nLoadFilterConfigEP7_JNIEnvP8_jobjectlP8_jstring
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbfdf0 | Size: 244 bytes | SHA256: 2bc6af46792387dc7c633c73719a8b508fe8818e0c27edae4af602fcf1c12acf
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nLoadFilterConfig(JLjava/lang/String;)Z (table at 0x1ca590)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "FilterKernel_jni"
//   "nLoadFilterConfig begin: %s"
//   "nLoadFilterConfig end."

jobject _ZN20MTFilterKernelRender17nLoadFilterConfigEP7_JNIEnvP8_jobjectlP8_jstring(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 61 instructions
    /* 0xbfdf0 */ stp x29, x30, [sp, #-0x40]!;
    /* 0xbfdf4 */ str x23, [sp, #0x10];
    /* 0xbfdf8 */ stp x22, x21, [sp, #0x20];
    /* 0xbfdfc */ stp x20, x19, [sp, #0x30];
    /* 0xbfe00 */ mov x29, sp;
    /* 0xbfe04 */ mov x19, x3;
    /* 0xbfe08 */ mov x20, x2;
    /* 0xbfe0c */ cbz x2, #0xbfea4;
    /* 0xbfe10 */ cbz x19, #0xbfea4;
    /* 0xbfe14 */ ldr x8, [x0];
    /* 0xbfe18 */ mov x1, x19;
    __android_log_print();
    _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface16loadFilterConfigEPKc();
    __android_log_print();
    return x0;
    return x0;
    _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface16loadFilterConfigEPKc();
    return x0;
}
