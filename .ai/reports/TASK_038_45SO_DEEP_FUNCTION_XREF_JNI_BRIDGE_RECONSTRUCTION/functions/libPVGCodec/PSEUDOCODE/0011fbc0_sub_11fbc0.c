// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11fbc0
// Recovered Name: sub_11fbc0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11fbc0 | Size: 12 bytes | SHA256: f67582071b6c0c6dedfca3fa9aec69ff9ef9e9f103ab84eee73a0b9c6544216e
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_getDuration(J)D (table at 0x13a658)
// Calls external APIs: _ZNK3PVG11MediaConcat11getDurationEv

jlong sub_11fbc0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x11fbc0 */ cbz x2, #0x11fbcc;
    /* 0x11fbc4 */ mov x0, x2;
    /* 0x11fbc8 */ b #0x132b20;
}
