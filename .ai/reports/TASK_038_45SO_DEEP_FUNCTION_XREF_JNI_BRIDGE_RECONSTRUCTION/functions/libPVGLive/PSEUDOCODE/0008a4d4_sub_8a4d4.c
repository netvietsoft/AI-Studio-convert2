// Library: libPVGLive.so
// Function ID: libPVGLive::0x8a4d4
// Recovered Name: sub_8a4d4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x8a4d4 | Size: 16 bytes | SHA256: 8601bc9b3a0ec331580be410e2b736f320358590d412f7e2ce77355f4a735b49
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeDestroyInstance(J)V (table at 0x9a9c8)
// Calls external APIs: _ZN7PVGLIVE7PVGLive7destroyEPS0_

jlong sub_8a4d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8a4d4 */ cbz x2, #0x8a4e0;
    /* 0x8a4d8 */ mov x0, x2;
    /* 0x8a4dc */ b #0x90b00;
    return x0;
}
