// Library: libaicodec.so
// Function ID: libaicodec::0xebcd4
// Recovered Name: _ZN7MMCodec14OutMediaHandle29setTSSaveSegmentReadyListenerENSt6__ndk18functionIFvPKcEEE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xebcd4 | Size: 172 bytes | SHA256: 7a5e8338bd36b54e683b95189259f117816ae231f1e0fd1b90d8ce273b460048
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN7MMCodec14OutMediaHandle29setTSSaveSegmentReadyListenerENSt6__ndk18functionIFvPKcEEE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 43 instructions
    /* 0xebcd4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xebcd8 */ str x21, [sp, #0x10];
    /* 0xebcdc */ stp x20, x19, [sp, #0x20];
    /* 0xebce0 */ mov x29, sp;
    /* 0xebce4 */ mov x20, x0;
    /* 0xebce8 */ mov x21, x1;
    /* 0xebcec */ ldr x0, [x20, #0xd0]!;
    /* 0xebcf0 */ sub x19, x20, #0x20;
    /* 0xebcf4 */ str xzr, [x20];
    /* 0xebcf8 */ cmp x0, x19;
    /* 0xebcfc */ b.eq #0xebd0c;
    return x0;
    return x0;
    sub_cebc4();
}
