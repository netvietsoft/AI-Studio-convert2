// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58ba38
// Recovered Name: sub_58ba38
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58ba38 | Size: 20 bytes | SHA256: 5eb5aca58c3437a663509c9718458c18fc594a462eec81194ea5eaa46222730e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentValue(JI)V (table at 0x10d07f0)

jlong sub_58ba38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58ba38 */ cbz x2, #0x58ba48;
    /* 0x58ba3c */ mov w8, #1;
    /* 0x58ba40 */ str w3, [x2, #0x94];
    /* 0x58ba44 */ strb w8, [x2, #0x70];
    return x0;
}
