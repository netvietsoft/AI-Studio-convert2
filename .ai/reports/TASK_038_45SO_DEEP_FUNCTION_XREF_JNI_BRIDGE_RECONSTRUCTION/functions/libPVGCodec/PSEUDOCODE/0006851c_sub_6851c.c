// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x6851c
// Recovered Name: sub_6851c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6851c | Size: 16 bytes | SHA256: fbf85579377a2d529eaa6659a924468181af9a9f210d324ef21fdcb5d853a5df
// Callers: 2 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt6__ndk15mutexD1Ev

void sub_6851c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x6851c */ adrp x8, #0x139000;
    /* 0x68520 */ add x8, x8, #0x168;
    /* 0x68524 */ str x8, [x0], #8;
    /* 0x68528 */ b #0x1327c0;
}
