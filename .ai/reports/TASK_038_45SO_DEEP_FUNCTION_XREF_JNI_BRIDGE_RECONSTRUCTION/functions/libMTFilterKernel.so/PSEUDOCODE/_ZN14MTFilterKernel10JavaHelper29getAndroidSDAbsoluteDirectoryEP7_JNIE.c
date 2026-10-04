// Function: MTFilterKernel::JavaHelper::getAndroidSDAbsoluteDirectory(_JNIEnv*)
// RVA: 0xc136c, Size: 328 bytes
int64_t _ZN14MTFilterKernel10JavaHelper29getAndroidSDAbsoluteDirectoryEP7_JNIEnv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "android/os/Environment";
    (*x8)(...);
    const char* str = "getExternalStorageDirectory";
    const char* str = "()Ljava/io/File;";
    (*x8)(...);
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call internal at 0xc13d4
    const char* str = "java/io/File";
    (*x8)(...);
    const char* str = "getAbsolutePath";
    const char* str = "()Ljava/lang/String;";
    (*x8)(...);
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call internal at 0xc1430
    (*x8)(...);
    strlen(...); // call PLT API at 0xc1458
    _Znam(...); // call PLT API at 0xc1470
    strcpy(...); // call PLT API at 0xc1480
    (*x8)(...);
    return a0;
}
