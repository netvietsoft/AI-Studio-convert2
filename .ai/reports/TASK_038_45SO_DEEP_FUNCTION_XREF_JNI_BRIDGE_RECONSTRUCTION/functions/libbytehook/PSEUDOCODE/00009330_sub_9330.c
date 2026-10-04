// Library: libbytehook.so
// Function ID: libbytehook::0x9330
// Recovered Name: sub_9330
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x9330 | Size: 24 bytes | SHA256: 5212b6c59bb27b16c6c24e143229bb77f9173e10f8ca9751edf49bfd451f7a04
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeGetRecordable()Z (table at 0x11838)
// Calls external APIs: bytehook_get_recordable

jlong sub_9330(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x9330 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9334 */ mov x29, sp;
    bytehook_get_recordable();
    /* 0x933c */ and w0, w0, #1;
    /* 0x9340 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
