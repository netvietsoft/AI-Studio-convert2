// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579048
// Recovered Name: sub_579048
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579048 | Size: 20 bytes | SHA256: b97fe07984b583c0d57170f7236f7c9996b8983390f9eac3fd290ad0e8d90550
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetPartLayer(J)I (table at 0x10ce180)

jlong sub_579048(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x579048 */ cbz x2, #0x579054;
    /* 0x57904c */ mov x0, x2;
    /* 0x579050 */ b #0x8e09d0;
    /* 0x579054 */ mov w0, wzr;
    return x0;
}
