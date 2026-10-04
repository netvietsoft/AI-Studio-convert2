// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x687b4
// Recovered Name: sub_687b4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x687b4 | Size: 16 bytes | SHA256: 468a112520ca1e31408ec32f1faef578e42fbb7d27233214ef13635a5b5240e5
// Callers: 1 | Callees: 0 | Imports: 0


void sub_687b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x687b4 */ adrp x8, #0x139000;
    /* 0x687b8 */ add x8, x8, #0x198;
    /* 0x687bc */ stp x8, xzr, [x0];
    return x0;
}
