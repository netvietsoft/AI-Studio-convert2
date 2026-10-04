// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11f5bc
// Recovered Name: sub_11f5bc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11f5bc | Size: 12 bytes | SHA256: 11bf6876b776b92ef67fb0bc5fc94e89eaf877490ff2ff1fd377e0818f029ff2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: native_setListener(JZ)I (table at 0x13a5f8)

jlong sub_11f5bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x11f5bc */ cbz x2, #0x11f5c8;
    /* 0x11f5c0 */ mov w0, wzr;
    return x0;
}
