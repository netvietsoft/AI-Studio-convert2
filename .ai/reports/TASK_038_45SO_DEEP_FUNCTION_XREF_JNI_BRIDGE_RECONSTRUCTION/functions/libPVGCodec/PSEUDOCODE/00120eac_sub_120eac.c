// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x120eac
// Recovered Name: sub_120eac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x120eac | Size: 24 bytes | SHA256: 13193267f516805c9cca73893dfd639ac671d9f909dd713498ad3b526a892c3e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: native_getKeyEntryTimestamp(JI)J (table at 0x13a778)

jlong sub_120eac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x120eac */ cbz x2, #0x120ec4;
    /* 0x120eb0 */ ldr x8, [x2];
    /* 0x120eb4 */ mov x0, x2;
    /* 0x120eb8 */ mov w1, w3;
    /* 0x120ebc */ ldr x4, [x8, #0x38];
    /* 0x120ec0 */ br x4;
}
