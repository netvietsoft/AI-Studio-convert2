// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56d9f4
// Recovered Name: sub_56d9f4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56d9f4 | Size: 36 bytes | SHA256: 794c8fadc3961ce875a8bc17236ecb496403478cc352da00cafbd0a43390e9af
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFoodLabelScore(JIF)V (table at 0x10cd418)

jlong sub_56d9f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x56d9f4 */ cbz x2, #0x56da14;
    /* 0x56d9f8 */ cmp w3, #9;
    /* 0x56d9fc */ b.hi #0x56da14;
    /* 0x56da00 */ mov w8, #0x34;
    /* 0x56da04 */ mov w9, #1;
    /* 0x56da08 */ umaddl x8, w3, w8, x2;
    /* 0x56da0c */ strb w9, [x8, #0x44];
    /* 0x56da10 */ str s0, [x8, #0x48];
    return x0;
}
