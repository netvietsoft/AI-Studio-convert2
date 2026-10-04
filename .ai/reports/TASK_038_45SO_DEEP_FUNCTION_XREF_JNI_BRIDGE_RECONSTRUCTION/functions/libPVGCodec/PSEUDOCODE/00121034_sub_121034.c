// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x121034
// Recovered Name: sub_121034
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x121034 | Size: 20 bytes | SHA256: 724e28689a556e04747e92482ceca283bc5e1ebb69b0a4b190ba4b04dc236e81
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: native_getKeyFramesNb(J)I (table at 0x13a7a8)

jlong sub_121034(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x121034 */ cbz x2, #0x121048;
    /* 0x121038 */ ldr x8, [x2];
    /* 0x12103c */ mov x0, x2;
    /* 0x121040 */ ldr x1, [x8, #0x48];
    /* 0x121044 */ br x1;
}
