// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc34ff8
// Recovered Name: sub_c34ff8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc34ff8 | Size: 944 bytes | SHA256: f9159fa1732975733f4501e65366343b7799e9884c377aabe2b7d16bef724748
// Callers: 1 | Callees: 2 | Imports: 0

// Strings referenced:
//   "EnableBodySegmentProcess"
//   "EnableProfileEyeOptimization"
//   "EnableSegmentFaceProcess"
//   "EnableSegmentFaceWith2p5DEffect"
//   "EnableSegmentMouthProcess"

void sub_c34ff8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 236 instructions
    /* 0xc34ff8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xc34ffc */ str x21, [sp, #0x10];
    /* 0xc35000 */ stp x20, x19, [sp, #0x20];
    /* 0xc35004 */ mov x29, sp;
    /* 0xc35008 */ ldr x8, [x1];
    /* 0xc3500c */ mov x19, x0;
    /* 0xc35010 */ mov x0, x1;
    /* 0xc35014 */ mov x20, x1;
    /* 0xc35018 */ ldr x8, [x8, #0xa8];
    /* 0xc3501c */ blr x8;
    /* 0xc35020 */ ldr x8, [x20];
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8de8();
    sub_5a8de8();
    return x0;
}
