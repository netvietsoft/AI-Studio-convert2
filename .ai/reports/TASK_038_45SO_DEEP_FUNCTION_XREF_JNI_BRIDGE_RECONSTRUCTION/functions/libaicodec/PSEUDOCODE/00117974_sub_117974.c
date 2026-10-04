// Library: libaicodec.so
// Function ID: libaicodec::0x117974
// Recovered Name: sub_117974
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x117974 | Size: 344 bytes | SHA256: 289516bfef1a265b953c91c69480c82433b85705644cb3340027a0b7213d54bf
// Callers: 0 | Callees: 0 | Imports: 5

// Dynamic Registration: native_registerEGLContext(J)I (table at 0x1ff1d0)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec13MediaRecorder10getContextEv, _ZN7MMCodec14AICodecContext18setSharedGLContextEPv, __android_log_print, eglGetCurrentContext
// Strings referenced:
//   "[%s(%d)]:> eglGetCurrentContext is null"
//   "[%s(%d)]:> native handle is null"
//   "com_meitu_media_encoder_FlyMediaRecorder_native_registerEGLContext"

jlong sub_117974(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 86 instructions
    /* 0x117974 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x117978 */ stp x20, x19, [sp, #0x10];
    /* 0x11797c */ mov x29, sp;
    /* 0x117980 */ cbz x2, #0x1179b4;
    /* 0x117984 */ mov x19, x2;
    eglGetCurrentContext();
    /* 0x11798c */ cbz x0, #0x117a40;
    /* 0x117990 */ mov x20, x0;
    /* 0x117994 */ mov x0, x19;
    _ZN7MMCodec13MediaRecorder10getContextEv();
    /* 0x11799c */ mov x1, x20;
    _ZN7MMCodec14AICodecContext18setSharedGLContextEPv();
    return x0;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
