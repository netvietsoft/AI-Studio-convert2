// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa61210
// Recovered Name: sub_a61210
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa61210 | Size: 356 bytes | SHA256: fbec8d85b0b495ab2324fed8d54d02e6db3eae51260998f56501564fdedaeb0a
// Callers: 0 | Callees: 3 | Imports: 0

// Strings referenced:
//   "Degree"
//   "FabbyMaskType"
//   "Level"
//   "SegmentMaskType"

void sub_a61210(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 89 instructions
    /* 0xa61210 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xa61214 */ stp x22, x21, [sp, #0x10];
    /* 0xa61218 */ stp x20, x19, [sp, #0x20];
    /* 0xa6121c */ mov x29, sp;
    /* 0xa61220 */ mov x21, x1;
    /* 0xa61224 */ mov x19, x0;
    sub_61bfa0();
    /* 0xa6122c */ mov w20, w0;
    /* 0xa61230 */ tbz w0, #0, #0xa61360;
    /* 0xa61234 */ ldr x8, [x21];
    /* 0xa61238 */ mov x0, x21;
    sub_5a8da0();
    sub_5a8d1c();
    return x0;
}
