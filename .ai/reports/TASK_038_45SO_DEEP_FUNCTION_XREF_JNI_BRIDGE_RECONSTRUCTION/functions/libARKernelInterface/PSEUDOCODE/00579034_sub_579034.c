// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579034
// Recovered Name: sub_579034
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579034 | Size: 20 bytes | SHA256: 36d5a898f5e4798224dd0517b8e5a8b16d14f624c5ddd5cc40feef5d898662d8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetPartID(J)I (table at 0x10ce168)

jlong sub_579034(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x579034 */ cbz x2, #0x579040;
    /* 0x579038 */ mov x0, x2;
    /* 0x57903c */ b #0x8e09b8;
    /* 0x579040 */ mov w0, wzr;
    return x0;
}
