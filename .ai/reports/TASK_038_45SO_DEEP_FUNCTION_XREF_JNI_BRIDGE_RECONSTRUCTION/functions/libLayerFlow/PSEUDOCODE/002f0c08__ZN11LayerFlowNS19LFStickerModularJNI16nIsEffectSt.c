// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f0c08
// Recovered Name: _ZN11LayerFlowNS19LFStickerModularJNI16nIsEffectStickerEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f0c08 | Size: 20 bytes | SHA256: f0e8a53a8cad9a29e76b2d6ff69bd0cc604991f8db1b3c158fd5817218ee02d9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nIsEffectSticker(J)Z (table at 0x53a398)

jobject _ZN11LayerFlowNS19LFStickerModularJNI16nIsEffectStickerEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2f0c08 */ ldr x8, [x2, #0x28];
    /* 0x2f0c0c */ sub x8, x8, #0x9a8, lsl #12;
    /* 0x2f0c10 */ cmp x8, #0x9a4;
    /* 0x2f0c14 */ cset w0, eq;
    return x0;
}
