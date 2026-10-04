// Library: libMTARMPM.so
// Function ID: libMTARMPM::0xa2ac
// Recovered Name: _Z16MTARMPMSetJavaVMPv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xa2ac | Size: 24 bytes | SHA256: b30758a0061885eda3ef2ba9a3f026e42b3cb9a45a0f66eca2392f8613f95ca9
// Callers: 0 | Callees: 2 | Imports: 0


void _Z16MTARMPMSetJavaVMPv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0xa2ac */ stp x29, x30, [sp, #-0x10]!;
    /* 0xa2b0 */ mov x29, sp;
    sub_11ce8();
    sub_11c78();
    /* 0xa2bc */ ldp x29, x30, [sp], #0x10;
    /* 0xa2c0 */ b #0x10294;
}
