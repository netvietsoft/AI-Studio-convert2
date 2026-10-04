// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x59ee6c
// Recovered Name: _ZN11arkernelcpp38ARKernelSlimManualPartControlInterface23SetManualSlimBodyEnableEiNS_9ParamFlagEb
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x59ee6c | Size: 20 bytes | SHA256: 093b4ad1bfb061a522977fa55c424d19666ad5f2b83c3a8d334cc40e57f6f294
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN11arkernelcpp38ARKernelSlimManualPartControlInterface23SetManualSlimBodyEnableEiNS_9ParamFlagEb(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x59ee6c */ ldr x0, [x0, #8];
    /* 0x59ee70 */ cbz x0, #0x59ee7c;
    /* 0x59ee74 */ and w3, w3, #1;
    /* 0x59ee78 */ b #0x96ec1c;
    return x0;
}
