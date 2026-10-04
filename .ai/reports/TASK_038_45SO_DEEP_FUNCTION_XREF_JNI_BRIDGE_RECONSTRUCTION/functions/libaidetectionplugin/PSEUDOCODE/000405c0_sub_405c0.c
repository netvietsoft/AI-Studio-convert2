// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x405c0
// Recovered Name: sub_405c0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x405c0 | Size: 12 bytes | SHA256: dbddc0418d0d0875cc8884a1f23db765bc6b4e59f20b9b6d9b9883b2036ffa72
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetEnableParamsCapture(Z)V (table at 0x81de0)
// Calls external APIs: _ZN17MMDetectionPlugin23AIDetectionPluginConfig22setEnableParamsCaptureEb

jlong sub_405c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x405c0 */ tst w2, #0xff;
    /* 0x405c4 */ cset w0, ne;
    /* 0x405c8 */ b #0x79c90;
}
