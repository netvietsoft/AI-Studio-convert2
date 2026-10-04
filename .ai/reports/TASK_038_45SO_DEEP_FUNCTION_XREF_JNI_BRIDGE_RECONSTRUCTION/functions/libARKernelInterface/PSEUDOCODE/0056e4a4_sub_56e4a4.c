// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56e4a4
// Recovered Name: sub_56e4a4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56e4a4 | Size: 120 bytes | SHA256: bde356955d37a2f64ca77176d9eead3354e6f2e727c3aca474f97887e7125ffe
// Callers: 0 | Callees: 4 | Imports: 1

// Dynamic Registration: nativeStartSoundService()Z (table at 0x10cd4a8)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelGlobalInterfaceJNI::StartSoundService"
//   "arkernel"

jlong sub_56e4a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0x56e4a4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x56e4a8 */ mov x29, sp;
    /* 0x56e4ac */ adrp x8, #0x10d0000;
    /* 0x56e4b0 */ add x8, x8, #0xc30;
    /* 0x56e4b4 */ ldr w8, [x8];
    /* 0x56e4b8 */ cmp w8, #2;
    /* 0x56e4bc */ b.gt #0x56e504;
    /* 0x56e4c0 */ adrp x8, #0x1108000;
    /* 0x56e4c4 */ add x8, x8, #0x8f8;
    /* 0x56e4c8 */ ldr x8, [x8];
    /* 0x56e4cc */ cbz x8, #0x56e4ec;
    sub_5a6b20();
    __android_log_print();
    sub_55d9c4();
    sub_6061bc();
    sub_6061c0();
    return x0;
}
