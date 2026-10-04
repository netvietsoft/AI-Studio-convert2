// Library: libbytehook.so
// Function ID: libbytehook::0x5640
// Recovered Name: sub_5640
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5640 | Size: 180 bytes | SHA256: 9fe393c761399a0227e32478a96ec70e00ffcaec2037b3f8b66c171292f54f7d
// Callers: 1 | Callees: 0 | Imports: 3

// Calls external APIs: free, malloc, realloc

void sub_5640(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x5640 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5644 */ str x21, [sp, #0x10];
    /* 0x5648 */ stp x20, x19, [sp, #0x20];
    /* 0x564c */ mov x29, sp;
    /* 0x5650 */ ldp x9, x8, [x0, #8];
    /* 0x5654 */ mov x19, x0;
    /* 0x5658 */ mov x20, x1;
    /* 0x565c */ cmp x9, x8;
    /* 0x5660 */ b.hs #0x5690;
    /* 0x5664 */ ldr x0, [x19];
    /* 0x5668 */ str x20, [x0, x9, lsl #3];
    return x0;
    realloc();
    free();
    malloc();
}
