// Library: libMTGif.so
// Function ID: libMTGif::0x8670
// Recovered Name: sub_8670
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8670 | Size: 628 bytes | SHA256: 82de78dda0b5a61c8c26769a9b4d36ec2ddb9791b2b086895d93b3ad5b5212bf
// Callers: 0 | Callees: 0 | Imports: 18

// Calls external APIs: _ZN13FormatConvert18VideoFormatTranser13_ImageConvertEPP7AVFrame, _ZN13FormatConvert18VideoFormatTranser6_flushEv, _ZN13FormatConvert18VideoFormatTranser8_releaseEv, _Znwm, __stack_chk_fail, av_frame_alloc, av_frame_free, av_frame_get_best_effort_timestamp, av_packet_alloc, av_packet_free, av_packet_unref, av_read_frame, avcodec_receive_frame, avcodec_send_packet, pthread_cond_signal, pthread_cond_wait, pthread_mutex_lock, pthread_mutex_unlock

void sub_8670(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 157 instructions
    /* 0x8670 */ stp x29, x30, [sp, #0x20];
    /* 0x8674 */ stp x26, x25, [sp, #0x30];
    /* 0x8678 */ stp x24, x23, [sp, #0x40];
    /* 0x867c */ stp x22, x21, [sp, #0x50];
    /* 0x8680 */ stp x20, x19, [sp, #0x60];
    /* 0x8684 */ add x29, sp, #0x20;
    /* 0x8688 */ mrs x23, tpidr_el0;
    /* 0x868c */ ldr x8, [x23, #0x28];
    /* 0x8690 */ stur x8, [x29, #-8];
    /* 0x8694 */ cbz x0, #0x88b0;
    /* 0x8698 */ mov x19, x0;
    av_packet_alloc();
    pthread_mutex_unlock();
    pthread_mutex_lock();
    pthread_cond_wait();
    av_read_frame();
    avcodec_send_packet();
    av_packet_unref();
    av_frame_alloc();
    avcodec_receive_frame();
    av_frame_get_best_effort_timestamp();
    _ZN13FormatConvert18VideoFormatTranser13_ImageConvertEPP7AVFrame();
    pthread_mutex_lock();
    _Znwm();
    pthread_mutex_unlock();
    pthread_cond_signal();
    av_packet_unref();
    av_frame_free();
    av_packet_free();
    _ZN13FormatConvert18VideoFormatTranser6_flushEv();
    pthread_mutex_lock();
    pthread_mutex_unlock();
    pthread_cond_signal();
    _ZN13FormatConvert18VideoFormatTranser8_releaseEv();
    return x0;
    __stack_chk_fail();
}
