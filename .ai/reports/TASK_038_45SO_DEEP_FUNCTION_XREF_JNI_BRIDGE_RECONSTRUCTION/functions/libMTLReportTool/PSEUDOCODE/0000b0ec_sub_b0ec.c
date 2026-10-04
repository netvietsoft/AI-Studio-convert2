// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0xb0ec
// Recovered Name: sub_b0ec
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xb0ec | Size: 48 bytes | SHA256: 58e6b83a8a508fce4ed8de880f6c8ea1350d15c767c1541c594fe4059623e954
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeVersion()Ljava/lang/String; (table at 0x19598)
// Calls external APIs: _ZN13MTLReportTool9Interface7versionEv

jlong sub_b0ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0xb0ec */ stp x29, x30, [sp, #-0x20]!;
    /* 0xb0f0 */ str x19, [sp, #0x10];
    /* 0xb0f4 */ mov x29, sp;
    /* 0xb0f8 */ mov x19, x0;
    _ZN13MTLReportTool9Interface7versionEv();
    /* 0xb100 */ ldr x8, [x19];
    /* 0xb104 */ mov x1, x0;
    /* 0xb108 */ ldr x2, [x8, #0x538];
    /* 0xb10c */ mov x0, x19;
    /* 0xb110 */ ldr x19, [sp, #0x10];
    /* 0xb114 */ ldp x29, x30, [sp], #0x20;
}
