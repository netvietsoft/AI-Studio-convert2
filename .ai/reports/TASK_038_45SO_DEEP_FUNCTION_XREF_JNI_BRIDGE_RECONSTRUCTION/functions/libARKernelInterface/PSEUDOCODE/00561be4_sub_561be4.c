// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x561be4
// Recovered Name: sub_561be4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x561be4 | Size: 624 bytes | SHA256: ff100b16bb9f0eba669179bbf14517fb3a64b865f4fbc2832f62b3b3ee835d03
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nativeSetContourData(JI[F[FI)V (table at 0x10cc5c0)
// Calls external APIs: __android_log_print, memcpy
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::SetBodyData illegal body index"
//   "ARKernelBodyInterfaceJNI::SetBodyData too contour scores"
//   "ARKernelBodyInterfaceJNI::SetBodyData too few contour points"
//   "arkernel"

jlong sub_561be4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 156 instructions
    /* 0x561be4 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x561be8 */ str x27, [sp, #0x10];
    /* 0x561bec */ stp x26, x25, [sp, #0x20];
    /* 0x561bf0 */ stp x24, x23, [sp, #0x30];
    /* 0x561bf4 */ stp x22, x21, [sp, #0x40];
    /* 0x561bf8 */ stp x20, x19, [sp, #0x50];
    /* 0x561bfc */ mov x29, sp;
    /* 0x561c00 */ cbz x2, #0x561de0;
    /* 0x561c04 */ ldr w8, [x2, #0xc];
    /* 0x561c08 */ cbz w8, #0x561de0;
    /* 0x561c0c */ tbnz w3, #0x1f, #0x561ca0;
    memcpy();
    memcpy();
    return x0;
}
