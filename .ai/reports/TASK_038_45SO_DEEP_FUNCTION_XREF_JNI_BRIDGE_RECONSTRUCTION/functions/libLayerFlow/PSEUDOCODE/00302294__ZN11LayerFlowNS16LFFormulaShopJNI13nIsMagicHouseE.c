// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x302294
// Recovered Name: _ZN11LayerFlowNS16LFFormulaShopJNI13nIsMagicHouseEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x302294 | Size: 28 bytes | SHA256: f9bbb14d420e1f702be044d6cbfad52b67127f5807b4433bdd779a09af90541c
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nIsMagicHouse(J)Z (table at 0x53bfb8)

jobject _ZN11LayerFlowNS16LFFormulaShopJNI13nIsMagicHouseEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x302294 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x302298 */ mov x29, sp;
    /* 0x30229c */ mov x0, x2;
    _ZNK11LayerFlowNS13LFFormulaShop12isMagicHouseEv();
    /* 0x3022a4 */ and w0, w0, #1;
    /* 0x3022a8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
