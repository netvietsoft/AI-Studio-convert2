// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56ad24
// Recovered Name: sub_56ad24
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56ad24 | Size: 324 bytes | SHA256: f2976726ddef123722bfcd963604b5bb9d4ec3d52c2c151d27d58ee955498626
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetNeckPoints(JI[F)V (table at 0x10cd058)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelFaceInterface::SetNeckPoints: data len = %d , neck point count = %d"
//   "arkernel"

jlong sub_56ad24(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 81 instructions
    /* 0x56ad24 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x56ad28 */ stp x22, x21, [sp, #0x10];
    /* 0x56ad2c */ stp x20, x19, [sp, #0x20];
    /* 0x56ad30 */ mov x29, sp;
    /* 0x56ad34 */ cbz x2, #0x56ae58;
    /* 0x56ad38 */ mov w22, w3;
    /* 0x56ad3c */ cmp w3, #0x13;
    /* 0x56ad40 */ b.hi #0x56ae58;
    /* 0x56ad44 */ ldr x8, [x0];
    /* 0x56ad48 */ mov x1, x4;
    /* 0x56ad4c */ mov x19, x4;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
