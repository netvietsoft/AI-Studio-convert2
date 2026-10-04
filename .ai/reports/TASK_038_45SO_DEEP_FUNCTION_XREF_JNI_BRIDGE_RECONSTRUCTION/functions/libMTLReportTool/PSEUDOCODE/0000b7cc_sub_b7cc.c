// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0xb7cc
// Recovered Name: sub_b7cc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xb7cc | Size: 468 bytes | SHA256: 90da497b505867fccda720d9d13857a81bd947cb175d231e571c6210058cb180
// Callers: 0 | Callees: 2 | Imports: 5

// Dynamic Registration: release()V (table at 0x195f8)
// Calls external APIs: _ZNSt6__ndk15mutex4lockEv, _ZNSt6__ndk15mutex6unlockEv, __android_log_print, __cxa_begin_catch, __cxa_end_catch
// Strings referenced:
//   "Deleted LogInfoModel class reference"
//   "Deleted log callback reference"
//   "java/lang/RuntimeException"
//   "vllogRelease called"
//   "vllogRelease completed successfully"

jlong sub_b7cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 117 instructions
    /* 0xb7cc */ stp x29, x30, [sp, #-0x30]!;
    /* 0xb7d0 */ str x21, [sp, #0x10];
    /* 0xb7d4 */ stp x20, x19, [sp, #0x20];
    /* 0xb7d8 */ mov x29, sp;
    /* 0xb7dc */ mov x19, x0;
    /* 0xb7e0 */ adrp x1, #0x4000;
    /* 0xb7e4 */ add x1, x1, #0xc53;
    /* 0xb7e8 */ adrp x2, #0x4000;
    /* 0xb7ec */ add x2, x2, #0x793;
    /* 0xb7f0 */ mov w0, #3;
    __android_log_print();
    _ZNSt6__ndk15mutex4lockEv();
    __android_log_print();
    _ZNSt6__ndk15mutex6unlockEv();
    _ZNSt6__ndk15mutex4lockEv();
    __android_log_print();
    _ZNSt6__ndk15mutex6unlockEv();
    __android_log_print();
    return x0;
    _ZNSt6__ndk15mutex6unlockEv();
    __cxa_begin_catch();
    __android_log_print();
    __cxa_end_catch();
    sub_ca4c();
    sub_80b0();
}
