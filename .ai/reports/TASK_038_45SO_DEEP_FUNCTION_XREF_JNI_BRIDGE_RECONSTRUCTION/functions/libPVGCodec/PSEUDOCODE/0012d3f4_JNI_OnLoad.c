// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x12d3f4
// Recovered Name: JNI_OnLoad
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x12d3f4 | Size: 2924 bytes | SHA256: 19dbc1429d52045e8bdfc717fc355dee63caf2507c36c0f17fff710389eb4bd2
// Callers: 0 | Callees: 19 | Imports: 3

// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> %s"
//   "%s/%s: F[%s, L(%d)], T(%p):> NS_PVG::JniHelper::getEnv() is null"
//   "%s/%s: F[%s, L(%d)], T(%p):> register jni func"
//   "%s/%s: F[%s, L(%d)], T(%p):> register_JNIAudioDecoder failed"
//   "%s/%s: F[%s, L(%d)], T(%p):> register_JNIAudioExtractor failed"

jobject JNI_OnLoad(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 731 instructions
    /* 0x12d3f4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x12d3f8 */ stp x22, x21, [sp, #0x10];
    /* 0x12d3fc */ stp x20, x19, [sp, #0x20];
    /* 0x12d400 */ mov x29, sp;
    /* 0x12d404 */ adrp x22, #0x13b000;
    /* 0x12d408 */ mov x19, x0;
    /* 0x12d40c */ ldr x22, [x22, #0x198];
    /* 0x12d410 */ ldr w8, [x22];
    /* 0x12d414 */ cmp w8, #3;
    /* 0x12d418 */ b.gt #0x12d44c;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    sub_12b1e4();
    sub_12b0ec();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    sub_11dd58();
    sub_123d98();
    sub_11eb28();
    sub_120300();
    sub_121d84();
    sub_1211b4();
    sub_11bb80();
    sub_11938c();
    sub_11a36c();
    sub_11ae10();
    sub_12a944();
    sub_11f678();
    sub_1285bc();
    sub_129740();
    sub_127d40();
    sub_125010();
    sub_11c62c();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
}
