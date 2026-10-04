// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0xb07c
// Recovered Name: sub_b07c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xb07c | Size: 64 bytes | SHA256: 325d54ac99bfcfa4b268627cafc1eef876b36c48628d8b4dd675cf4980d74608
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: nativeCreateInstance()J (table at 0x19568)
// Calls external APIs: _ZN13MTLReportTool9InterfaceC1Ev, _ZdlPv, _Znwm

jlong sub_b07c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0xb07c */ stp x29, x30, [sp, #-0x20]!;
    /* 0xb080 */ stp x20, x19, [sp, #0x10];
    /* 0xb084 */ mov x29, sp;
    /* 0xb088 */ mov w0, #8;
    _Znwm();
    /* 0xb090 */ mov x19, x0;
    _ZN13MTLReportTool9InterfaceC1Ev();
    /* 0xb098 */ mov x0, x19;
    /* 0xb09c */ ldp x20, x19, [sp, #0x10];
    /* 0xb0a0 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_ca4c();
}
