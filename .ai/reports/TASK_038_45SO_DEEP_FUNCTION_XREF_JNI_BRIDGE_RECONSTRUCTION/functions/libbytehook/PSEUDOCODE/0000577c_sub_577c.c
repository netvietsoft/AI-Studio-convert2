// Library: libbytehook.so
// Function ID: libbytehook::0x577c
// Recovered Name: sub_577c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x577c | Size: 340 bytes | SHA256: 0c5455cb63c0e0918a50903d22c17daa56c4d40c6735433a6551b214d189d750
// Callers: 0 | Callees: 5 | Imports: 4

// Calls external APIs: __stack_chk_fail, gettid, sigsetjmp, syscall

void sub_577c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 85 instructions
    /* 0x577c */ stp x29, x30, [sp, #0x120];
    /* 0x5780 */ str x28, [sp, #0x130];
    /* 0x5784 */ stp x24, x23, [sp, #0x140];
    /* 0x5788 */ stp x22, x21, [sp, #0x150];
    /* 0x578c */ stp x20, x19, [sp, #0x160];
    /* 0x5790 */ add x29, sp, #0x120;
    /* 0x5794 */ mrs x23, tpidr_el0;
    /* 0x5798 */ ldr x8, [x23, #0x28];
    /* 0x579c */ stur x8, [x29, #-8];
    sub_ba68();
    /* 0x57a4 */ cmp w0, #0x1a;
    sub_b9a8();
    gettid();
    syscall();
    sub_ce14();
    sigsetjmp();
    sub_ceb4();
    return x0;
    sub_ceb4();
    sub_d170();
    __stack_chk_fail();
}
