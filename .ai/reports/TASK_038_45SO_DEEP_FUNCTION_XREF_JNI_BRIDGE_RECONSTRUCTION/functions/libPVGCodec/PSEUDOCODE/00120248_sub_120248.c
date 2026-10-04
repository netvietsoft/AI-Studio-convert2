// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x120248
// Recovered Name: sub_120248
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x120248 | Size: 12 bytes | SHA256: 3c7ff204cb4236749a576a293657254a0cebae6ddd6c31f5e9393a7ca9309ebf
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_abort(J)I (table at 0x13a6a0)
// Calls external APIs: _ZN3PVG11MediaConcat5abortEv

jlong sub_120248(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x120248 */ cbz x2, #0x120254;
    /* 0x12024c */ mov x0, x2;
    /* 0x120250 */ b #0x132bc0;
}
