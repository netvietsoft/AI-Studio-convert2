// Library: libManis.so
// Function ID: libManis::0x32c4d8
// Recovered Name: sub_32c4d8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x32c4d8 | Size: 2724 bytes | SHA256: 42a84be0f6f0f8d125c6e90c36870eb44c57ec9682b2c94bca87c845b49ae5b3
// Callers: 1 | Callees: 0 | Imports: 6

// Calls external APIs: __android_log_print, __open_2, __read_chk, close, fprintf, memmove
// Strings referenced:
//   "Mizar"
//   "ll"

void sub_32c4d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 681 instructions
    /* 0x32c4d8 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x32c4dc */ stp x28, x27, [sp, #0x10];
    /* 0x32c4e0 */ stp x26, x25, [sp, #0x20];
    /* 0x32c4e4 */ stp x24, x23, [sp, #0x30];
    /* 0x32c4e8 */ stp x22, x21, [sp, #0x40];
    /* 0x32c4ec */ stp x20, x19, [sp, #0x50];
    /* 0x32c4f0 */ mov x29, sp;
    /* 0x32c4f4 */ sub sp, sp, #0x110;
    /* 0x32c4f8 */ stur x2, [x29, #-0xa0];
    /* 0x32c4fc */ mrs x26, tpidr_el0;
    /* 0x32c500 */ add x9, x1, #0xf;
    __open_2();
    memmove();
    __read_chk();
    __android_log_print();
    fprintf();
    __android_log_print();
    fprintf();
    close();
    close();
    close();
}
