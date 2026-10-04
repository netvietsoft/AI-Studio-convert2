// Reconstructed Pseudocode for FN_libkoom-strip-dump_00038BDC (Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_exitProcess)
// Library: libkoom-strip-dump.so | RVA: 0x38BDC | Size: 48B | Visibility: FACT

/* Imported APIs: getpid;__android_log_print;_exit */
/* String XREFs: JNIBridge;process %d will exit! */

int Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_exitProcess(void* ctx) {
    // Function prologue: set up stack frame
    getpid(...);
    __android_log_print(...);
    _exit(...);
    return 0;
}
