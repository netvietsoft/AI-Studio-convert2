// Library: libbytehook.so
// Function ID: libbytehook::0x9234
// Recovered Name: sub_9234
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x9234 | Size: 56 bytes | SHA256: 29c4fc487e5666af6ff65d1a24f8754994cda50ecf47c9295a4f4feacc640c47
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeGetVersion()Ljava/lang/String; (table at 0x117a8)
// Calls external APIs: bytehook_get_version

jlong sub_9234(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x9234 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9238 */ str x19, [sp, #0x10];
    /* 0x923c */ mov x29, sp;
    /* 0x9240 */ ldr x8, [x0];
    /* 0x9244 */ mov x19, x0;
    /* 0x9248 */ ldr x0, [x8, #0x538];
    /* 0x924c */ str x0, [x29, #0x18];
    bytehook_get_version();
    /* 0x9254 */ mov x1, x0;
    /* 0x9258 */ mov x0, x19;
    /* 0x925c */ ldr x2, [x29, #0x18];
}
