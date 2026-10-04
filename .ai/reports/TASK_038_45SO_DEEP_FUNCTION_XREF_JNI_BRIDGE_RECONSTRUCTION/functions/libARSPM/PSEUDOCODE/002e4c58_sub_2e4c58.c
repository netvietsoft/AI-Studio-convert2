// Library: libARSPM.so
// Function ID: libARSPM::0x2e4c58
// Recovered Name: sub_2e4c58
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e4c58 | Size: 1692 bytes | SHA256: ccc83a706f85359a1f967b51a848444f60fa0824ae6953903b96a778fbec5909
// Callers: 0 | Callees: 13 | Imports: 3

// Calls external APIs: _ZdaPv, _Znam, expf
// Strings referenced:
//   "1-D Circular Blur"

void sub_2e4c58(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 423 instructions
    /* 0x2e4c58 */ adrp x9, #0x516000;
    /* 0x2e4c5c */ add x8, sp, #0xa8;
    /* 0x2e4c60 */ adrp x10, #0x68000;
    /* 0x2e4c64 */ add x10, x10, #0x340;
    /* 0x2e4c68 */ ldr w9, [x9, #0x5dc];
    /* 0x2e4c6c */ add x24, x8, #8;
    /* 0x2e4c70 */ add x0, x8, #0xc;
    /* 0x2e4c74 */ str x24, [sp, #0xa8];
    /* 0x2e4c78 */ orr x9, x9, #0xc0000;
    /* 0x2e4c7c */ stp xzr, x10, [sp, #0xd0];
    /* 0x2e4c80 */ stp wzr, w9, [sp, #0xb0];
    sub_3f2364();
    sub_31189c();
    sub_331af0();
    sub_4ecb10();
    sub_134f28();
    sub_168208();
    sub_167f28();
    sub_135b2c();
    sub_167cb0();
    _Znam();
    expf();
    _Znam();
    expf();
    _ZdaPv();
    sub_1361ac();
    sub_315de0();
    sub_4ecb10();
    sub_4ecb10();
    sub_311fa8();
    sub_4ecb10();
    sub_4ecb10();
    sub_13502c();
}
