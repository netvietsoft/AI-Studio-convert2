// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0x806c
// Recovered Name: _ZN13MTLReportTool9InterfaceD1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x806c | Size: 56 bytes | SHA256: 84c34488594f5a40d748c3bb7943eb1a0e3cf1c864551262847a95460da5f3d8
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN13MTLReportTool9Interface4ImplD1Ev, _ZdlPv

void _ZN13MTLReportTool9InterfaceD1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x806c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8070 */ stp x20, x19, [sp, #0x10];
    /* 0x8074 */ mov x29, sp;
    /* 0x8078 */ ldr x20, [x0];
    /* 0x807c */ cbz x20, #0x8098;
    /* 0x8080 */ mov x19, x0;
    /* 0x8084 */ mov x0, x20;
    _ZN13MTLReportTool9Interface4ImplD1Ev();
    /* 0x808c */ mov x0, x20;
    _ZdlPv();
    /* 0x8094 */ str xzr, [x19];
    return x0;
}
