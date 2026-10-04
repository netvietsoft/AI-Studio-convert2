// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e3280
// Recovered Name: _ZN11LayerFlowNS13LFFontInfoJNI16getFallbackPathsEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e3280 | Size: 260 bytes | SHA256: c76af3f3a59a0c009e1fb7428d60182307fe85f5c078c0596e3bad278fadf2c5
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: getFallbackPaths(J)[Ljava/lang/String; (table at 0x537f00)
// Calls external APIs: _ZN12MTImageKitNS8JniUtils15cString2jStringEP7_JNIEnvRKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE
// Strings referenced:
//   "java/lang/String"

jobject _ZN11LayerFlowNS13LFFontInfoJNI16getFallbackPathsEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 65 instructions
    /* 0x2e3280 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x2e3284 */ str x25, [sp, #0x10];
    /* 0x2e3288 */ stp x24, x23, [sp, #0x20];
    /* 0x2e328c */ stp x22, x21, [sp, #0x30];
    /* 0x2e3290 */ stp x20, x19, [sp, #0x40];
    /* 0x2e3294 */ mov x29, sp;
    /* 0x2e3298 */ ldp x10, x9, [x2, #0x38];
    /* 0x2e329c */ mov w8, #0xaaab;
    /* 0x2e32a0 */ movk w8, #0xaaaa, lsl #16;
    /* 0x2e32a4 */ adrp x1, #0x1dd000;
    /* 0x2e32a8 */ add x1, x1, #0x106;
    _ZN12MTImageKitNS8JniUtils15cString2jStringEP7_JNIEnvRKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE();
    return x0;
}
