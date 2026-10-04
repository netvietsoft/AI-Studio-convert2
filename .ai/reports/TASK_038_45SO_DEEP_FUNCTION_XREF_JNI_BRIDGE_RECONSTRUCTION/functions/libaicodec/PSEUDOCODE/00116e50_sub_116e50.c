// Library: libaicodec.so
// Function ID: libaicodec::0x116e50
// Recovered Name: sub_116e50
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x116e50 | Size: 24 bytes | SHA256: 3390a9300ee15f6a32966ce594932508667d128e30868a58dc2828f69e88de08
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setAudioOutParam(JIII)I (table at 0x1ff110)
// Calls external APIs: _ZN7MMCodec10MediaParam16setAudioOutParamEiii

jlong sub_116e50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x116e50 */ cbz x2, #0x116e68;
    /* 0x116e54 */ mov x0, x2;
    /* 0x116e58 */ mov w1, w3;
    /* 0x116e5c */ mov w2, w4;
    /* 0x116e60 */ mov w3, w5;
    /* 0x116e64 */ b #0x1f5230;
}
