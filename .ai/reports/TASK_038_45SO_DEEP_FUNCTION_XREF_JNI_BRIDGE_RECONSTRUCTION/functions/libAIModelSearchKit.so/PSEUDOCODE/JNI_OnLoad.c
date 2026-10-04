// Function: JNI_OnLoad
// RVA: 0x727cc, Size: 148 bytes
int64_t JNI_OnLoad(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x72810
    return a0;
    _ZN13aimodelsearch21initializeClassLoaderEP7_JNIEnv(...); // call imported API via PLT at 0x72840
    __stack_chk_fail(...); // call imported API via PLT at 0x7285c
}
