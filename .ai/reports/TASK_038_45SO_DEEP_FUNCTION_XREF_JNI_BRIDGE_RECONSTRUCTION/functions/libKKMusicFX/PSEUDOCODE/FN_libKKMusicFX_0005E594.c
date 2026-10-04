// Reconstructed Pseudocode for FN_libKKMusicFX_0005E594 (native_initialiseJUCE_(Landroid/content/Context;)V)
// Library: libKKMusicFX.so | RVA: 0x5E594 | Size: 588B | Visibility: FACT

/* Imported APIs: pthread_mutex_lock;pthread_mutex_unlock;__cxa_guard_acquire;__cxa_atexit;__cxa_guard_release;__cxa_guard_abort;__stack_chk_fail */
/* String XREFs: /Users/meitu/apollo-ws/source/JUCE/juce_core/native/juce_Threads_android.cpp;/Users/meitu/apollo-ws/source/JUCE/juce_core/native/juce_Threads_android.cpp */

int native_initialiseJUCE_(Landroid/content/Context;)V(void* ctx) {
    // Function prologue: set up stack frame
    sub_5C19C(ctx);
    sub_46BE8(ctx);
    sub_46BE8(ctx);
    sub_59604(ctx);
    sub_6CEF8(ctx);
    pthread_mutex_lock(...);
    pthread_mutex_unlock(...);
    __cxa_guard_acquire(...);
    __cxa_atexit(...);
    __cxa_guard_release(...);
    return 0;
}
