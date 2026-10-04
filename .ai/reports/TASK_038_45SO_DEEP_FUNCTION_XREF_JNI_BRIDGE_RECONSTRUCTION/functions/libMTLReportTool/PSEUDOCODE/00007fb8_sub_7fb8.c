// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0x7fb8
// Recovered Name: sub_7fb8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7fb8 | Size: 100 bytes | SHA256: f92e1dd49ef5ac3e2327063dc536724f476d8bc064c3e617e0a91b920da06b64
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: __cxa_atexit

void sub_7fb8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x7fb8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x7fbc */ stp x20, x19, [sp, #0x10];
    /* 0x7fc0 */ mov x29, sp;
    /* 0x7fc4 */ nop ;
    /* 0x7fc8 */ adr x19, #0x19680;
    /* 0x7fcc */ nop ;
    /* 0x7fd0 */ adr x1, #0x4f86;
    /* 0x7fd4 */ mov x0, x19;
    sub_7df0();
    /* 0x7fdc */ adrp x0, #0x15000;
    /* 0x7fe0 */ nop ;
    __cxa_atexit();
}
