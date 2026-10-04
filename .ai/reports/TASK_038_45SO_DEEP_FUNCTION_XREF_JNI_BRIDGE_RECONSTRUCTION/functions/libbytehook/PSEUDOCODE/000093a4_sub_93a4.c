// Library: libbytehook.so
// Function ID: libbytehook::0x93a4
// Recovered Name: sub_93a4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x93a4 | Size: 20 bytes | SHA256: 0280592179d4ad893343cc563b4cc19d6be94734a9cf757ea61bba030cd765a0
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetArch()Ljava/lang/String; (table at 0x11880)
// Strings referenced:
//   "arm64"

jlong sub_93a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x93a4 */ ldr x8, [x0];
    /* 0x93a8 */ adrp x1, #0x2000;
    /* 0x93ac */ add x1, x1, #0xac4;
    /* 0x93b0 */ ldr x2, [x8, #0x538];
    /* 0x93b4 */ br x2;
}
