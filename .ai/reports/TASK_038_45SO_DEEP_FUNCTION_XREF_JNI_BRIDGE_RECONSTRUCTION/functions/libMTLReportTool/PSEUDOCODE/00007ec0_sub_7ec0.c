// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0x7ec0
// Recovered Name: sub_7ec0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7ec0 | Size: 80 bytes | SHA256: f295d944bfc1844e127d7bbd7bff9a45c985fc65baafc6a626d9e1a80084fe04
// Callers: 3 | Callees: 2 | Imports: 3

// Calls external APIs: __cxa_allocate_exception, __cxa_free_exception, __cxa_throw

void sub_7ec0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x7ec0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x7ec4 */ stp x20, x19, [sp, #0x10];
    /* 0x7ec8 */ mov x29, sp;
    /* 0x7ecc */ mov x20, x0;
    /* 0x7ed0 */ mov w0, #0x10;
    __cxa_allocate_exception();
    /* 0x7ed8 */ mov x19, x0;
    /* 0x7edc */ mov x1, x20;
    sub_7f10();
    /* 0x7ee4 */ adrp x1, #0x15000;
    /* 0x7ee8 */ adrp x2, #0x15000;
    __cxa_throw();
    __cxa_free_exception();
    sub_ca4c();
}
