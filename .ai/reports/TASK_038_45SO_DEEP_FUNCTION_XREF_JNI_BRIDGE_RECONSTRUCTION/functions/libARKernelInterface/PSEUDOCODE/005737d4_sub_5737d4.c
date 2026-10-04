// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5737d4
// Recovered Name: sub_5737d4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5737d4 | Size: 144 bytes | SHA256: 5902ad63478ad59a958cbbe8506fafaa796b026885fadeca062333441018b7f3
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetPoseBlendShape(JI[F)V (table at 0x10cda90)
// Calls external APIs: memcpy

jlong sub_5737d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x5737d4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5737d8 */ stp x22, x21, [sp, #0x10];
    /* 0x5737dc */ stp x20, x19, [sp, #0x20];
    /* 0x5737e0 */ mov x29, sp;
    /* 0x5737e4 */ cbz x2, #0x573854;
    /* 0x5737e8 */ mov x19, x4;
    /* 0x5737ec */ cbz x4, #0x573854;
    /* 0x5737f0 */ ldr x8, [x0];
    /* 0x5737f4 */ mov x21, x2;
    /* 0x5737f8 */ mov x1, x19;
    /* 0x5737fc */ mov x2, xzr;
    memcpy();
    return x0;
}
