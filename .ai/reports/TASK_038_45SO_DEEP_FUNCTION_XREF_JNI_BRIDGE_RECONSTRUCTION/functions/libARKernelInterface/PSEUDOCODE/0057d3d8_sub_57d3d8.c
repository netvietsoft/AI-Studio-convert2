// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d3d8
// Recovered Name: sub_57d3d8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d3d8 | Size: 16 bytes | SHA256: 3bf38c002208df13f3271c7488dd80dd47075aecd864533936921b93797c9fad
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeDestroyInstance(J)V (table at 0x10cecf0)
// Calls external APIs: _ZdlPv

jlong sub_57d3d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57d3d8 */ cbz x2, #0x57d3e4;
    /* 0x57d3dc */ mov x0, x2;
    /* 0x57d3e0 */ b #0x1046a20;
    return x0;
}
