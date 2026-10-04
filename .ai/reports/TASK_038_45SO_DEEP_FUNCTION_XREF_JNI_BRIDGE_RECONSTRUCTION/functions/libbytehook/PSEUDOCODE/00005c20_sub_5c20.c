// Library: libbytehook.so
// Function ID: libbytehook::0x5c20
// Recovered Name: sub_5c20
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5c20 | Size: 172 bytes | SHA256: 38c0fa4f122ec2d521e2a89d261e499b0a27b0971138d4977b57397e7133cf5a
// Callers: 1 | Callees: 1 | Imports: 4

// Calls external APIs: __errno, __read_chk, lseek, malloc

void sub_5c20(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 43 instructions
    /* 0x5c20 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5c24 */ stp x22, x21, [sp, #0x10];
    /* 0x5c28 */ stp x20, x19, [sp, #0x20];
    /* 0x5c2c */ mov x29, sp;
    /* 0x5c30 */ mov x21, xzr;
    /* 0x5c34 */ cbz x3, #0x5cb8;
    /* 0x5c38 */ add x8, x3, x2;
    /* 0x5c3c */ mov x19, x3;
    /* 0x5c40 */ mov x22, x2;
    /* 0x5c44 */ cmp x8, x1;
    /* 0x5c48 */ b.hi #0x5cb8;
    lseek();
    malloc();
    __errno();
    __read_chk();
    sub_5cd8();
    return x0;
}
