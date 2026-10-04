// Library: libbytehook.so
// Function ID: libbytehook::0x9348
// Recovered Name: sub_9348
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x9348 | Size: 12 bytes | SHA256: 510b623d23ff93b0a04b95d73f5bdfe7a9379f7f919a9fc05ab888e712ad9c95
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetRecordable(Z)V (table at 0x11850)
// Calls external APIs: bytehook_set_recordable

jlong sub_9348(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x9348 */ tst w2, #0xff;
    /* 0x934c */ cset w0, ne;
    /* 0x9350 */ b #0xd580;
}
