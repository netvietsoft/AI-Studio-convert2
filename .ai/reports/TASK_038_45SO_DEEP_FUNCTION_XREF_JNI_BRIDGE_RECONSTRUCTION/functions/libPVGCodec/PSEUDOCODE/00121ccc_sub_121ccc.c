// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x121ccc
// Recovered Name: sub_121ccc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x121ccc | Size: 12 bytes | SHA256: c45d7ad53baabd85c683ce149512150cc4a1644b6c7131c6b6ff4d957f8868a4
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_abort(J)I (table at 0x13a850)
// Calls external APIs: _ZN3PVG13MediaReverser5abortEv

jlong sub_121ccc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x121ccc */ cbz x2, #0x121cd8;
    /* 0x121cd0 */ mov x0, x2;
    /* 0x121cd4 */ b #0x1330a0;
}
