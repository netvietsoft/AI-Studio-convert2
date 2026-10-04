// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d224
// Recovered Name: sub_57d224
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d224 | Size: 16 bytes | SHA256: 79aa87d2b8b286593b73a5cc6a74c573434f2563ac063edc7dc5b08e8e7107d9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetInterval(JI)V (table at 0x10ceca8)

jlong sub_57d224(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57d224 */ cbz x2, #0x57d230;
    /* 0x57d228 */ sxtw x8, w3;
    /* 0x57d22c */ str x8, [x2, #0x10];
    return x0;
}
