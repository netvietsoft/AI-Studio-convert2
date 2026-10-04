// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5659fc
// Recovered Name: sub_5659fc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5659fc | Size: 64 bytes | SHA256: 80fdd84783765832852113933dde276dc46477fa537eef44ff75d80406892d2e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetErrorParam(JI)Ljava/lang/String; (table at 0x10cc7d0)

jlong sub_5659fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x5659fc */ cbz x2, #0x565a28;
    /* 0x565a00 */ mov w8, #0x198;
    /* 0x565a04 */ ldr w9, [x2, #0xc];
    /* 0x565a08 */ nop ;
    /* 0x565a0c */ smaddl x8, w3, w8, x2;
    /* 0x565a10 */ cmp w9, w3;
    /* 0x565a14 */ adrp x9, #0x1ad000;
    /* 0x565a18 */ add x9, x9, #0x439;
    /* 0x565a1c */ add x8, x8, #0x18;
    /* 0x565a20 */ csel x1, x9, x8, le;
    /* 0x565a24 */ b #0x565a30;
}
