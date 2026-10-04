// Library: libaicodec.so
// Function ID: libaicodec::0xce7f0
// Recovered Name: _ZN7MMCodec11AudioStreamC1EPNS_14OutMediaHandleE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xce7f0 | Size: 772 bytes | SHA256: dd324e528f36ef9d213f4ff69ab02ee3e5494b7cc4661cfd7d2c086ce8b08563
// Callers: 0 | Callees: 1 | Imports: 4

// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec16ExportStreamBaseD2Ev, __android_log_print, pthread_self
// Strings referenced:
//   "AudioStream"
//   "[%s(%d)]:> [AudioStream(%p)](%ld):> "

void _ZN7MMCodec11AudioStreamC1EPNS_14OutMediaHandleE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 193 instructions
    /* 0xce7f0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xce7f4 */ stp x20, x19, [sp, #0x10];
    /* 0xce7f8 */ mov x29, sp;
    /* 0xce7fc */ adrp x8, #0x66000;
    /* 0xce800 */ nop ;
    /* 0xce804 */ adr x9, #0x91c32;
    /* 0xce808 */ ldr q1, [x8, #0xe50];
    /* 0xce80c */ ldp q3, q4, [x9, #0x20];
    /* 0xce810 */ mov x10, #0x6400000000;
    /* 0xce814 */ add x12, x0, #0x12c;
    /* 0xce818 */ movi v0.2d, #0000000000000000;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    return x0;
    _ZN7MMCodec16ExportStreamBaseD2Ev();
    sub_1f00ec();
}
