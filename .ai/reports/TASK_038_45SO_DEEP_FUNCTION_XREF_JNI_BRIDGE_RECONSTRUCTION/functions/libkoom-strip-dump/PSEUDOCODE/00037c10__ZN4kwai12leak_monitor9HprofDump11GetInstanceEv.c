// Library: libkoom-strip-dump.so
// Function ID: libkoom-strip-dump::0x37c10
// Recovered Name: _ZN4kwai12leak_monitor9HprofDump11GetInstanceEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x37c10 | Size: 140 bytes | SHA256: 972cff33a4ee709783f566af4cd7f9572a7d767be3bee0bf64e476a9fc4ccdd1
// Callers: 0 | Callees: 1 | Imports: 5

// Calls external APIs: _ZN4kwai12leak_monitor9HprofDumpC1Ev, __cxa_atexit, __cxa_guard_abort, __cxa_guard_acquire, __cxa_guard_release

void _ZN4kwai12leak_monitor9HprofDump11GetInstanceEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 35 instructions
    /* 0x37c10 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x37c14 */ str x19, [sp, #0x10];
    /* 0x37c18 */ mov x29, sp;
    /* 0x37c1c */ nop ;
    /* 0x37c20 */ adr x8, #0x94280;
    /* 0x37c24 */ ldarb w8, [x8];
    /* 0x37c28 */ tbz w8, #0, #0x37c40;
    /* 0x37c2c */ ldr x19, [sp, #0x10];
    /* 0x37c30 */ adrp x0, #0x94000;
    /* 0x37c34 */ add x0, x0, #0x288;
    /* 0x37c38 */ ldp x29, x30, [sp], #0x20;
    return x0;
    __cxa_guard_acquire();
    _ZN4kwai12leak_monitor9HprofDumpC1Ev();
    __cxa_atexit();
    __cxa_guard_release();
    __cxa_guard_abort();
    sub_8130c();
}
