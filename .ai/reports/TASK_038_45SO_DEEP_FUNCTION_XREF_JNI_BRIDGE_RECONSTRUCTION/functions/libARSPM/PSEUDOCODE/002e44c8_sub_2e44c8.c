// Library: libARSPM.so
// Function ID: libARSPM::0x2e44c8
// Recovered Name: sub_2e44c8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e44c8 | Size: 1220 bytes | SHA256: dac5cc06c87838e3f44a662d40d9e38013511c38b34bc2e3e2de2577e622c428
// Callers: 0 | Callees: 18 | Imports: 0

// Strings referenced:
//   "Rect Blur Mask"
//   "RectBlur"
//   "integral"
//   "isFast"
//   "rect"

void sub_2e44c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 305 instructions
    /* 0x2e44c8 */ adrp x9, #0x516000;
    /* 0x2e44cc */ sub x8, x29, #0x50;
    /* 0x2e44d0 */ adrp x10, #0x63000;
    /* 0x2e44d4 */ add x10, x10, #0x21e;
    /* 0x2e44d8 */ ldr w9, [x9, #0x5d8];
    /* 0x2e44dc */ add x23, x8, #8;
    /* 0x2e44e0 */ add x0, x8, #0xc;
    /* 0x2e44e4 */ stur x23, [x29, #-0x50];
    /* 0x2e44e8 */ orr x9, x9, #0xc0000;
    /* 0x2e44ec */ stp xzr, x10, [x29, #-0x28];
    /* 0x2e44f0 */ stp wzr, w9, [x29, #-0x48];
    sub_3f2364();
    sub_172d18();
    sub_31189c();
    sub_331af0();
    sub_4ecb10();
    sub_134f28();
    sub_256820();
    sub_315de0();
    sub_4ecb10();
    sub_4ecb10();
    sub_311fa8();
    sub_4ecb10();
    sub_4ecb10();
    sub_13502c();
    sub_4ecb10();
    sub_4ecb10();
    sub_14803c();
    sub_148054();
    sub_2666f8();
    sub_2e6c40();
    sub_327904();
    sub_1726d8();
    sub_32b614();
    sub_2f17fc();
}
