// Library: libaicodec.so
// Function ID: libaicodec::0x10725c
// Recovered Name: sub_10725c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x10725c | Size: 168 bytes | SHA256: bf818a85e9f42ce76fd47f421702bc7c10b4db9019ce675b6e96d3a7daea4c1d
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_hasAudio(J)Z (table at 0x1fec60)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_hasAudio"

jlong sub_10725c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x10725c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x107260 */ mov x29, sp;
    /* 0x107264 */ cbz x2, #0x10727c;
    /* 0x107268 */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107270 */ ldrb w0, [x0, #0x1e0];
    /* 0x107274 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x10727c */ adrp x8, #0x201000;
    /* 0x107280 */ ldr x8, [x8, #0x868];
    /* 0x107284 */ ldr w8, [x8];
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
