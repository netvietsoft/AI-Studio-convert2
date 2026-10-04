// Library: libaicodec.so
// Function ID: libaicodec::0x117d00
// Recovered Name: sub_117d00
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x117d00 | Size: 176 bytes | SHA256: b0a234cf546fddbd7e73bdff47d23bf7aaf5a42da28b9b96e7e066a2d2c80699
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_setEnableAsyncSendVideo(JZ)I (table at 0x1ff218)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec13MediaRecorder20enableAsyncSendVideoEb, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> native handle is null"
//   "com_meitu_media_encoder_FlyMediaRecorder_native_setEnableAsyncSendVideo"

jlong sub_117d00(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x117d00 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x117d04 */ mov x29, sp;
    /* 0x117d08 */ cbz x2, #0x117d28;
    /* 0x117d0c */ tst w3, #0xff;
    /* 0x117d10 */ mov x0, x2;
    /* 0x117d14 */ cset w1, ne;
    _ZN7MMCodec13MediaRecorder20enableAsyncSendVideoEb();
    /* 0x117d1c */ mov w0, wzr;
    /* 0x117d20 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x117d28 */ adrp x8, #0x201000;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
