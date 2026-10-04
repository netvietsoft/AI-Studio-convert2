// Library: libMtlabSign.so
// Function ID: libMtlabSign::0x1c94
// Recovered Name: _Z11jstring2strP7_JNIEnvP8_jstring
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1c94 | Size: 412 bytes | SHA256: c4ee1efac78e03abc445a32d804562e061c576a989a2fb8e2d920fa3febf4048
// Callers: 0 | Callees: 1 | Imports: 6

// Calls external APIs: _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz, _Znwm, free, malloc, memcpy, strlen
// Strings referenced:
//   "(Ljava/lang/String;)[B"
//   "UTF-8"
//   "getBytes"

void _Z11jstring2strP7_JNIEnvP8_jstring(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 103 instructions
    /* 0x1c94 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x1c98 */ stp x24, x23, [sp, #0x10];
    /* 0x1c9c */ stp x22, x21, [sp, #0x20];
    /* 0x1ca0 */ stp x20, x19, [sp, #0x30];
    /* 0x1ca4 */ mov x29, sp;
    /* 0x1ca8 */ ldr x9, [x0];
    /* 0x1cac */ mov x21, x1;
    /* 0x1cb0 */ nop ;
    /* 0x1cb4 */ adr x1, #0x15d0;
    /* 0x1cb8 */ mov x20, x0;
    /* 0x1cbc */ mov x19, x8;
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz();
    malloc();
    memcpy();
    strlen();
    return x0;
    _Znwm();
    memcpy();
    sub_24ec();
}
