// Library: libbmpKit.so
// Function ID: libbmpKit::0x345f0
// Recovered Name: sub_345f0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x345f0 | Size: 188 bytes | SHA256: e0e23fbbe0d18bd9be8aa51161c0e55febb6a9ba1fc440c42258185d41923521
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: _ZN7_JNIEnv15RegisterNativesEP7_jclassPK15JNINativeMethodi, _ZN7_JNIEnv9FindClassEPKc, __android_log_print
// Strings referenced:
//   "Can't find class(%s)"
//   "Can't register method for class(%s)"
//   "cBmpKit"

void sub_345f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x345f0 */ stp x29, x30, [sp, #0x20];
    /* 0x345f4 */ add x29, sp, #0x20;
    /* 0x345f8 */ str x0, [sp, #0x10];
    /* 0x345fc */ ldr x0, [sp, #0x10];
    /* 0x34600 */ nop ;
    /* 0x34604 */ adr x1, #0x18afe;
    _ZN7_JNIEnv9FindClassEPKc();
    /* 0x3460c */ str x0, [sp, #8];
    /* 0x34610 */ ldr x8, [sp, #8];
    /* 0x34614 */ cbnz x8, #0x34648;
    /* 0x34618 */ b #0x3461c;
    __android_log_print();
    _ZN7_JNIEnv15RegisterNativesEP7_jclassPK15JNINativeMethodi();
    __android_log_print();
    return x0;
}
