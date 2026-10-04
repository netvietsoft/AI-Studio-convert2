// Library: libaicodec.so
// Function ID: libaicodec::0xceeb8
// Recovered Name: _ZN7MMCodec11AudioStream10setEncoderEi
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xceeb8 | Size: 268 bytes | SHA256: a07795b2a0ebee5c4569679d2bce2cb92bc4add4c9b8cf7f2c3eb812406c5e77
// Callers: 0 | Callees: 0 | Imports: 5

// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, __android_log_print, avcodec_find_encoder, avcodec_get_name, pthread_self
// Strings referenced:
//   "[%s(%d)]:> [AudioStream(%p)](%ld):> Cannot find codec %s"
//   "setEncoder"

void _ZN7MMCodec11AudioStream10setEncoderEi(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 67 instructions
    /* 0xceeb8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xceebc */ stp x22, x21, [sp, #0x10];
    /* 0xceec0 */ stp x20, x19, [sp, #0x20];
    /* 0xceec4 */ mov x29, sp;
    /* 0xceec8 */ mov x19, x0;
    /* 0xceecc */ mov w0, w1;
    /* 0xceed0 */ mov w20, w1;
    avcodec_find_encoder();
    /* 0xceed8 */ str x0, [x19, #0x28];
    /* 0xceedc */ cbz x0, #0xceef4;
    /* 0xceee0 */ mov w0, wzr;
    return x0;
    pthread_self();
    avcodec_get_name();
    __android_log_print();
    pthread_self();
    avcodec_get_name();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
