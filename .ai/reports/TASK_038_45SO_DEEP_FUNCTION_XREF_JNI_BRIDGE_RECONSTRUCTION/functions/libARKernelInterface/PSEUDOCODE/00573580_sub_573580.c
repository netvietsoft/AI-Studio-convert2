// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x573580
// Recovered Name: sub_573580
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x573580 | Size: 276 bytes | SHA256: f5c01c807122047300034bc864389a426dac8f6b2072cdcd0c37bc7285282510
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetHumanBodyInfo(JIJ[F[F)V (table at 0x10cda48)

jlong sub_573580(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 69 instructions
    /* 0x573580 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x573584 */ str x23, [sp, #0x10];
    /* 0x573588 */ stp x22, x21, [sp, #0x20];
    /* 0x57358c */ stp x20, x19, [sp, #0x30];
    /* 0x573590 */ mov x29, sp;
    /* 0x573594 */ cbz x2, #0x573680;
    /* 0x573598 */ mov w8, #0xa30;
    /* 0x57359c */ sxtw x23, w3;
    /* 0x5735a0 */ mov x19, x6;
    /* 0x5735a4 */ smaddl x8, w3, w8, x2;
    /* 0x5735a8 */ mov x21, x2;
    return x0;
}
