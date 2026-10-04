// Library: libaicodec.so
// Function ID: libaicodec::0x107f80
// Recovered Name: sub_107f80
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107f80 | Size: 16 bytes | SHA256: 15085c327d1e5a04f8e478d69982975585831ea9385dd551076229fce9598c37
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setDuration(JJ)J (table at 0x1fee28)
// Calls external APIs: _ZN7MMCodec13MTMediaReader11setDurationEl

jlong sub_107f80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x107f80 */ cbz x2, #0x107f90;
    /* 0x107f84 */ mov x0, x2;
    /* 0x107f88 */ mov x1, x3;
    /* 0x107f8c */ b #0x1f65f0;
}
