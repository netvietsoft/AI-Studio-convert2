// Library: libkoom-strip-dump.so
// Function ID: libkoom-strip-dump::0x381b0
// Recovered Name: sub_381b0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x381b0 | Size: 272 bytes | SHA256: 8c93735c18072e99e69ec2ef5224d997419c075ccbd5ff8db3b1b399cf158cec
// Callers: 0 | Callees: 4 | Imports: 5

// Calls external APIs: __android_log_print, __errno, __stack_chk_fail, async_safe_format_log, waitpid
// Strings referenced:
//   "Child process %d exited with status %d, terminated by signal %d"
//   "HprofDump"
//   "ResumeAndWait"
//   "init_done_"

void sub_381b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 68 instructions
    /* 0x381b0 */ stp x29, x30, [sp, #0x10];
    /* 0x381b4 */ str x21, [sp, #0x20];
    /* 0x381b8 */ stp x20, x19, [sp, #0x30];
    /* 0x381bc */ add x29, sp, #0x10;
    sub_38370();
    /* 0x381c4 */ cbz w8, #0x381e8;
    /* 0x381c8 */ ldr w8, [x0, #4];
    /* 0x381cc */ mov x20, x0;
    /* 0x381d0 */ mov w19, w1;
    /* 0x381d4 */ cmp w8, #0x1d;
    /* 0x381d8 */ b.gt #0x38214;
    __errno();
    sub_38318();
    sub_38328();
    async_safe_format_log();
    waitpid();
    __errno();
    __android_log_print();
    sub_38348();
    return x0;
    __stack_chk_fail();
}
