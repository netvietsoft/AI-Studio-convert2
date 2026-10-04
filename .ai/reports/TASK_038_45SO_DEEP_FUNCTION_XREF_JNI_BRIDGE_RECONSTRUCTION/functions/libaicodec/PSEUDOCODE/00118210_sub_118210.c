// Library: libaicodec.so
// Function ID: libaicodec::0x118210
// Recovered Name: sub_118210
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x118210 | Size: 204 bytes | SHA256: 85c11aa9d3cadf539426eced19307cdc06b19529b5e739509f9d86304ed6f515
// Callers: 0 | Callees: 0 | Imports: 4

// Dynamic Registration: native_close(J)I (table at 0x1ff248)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec13MediaRecorder5closeEv, _ZN7MMCodec13MediaRecorder6finishEb, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> native handle is null"
//   "com_meitu_media_encoder_FlyMediaRecorder_native_close"

jlong sub_118210(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x118210 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x118214 */ stp x20, x19, [sp, #0x10];
    /* 0x118218 */ mov x29, sp;
    /* 0x11821c */ cbz x2, #0x118250;
    /* 0x118220 */ mov x0, x2;
    /* 0x118224 */ mov w1, wzr;
    /* 0x118228 */ mov x19, x2;
    _ZN7MMCodec13MediaRecorder6finishEb();
    /* 0x118230 */ mov w20, w0;
    /* 0x118234 */ mov x0, x19;
    _ZN7MMCodec13MediaRecorder5closeEv();
    return x0;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
