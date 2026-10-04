// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x582804
// Recovered Name: sub_582804
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x582804 | Size: 32 bytes | SHA256: 385aa263ef8bbe148b312f8048f571e62096ff623c44476aa2367a432bf33c52
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetAlpha(J)F (table at 0x10cf5d8)

jlong sub_582804(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x582804 */ cbz x2, #0x58281c;
    /* 0x582808 */ ldr x0, [x2, #0x560];
    /* 0x58280c */ cbz x0, #0x582824;
    /* 0x582810 */ ldr x8, [x0];
    /* 0x582814 */ ldr x1, [x8, #0x30];
    /* 0x582818 */ br x1;
    /* 0x58281c */ movi d0, #0000000000000000;
    return x0;
}
