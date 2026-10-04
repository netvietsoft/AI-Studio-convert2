// Library: libbytehook.so
// Function ID: libbytehook::0x5b58
// Recovered Name: sub_5b58
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5b58 | Size: 48 bytes | SHA256: 20c805465b8143ce3593a3bebce62f8d691e02eee35bdbec8012782edeeacc4a
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: free

void sub_5b58(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x5b58 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x5b5c */ str x19, [sp, #0x10];
    /* 0x5b60 */ mov x29, sp;
    /* 0x5b64 */ mov x19, x0;
    /* 0x5b68 */ ldr x0, [x0, #0x10];
    free();
    /* 0x5b70 */ ldr x0, [x19, #0x20];
    free();
    /* 0x5b78 */ mov x0, x19;
    /* 0x5b7c */ ldr x19, [sp, #0x10];
    /* 0x5b80 */ ldp x29, x30, [sp], #0x20;
}
