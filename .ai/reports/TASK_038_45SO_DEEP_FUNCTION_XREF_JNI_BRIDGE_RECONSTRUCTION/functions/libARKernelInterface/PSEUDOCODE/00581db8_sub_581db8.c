// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x581db8
// Recovered Name: sub_581db8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x581db8 | Size: 32 bytes | SHA256: 3e2779800262363d48d4322f1081b9979c659c0cae4894dbf7328ccb4ab57c96
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetRepeatCount(J)I (table at 0x10cf3b0)

jlong sub_581db8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x581db8 */ cbz x2, #0x581dd0;
    /* 0x581dbc */ ldr x0, [x2, #0x320];
    /* 0x581dc0 */ cbz x0, #0x581dd8;
    /* 0x581dc4 */ ldr x8, [x0];
    /* 0x581dc8 */ ldr x1, [x8, #0x30];
    /* 0x581dcc */ br x1;
    /* 0x581dd0 */ mov w0, wzr;
    return x0;
}
