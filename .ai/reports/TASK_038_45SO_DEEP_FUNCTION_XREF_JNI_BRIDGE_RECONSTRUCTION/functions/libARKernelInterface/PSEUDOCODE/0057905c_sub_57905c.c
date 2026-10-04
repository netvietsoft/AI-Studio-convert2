// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57905c
// Recovered Name: sub_57905c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57905c | Size: 20 bytes | SHA256: 07d8a9fbc1befdba78030bb35023c79b4472a539b3cd6eaa9108a454917c000f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetPartControlLayer(J)I (table at 0x10ce198)

jlong sub_57905c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57905c */ cbz x2, #0x579068;
    /* 0x579060 */ mov x0, x2;
    /* 0x579064 */ b #0x8e09e8;
    /* 0x579068 */ mov w0, wzr;
    return x0;
}
