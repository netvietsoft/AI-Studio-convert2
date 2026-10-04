// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58897c
// Recovered Name: sub_58897c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58897c | Size: 32 bytes | SHA256: 06e13db0a712d205f66a447fbaab0e34698230de2fc45a13be4b55d466f9c8de
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLineSpacing(J)F (table at 0x10cff50)

jlong sub_58897c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x58897c */ cbz x2, #0x588994;
    /* 0x588980 */ ldr x0, [x2, #0xa40];
    /* 0x588984 */ cbz x0, #0x58899c;
    /* 0x588988 */ ldr x8, [x0];
    /* 0x58898c */ ldr x1, [x8, #0x30];
    /* 0x588990 */ br x1;
    /* 0x588994 */ movi d0, #0000000000000000;
    return x0;
}
