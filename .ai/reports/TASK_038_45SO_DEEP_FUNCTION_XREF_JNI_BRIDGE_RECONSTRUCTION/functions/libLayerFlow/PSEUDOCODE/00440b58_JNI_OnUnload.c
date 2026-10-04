// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x440b58
// Recovered Name: JNI_OnUnload
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x440b58 | Size: 24 bytes | SHA256: 93ade5d83b71a973c5c5c1a8a43958fff5750b8dbf4a84408a94c996f982f93c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "JNI_OnUnload LayerFlow.so detach from system!"
//   "mtik_"

jlong JNI_OnUnload(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x440b58 */ adrp x1, #0x1e9000;
    /* 0x440b5c */ add x1, x1, #0x177;
    /* 0x440b60 */ adrp x2, #0x1d2000;
    /* 0x440b64 */ add x2, x2, #0x58d;
    /* 0x440b68 */ mov w0, #6;
    /* 0x440b6c */ b #0x52a250;
}
