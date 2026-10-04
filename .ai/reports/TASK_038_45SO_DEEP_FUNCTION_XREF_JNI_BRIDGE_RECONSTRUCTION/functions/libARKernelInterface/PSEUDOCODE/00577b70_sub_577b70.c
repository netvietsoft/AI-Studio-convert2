// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x577b70
// Recovered Name: sub_577b70
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x577b70 | Size: 20 bytes | SHA256: ae03a0f3f9fd78183895f85b3c15bf37f4026bdecb3cc7390bc4f278512993ba
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMemoryUsage(J)J (table at 0x10cde50)

jlong sub_577b70(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x577b70 */ cbz x2, #0x577b7c;
    /* 0x577b74 */ mov x0, x2;
    /* 0x577b78 */ b #0x57567c;
    /* 0x577b7c */ mov x0, xzr;
    return x0;
}
