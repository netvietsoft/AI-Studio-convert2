// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x120ba4
// Recovered Name: sub_120ba4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x120ba4 | Size: 20 bytes | SHA256: dfa82c747315efd95996fc71ae4fad9c6cef3675da6018d90a54eeba5a77dc97
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: native_close(J)I (table at 0x13a718)

jlong sub_120ba4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x120ba4 */ cbz x2, #0x120bb8;
    /* 0x120ba8 */ ldr x8, [x2];
    /* 0x120bac */ mov x0, x2;
    /* 0x120bb0 */ ldr x1, [x8, #0x18];
    /* 0x120bb4 */ br x1;
}
