// Library: libaicodec.so
// Function ID: libaicodec::0x106d8c
// Recovered Name: sub_106d8c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x106d8c | Size: 400 bytes | SHA256: 88dfed11938fe58be4bc70949684855cc141ff73f838c6dc767c1d9d5019383b
// Callers: 0 | Callees: 1 | Imports: 10

// Dynamic Registration: native_open(JLjava/lang/String;)J (table at 0x1febd0)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec13MTMediaReader17setAICodecContextEPNS_14AICodecContextE, _ZN7MMCodec13MTMediaReader4openEv, _ZN7MMCodec13MTMediaReaderC1EPKcPKhm, _ZN7MMCodec13MTMediaReaderD1Ev, _ZN7MMCodec14AICodecContextC1Ev, _ZN7MMCodec6AVIRef7releaseEv, _ZdlPv, _Znwm, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> open media file : %s failed"
//   "com_meitu_media_FlyMediaReader_open"

jlong sub_106d8c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 100 instructions
    /* 0x106d8c */ stp x29, x30, [sp, #-0x40]!;
    /* 0x106d90 */ str x23, [sp, #0x10];
    /* 0x106d94 */ stp x22, x21, [sp, #0x20];
    /* 0x106d98 */ stp x20, x19, [sp, #0x30];
    /* 0x106d9c */ mov x29, sp;
    /* 0x106da0 */ mov x19, x3;
    /* 0x106da4 */ mov x20, x0;
    /* 0x106da8 */ cbz x2, #0x106dc0;
    /* 0x106dac */ mov x0, x2;
    /* 0x106db0 */ mov x21, x2;
    _ZN7MMCodec13MTMediaReaderD1Ev();
    _ZdlPv();
    _Znwm();
    _ZN7MMCodec13MTMediaReaderC1EPKcPKhm();
    _Znwm();
    _ZN7MMCodec14AICodecContextC1Ev();
    _ZN7MMCodec13MTMediaReader17setAICodecContextEPNS_14AICodecContextE();
    _ZN7MMCodec6AVIRef7releaseEv();
    _ZN7MMCodec13MTMediaReader4openEv();
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    _ZN7MMCodec13MTMediaReaderD1Ev();
    _ZdlPv();
    return x0;
    _ZdlPv();
    sub_1f00ec();
    _ZdlPv();
    sub_1f00ec();
}
