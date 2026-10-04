// Library: libkoom-strip-dump.so
// Function ID: libkoom-strip-dump::0x37c9c
// Recovered Name: _ZN4kwai12leak_monitor9HprofDumpD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x37c9c | Size: 40 bytes | SHA256: aad6fdc018ad5bb679e11a7db04e22432c8d3287ce7d80be8e5b7deef2b57124
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN4kwai12leak_monitor9HprofDumpD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x37c9c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x37ca0 */ str x19, [sp, #0x10];
    /* 0x37ca4 */ mov x29, sp;
    /* 0x37ca8 */ mov x19, x0;
    /* 0x37cac */ add x0, x0, #0x10;
    sub_37d9c();
    /* 0x37cb4 */ add x0, x19, #8;
    /* 0x37cb8 */ ldr x19, [sp, #0x10];
    /* 0x37cbc */ ldp x29, x30, [sp], #0x20;
    /* 0x37cc0 */ b #0x37d9c;
}
