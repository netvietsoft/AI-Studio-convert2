// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x573694
// Recovered Name: sub_573694
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x573694 | Size: 172 bytes | SHA256: 58979985b0ee2247a7991ab988875ec83437e4c1f0fd88767a5316b3b1d72f1c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetHumanBodyJointInfo(JII[F)V (table at 0x10cda60)

jlong sub_573694(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 43 instructions
    /* 0x573694 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x573698 */ str x23, [sp, #0x10];
    /* 0x57369c */ stp x22, x21, [sp, #0x20];
    /* 0x5736a0 */ stp x20, x19, [sp, #0x30];
    /* 0x5736a4 */ mov x29, sp;
    /* 0x5736a8 */ cbz x2, #0x57372c;
    /* 0x5736ac */ mov x19, x5;
    /* 0x5736b0 */ cbz x5, #0x57372c;
    /* 0x5736b4 */ ldr x8, [x0];
    /* 0x5736b8 */ mov x22, x2;
    /* 0x5736bc */ mov x1, x19;
    return x0;
}
