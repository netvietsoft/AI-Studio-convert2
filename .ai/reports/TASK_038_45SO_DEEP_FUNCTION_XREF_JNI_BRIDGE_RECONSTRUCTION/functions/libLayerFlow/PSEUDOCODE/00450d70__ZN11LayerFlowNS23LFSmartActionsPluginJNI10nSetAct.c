// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x450d70
// Recovered Name: _ZN11LayerFlowNS23LFSmartActionsPluginJNI10nSetActionEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x450d70 | Size: 36 bytes | SHA256: 24cf35fcb3c1fbd8ecd4a061a9b1a64c884576dc798c1fb889a1f6d72cee102f
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nSetAction(JI)V (table at 0x546ae8)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "mtik_"
//   "plugin is null"

jobject _ZN11LayerFlowNS23LFSmartActionsPluginJNI10nSetActionEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x450d70 */ cbz x2, #0x450d7c;
    /* 0x450d74 */ str w3, [x2, #0x20];
    return x0;
    /* 0x450d7c */ adrp x1, #0x1e9000;
    /* 0x450d80 */ add x1, x1, #0x177;
    /* 0x450d84 */ adrp x2, #0x1d9000;
    /* 0x450d88 */ add x2, x2, #0x5a3;
    /* 0x450d8c */ mov w0, #6;
    /* 0x450d90 */ b #0x52a250;
}
