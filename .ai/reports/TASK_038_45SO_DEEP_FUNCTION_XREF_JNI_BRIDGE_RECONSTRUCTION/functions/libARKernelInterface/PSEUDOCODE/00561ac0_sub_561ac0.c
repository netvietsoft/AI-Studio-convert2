// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x561ac0
// Recovered Name: sub_561ac0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x561ac0 | Size: 292 bytes | SHA256: b14e7e180a9e7437228ba8b098e9fb24670e1207b1c55d1f7e01c7848a6c67c4
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetBodyScores(JI)[F (table at 0x10cc5a8)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::GetBodyScores illegal index"
//   "arkernel"

jlong sub_561ac0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 73 instructions
    /* 0x561ac0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x561ac4 */ stp x22, x21, [sp, #0x10];
    /* 0x561ac8 */ stp x20, x19, [sp, #0x20];
    /* 0x561acc */ mov x29, sp;
    /* 0x561ad0 */ cbz x2, #0x561bc8;
    /* 0x561ad4 */ tbnz w3, #0x1f, #0x561b58;
    /* 0x561ad8 */ ldr w8, [x2, #0xc];
    /* 0x561adc */ cmp w8, w3;
    /* 0x561ae0 */ b.le #0x561b58;
    /* 0x561ae4 */ mov w8, #0x770;
    /* 0x561ae8 */ ldr x9, [x0];
    return x0;
    sub_5a6b20();
    __android_log_print();
}
