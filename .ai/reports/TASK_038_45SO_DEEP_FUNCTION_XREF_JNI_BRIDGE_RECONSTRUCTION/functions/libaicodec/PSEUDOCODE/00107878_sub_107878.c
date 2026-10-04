// Library: libaicodec.so
// Function ID: libaicodec::0x107878
// Recovered Name: sub_107878
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107878 | Size: 232 bytes | SHA256: 8385652962278ee03587b06e05d007e54a8aa32882ef8ace50d0ecff8348db2d
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_getVideoCodec(J)Ljava/lang/String; (table at 0x1fed38)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> get nativeObject error"
//   "com_meitu_media_FlyMediaReader_getVideoCodec"

jlong sub_107878(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x107878 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x10787c */ str x19, [sp, #0x10];
    /* 0x107880 */ mov x29, sp;
    /* 0x107884 */ cbz x2, #0x1078b0;
    /* 0x107888 */ mov x19, x0;
    /* 0x10788c */ mov x0, x2;
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv();
    /* 0x107894 */ ldr x8, [x19];
    /* 0x107898 */ add x1, x0, #0xc4;
    /* 0x10789c */ ldr x2, [x8, #0x538];
    /* 0x1078a0 */ mov x0, x19;
    return x0;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
