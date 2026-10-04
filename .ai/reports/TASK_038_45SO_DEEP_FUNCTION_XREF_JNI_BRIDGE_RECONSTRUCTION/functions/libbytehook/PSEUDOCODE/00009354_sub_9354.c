// Library: libbytehook.so
// Function ID: libbytehook::0x9354
// Recovered Name: sub_9354
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x9354 | Size: 80 bytes | SHA256: 3a0aa547de704b6001e03ad76e039ce1f3f6cfb63e733cec95d2031827a865f8
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nativeGetRecords(I)Ljava/lang/String; (table at 0x11868)
// Calls external APIs: bytehook_get_records, free

jlong sub_9354(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x9354 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9358 */ stp x20, x19, [sp, #0x10];
    /* 0x935c */ mov x29, sp;
    /* 0x9360 */ mov x20, x0;
    /* 0x9364 */ mov w0, w2;
    bytehook_get_records();
    /* 0x936c */ cbz x0, #0x9398;
    /* 0x9370 */ ldr x8, [x20];
    /* 0x9374 */ mov x19, x0;
    /* 0x9378 */ mov x0, x20;
    /* 0x937c */ mov x1, x19;
    free();
    return x0;
}
