// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56e51c
// Recovered Name: sub_56e51c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56e51c | Size: 140 bytes | SHA256: 447ce855e9653d21965894ef3b7f8df9d14bf693c6eb197ab2bb6d27b84bd1f0
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativePauseSoundService(Z)V (table at 0x10cd4c0)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelGlobalInterfaceJNI::PauseSoundService: %s"
//   "arkernel"
//   "false"
//   "true"

jlong sub_56e51c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 35 instructions
    /* 0x56e51c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x56e520 */ str x19, [sp, #0x10];
    /* 0x56e524 */ mov x29, sp;
    /* 0x56e528 */ adrp x8, #0x10c5000;
    /* 0x56e52c */ mov w19, w2;
    /* 0x56e530 */ ldr x8, [x8, #0x7a8];
    /* 0x56e534 */ ldr w8, [x8];
    /* 0x56e538 */ cmp w8, #2;
    /* 0x56e53c */ b.gt #0x56e590;
    /* 0x56e540 */ adrp x8, #0x10c5000;
    /* 0x56e544 */ and w9, w19, #0xff;
    sub_5a6b20();
    __android_log_print();
}
