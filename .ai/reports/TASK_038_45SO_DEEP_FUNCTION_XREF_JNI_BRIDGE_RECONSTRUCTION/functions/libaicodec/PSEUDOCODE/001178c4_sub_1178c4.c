// Library: libaicodec.so
// Function ID: libaicodec::0x1178c4
// Recovered Name: sub_1178c4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x1178c4 | Size: 176 bytes | SHA256: 404037d35efe273d91e60fafff273686d08fe06cca2d1d683214057e6cb07999
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_setEnableHardwareMode(JZ)I (table at 0x1ff1b8)
// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec13MediaRecorder21setEnableHardwareModeEb, __android_log_print
// Strings referenced:
//   "[%s(%d)]:> native handle is null"
//   "com_meitu_media_encoder_FlyMediaRecorder_native_setEnableHardwareMode"

jlong sub_1178c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x1178c4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1178c8 */ mov x29, sp;
    /* 0x1178cc */ cbz x2, #0x1178ec;
    /* 0x1178d0 */ tst w3, #0xff;
    /* 0x1178d4 */ mov x0, x2;
    /* 0x1178d8 */ cset w1, ne;
    _ZN7MMCodec13MediaRecorder21setEnableHardwareModeEb();
    /* 0x1178e0 */ mov w0, wzr;
    /* 0x1178e4 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1178ec */ adrp x8, #0x201000;
    __android_log_print();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
