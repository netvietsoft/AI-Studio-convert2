// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa9be94
// Recovered Name: sub_a9be94
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa9be94 | Size: 200 bytes | SHA256: 2e82843c5ff8ccb0f277dbbc7c6d8e62caa8fb37a2c72f4bbcaa8275b493e74e
// Callers: 0 | Callees: 1 | Imports: 0

// Strings referenced:
//   "FabbyMaskType"
//   "SegmentMaskType"

void sub_a9be94(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0xa9be94 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xa9be98 */ stp x22, x21, [sp, #0x10];
    /* 0xa9be9c */ stp x20, x19, [sp, #0x20];
    /* 0xa9bea0 */ mov x29, sp;
    /* 0xa9bea4 */ mov x21, x1;
    /* 0xa9bea8 */ mov x19, x0;
    sub_7a1fb4();
    /* 0xa9beb0 */ mov w20, w0;
    /* 0xa9beb4 */ tbz w0, #0, #0xa9bf44;
    /* 0xa9beb8 */ ldr x8, [x21];
    /* 0xa9bebc */ mov x0, x21;
    return x0;
}
