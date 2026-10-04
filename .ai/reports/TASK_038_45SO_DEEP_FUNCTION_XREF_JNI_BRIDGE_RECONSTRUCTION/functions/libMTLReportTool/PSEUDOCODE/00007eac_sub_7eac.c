// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0x7eac
// Recovered Name: sub_7eac
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7eac | Size: 20 bytes | SHA256: 278e78cc1426a29ae63edc33eeee0be808c6db5a40f5fcd08b73c55c38e7c82d
// Callers: 4 | Callees: 1 | Imports: 0

// Strings referenced:
//   "basic_string"

void sub_7eac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x7eac */ stp x29, x30, [sp, #-0x10]!;
    /* 0x7eb0 */ mov x29, sp;
    /* 0x7eb4 */ adrp x0, #0x5000;
    /* 0x7eb8 */ add x0, x0, #0x608;
    sub_7ec0();
}
