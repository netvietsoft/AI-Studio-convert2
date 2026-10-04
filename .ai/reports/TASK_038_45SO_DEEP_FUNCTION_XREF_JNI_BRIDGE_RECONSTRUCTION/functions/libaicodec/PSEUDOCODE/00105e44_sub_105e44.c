// Library: libaicodec.so
// Function ID: libaicodec::0x105e44
// Recovered Name: sub_105e44
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x105e44 | Size: 452 bytes | SHA256: a74eaa3d1f13db81753c94f41b3bef2f22de0987f44274633916b069da525fe4
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: getVersion()Lcom/meitu/media/aicodec/AICodec$Version; (table at 0x1feb88)
// Calls external APIs: _ZN7MMCodec10JniUtility12getJavaClassEPKc, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7_JNIEnv9NewObjectEP7_jclassP10_jmethodIDz, __android_log_print
// Strings referenced:
//   "(IIII)V"
//   "<init>"
//   "[%s(%d)]:> Couldn't find class %s"
//   "[%s(%d)]:> Couldn't find class %s constructor"
//   "com_meitu_media_aicodec_AICodec_getVersion"

jlong sub_105e44(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 113 instructions
    /* 0x105e44 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x105e48 */ str x21, [sp, #0x10];
    /* 0x105e4c */ stp x20, x19, [sp, #0x20];
    /* 0x105e50 */ mov x29, sp;
    /* 0x105e54 */ adrp x19, #0x20a000;
    /* 0x105e58 */ ldr x1, [x19, #0x5b0];
    /* 0x105e5c */ cbnz x1, #0x105e88;
    /* 0x105e60 */ adrp x20, #0x201000;
    /* 0x105e64 */ mov x21, x0;
    /* 0x105e68 */ ldr x20, [x20, #0xe48];
    /* 0x105e6c */ ldr x8, [x20];
    _ZN7MMCodec10JniUtility12getJavaClassEPKc();
    __android_log_print();
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
