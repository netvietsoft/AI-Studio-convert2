// Library: libbytehook.so
// Function ID: libbytehook::0x926c
// Recovered Name: sub_926c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x926c | Size: 16 bytes | SHA256: e3e99a91b907924631b824d8667244ea7b31b90d1ed6988882434cf2ace8a893
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeInit(IZ)I (table at 0x117c0)
// Calls external APIs: bytehook_init

jlong sub_926c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x926c */ tst w3, #0xff;
    /* 0x9270 */ cset w1, ne;
    /* 0x9274 */ mov w0, w2;
    /* 0x9278 */ b #0xd530;
}
