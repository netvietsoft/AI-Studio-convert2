// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x562090
// Recovered Name: sub_562090
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x562090 | Size: 624 bytes | SHA256: 32524ae0647aa07523be04eb29c0c43c39643ff254331b8cc06fb3348928c937
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nativeSetNeckData(JI[F[FI)V (table at 0x10cc608)
// Calls external APIs: __android_log_print, memcpy
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::SetBodyData illegal body index"
//   "ARKernelBodyInterfaceJNI::SetBodyData too few key points"
//   "ARKernelBodyInterfaceJNI::SetBodyData too few scores"
//   "arkernel"

jlong sub_562090(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 156 instructions
    /* 0x562090 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x562094 */ str x27, [sp, #0x10];
    /* 0x562098 */ stp x26, x25, [sp, #0x20];
    /* 0x56209c */ stp x24, x23, [sp, #0x30];
    /* 0x5620a0 */ stp x22, x21, [sp, #0x40];
    /* 0x5620a4 */ stp x20, x19, [sp, #0x50];
    /* 0x5620a8 */ mov x29, sp;
    /* 0x5620ac */ cbz x2, #0x56228c;
    /* 0x5620b0 */ ldr w8, [x2, #0xc];
    /* 0x5620b4 */ cbz w8, #0x56228c;
    /* 0x5620b8 */ tbnz w3, #0x1f, #0x56214c;
    memcpy();
    memcpy();
    return x0;
}
