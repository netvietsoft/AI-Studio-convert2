// Library: libARSPM.so
// Function ID: libARSPM::0x2548cc
// Recovered Name: sub_2548cc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2548cc | Size: 3816 bytes | SHA256: 421c5109ae628d5c3629f25e144a9b5afd858f45a17849e0ab95853f8caa6183
// Callers: 0 | Callees: 24 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "RescaledSurfaceDrawContext"
//   "SurfaceDrawContext_GaussianBlur"

void sub_2548cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 954 instructions
    /* 0x2548cc */ ldur x8, [x29, #-0x88];
    /* 0x2548d0 */ cbz x8, #0x2548f8;
    /* 0x2548d4 */ ldur x8, [x29, #-0x80];
    /* 0x2548d8 */ ldrb w8, [x8];
    /* 0x2548dc */ cbz w8, #0x2548f8;
    sub_207b3c();
    /* 0x2548e4 */ ldr x8, [x0];
    /* 0x2548e8 */ ldp x1, x2, [x29, #-0x80];
    /* 0x2548ec */ ldur x3, [x29, #-0x70];
    /* 0x2548f0 */ ldr x8, [x8, #0x28];
    /* 0x2548f4 */ blr x8;
    return x0;
    sub_1b5ff0();
    sub_2d1ce4();
    sub_1e98c8();
    sub_31e55c();
    sub_4ecb10();
    _ZdlPv();
    sub_1756d8();
    sub_2d1ce4();
    sub_331f04();
    sub_4ecb10();
    sub_255ae8();
    sub_31e99c();
    _ZdlPv();
    sub_4eca80();
    sub_2d06f8();
    sub_4ecb10();
    _ZdlPv();
    sub_4eca80();
    sub_30103c();
    sub_4ecb10();
    sub_2d0abc();
    sub_1e98c8();
    sub_31e55c();
    sub_4ecb10();
    _ZdlPv();
    sub_256004();
    sub_31c16c();
    sub_256074();
    sub_256074();
    sub_256074();
    sub_256074();
    sub_256074();
    sub_256074();
    sub_256074();
    sub_256074();
    sub_4eca80();
    sub_4ecb10();
    sub_31e99c();
    _ZdlPv();
    sub_2561f8();
    sub_256268();
    sub_4eca80();
    sub_254778();
    sub_4ecb10();
    _ZdlPv();
    sub_4ecb10();
    sub_2562c0();
    sub_4ecb10();
    _ZdlPv();
    sub_255bcc();
    sub_4ecb10();
    _ZdlPv();
    sub_4ecb10();
    sub_255b90();
    sub_31e99c();
    _ZdlPv();
    sub_2d09d8();
}
