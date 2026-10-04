// Library: libfntvcrash.so
// Function ID: libfntvcrash::0x4a50
// Recovered Name: sub_4a50
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x4a50 | Size: 120 bytes | SHA256: ab0afb9ea78927564fd272662f0a837e6b3039afa8c84a7ad579343e8af57540
// Callers: 0 | Callees: 0 | Imports: 0


void sub_4a50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0x4a50 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x4a54 */ str x21, [sp, #0x10];
    /* 0x4a58 */ stp x20, x19, [sp, #0x20];
    /* 0x4a5c */ mov x29, sp;
    /* 0x4a60 */ ldr x8, [x0];
    /* 0x4a64 */ mov x19, x2;
    /* 0x4a68 */ mov x20, x0;
    /* 0x4a6c */ mov w21, w1;
    /* 0x4a70 */ ldr x8, [x8, #0x10];
    /* 0x4a74 */ blr x8;
    /* 0x4a78 */ tbz w0, #0, #0x4ab0;
    return x0;
    return x0;
}
