// Library: libaicodec.so
// Function ID: libaicodec::0x1077bc
// Recovered Name: sub_1077bc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x1077bc | Size: 12 bytes | SHA256: 6ab1d9156819443ecccd53dd85a6ee61d488261686c5be8eb6965e905f3fc8c5
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_getRotation(J)I (table at 0x1fed20)
// Calls external APIs: _ZN7MMCodec29MediaReaderWrapperGetRotationEPv

jlong sub_1077bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x1077bc */ cbz x2, #0x1077c8;
    /* 0x1077c0 */ mov x0, x2;
    /* 0x1077c4 */ b #0x1f65b0;
}
