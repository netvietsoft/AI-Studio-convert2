// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56d814
// Recovered Name: sub_56d814
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56d814 | Size: 52 bytes | SHA256: 71e2b45ebd4a04817ddba0fc0b2c48c0284384f9148918c3a04a27cb6b4256cb
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFoodID(JI)I (table at 0x10cd370)

jlong sub_56d814(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x56d814 */ mov w0, #-1;
    /* 0x56d818 */ cbz x2, #0x56d844;
    /* 0x56d81c */ cmp w3, #9;
    /* 0x56d820 */ b.hi #0x56d844;
    /* 0x56d824 */ mov w8, #0x34;
    /* 0x56d828 */ umaddl x8, w3, w8, x2;
    /* 0x56d82c */ ldrb w8, [x8, #0x18];
    /* 0x56d830 */ cbz w8, #0x56d844;
    /* 0x56d834 */ mov w8, w3;
    /* 0x56d838 */ mov w9, #0x34;
    /* 0x56d83c */ umaddl x8, w8, w9, x2;
    return x0;
}
