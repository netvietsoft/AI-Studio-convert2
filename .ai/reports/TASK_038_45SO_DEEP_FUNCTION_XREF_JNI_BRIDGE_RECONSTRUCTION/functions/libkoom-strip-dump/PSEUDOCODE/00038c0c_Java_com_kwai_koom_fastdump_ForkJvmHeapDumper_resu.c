// Library: libkoom-strip-dump.so
// Function ID: libkoom-strip-dump::0x38c0c
// Recovered Name: Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_resumeAndWait
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x38c0c | Size: 44 bytes | SHA256: 1040a04d45d4d4e96f01d4cc6f4bf225eff12c628edb94c8db4e4d369f0ff607
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN4kwai12leak_monitor9HprofDump11GetInstanceEv, _ZN4kwai12leak_monitor9HprofDump13ResumeAndWaitEi

jlong Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_resumeAndWait(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x38c0c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x38c10 */ str x19, [sp, #0x10];
    /* 0x38c14 */ mov x29, sp;
    /* 0x38c18 */ mov w19, w2;
    _ZN4kwai12leak_monitor9HprofDump11GetInstanceEv();
    /* 0x38c20 */ mov w1, w19;
    _ZN4kwai12leak_monitor9HprofDump13ResumeAndWaitEi();
    /* 0x38c28 */ ldr x19, [sp, #0x10];
    /* 0x38c2c */ and w0, w0, #1;
    /* 0x38c30 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
