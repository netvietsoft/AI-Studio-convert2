// Library: libaicodec.so
// Function ID: libaicodec::0xcebf8
// Recovered Name: _ZN7MMCodec11AudioStream4initEPNS_10MediaParamEi
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xcebf8 | Size: 428 bytes | SHA256: e87ab7075bf0377fc1243bee1c4b48331346f566eaa5e4350b1eeedcd67fd179
// Callers: 0 | Callees: 0 | Imports: 5

// Calls external APIs: _ZN7MMCodec10MediaParam19readInAudioSettingsEPNS_12AudioParam_tE, _ZN7MMCodec10MediaParam20readOutAudioSettingsEPNS_12AudioParam_tE, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "[%s(%d)]:> [AudioStream(%p)](%ld):> read in audio settings error!"
//   "[%s(%d)]:> [AudioStream(%p)](%ld):> read out audio settings error!"
//   "init"

void _ZN7MMCodec11AudioStream4initEPNS_10MediaParamEi(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 107 instructions
    /* 0xcebf8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xcebfc */ str x21, [sp, #0x10];
    /* 0xcec00 */ stp x20, x19, [sp, #0x20];
    /* 0xcec04 */ mov x29, sp;
    /* 0xcec08 */ mov x20, x1;
    /* 0xcec0c */ mov x19, x0;
    /* 0xcec10 */ str w2, [x0, #0x490];
    /* 0xcec14 */ add x1, x0, #0x294;
    /* 0xcec18 */ mov x0, x20;
    _ZN7MMCodec10MediaParam20readOutAudioSettingsEPNS_12AudioParam_tE();
    /* 0xcec20 */ tbnz w0, #0x1f, #0xcec44;
    _ZN7MMCodec10MediaParam19readInAudioSettingsEPNS_12AudioParam_tE();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
}
