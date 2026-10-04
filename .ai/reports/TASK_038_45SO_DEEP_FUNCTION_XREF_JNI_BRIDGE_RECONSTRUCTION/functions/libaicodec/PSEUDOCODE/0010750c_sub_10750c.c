// Library: libaicodec.so
// Function ID: libaicodec::0x10750c
// Recovered Name: sub_10750c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x10750c | Size: 176 bytes | SHA256: 166c3ce35a3706e19d3df5aa85a20538b42120cb57448cf73bd0facfbf37678a
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getAudioDuration(J)D (table at 0x1fecc0)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getAudioDuration"

jlong sub_10750c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x10750c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x107510 */ mov x29, sp;
    /* 0x107514 */ cbz x2, #0x107528;
    /* 0x107518 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107520 */ ldr d0, [x0, #0x1e8];
    /* 0x107524 */ b #0x1075b4;
    /* 0x107528 */ adrp x8, #0x201000;
    /* 0x10752c */ ldr x8, [x8, #0x868];
    /* 0x107530 */ ldr w8, [x8];
    /* 0x107534 */ cmp w8, #5;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
    return x0;
}
