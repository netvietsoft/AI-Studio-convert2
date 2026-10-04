// Library: libMTGif.so
// Function ID: libMTGif::0x8a40
// Recovered Name: sub_8a40
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8a40 | Size: 420 bytes | SHA256: 698d45a25ffb45d48ccb4aabb540100f22f4663f36859e7cd6c7562cf905f917
// Callers: 0 | Callees: 0 | Imports: 12

// Calls external APIs: _ZN13FormatConvert18VideoFormatTranser13_ImageConvertEPP7AVFrame, _Znwm, __stack_chk_fail, av_frame_alloc, av_frame_free, av_frame_get_best_effort_timestamp, avcodec_receive_frame, avcodec_send_packet, pthread_cond_signal, pthread_cond_wait, pthread_mutex_lock, pthread_mutex_unlock

void sub_8a40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 105 instructions
    /* 0x8a40 */ stp x29, x30, [sp, #0x10];
    /* 0x8a44 */ stp x22, x21, [sp, #0x20];
    /* 0x8a48 */ stp x20, x19, [sp, #0x30];
    /* 0x8a4c */ add x29, sp, #0x10;
    /* 0x8a50 */ mrs x20, tpidr_el0;
    /* 0x8a54 */ mov x19, x0;
    /* 0x8a58 */ mov x1, xzr;
    /* 0x8a5c */ ldr x8, [x20, #0x28];
    /* 0x8a60 */ str x8, [sp, #8];
    /* 0x8a64 */ ldr x9, [x0, #0x10];
    /* 0x8a68 */ ldr w8, [x0, #0xb0];
    avcodec_send_packet();
    pthread_mutex_unlock();
    pthread_mutex_lock();
    pthread_cond_wait();
    av_frame_alloc();
    avcodec_receive_frame();
    av_frame_get_best_effort_timestamp();
    _ZN13FormatConvert18VideoFormatTranser13_ImageConvertEPP7AVFrame();
    av_frame_free();
    pthread_mutex_lock();
    _Znwm();
    pthread_mutex_unlock();
    pthread_cond_signal();
    av_frame_free();
    return x0;
    __stack_chk_fail();
}
