// Library: libPVGVideoCodec.so
// Function ID: libPVGVideoCodec::0x73400
// Recovered Name: JNI_OnUnload
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x73400 | Size: 20 bytes | SHA256: a73b75b4c6070abc9cc3018dbc66768d5f26fb359c132eb1c8b75fa8a1bfb0cd
// Callers: 0 | Callees: 0 | Imports: 0


jlong JNI_OnUnload(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x73400 */ adrp x8, #0x11a000;
    /* 0x73404 */ ldr x8, [x8, #0xd58];
    /* 0x73408 */ ldr w8, [x8];
    /* 0x7340c */ cmp w8, #6;
    /* 0x73410 */ b.gt #0x73450;
}
