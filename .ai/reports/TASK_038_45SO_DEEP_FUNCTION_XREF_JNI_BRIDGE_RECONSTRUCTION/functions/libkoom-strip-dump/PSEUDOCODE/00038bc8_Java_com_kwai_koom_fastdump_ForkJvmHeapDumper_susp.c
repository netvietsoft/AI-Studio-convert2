// Library: libkoom-strip-dump.so
// Function ID: libkoom-strip-dump::0x38bc8
// Recovered Name: Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_suspendAndFork
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x38bc8 | Size: 20 bytes | SHA256: 45d8ed757354efdc2e1ac319aa3fcb70fafff74c58c527157a781773cdb588f6
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN4kwai12leak_monitor9HprofDump11GetInstanceEv, _ZN4kwai12leak_monitor9HprofDump14SuspendAndForkEv

jlong Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_suspendAndFork(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x38bc8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x38bcc */ mov x29, sp;
    _ZN4kwai12leak_monitor9HprofDump11GetInstanceEv();
    /* 0x38bd4 */ ldp x29, x30, [sp], #0x10;
    /* 0x38bd8 */ b #0x852e0;
}
