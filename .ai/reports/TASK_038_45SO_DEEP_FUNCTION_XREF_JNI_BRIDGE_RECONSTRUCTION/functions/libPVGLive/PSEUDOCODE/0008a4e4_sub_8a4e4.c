// Library: libPVGLive.so
// Function ID: libPVGLive::0x8a4e4
// Recovered Name: sub_8a4e4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x8a4e4 | Size: 60 bytes | SHA256: 89fb281314018103aede3f42a099cc35d78bc4e612c00056dec8aeacb4d9ae1a
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeVersion()Ljava/lang/String; (table at 0x9a9e0)
// Calls external APIs: _ZN7PVGLIVE7PVGLive7versionEv

jlong sub_8a4e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x8a4e4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8a4e8 */ str x19, [sp, #0x10];
    /* 0x8a4ec */ mov x29, sp;
    /* 0x8a4f0 */ mov x19, x0;
    _ZN7PVGLIVE7PVGLive7versionEv();
    /* 0x8a4f8 */ ldr x8, [x19];
    /* 0x8a4fc */ adrp x9, #0xe000;
    /* 0x8a500 */ add x9, x9, #0x82c;
    /* 0x8a504 */ cmp x0, #0;
    /* 0x8a508 */ ldr x2, [x8, #0x538];
    /* 0x8a50c */ csel x1, x9, x0, eq;
}
