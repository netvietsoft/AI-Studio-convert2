// Library: libkoom-strip-dump.so
// Function ID: libkoom-strip-dump::0x38c3c
// Recovered Name: Java_com_kwai_koom_javaoom_hprof_ForkStripHeapDumper_hprofName
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x38c3c | Size: 96 bytes | SHA256: dab7558a6f03f4f2da2a10bb7598c9073f4842e81778b00665236573adb05e44
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN4kwai12leak_monitor10HprofStrip11GetInstanceEv, _ZN4kwai12leak_monitor10HprofStrip12SetHprofNameEPKc

jlong Java_com_kwai_koom_javaoom_hprof_ForkStripHeapDumper_hprofName(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 24 instructions
    /* 0x38c3c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x38c40 */ str x21, [sp, #0x10];
    /* 0x38c44 */ stp x20, x19, [sp, #0x20];
    /* 0x38c48 */ mov x29, sp;
    /* 0x38c4c */ ldr x8, [x0];
    /* 0x38c50 */ mov x20, x2;
    /* 0x38c54 */ mov x1, x2;
    /* 0x38c58 */ mov x2, xzr;
    /* 0x38c5c */ mov x19, x0;
    /* 0x38c60 */ ldr x8, [x8, #0x548];
    /* 0x38c64 */ blr x8;
    _ZN4kwai12leak_monitor10HprofStrip11GetInstanceEv();
    _ZN4kwai12leak_monitor10HprofStrip12SetHprofNameEPKc();
}
