// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56253c
// Recovered Name: sub_56253c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56253c | Size: 624 bytes | SHA256: c46c7604fd6af935a50d7b9bbc8d597e31623b9a96f7a8aa2715d34db57d903a
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nativeSetBreastData(JI[F[FI)V (table at 0x10cc650)
// Calls external APIs: __android_log_print, memcpy
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::SetBodyData illegal body index"
//   "ARKernelBodyInterfaceJNI::SetBodyData too few key points"
//   "ARKernelBodyInterfaceJNI::SetBodyData too few scores"
//   "arkernel"

jlong sub_56253c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 156 instructions
    /* 0x56253c */ stp x29, x30, [sp, #-0x60]!;
    /* 0x562540 */ str x27, [sp, #0x10];
    /* 0x562544 */ stp x26, x25, [sp, #0x20];
    /* 0x562548 */ stp x24, x23, [sp, #0x30];
    /* 0x56254c */ stp x22, x21, [sp, #0x40];
    /* 0x562550 */ stp x20, x19, [sp, #0x50];
    /* 0x562554 */ mov x29, sp;
    /* 0x562558 */ cbz x2, #0x562738;
    /* 0x56255c */ ldr w8, [x2, #0xc];
    /* 0x562560 */ cbz w8, #0x562738;
    /* 0x562564 */ tbnz w3, #0x1f, #0x5625f8;
    memcpy();
    memcpy();
    return x0;
}
