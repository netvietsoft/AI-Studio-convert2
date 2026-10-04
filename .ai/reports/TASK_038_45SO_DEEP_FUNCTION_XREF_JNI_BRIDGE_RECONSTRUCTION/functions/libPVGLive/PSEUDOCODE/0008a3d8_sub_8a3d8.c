// Library: libPVGLive.so
// Function ID: libPVGLive::0x8a3d8
// Recovered Name: sub_8a3d8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x8a3d8 | Size: 24 bytes | SHA256: a9e6762ebb0235b5447de1869a9f201ce60a6c598723be91e7ff027cdb1bb7c7
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeIsDebug()Z (table at 0x9a968)
// Calls external APIs: _ZN7PVGLIVE9PVGGlobal7isDebugEv

jlong sub_8a3d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x8a3d8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8a3dc */ mov x29, sp;
    _ZN7PVGLIVE9PVGGlobal7isDebugEv();
    /* 0x8a3e4 */ and w0, w0, #1;
    /* 0x8a3e8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
