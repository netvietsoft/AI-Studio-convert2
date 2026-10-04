// Function: aimodelsearch::initializeClassLoader(_JNIEnv*)
// RVA: 0x7255c, Size: 312 bytes
int64_t _ZN13aimodelsearch21initializeClassLoaderEP7_JNIEnv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_49104 = "java/lang/Thread"; // string xref
    (*x8)(...); // indirect call at 0x72584
    const char* s_4a129 = "currentThread"; // string xref
    const char* s_4977a = "()Ljava/lang/Thread;"; // string xref
    (*x8)(...); // indirect call at 0x725b0
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call imported API via PLT at 0x725c4
    const char* s_48f40 = "getContextClassLoader"; // string xref
    const char* s_4a854 = "()Ljava/lang/ClassLoader;"; // string xref
    (*x8)(...); // indirect call at 0x725f0
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0x72604
    (*x8)(...); // indirect call at 0x72620
    (*x8)(...); // indirect call at 0x72640
    const char* s_49338 = "findClass"; // string xref
    const char* s_49249 = "(Ljava/lang/String;)Ljava/lang/Class;"; // string xref
    (*x8)(...); // indirect call at 0x72664
    return a0;
}
