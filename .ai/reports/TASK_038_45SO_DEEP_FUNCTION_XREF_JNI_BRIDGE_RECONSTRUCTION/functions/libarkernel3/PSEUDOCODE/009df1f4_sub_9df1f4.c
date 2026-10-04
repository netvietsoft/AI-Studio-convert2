// Library: libarkernel3.so
// Function ID: libarkernel3::0x9df1f4
// Recovered Name: sub_9df1f4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9df1f4 | Size: 1108 bytes | SHA256: 79fc0cf902b69bf8f2ccacedb017ccadb756401bd54db755c0a6d27d6a0dd810
// Callers: 0 | Callees: 32 | Imports: 6

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, wgpuTextureGetFormat, wgpuTextureGetHeight, wgpuTextureGetWidth
// Strings referenced:
//   "StrokePart::onRenderImpl"
//   "mask texture(%d) is nullptr!"
//   "mtlabar3"
//   "onRenderImpl"
//   "segment_stroke"

void sub_9df1f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 277 instructions
    /* 0x9df1f4 */ stp x29, x30, [sp, #0x20];
    /* 0x9df1f8 */ stp x28, x27, [sp, #0x30];
    /* 0x9df1fc */ stp x26, x25, [sp, #0x40];
    /* 0x9df200 */ stp x24, x23, [sp, #0x50];
    /* 0x9df204 */ stp x22, x21, [sp, #0x60];
    /* 0x9df208 */ stp x20, x19, [sp, #0x70];
    /* 0x9df20c */ add x29, sp, #0x20;
    /* 0x9df210 */ sub sp, sp, #0x250;
    /* 0x9df214 */ mrs x22, tpidr_el0;
    /* 0x9df218 */ mov x19, x1;
    /* 0x9df21c */ mov x21, x0;
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a43064();
    sub_a576d8();
    sub_a7fc40();
    wgpuTextureGetFormat();
    wgpuTextureGetWidth();
    wgpuTextureGetHeight();
    sub_5aa23c();
    sub_a59d1c();
    sub_a59d24();
    sub_9deff4();
    sub_a6e834();
    sub_9e1ca0();
    sub_a59cc4();
    sub_a00a24();
    sub_a012b4();
    sub_a7fc40();
    sub_a82220();
    _Znwm();
    sub_a00d3c();
    sub_a012ac();
    sub_a59cf4();
    sub_a0126c();
    sub_a59cac();
    sub_a01014();
    sub_a01014();
    sub_a01014();
    sub_a6e7f4();
    sub_a01014();
    sub_9fdf90();
    sub_a0179c();
    _ZdlPv();
    sub_a00c0c();
    sub_a5a194();
    sub_a59d2c();
    sub_a6e6d0();
    sub_5ab304();
    return x0;
    sub_562d14();
    _ZdlPv();
    sub_a00c0c();
    sub_a6e6d0();
    sub_5ab304();
    sub_106b814();
    __stack_chk_fail();
}
