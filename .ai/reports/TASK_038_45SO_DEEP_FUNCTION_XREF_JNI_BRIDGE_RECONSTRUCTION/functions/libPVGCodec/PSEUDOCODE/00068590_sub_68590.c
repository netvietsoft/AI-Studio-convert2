// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x68590
// Recovered Name: sub_68590
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x68590 | Size: 420 bytes | SHA256: 57890b48e935231395b075c2be30301aa74afa8242eb0372e0aa495fee700dc6
// Callers: 3 | Callees: 0 | Imports: 5

// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, _ZNSt6__ndk15mutex4lockEv, _ZNSt6__ndk15mutex6unlockEv, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> Ref type error, unknown type"
//   "%s/%s: F[%s, L(%d)], T(%p):> gl type is unsupported"
//   "F[%s, L(%d)], T(%p):> Ref type error, unknown type"
//   "F[%s, L(%d)], T(%p):> gl type is unsupported"
//   "release"

void sub_68590(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 105 instructions
    /* 0x68590 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x68594 */ stp x20, x19, [sp, #0x10];
    /* 0x68598 */ mov x29, sp;
    /* 0x6859c */ mov x19, x0;
    /* 0x685a0 */ add x0, x0, #8;
    _ZNSt6__ndk15mutex4lockEv();
    /* 0x685a8 */ ldr w8, [x19, #0x30];
    /* 0x685ac */ add x0, x19, #8;
    /* 0x685b0 */ sub w20, w8, #1;
    /* 0x685b4 */ str w20, [x19, #0x30];
    _ZNSt6__ndk15mutex6unlockEv();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
}
