// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5627ac
// Recovered Name: sub_5627ac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5627ac | Size: 280 bytes | SHA256: 7e1459a2031695daa09139f2ebabade35473fdf2ede6ac12ddf622e96c6d7ffc
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetBreastPoints(JI)[F (table at 0x10cc668)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::GetBodyPoints illegal index"
//   "arkernel"

jlong sub_5627ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 70 instructions
    /* 0x5627ac */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5627b0 */ stp x22, x21, [sp, #0x10];
    /* 0x5627b4 */ stp x20, x19, [sp, #0x20];
    /* 0x5627b8 */ mov x29, sp;
    /* 0x5627bc */ cbz x2, #0x5628a8;
    /* 0x5627c0 */ tbnz w3, #0x1f, #0x562848;
    /* 0x5627c4 */ ldr w8, [x2, #0xc];
    /* 0x5627c8 */ cmp w8, w3;
    /* 0x5627cc */ b.le #0x562848;
    /* 0x5627d0 */ mov w8, #0x770;
    /* 0x5627d4 */ umaddl x8, w3, w8, x2;
    return x0;
    sub_5a6b20();
    __android_log_print();
}
