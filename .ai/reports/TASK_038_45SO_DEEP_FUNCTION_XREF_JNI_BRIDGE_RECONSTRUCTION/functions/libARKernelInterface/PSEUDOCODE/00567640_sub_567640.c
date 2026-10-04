// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x567640
// Recovered Name: sub_567640
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x567640 | Size: 20 bytes | SHA256: 5880ee2ae2ff56b3c3b4ff8800721460004204c34d0c6f0cd4ef9211370cd81a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSet2DIndex(JIJ)V (table at 0x10ccc20)

jlong sub_567640(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x567640 */ cbz x2, #0x567650;
    /* 0x567644 */ mov w8, #0x88;
    /* 0x567648 */ smaddl x8, w3, w8, x2;
    /* 0x56764c */ str x4, [x8, #0x70];
    return x0;
}
