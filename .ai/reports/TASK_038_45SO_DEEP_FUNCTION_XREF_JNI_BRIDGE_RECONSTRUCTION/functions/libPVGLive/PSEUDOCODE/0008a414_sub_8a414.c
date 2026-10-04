// Library: libPVGLive.so
// Function ID: libPVGLive::0x8a414
// Recovered Name: sub_8a414
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x8a414 | Size: 88 bytes | SHA256: 14dbcf480587245bc2d0e1927513d4960a07ba47e653739e25f07ae9aa94a267
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: nativeGetAndroidContext()Landroid/content/Context; (table at 0x9a998)
// Calls external APIs: _ZN7PVGLIVE9PVGGlobal11getInstanceEv, _ZN7PVGLIVE9PVGGlobal17getAndroidContextEv, _ZN7PVGLIVE9PVGGlobal21releaseAndroidContextEv

jlong sub_8a414(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 22 instructions
    /* 0x8a414 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8a418 */ stp x20, x19, [sp, #0x10];
    /* 0x8a41c */ mov x29, sp;
    /* 0x8a420 */ mov x20, x0;
    _ZN7PVGLIVE9PVGGlobal11getInstanceEv();
    /* 0x8a428 */ mov x19, x0;
    _ZN7PVGLIVE9PVGGlobal17getAndroidContextEv();
    /* 0x8a430 */ cbz x0, #0x8a450;
    /* 0x8a434 */ ldr x8, [x20];
    /* 0x8a438 */ mov x1, x0;
    /* 0x8a43c */ mov x0, x20;
    _ZN7PVGLIVE9PVGGlobal21releaseAndroidContextEv();
    return x0;
}
