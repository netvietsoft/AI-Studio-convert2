// Library: libaicodec.so
// Function ID: libaicodec::0x116fe0
// Recovered Name: sub_116fe0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x116fe0 | Size: 864 bytes | SHA256: 1e95bae283dfb7ef9ebcf71b08922afa1671ed423e5de70bc4fed8ff1bfc68a8
// Callers: 0 | Callees: 0 | Imports: 6

// Dynamic Registration: native_setVideoOutParam(JIIIIII)I (table at 0x1ff140)
// Calls external APIs: _ZN7MMCodec10MediaParam11setVideoGopEi, _ZN7MMCodec10MediaParam14setVideoRotateEi, _ZN7MMCodec10MediaParam16setVideoOutParamEiii, _ZN7MMCodec10MediaParam6setFpsEi, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> native handle is null"
//   "[%s(%d)]:> setFps failed"
//   "[%s(%d)]:> setVideoGop failed"
//   "[%s(%d)]:> setVideoOutParam failed"
//   "[%s(%d)]:> setVideoRotate failed"

jlong sub_116fe0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 216 instructions
    /* 0x116fe0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x116fe4 */ str x21, [sp, #0x10];
    /* 0x116fe8 */ stp x20, x19, [sp, #0x20];
    /* 0x116fec */ mov x29, sp;
    /* 0x116ff0 */ cbz x2, #0x117054;
    /* 0x116ff4 */ mov x20, x2;
    /* 0x116ff8 */ mov x0, x2;
    /* 0x116ffc */ mov w1, w3;
    /* 0x117000 */ mov w2, w4;
    /* 0x117004 */ mov w3, w6;
    /* 0x117008 */ mov w21, w7;
    _ZN7MMCodec10MediaParam16setVideoOutParamEiii();
    _ZN7MMCodec10MediaParam6setFpsEi();
    _ZN7MMCodec10MediaParam11setVideoGopEi();
    _ZN7MMCodec10MediaParam14setVideoRotateEi();
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
    __android_log_print();
    return x0;
    __android_log_print();
    __android_log_print();
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
    return x0;
}
