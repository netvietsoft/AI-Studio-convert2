// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5628c4
// Recovered Name: sub_5628c4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5628c4 | Size: 292 bytes | SHA256: 16bdda62aa925f92a95e3ddc81bfce56bb0ee61fa15fc53e8906b91ab3613373
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetBreastScores(JI)[F (table at 0x10cc680)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::GetBodyScores illegal index"
//   "arkernel"

jlong sub_5628c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 73 instructions
    /* 0x5628c4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5628c8 */ stp x22, x21, [sp, #0x10];
    /* 0x5628cc */ stp x20, x19, [sp, #0x20];
    /* 0x5628d0 */ mov x29, sp;
    /* 0x5628d4 */ cbz x2, #0x5629cc;
    /* 0x5628d8 */ tbnz w3, #0x1f, #0x56295c;
    /* 0x5628dc */ ldr w8, [x2, #0xc];
    /* 0x5628e0 */ cmp w8, w3;
    /* 0x5628e4 */ b.le #0x56295c;
    /* 0x5628e8 */ mov w8, #0x770;
    /* 0x5628ec */ ldr x9, [x0];
    return x0;
    sub_5a6b20();
    __android_log_print();
}
