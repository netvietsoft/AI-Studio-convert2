// Library: libarkernel3.so
// Function ID: libarkernel3::0xa57ab8
// Recovered Name: sub_a57ab8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa57ab8 | Size: 576 bytes | SHA256: 594f83a6e27c9c8d776382ba9ceac054dfa7f68cd70b505e583420076327e234
// Callers: 0 | Callees: 8 | Imports: 5

// Calls external APIs: __stack_chk_fail, wgpuDeviceCreateTexture, wgpuTextureCreateView, wgpuTextureGetHeight, wgpuTextureGetWidth
// Strings referenced:
//   "SegmentMaskProcess"

void sub_a57ab8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 144 instructions
    /* 0xa57ab8 */ stp x29, x30, [sp, #0x70];
    /* 0xa57abc */ stp x26, x25, [sp, #0x80];
    /* 0xa57ac0 */ stp x24, x23, [sp, #0x90];
    /* 0xa57ac4 */ stp x22, x21, [sp, #0xa0];
    /* 0xa57ac8 */ stp x20, x19, [sp, #0xb0];
    /* 0xa57acc */ add x29, sp, #0x70;
    /* 0xa57ad0 */ mrs x26, tpidr_el0;
    /* 0xa57ad4 */ mov x19, x0;
    /* 0xa57ad8 */ ldr x8, [x26, #0x28];
    /* 0xa57adc */ stur x8, [x29, #-0x18];
    /* 0xa57ae0 */ ldr x0, [x0, #0x18];
    wgpuTextureGetWidth();
    wgpuTextureGetHeight();
    sub_9fdf80();
    wgpuDeviceCreateTexture();
    wgpuTextureCreateView();
    sub_a7fc40();
    sub_5aa23c();
    sub_5aa23c();
    sub_9eeacc();
    sub_9eeacc();
    sub_9ee3c4();
    sub_9ee3c4();
    sub_9ee624();
    sub_9ee3c4();
    sub_9ee3c4();
    sub_5ab304();
    return x0;
    __stack_chk_fail();
    sub_562d14();
    sub_562d14();
    sub_562d14();
}
