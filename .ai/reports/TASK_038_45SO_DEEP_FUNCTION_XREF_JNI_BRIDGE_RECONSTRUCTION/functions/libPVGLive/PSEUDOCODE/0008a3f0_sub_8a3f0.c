// Library: libPVGLive.so
// Function ID: libPVGLive::0x8a3f0
// Recovered Name: sub_8a3f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x8a3f0 | Size: 36 bytes | SHA256: 9a18f971b171ab87d891c8f25484b29dba5ba950ba31eb2a067e868640c4395f
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nativeSetAndroidContext(Landroid/content/Context;)I (table at 0x9a980)
// Calls external APIs: _ZN7PVGLIVE9PVGGlobal11getInstanceEv, _ZN7PVGLIVE9PVGGlobal17setAndroidContextEP8_jobject

jlong sub_8a3f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x8a3f0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8a3f4 */ str x19, [sp, #0x10];
    /* 0x8a3f8 */ mov x29, sp;
    /* 0x8a3fc */ mov x19, x2;
    _ZN7PVGLIVE9PVGGlobal11getInstanceEv();
    /* 0x8a404 */ mov x1, x19;
    /* 0x8a408 */ ldr x19, [sp, #0x10];
    /* 0x8a40c */ ldp x29, x30, [sp], #0x20;
    /* 0x8a410 */ b #0x90aa0;
}
