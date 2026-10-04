// Reconstructed Pseudocode for FN_libhiai_000303C0 (HIAI_MR_GetVersion)
// Library: libhiai.so | RVA: 0x303C0 | Size: 736B | Visibility: FACT

/* Imported APIs: pthread_mutex_lock;pthread_mutex_unlock;dlopen;dlsym;strlen;strncmp;__strrchr_chk;AI_Log_Print;dlerror;dlclose */
/* String XREFs: libhiai_enhance.so;GetPluginHiAIVersion;com/huawei/hiai/computecapability/ComputeCapabilityDynamicClient;getPluginHiAIVersion;(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String */

int HIAI_MR_GetVersion(void* ctx) {
    // Function prologue: set up stack frame
    sub_6B24C(ctx);
    pthread_mutex_lock(...);
    pthread_mutex_unlock(...);
    dlopen(...);
    dlsym(...);
    strlen(...);
    return 0;
}
