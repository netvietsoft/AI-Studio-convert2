// Library: libARSPM.so
// Function ID: libARSPM::0x428e38
// Recovered Name: sub_428e38
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x428e38 | Size: 1388 bytes | SHA256: 8a5002147597307e7935e735bb9e99670d7fff6244f3c76072deac7d1443aa8a
// Callers: 1 | Callees: 8 | Imports: 0

// Strings referenced:
//   "Bad code word"
//   "Frame not displayable."
//   "Incorrect keyframe parameters."
//   "Not a key frame."
//   "OK"

void sub_428e38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 347 instructions
    /* 0x428e38 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x428e3c */ str x23, [sp, #0x10];
    /* 0x428e40 */ stp x22, x21, [sp, #0x20];
    /* 0x428e44 */ stp x20, x19, [sp, #0x30];
    /* 0x428e48 */ mov x29, sp;
    /* 0x428e4c */ cbz x0, #0x4292a0;
    /* 0x428e50 */ adrp x8, #0x56000;
    /* 0x428e54 */ add x8, x8, #0x87a;
    /* 0x428e58 */ str wzr, [x0];
    /* 0x428e5c */ str x8, [x0, #8];
    /* 0x428e60 */ cbz x1, #0x428e88;
    sub_427878();
    return x0;
    sub_450244();
    sub_450348();
    sub_450348();
    sub_450348();
    sub_450348();
    sub_450348();
    sub_450348();
    sub_450348();
    sub_450490();
    sub_450348();
    sub_450490();
    sub_450348();
    sub_450490();
    sub_450348();
    sub_450490();
    sub_450348();
    sub_450490();
    sub_450348();
    sub_450490();
    sub_450348();
    sub_450490();
    sub_450348();
    sub_450490();
    sub_450348();
    sub_450348();
    sub_450348();
    sub_450348();
    sub_450348();
    sub_450348();
    return x0;
    sub_4293a4();
    sub_42953c();
    sub_42aeac();
    sub_450348();
    sub_42880c();
}
