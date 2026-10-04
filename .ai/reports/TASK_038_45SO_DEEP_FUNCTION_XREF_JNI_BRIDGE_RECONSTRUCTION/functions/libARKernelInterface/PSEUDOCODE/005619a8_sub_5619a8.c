// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5619a8
// Recovered Name: sub_5619a8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5619a8 | Size: 280 bytes | SHA256: 4611fc4d69c7625f3897f9e61de9c3feccd57eb744ba8d8c29d60c4c0c569f55
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetBodyPoints(JI)[F (table at 0x10cc590)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::GetBodyPoints illegal index"
//   "arkernel"

jlong sub_5619a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 70 instructions
    /* 0x5619a8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5619ac */ stp x22, x21, [sp, #0x10];
    /* 0x5619b0 */ stp x20, x19, [sp, #0x20];
    /* 0x5619b4 */ mov x29, sp;
    /* 0x5619b8 */ cbz x2, #0x561aa4;
    /* 0x5619bc */ tbnz w3, #0x1f, #0x561a44;
    /* 0x5619c0 */ ldr w8, [x2, #0xc];
    /* 0x5619c4 */ cmp w8, w3;
    /* 0x5619c8 */ b.le #0x561a44;
    /* 0x5619cc */ mov w8, #0x770;
    /* 0x5619d0 */ umaddl x8, w3, w8, x2;
    return x0;
    sub_5a6b20();
    __android_log_print();
}
