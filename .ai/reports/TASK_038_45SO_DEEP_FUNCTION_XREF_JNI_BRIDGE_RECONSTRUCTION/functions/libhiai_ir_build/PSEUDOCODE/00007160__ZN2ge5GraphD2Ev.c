// Library: libhiai_ir_build.so
// Function ID: libhiai_ir_build::0x7160
// Recovered Name: _ZN2ge5GraphD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x7160 | Size: 20 bytes | SHA256: be50a0976e37329a5f1cacfb5856f74ec6fe67095091a378dee900f3ea0d9c1f
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN2ge5GraphD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x7160 */ adrp x8, #0xe000;
    /* 0x7164 */ ldr x8, [x8, #0x58];
    /* 0x7168 */ add x8, x8, #0x10;
    /* 0x716c */ str x8, [x0], #8;
    /* 0x7170 */ b #0x745c;
}
