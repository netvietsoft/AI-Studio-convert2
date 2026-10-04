// Library: libbytehook.so
// Function ID: libbytehook::0x927c
// Recovered Name: sub_927c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x927c | Size: 116 bytes | SHA256: ac86b81101322ea7083248dd619b7184c2d6b6863ef2af20f80edf92c3efa844
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeAddIgnore(Ljava/lang/String;)I (table at 0x117d8)
// Calls external APIs: bytehook_add_ignore

jlong sub_927c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0x927c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x9280 */ stp x22, x21, [sp, #0x10];
    /* 0x9284 */ stp x20, x19, [sp, #0x20];
    /* 0x9288 */ mov x29, sp;
    /* 0x928c */ cbz x2, #0x92dc;
    /* 0x9290 */ ldr x8, [x0];
    /* 0x9294 */ mov x19, x2;
    /* 0x9298 */ mov x1, x2;
    /* 0x929c */ mov x2, xzr;
    /* 0x92a0 */ ldr x8, [x8, #0x548];
    /* 0x92a4 */ mov x20, x0;
    bytehook_add_ignore();
    return x0;
}
