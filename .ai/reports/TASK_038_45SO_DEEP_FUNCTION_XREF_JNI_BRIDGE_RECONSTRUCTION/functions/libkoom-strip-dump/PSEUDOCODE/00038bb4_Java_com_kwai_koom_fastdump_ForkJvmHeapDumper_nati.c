// Library: libkoom-strip-dump.so
// Function ID: libkoom-strip-dump::0x38bb4
// Recovered Name: Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_nativeInit
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x38bb4 | Size: 20 bytes | SHA256: 365781768f947e8bf2fd56288227249266c0a6520a67c4daf65b57259ad34060
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN4kwai12leak_monitor9HprofDump10InitializeEv, _ZN4kwai12leak_monitor9HprofDump11GetInstanceEv

jlong Java_com_kwai_koom_fastdump_ForkJvmHeapDumper_nativeInit(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x38bb4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x38bb8 */ mov x29, sp;
    _ZN4kwai12leak_monitor9HprofDump11GetInstanceEv();
    /* 0x38bc0 */ ldp x29, x30, [sp], #0x10;
    /* 0x38bc4 */ b #0x85270;
}
