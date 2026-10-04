// Library: libaicodec.so
// Function ID: libaicodec::0x14fbc0
// Recovered Name: sub_14fbc0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x14fbc0 | Size: 732 bytes | SHA256: f36066aa889e73d7fa74af5312894fdfe4f09399ed3b6b2b84c2d788c3c11dc3
// Callers: 0 | Callees: 1 | Imports: 11

// Calls external APIs: _ZN7MMCodec12MMCodecFrame12allocAVFrameEv, _ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec14AICodecContext12acquireFrameEv, _ZN7MMCodec18MediaHandleContext17getAICodecContextEv, _ZN7MMCodec25MotionEffectFormatContext15_dumpCacheFrameEPNS_12MMCodecFrameEi, _ZNSt6__ndk15mutex6unlockEv, _ZdlPv, __android_log_print, av_rescale_q, pthread_self
// Strings referenced:
//   "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> %d end of %d:with:%lld:file:%lld->%lld, packet:%lld->%lld, frame:%lld->%lld"
//   "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> maybe got before segment frame %lld:> %lld, current key frame:%lld"
//   "receiveFrame"

void sub_14fbc0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 183 instructions
    /* 0x14fbc0 */ mov x2, x0;
    /* 0x14fbc4 */ mov x0, x26;
    /* 0x14fbc8 */ mov x1, x27;
    av_rescale_q();
    /* 0x14fbd0 */ str x0, [x21, #0x28];
    /* 0x14fbd4 */ b #0x14fea0;
    /* 0x14fbd8 */ ldr x8, [x1, #0x18];
    /* 0x14fbdc */ add x0, x19, #0xc8;
    /* 0x14fbe0 */ str x8, [x21, #0x30];
    /* 0x14fbe4 */ sub x8, x29, #0x20;
    sub_14a8e4();
    _ZdlPv();
    _ZNSt6__ndk15mutex6unlockEv();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv();
    _ZN7MMCodec14AICodecContext12acquireFrameEv();
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    _ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_();
    _ZN7MMCodec25MotionEffectFormatContext15_dumpCacheFrameEPNS_12MMCodecFrameEi();
}
