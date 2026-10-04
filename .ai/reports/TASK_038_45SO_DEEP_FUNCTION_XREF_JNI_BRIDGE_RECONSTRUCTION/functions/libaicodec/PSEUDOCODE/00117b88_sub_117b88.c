// Library: libaicodec.so
// Function ID: libaicodec::0x117b88
// Recovered Name: sub_117b88
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x117b88 | Size: 376 bytes | SHA256: dd0f948ef506ef3bb5cf68bcf446ce9de9521734a49d2405eb7f4d7867a08c6d
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_recordAudio(JLjava/nio/ByteBuffer;)I (table at 0x1ff200)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec13MediaRecorder11recordAudioEPhi, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> input buffer is invalid"
//   "[%s(%d)]:> native handle is null"
//   "com_meitu_media_encoder_FlyMediaRecorder_native_recordAudio"

jlong sub_117b88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 94 instructions
    /* 0x117b88 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x117b8c */ stp x22, x21, [sp, #0x10];
    /* 0x117b90 */ stp x20, x19, [sp, #0x20];
    /* 0x117b94 */ mov x29, sp;
    /* 0x117b98 */ cbz x2, #0x117bf8;
    /* 0x117b9c */ ldr x8, [x0];
    /* 0x117ba0 */ mov x1, x3;
    /* 0x117ba4 */ mov x21, x3;
    /* 0x117ba8 */ mov x19, x2;
    /* 0x117bac */ mov x22, x0;
    /* 0x117bb0 */ ldr x8, [x8, #0x738];
    __android_log_print();
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
