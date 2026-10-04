// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x567690
// Recovered Name: sub_567690
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x567690 | Size: 20 bytes | SHA256: 2a0a713b52df3b83446c95ec33bc464bdc2d0244597735230fed758b69acf2b4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetMatToNDC(JIJ)V (table at 0x10ccba8)

jlong sub_567690(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x567690 */ cbz x2, #0x5676a0;
    /* 0x567694 */ mov w8, #0x88;
    /* 0x567698 */ smaddl x8, w3, w8, x2;
    /* 0x56769c */ str x4, [x8, #0x58];
    return x0;
}
