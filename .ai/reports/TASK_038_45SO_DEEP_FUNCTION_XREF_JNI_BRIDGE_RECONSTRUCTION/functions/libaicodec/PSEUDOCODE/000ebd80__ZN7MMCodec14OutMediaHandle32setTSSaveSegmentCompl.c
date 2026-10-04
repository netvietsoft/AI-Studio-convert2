// Library: libaicodec.so
// Function ID: libaicodec::0xebd80
// Recovered Name: _ZN7MMCodec14OutMediaHandle32setTSSaveSegmentCompleteListenerENSt6__ndk18functionIFvvEEE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xebd80 | Size: 176 bytes | SHA256: 71d5d0e926e7eb8594ec201471cd1ffd0e495f07fa32cfe5fc29d3d3ff24e2dd
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN7MMCodec14OutMediaHandle32setTSSaveSegmentCompleteListenerENSt6__ndk18functionIFvvEEE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0xebd80 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xebd84 */ str x21, [sp, #0x10];
    /* 0xebd88 */ stp x20, x19, [sp, #0x20];
    /* 0xebd8c */ mov x29, sp;
    /* 0xebd90 */ mov x21, x0;
    /* 0xebd94 */ ldr x0, [x0, #0x100];
    /* 0xebd98 */ mov x20, x1;
    /* 0xebd9c */ add x19, x21, #0xe0;
    /* 0xebda0 */ str xzr, [x21, #0x100];
    /* 0xebda4 */ cmp x0, x19;
    /* 0xebda8 */ b.eq #0xebdb8;
    return x0;
    return x0;
    sub_cebc4();
}
