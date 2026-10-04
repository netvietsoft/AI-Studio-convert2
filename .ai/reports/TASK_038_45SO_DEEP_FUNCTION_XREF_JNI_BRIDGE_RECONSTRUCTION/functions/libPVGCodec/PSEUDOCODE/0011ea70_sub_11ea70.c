// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11ea70
// Recovered Name: sub_11ea70
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11ea70 | Size: 12 bytes | SHA256: b9e07eeff471bf6459d50f4d28c08f533e3d623e8683ec4bd4e8372b7fb89d9c
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_abort(J)I (table at 0x13a568)
// Calls external APIs: _ZN3PVG12MediaClipper5abortEv

jlong sub_11ea70(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x11ea70 */ cbz x2, #0x11ea7c;
    /* 0x11ea74 */ mov x0, x2;
    /* 0x11ea78 */ b #0x134c10;
}
