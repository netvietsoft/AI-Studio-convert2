// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0xb9a0
// Recovered Name: sub_b9a0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xb9a0 | Size: 260 bytes | SHA256: b40e3477884aba7467f572a9db73e15fd6baf45867eb56327e32aa1b46f210af
// Callers: 0 | Callees: 2 | Imports: 5

// Dynamic Registration: getVersion()Ljava/lang/String; (table at 0x19610)
// Calls external APIs: _ZN13VLLogMediator11getInstanceEv, _ZN13VLLogMediator15getVllogVersionEv, __android_log_print, __cxa_begin_catch, __cxa_end_catch
// Strings referenced:
//   "VLLog version: %s"
//   "java/lang/RuntimeException"
//   "vllogGetVersion failed: %s"
//   "vllogmediatorLog-JNI"

jlong sub_b9a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 65 instructions
    /* 0xb9a0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xb9a4 */ str x21, [sp, #0x10];
    /* 0xb9a8 */ stp x20, x19, [sp, #0x20];
    /* 0xb9ac */ mov x29, sp;
    /* 0xb9b0 */ mov x19, x0;
    _ZN13VLLogMediator11getInstanceEv();
    _ZN13VLLogMediator15getVllogVersionEv();
    /* 0xb9bc */ mov x20, x0;
    /* 0xb9c0 */ adrp x1, #0x4000;
    /* 0xb9c4 */ add x1, x1, #0xc53;
    /* 0xb9c8 */ adrp x2, #0x4000;
    __android_log_print();
    return x0;
    __cxa_begin_catch();
    __android_log_print();
    __cxa_end_catch();
    __cxa_end_catch();
    sub_ca4c();
    sub_80b0();
}
