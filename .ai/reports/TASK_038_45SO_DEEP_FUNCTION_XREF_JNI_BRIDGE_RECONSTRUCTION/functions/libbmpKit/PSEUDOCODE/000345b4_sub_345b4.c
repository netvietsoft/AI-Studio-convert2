// Library: libbmpKit.so
// Function ID: libbmpKit::0x345b4
// Recovered Name: sub_345b4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x345b4 | Size: 56 bytes | SHA256: 968c5dc86c87a210efe32b81812f8692e08d833e2e52c2da044d052ca4fdd426
// Callers: 0 | Callees: 0 | Imports: 0


void sub_345b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x345b4 */ stp x29, x30, [sp, #0x20];
    /* 0x345b8 */ add x29, sp, #0x20;
    /* 0x345bc */ stur x0, [x29, #-8];
    /* 0x345c0 */ str x1, [sp, #0x10];
    /* 0x345c4 */ str w2, [sp, #0xc];
    /* 0x345c8 */ ldur x0, [x29, #-8];
    /* 0x345cc */ ldr x8, [x0];
    /* 0x345d0 */ ldr x8, [x8, #0x30];
    /* 0x345d4 */ ldr x1, [sp, #0x10];
    /* 0x345d8 */ ldr w2, [sp, #0xc];
    /* 0x345dc */ blr x8;
    return x0;
}
