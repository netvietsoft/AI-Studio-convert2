// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0xbc5c
// Recovered Name: sub_bc5c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbc5c | Size: 20 bytes | SHA256: c420c72c6bbac48df8ff1329a9cb8e343acdc17d8d6284778993599ece1c2782
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: testLog()V (table at 0x19640)
// Calls external APIs: _ZN13VLLogMediator11getInstanceEv, _ZN13VLLogMediator8testDataEv

jlong sub_bc5c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0xbc5c */ stp x29, x30, [sp, #-0x10]!;
    /* 0xbc60 */ mov x29, sp;
    _ZN13VLLogMediator11getInstanceEv();
    /* 0xbc68 */ ldp x29, x30, [sp], #0x10;
    /* 0xbc6c */ b #0x10cf0;
}
