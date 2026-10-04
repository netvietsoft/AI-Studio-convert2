// Library: libARSPM.so
// Function ID: libARSPM::0x12cb00
// Recovered Name: _Z24ARSPMCreateSkottieHandlev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x12cb00 | Size: 64 bytes | SHA256: 97e3778b599ba805e97403341b83a38d97b778b1cd5fd78b8b560589bfc132db
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

void _Z24ARSPMCreateSkottieHandlev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x12cb00 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x12cb04 */ stp x20, x19, [sp, #0x10];
    /* 0x12cb08 */ mov x29, sp;
    /* 0x12cb0c */ mov w0, #0x10;
    _Znwm();
    /* 0x12cb14 */ mov x19, x0;
    sub_12cb40();
    /* 0x12cb1c */ mov x0, x19;
    /* 0x12cb20 */ ldp x20, x19, [sp, #0x10];
    /* 0x12cb24 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_4eccd4();
}
