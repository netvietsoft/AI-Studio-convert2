// Function: MTFilterKernel::JavaHelper::jniDeleteFile(_JNIEnv*, char const*)
// RVA: 0xc2250, Size: 284 bytes
int64_t _ZN14MTFilterKernel10JavaHelper13jniDeleteFileEP7_JNIEnvPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "java/io/File";
    (*x8)(...);
    const char* str = "<init>";
    const char* str = "(Ljava/lang/String;)V";
    (*x8)(...);
    _ZN7_JNIEnv9NewObjectEP7_jclassP10_jmethodIDz(...); // call internal at 0xc22bc
    const char* str = "exists";
    const char* str = "()Z;";
    (*x8)(...);
    _ZN7_JNIEnv17CallBooleanMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc22f8
    return a0;
    const char* str = "delete";
    const char* str = "()Z;";
    (*x8)(...);
    _ZN7_JNIEnv17CallBooleanMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc2350
    return a0;
}
