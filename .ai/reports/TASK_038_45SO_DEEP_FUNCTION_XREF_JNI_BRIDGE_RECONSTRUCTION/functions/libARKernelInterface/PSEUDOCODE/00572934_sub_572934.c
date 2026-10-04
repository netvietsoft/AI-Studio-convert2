// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x572934
// Recovered Name: sub_572934
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x572934 | Size: 52 bytes | SHA256: 57723df257ab3b684861d8f11c49bdf3d08842de1808c633f2b09cf54cd6ceda
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetHandGesture(JI)I (table at 0x10cd8f8)

jlong sub_572934(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x572934 */ mov w0, #-1;
    /* 0x572938 */ cbz x2, #0x572964;
    /* 0x57293c */ cmp w3, #9;
    /* 0x572940 */ b.hi #0x572964;
    /* 0x572944 */ mov w8, #0xec;
    /* 0x572948 */ umaddl x8, w3, w8, x2;
    /* 0x57294c */ ldrb w8, [x8, #0x48];
    /* 0x572950 */ cbz w8, #0x572964;
    /* 0x572954 */ mov w8, w3;
    /* 0x572958 */ mov w9, #0xec;
    /* 0x57295c */ umaddl x8, w8, w9, x2;
    return x0;
}
