// Library: libPVGLive.so
// Function ID: libPVGLive::0x8b8d4
// Recovered Name: sub_8b8d4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x8b8d4 | Size: 92 bytes | SHA256: b535be5fc6a14fcf215ababc6b5608cf7e9335815f464a9c7e5fea58393e4e5e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeMetadataKeyAt(JJ)Ljava/lang/String; (table at 0x9ac20)

jlong sub_8b8d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x8b8d4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8b8d8 */ str x19, [sp, #0x10];
    /* 0x8b8dc */ mov x29, sp;
    /* 0x8b8e0 */ cbz x2, #0x8b920;
    /* 0x8b8e4 */ tbnz x3, #0x3f, #0x8b920;
    /* 0x8b8e8 */ ldr x8, [x2];
    /* 0x8b8ec */ mov x19, x0;
    /* 0x8b8f0 */ mov x0, x2;
    /* 0x8b8f4 */ mov x1, x3;
    /* 0x8b8f8 */ ldr x8, [x8, #0x30];
    /* 0x8b8fc */ blr x8;
    return x0;
}
