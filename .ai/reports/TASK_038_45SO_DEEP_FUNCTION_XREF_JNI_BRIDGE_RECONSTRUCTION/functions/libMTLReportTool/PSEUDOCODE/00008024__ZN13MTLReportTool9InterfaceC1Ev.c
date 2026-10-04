// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0x8024
// Recovered Name: _ZN13MTLReportTool9InterfaceC1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x8024 | Size: 72 bytes | SHA256: 0629ef08a9301d23d8a671a1c144f3d0713245bf80d763bb983d369e589088bc
// Callers: 0 | Callees: 1 | Imports: 3

// Calls external APIs: _ZN13MTLReportTool9Interface4ImplC1Ev, _ZdlPv, _Znwm

void _ZN13MTLReportTool9InterfaceC1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x8024 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8028 */ stp x20, x19, [sp, #0x10];
    /* 0x802c */ mov x29, sp;
    /* 0x8030 */ mov x19, x0;
    /* 0x8034 */ str xzr, [x0];
    /* 0x8038 */ mov w0, #1;
    _Znwm();
    /* 0x8040 */ mov x20, x0;
    _ZN13MTLReportTool9Interface4ImplC1Ev();
    /* 0x8048 */ str x20, [x19];
    /* 0x804c */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_ca4c();
}
