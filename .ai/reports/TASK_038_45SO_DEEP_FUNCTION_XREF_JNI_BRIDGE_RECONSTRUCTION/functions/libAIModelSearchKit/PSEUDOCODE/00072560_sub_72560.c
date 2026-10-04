// Library: libAIModelSearchKit.so
// Function ID: libAIModelSearchKit::0x72560
// Recovered Name: sub_72560
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x72560 | Size: 308 bytes | SHA256: 57a3909993d03420d1551bc2ac7e5e0a2792e3852690e514dc737e9f8d35972a
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz, _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz
// Strings referenced:
//   "()Ljava/lang/ClassLoader;"
//   "()Ljava/lang/Thread;"
//   "(Ljava/lang/String;)Ljava/lang/Class;"
//   "currentThread"
//   "findClass"

void sub_72560(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 77 instructions
    /* 0x72560 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x72564 */ str x21, [sp, #0x10];
    /* 0x72568 */ stp x20, x19, [sp, #0x20];
    /* 0x7256c */ mov x29, sp;
    /* 0x72570 */ ldr x8, [x0];
    /* 0x72574 */ adrp x1, #0x49000;
    /* 0x72578 */ add x1, x1, #0x104;
    /* 0x7257c */ mov x19, x0;
    /* 0x72580 */ ldr x8, [x8, #0x30];
    /* 0x72584 */ blr x8;
    /* 0x72588 */ cbz x0, #0x72684;
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz();
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz();
    return x0;
}
