// Library: libaicodec.so
// Function ID: libaicodec::0x118454
// Recovered Name: JNI_OnLoad
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x118454 | Size: 496 bytes | SHA256: 9a4f03a8554348cef82d386bb75be1217853299ec42f56fdd861680e7db171d9
// Callers: 0 | Callees: 0 | Imports: 6

// Calls external APIs: _Z15aicodec_set_jvmP7_JavaVM, _Z31register_aicodec_native_methodsP7_JNIEnv, _ZN7MMCodec10JniUtility4initEP7_JNIEnv, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN9JniHelper6getEnvEv, __android_log_print
// Strings referenced:
//   "JNI_OnLoad"
//   "[%s(%d)]:> [%s]JniHelper::getEnv() get null"
//   "[%s(%d)]:> aicodec_set_jvm failed"
//   "[%s(%d)]:> register_aicodec_native_methods failed"

jobject JNI_OnLoad(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 124 instructions
    /* 0x118454 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x118458 */ str x19, [sp, #0x10];
    /* 0x11845c */ mov x29, sp;
    _Z15aicodec_set_jvmP7_JavaVM();
    /* 0x118464 */ tbnz w0, #0x1f, #0x118498;
    _ZN9JniHelper6getEnvEv();
    /* 0x11846c */ cbz x0, #0x118524;
    /* 0x118470 */ mov x19, x0;
    _ZN7MMCodec10JniUtility4initEP7_JNIEnv();
    /* 0x118478 */ mov x0, x19;
    _Z31register_aicodec_native_methodsP7_JNIEnv();
    return x0;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
