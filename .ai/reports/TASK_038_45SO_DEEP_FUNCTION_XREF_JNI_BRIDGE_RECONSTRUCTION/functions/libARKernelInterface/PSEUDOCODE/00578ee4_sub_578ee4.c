// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x578ee4
// Recovered Name: sub_578ee4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x578ee4 | Size: 20 bytes | SHA256: f7e061edb94e1e293643256ef09ab2652aee4b6fb2ab9def79407e80ac6116b9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetPartTag(J)J (table at 0x10ce0f0)

jlong sub_578ee4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x578ee4 */ cbz x2, #0x578ef0;
    /* 0x578ee8 */ mov x0, x2;
    /* 0x578eec */ b #0x8e0dfc;
    /* 0x578ef0 */ mov x0, xzr;
    return x0;
}
