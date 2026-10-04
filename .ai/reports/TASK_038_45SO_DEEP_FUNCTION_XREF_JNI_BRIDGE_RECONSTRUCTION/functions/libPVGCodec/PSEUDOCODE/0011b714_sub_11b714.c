// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11b714
// Recovered Name: sub_11b714
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11b714 | Size: 20 bytes | SHA256: dfa82c747315efd95996fc71ae4fad9c6cef3675da6018d90a54eeba5a77dc97
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: native_close(J)I (table at 0x13a1f8)

jlong sub_11b714(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x11b714 */ cbz x2, #0x11b728;
    /* 0x11b718 */ ldr x8, [x2];
    /* 0x11b71c */ mov x0, x2;
    /* 0x11b720 */ ldr x1, [x8, #0x18];
    /* 0x11b724 */ br x1;
}
