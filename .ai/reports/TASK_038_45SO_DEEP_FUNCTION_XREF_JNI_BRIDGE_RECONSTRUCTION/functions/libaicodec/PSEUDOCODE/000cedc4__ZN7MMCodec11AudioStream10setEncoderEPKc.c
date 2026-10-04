// Library: libaicodec.so
// Function ID: libaicodec::0xcedc4
// Recovered Name: _ZN7MMCodec11AudioStream10setEncoderEPKc
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xcedc4 | Size: 244 bytes | SHA256: 3c56849c800ca34e010f06b7df90825f4828e146295e416dffc6a9ecbe56579a
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, __android_log_print, avcodec_find_encoder_by_name, pthread_self
// Strings referenced:
//   "[%s(%d)]:> [AudioStream(%p)](%ld):> Cannot find codec %s"
//   "setEncoder"

void _ZN7MMCodec11AudioStream10setEncoderEPKc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 61 instructions
    /* 0xcedc4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xcedc8 */ str x21, [sp, #0x10];
    /* 0xcedcc */ stp x20, x19, [sp, #0x20];
    /* 0xcedd0 */ mov x29, sp;
    /* 0xcedd4 */ mov x20, x0;
    /* 0xcedd8 */ mov x0, x1;
    /* 0xceddc */ mov x19, x1;
    avcodec_find_encoder_by_name();
    /* 0xcede4 */ str x0, [x20, #0x28];
    /* 0xcede8 */ cbz x0, #0xcee00;
    /* 0xcedec */ mov w0, wzr;
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
