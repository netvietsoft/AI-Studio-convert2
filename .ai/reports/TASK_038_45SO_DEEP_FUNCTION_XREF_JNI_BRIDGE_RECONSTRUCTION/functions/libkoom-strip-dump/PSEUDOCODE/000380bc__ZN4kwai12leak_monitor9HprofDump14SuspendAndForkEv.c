// Library: libkoom-strip-dump.so
// Function ID: libkoom-strip-dump::0x380bc
// Recovered Name: _ZN4kwai12leak_monitor9HprofDump14SuspendAndForkEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x380bc | Size: 240 bytes | SHA256: 6a743a20f5c6be36ed7e7ec8d5de38c6b7497e197536b18bfd7b10bf8bd406f8
// Callers: 0 | Callees: 2 | Imports: 5

// Calls external APIs: __errno, alarm, async_safe_format_log, fork, prctl
// Strings referenced:
//   "HprofDump"
//   "SuspendAndFork"
//   "forked-dump-process"
//   "init_done_"

void _ZN4kwai12leak_monitor9HprofDump14SuspendAndForkEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 60 instructions
    /* 0x380bc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x380c0 */ stp x20, x19, [sp, #0x10];
    /* 0x380c4 */ mov x29, sp;
    /* 0x380c8 */ ldrb w8, [x0];
    /* 0x380cc */ cbz w8, #0x380ec;
    /* 0x380d0 */ ldr w8, [x0, #4];
    /* 0x380d4 */ mov x19, x0;
    /* 0x380d8 */ cmp w8, #0x1d;
    /* 0x380dc */ b.gt #0x3811c;
    /* 0x380e0 */ ldr x8, [x19, #0x18];
    /* 0x380e4 */ blr x8;
    __errno();
    sub_38318();
    sub_38328();
    async_safe_format_log();
    fork();
    alarm();
    prctl();
    return x0;
}
