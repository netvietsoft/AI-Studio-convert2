// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x561e54
// Recovered Name: sub_561e54
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x561e54 | Size: 280 bytes | SHA256: 2518f1bc888e6c99a7db80bb16bbbdee0ea33ac4e6df7c465321590f268c90fb
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetContourPoints(JI)[F (table at 0x10cc5d8)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::GetBodyPoints illegal index"
//   "arkernel"

jlong sub_561e54(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 70 instructions
    /* 0x561e54 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x561e58 */ stp x22, x21, [sp, #0x10];
    /* 0x561e5c */ stp x20, x19, [sp, #0x20];
    /* 0x561e60 */ mov x29, sp;
    /* 0x561e64 */ cbz x2, #0x561f50;
    /* 0x561e68 */ tbnz w3, #0x1f, #0x561ef0;
    /* 0x561e6c */ ldr w8, [x2, #0xc];
    /* 0x561e70 */ cmp w8, w3;
    /* 0x561e74 */ b.le #0x561ef0;
    /* 0x561e78 */ mov w8, #0x770;
    /* 0x561e7c */ umaddl x8, w3, w8, x2;
    return x0;
    sub_5a6b20();
    __android_log_print();
}
