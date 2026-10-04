// Library: libkoom-strip-dump.so
// Function ID: libkoom-strip-dump::0x38bdc
// Recovered Name: Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_exitProcess
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x38bdc | Size: 48 bytes | SHA256: 22c2d62e02fba2562fedf40f7e569e2e34249194cf6d161e69ac99a87b767989
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: __android_log_print, _exit, getpid
// Strings referenced:
//   "process %d will exit!"

jlong Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_exitProcess(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x38bdc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x38be0 */ mov x29, sp;
    getpid();
    /* 0x38be8 */ mov w3, w0;
    /* 0x38bec */ nop ;
    /* 0x38bf0 */ adr x1, #0x22a31;
    /* 0x38bf4 */ adrp x2, #0x21000;
    /* 0x38bf8 */ add x2, x2, #0x9cb;
    /* 0x38bfc */ mov w0, #4;
    __android_log_print();
    /* 0x38c04 */ mov w0, wzr;
    _exit();
}
