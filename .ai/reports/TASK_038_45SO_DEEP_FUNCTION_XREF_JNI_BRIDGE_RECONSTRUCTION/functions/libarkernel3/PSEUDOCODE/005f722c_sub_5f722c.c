// Library: libarkernel3.so
// Function ID: libarkernel3::0x5f722c
// Recovered Name: sub_5f722c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5f722c | Size: 552 bytes | SHA256: 7cbce76324f082404e2b2cc0c2cd091a05b0a6ee983c698c540aa9b99a603812
// Callers: 5 | Callees: 11 | Imports: 4

// Calls external APIs: wgpuTextureGetFormat, wgpuTextureGetHeight, wgpuTextureGetWidth, wgpuTextureReference
// Strings referenced:
//   "commandQueue or dataResult is null"
//   "getSegmentMask"
//   "mtlabar3"
//   "segment mask(%d) texture is null"
//   "unsupported texture format"

void sub_5f722c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 138 instructions
    /* 0x5f722c */ stp x29, x30, [sp, #-0x40]!;
    /* 0x5f7230 */ str x23, [sp, #0x10];
    /* 0x5f7234 */ stp x22, x21, [sp, #0x20];
    /* 0x5f7238 */ stp x20, x19, [sp, #0x30];
    /* 0x5f723c */ mov x29, sp;
    /* 0x5f7240 */ ldr x8, [x0, #0x90];
    /* 0x5f7244 */ mov x21, x0;
    /* 0x5f7248 */ mov x0, xzr;
    /* 0x5f724c */ cbz x8, #0x5f7424;
    /* 0x5f7250 */ ldr x8, [x21, #0x98];
    /* 0x5f7254 */ cbz x8, #0x5f7424;
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c190();
    sub_a43064();
    sub_a576d8();
    wgpuTextureGetFormat();
    sub_cccfe0();
    sub_cccfe0();
    wgpuTextureReference();
    wgpuTextureGetWidth();
    wgpuTextureGetHeight();
    sub_e3ac50();
    sub_e3be50();
    sub_e3bf04();
    sub_e3bf18();
    sub_e16cc8();
    return x0;
}
