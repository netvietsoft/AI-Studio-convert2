// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x561738
// Recovered Name: sub_561738
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x561738 | Size: 624 bytes | SHA256: dec11674a6ef93e43ff03c4e50f3d2cf8cb96760b4bb2c6110243e61b502d031
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nativeSetBodyData(JI[F[FI)V (table at 0x10cc578)
// Calls external APIs: __android_log_print, memcpy
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::SetBodyData illegal body index"
//   "ARKernelBodyInterfaceJNI::SetBodyData too few key points"
//   "ARKernelBodyInterfaceJNI::SetBodyData too few scores"
//   "arkernel"

jlong sub_561738(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 156 instructions
    /* 0x561738 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x56173c */ str x27, [sp, #0x10];
    /* 0x561740 */ stp x26, x25, [sp, #0x20];
    /* 0x561744 */ stp x24, x23, [sp, #0x30];
    /* 0x561748 */ stp x22, x21, [sp, #0x40];
    /* 0x56174c */ stp x20, x19, [sp, #0x50];
    /* 0x561750 */ mov x29, sp;
    /* 0x561754 */ cbz x2, #0x561934;
    /* 0x561758 */ ldr w8, [x2, #0xc];
    /* 0x56175c */ cbz w8, #0x561934;
    /* 0x561760 */ tbnz w3, #0x1f, #0x5617f4;
    memcpy();
    memcpy();
    return x0;
}
