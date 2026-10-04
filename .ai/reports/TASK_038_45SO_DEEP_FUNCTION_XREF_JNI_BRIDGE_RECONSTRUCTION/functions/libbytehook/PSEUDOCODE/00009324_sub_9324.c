// Library: libbytehook.so
// Function ID: libbytehook::0x9324
// Recovered Name: sub_9324
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x9324 | Size: 12 bytes | SHA256: 66f53eae3612840e67bc0bd16bd3d5c651c2857bb1ab665401f4cb841b9a592e
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetDebug(Z)V (table at 0x11820)
// Calls external APIs: bytehook_set_debug

jlong sub_9324(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x9324 */ tst w2, #0xff;
    /* 0x9328 */ cset w0, ne;
    /* 0x932c */ b #0xd560;
}
