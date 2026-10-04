// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e6418
// Recovered Name: _ZN11LayerFlowNS18LFImageWithPathJNI8nGetPathEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e6418 | Size: 56 bytes | SHA256: 7ef57a5e19b187995421b13dd05e272d8f57c9e3d723b24135cd828a94b34c58
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetPath(J)Ljava/lang/String; (table at 0x538338)

jobject _ZN11LayerFlowNS18LFImageWithPathJNI8nGetPathEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x2e6418 */ cbz x2, #0x2e643c;
    /* 0x2e641c */ ldrb w8, [x2, #0x10];
    /* 0x2e6420 */ ldr x10, [x0];
    /* 0x2e6424 */ add x11, x2, #0x11;
    /* 0x2e6428 */ ldr x9, [x2, #0x20];
    /* 0x2e642c */ tst w8, #1;
    /* 0x2e6430 */ ldr x2, [x10, #0x538];
    /* 0x2e6434 */ csel x1, x11, x9, eq;
    /* 0x2e6438 */ br x2;
    /* 0x2e643c */ ldr x8, [x0];
    /* 0x2e6440 */ adrp x1, #0x1d5000;
}
