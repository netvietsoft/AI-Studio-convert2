// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x566188
// Recovered Name: sub_566188
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x566188 | Size: 20 bytes | SHA256: 6731e23750cd57511bc223bb764839f8ff3c57779ea588490238eeda83b1e568
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetReconstructTextureCoordinates(JIJ)V (table at 0x10cc8f0)

jlong sub_566188(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x566188 */ cbz x2, #0x566198;
    /* 0x56618c */ mov w8, #0x38;
    /* 0x566190 */ smaddl x8, w3, w8, x2;
    /* 0x566194 */ str x4, [x8, #0x28];
    return x0;
}
