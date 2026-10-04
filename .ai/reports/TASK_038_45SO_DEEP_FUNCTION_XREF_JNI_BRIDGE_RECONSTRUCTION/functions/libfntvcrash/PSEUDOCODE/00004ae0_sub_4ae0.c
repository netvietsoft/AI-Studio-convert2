// Library: libfntvcrash.so
// Function ID: libfntvcrash::0x4ae0
// Recovered Name: sub_4ae0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x4ae0 | Size: 396 bytes | SHA256: c125fe8428a3bcbd5d6ca4ca5f126b0f681d572482d390e16fce53624637acf5
// Callers: 0 | Callees: 3 | Imports: 0

// Strings referenced:
//   "CIE start does not match"
//   "FDE has zero length"
//   "FDE is really a CIE"

void sub_4ae0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 99 instructions
    /* 0x4ae0 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x4ae4 */ str x27, [sp, #0x10];
    /* 0x4ae8 */ stp x26, x25, [sp, #0x20];
    /* 0x4aec */ stp x24, x23, [sp, #0x30];
    /* 0x4af0 */ stp x22, x21, [sp, #0x40];
    /* 0x4af4 */ stp x20, x19, [sp, #0x50];
    /* 0x4af8 */ mov x29, sp;
    /* 0x4afc */ mov x23, x1;
    /* 0x4b00 */ mov x20, x3;
    /* 0x4b04 */ mov x19, x2;
    /* 0x4b08 */ ldr w22, [x23], #4;
    sub_4c6c();
    sub_6ac4();
    sub_6ac4();
    sub_6e50();
    sub_6ac4();
    sub_6ac4();
    return x0;
}
