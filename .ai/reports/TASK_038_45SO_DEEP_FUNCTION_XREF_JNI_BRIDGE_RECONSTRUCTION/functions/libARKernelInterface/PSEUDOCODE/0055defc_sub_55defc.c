// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55defc
// Recovered Name: sub_55defc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55defc | Size: 48 bytes | SHA256: e821d85e96224e55fb756081d6584f86a7acf692115af35113c0eeec12497725
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeCreateInstance()J (table at 0x10cc0b0)
// Calls external APIs: _Znwm
// Strings referenced:
//   "\U"

jlong sub_55defc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x55defc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x55df00 */ mov x29, sp;
    /* 0x55df04 */ mov w0, #0x28;
    _Znwm();
    /* 0x55df0c */ adrp x8, #0x104d000;
    /* 0x55df10 */ add x8, x8, #0x6e8;
    /* 0x55df14 */ strb wzr, [x0, #8];
    /* 0x55df18 */ str x8, [x0];
    /* 0x55df1c */ stp xzr, xzr, [x0, #0x18];
    /* 0x55df20 */ str xzr, [x0, #0x10];
    /* 0x55df24 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
