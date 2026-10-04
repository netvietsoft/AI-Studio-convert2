// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xcd094
// Recovered Name: sub_cd094
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xcd094 | Size: 960 bytes | SHA256: aba13c85d48a9377140828586dd0cdda8c6a9ab33d0e5c6fec8aaff077d1cad6
// Callers: 0 | Callees: 3 | Imports: 5

// Calls external APIs: ScalePlane, _ZdaPv, _Znam, __android_log_print, memcpy
// Strings referenced:
//   "Error: DefocusStep::Run, data is invalid: width = %d, height = %d"
//   "FilterKernel"
//   "FocusFaculaBlur/mask.png"

void sub_cd094(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 240 instructions
    /* 0xcd094 */ stp x29, x30, [sp, #0x100];
    /* 0xcd098 */ stp x28, x27, [sp, #0x110];
    /* 0xcd09c */ stp x26, x25, [sp, #0x120];
    /* 0xcd0a0 */ stp x24, x23, [sp, #0x130];
    /* 0xcd0a4 */ stp x22, x21, [sp, #0x140];
    /* 0xcd0a8 */ stp x20, x19, [sp, #0x150];
    /* 0xcd0ac */ add x29, sp, #0x100;
    /* 0xcd0b0 */ cmp w2, #0;
    /* 0xcd0b4 */ mov w26, w2;
    /* 0xcd0b8 */ mov w21, w3;
    /* 0xcd0bc */ mrs x28, tpidr_el0;
    _ZN14MTFilterKernel13CMeituDefocusC2Ev();
    _Znam();
    memcpy();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    _Znam();
    ScalePlane();
    _ZdaPv();
    _ZN14MTFilterKernel7GLUtils14LoadImage_FileEPKcPiS3_();
    _Znam();
}
