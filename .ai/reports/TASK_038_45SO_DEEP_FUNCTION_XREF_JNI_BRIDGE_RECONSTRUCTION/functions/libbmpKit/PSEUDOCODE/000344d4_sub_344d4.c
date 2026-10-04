// Library: libbmpKit.so
// Function ID: libbmpKit::0x344d4
// Recovered Name: sub_344d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x344d4 | Size: 220 bytes | SHA256: 889e93cdc77686caf63154fc9fe34754e01f154bc36e5aed68393beafc48d50a
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _ZN11KitApi30NDK18registerJniMethodsEP7_JNIEnv, _ZN7_JavaVM6GetEnvEPPvi, __android_log_print, __stack_chk_fail
// Strings referenced:
//   "KitApi30NDK registerJniMethods error!"
//   "jni OnLoad GetEnv error!"

void sub_344d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x344d4 */ stp x29, x30, [sp, #0x30];
    /* 0x344d8 */ add x29, sp, #0x30;
    /* 0x344dc */ mrs x8, tpidr_el0;
    /* 0x344e0 */ ldr x8, [x8, #0x28];
    /* 0x344e4 */ stur x8, [x29, #-8];
    /* 0x344e8 */ str x0, [sp, #0x10];
    /* 0x344ec */ str x1, [sp, #8];
    /* 0x344f0 */ mov x8, xzr;
    /* 0x344f4 */ stur x8, [x29, #-0x10];
    /* 0x344f8 */ ldr x0, [sp, #0x10];
    /* 0x344fc */ sub x1, x29, #0x10;
    _ZN7_JavaVM6GetEnvEPPvi();
    __android_log_print();
    _ZN11KitApi30NDK18registerJniMethodsEP7_JNIEnv();
    __android_log_print();
    return x0;
    __stack_chk_fail();
}
