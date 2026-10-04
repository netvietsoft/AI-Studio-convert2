// Function: Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_exitProcess
// RVA: 0x38bdc, Size: 48 bytes
int64_t Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_exitProcess(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    getpid(...); // call PLT API at 0x38be4
    const char* str = "JNIBridge";
    const char* str = "process %d will exit!";
    __android_log_print(...); // call PLT API at 0x38c00
    _exit(...); // call PLT API at 0x38c08
}
