// Library: libaicodec.so
// Function ID: libaicodec::0xceaf4
// Recovered Name: _ZN7MMCodec11AudioStreamD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xceaf4 | Size: 208 bytes | SHA256: db2fe56e8d74e25cb111e764bc7ea4e94dc9ed0611ac23ec65c115e220c0ed74
// Callers: 0 | Callees: 1 | Imports: 4

// Calls external APIs: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec16ExportStreamBaseD2Ev, __android_log_print, pthread_self
// Strings referenced:
//   "[%s(%d)]:> [AudioStream(%p)](%ld):> "
//   "~AudioStream"

void _ZN7MMCodec11AudioStreamD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 52 instructions
    /* 0xceaf4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xceaf8 */ stp x20, x19, [sp, #0x10];
    /* 0xceafc */ mov x29, sp;
    /* 0xceb00 */ adrp x8, #0x201000;
    /* 0xceb04 */ adrp x9, #0x201000;
    /* 0xceb08 */ mov x19, x0;
    /* 0xceb0c */ ldr x8, [x8, #0x868];
    /* 0xceb10 */ ldr x9, [x9, #0x860];
    /* 0xceb14 */ ldr w8, [x8];
    /* 0xceb18 */ add x9, x9, #0x10;
    /* 0xceb1c */ str x9, [x0];
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz();
    sub_cebc4();
}
