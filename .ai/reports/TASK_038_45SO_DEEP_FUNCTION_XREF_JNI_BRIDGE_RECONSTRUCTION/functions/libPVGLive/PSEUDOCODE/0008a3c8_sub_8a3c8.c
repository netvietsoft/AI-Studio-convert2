// Library: libPVGLive.so
// Function ID: libPVGLive::0x8a3c8
// Recovered Name: sub_8a3c8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x8a3c8 | Size: 16 bytes | SHA256: 0fba5ba983047ae45d0774063ecd5c9ec054590516cc625ecf9a33fedab7914c
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetDebug(Z)I (table at 0x9a950)
// Calls external APIs: _ZN7PVGLIVE9PVGGlobal8setDebugEb

jlong sub_8a3c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8a3c8 */ and w8, w2, #0xff;
    /* 0x8a3cc */ cmp w8, #1;
    /* 0x8a3d0 */ cset w0, eq;
    /* 0x8a3d4 */ b #0x90a90;
}
