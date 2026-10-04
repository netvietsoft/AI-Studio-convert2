// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11e3e8
// Recovered Name: sub_11e3e8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11e3e8 | Size: 12 bytes | SHA256: bb1bd1e592908e72143c093989189c9ec92069d3ee47e7e5cafc8768611497e4
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_getDuration(J)D (table at 0x13a520)
// Calls external APIs: _ZNK3PVG12MediaClipper11getDurationEv

jlong sub_11e3e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x11e3e8 */ cbz x2, #0x11e3f4;
    /* 0x11e3ec */ mov x0, x2;
    /* 0x11e3f0 */ b #0x134be0;
}
