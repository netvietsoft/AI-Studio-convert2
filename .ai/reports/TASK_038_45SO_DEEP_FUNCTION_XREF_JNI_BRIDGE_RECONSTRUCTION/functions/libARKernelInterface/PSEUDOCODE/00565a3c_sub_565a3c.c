// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x565a3c
// Recovered Name: sub_565a3c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x565a3c | Size: 64 bytes | SHA256: a193f31806d1a8e5c9838ccc870643eb35040679f87edc96e516b2bf5b46cc23
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetErrorInfo(JI)Ljava/lang/String; (table at 0x10cc7e8)

jlong sub_565a3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x565a3c */ cbz x2, #0x565a68;
    /* 0x565a40 */ mov w8, #0x198;
    /* 0x565a44 */ ldr w9, [x2, #0xc];
    /* 0x565a48 */ nop ;
    /* 0x565a4c */ smaddl x8, w3, w8, x2;
    /* 0x565a50 */ cmp w9, w3;
    /* 0x565a54 */ adrp x9, #0x1ad000;
    /* 0x565a58 */ add x9, x9, #0x439;
    /* 0x565a5c */ add x8, x8, #0xe0;
    /* 0x565a60 */ csel x1, x9, x8, le;
    /* 0x565a64 */ b #0x565a70;
}
