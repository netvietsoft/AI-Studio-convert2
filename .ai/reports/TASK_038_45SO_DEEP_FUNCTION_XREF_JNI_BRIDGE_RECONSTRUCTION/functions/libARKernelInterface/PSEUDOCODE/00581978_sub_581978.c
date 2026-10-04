// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x581978
// Recovered Name: sub_581978
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x581978 | Size: 32 bytes | SHA256: 5f127ec887143bb0651087014691620c5357a9f6f3d487a8e70817c60e89bdc3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetOnceTime(J)F (table at 0x10cf2c0)

jlong sub_581978(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x581978 */ cbz x2, #0x581990;
    /* 0x58197c */ ldr x0, [x2, #0x140];
    /* 0x581980 */ cbz x0, #0x581998;
    /* 0x581984 */ ldr x8, [x0];
    /* 0x581988 */ ldr x1, [x8, #0x30];
    /* 0x58198c */ br x1;
    /* 0x581990 */ movi d0, #0000000000000000;
    return x0;
}
