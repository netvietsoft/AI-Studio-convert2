// Library: libbytehook.so
// Function ID: libbytehook::0x930c
// Recovered Name: sub_930c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x930c | Size: 24 bytes | SHA256: f24ef491d8f9b6e693241adc5684dd9ab0e977b02acc7cb7e5ba7e0bd0f1abb4
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeGetDebug()Z (table at 0x11808)
// Calls external APIs: bytehook_get_debug

jlong sub_930c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x930c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9310 */ mov x29, sp;
    bytehook_get_debug();
    /* 0x9318 */ and w0, w0, #1;
    /* 0x931c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
