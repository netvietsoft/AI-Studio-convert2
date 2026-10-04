// Library: libarkernel3.so
// Function ID: libarkernel3::0x9fbfc0
// Recovered Name: sub_9fbfc0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9fbfc0 | Size: 3892 bytes | SHA256: d53f1b7517e76bcfa3c7706b115955c2c63c694603a125778c732daf3e7e1ba0
// Callers: 0 | Callees: 26 | Imports: 8

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, wgpuCommandEncoderBeginRenderPass, wgpuRenderPassEncoderEnd, wgpuTextureGetFormat, wgpuTextureGetHeight, wgpuTextureGetWidth
// Strings referenced:
//   "a_Position"
//   "a_position"
//   "a_sourceMouthUV"
//   "o""
//   "s_FaceMaskMap"

void sub_9fbfc0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 973 instructions
    /* 0x9fbfc0 */ ldr x8, [x27, #0x28];
    /* 0x9fbfc4 */ ldur x9, [x29, #-0x38];
    /* 0x9fbfc8 */ cmp x8, x9;
    /* 0x9fbfcc */ b.ne #0x9fcef0;
    /* 0x9fbfd0 */ and w0, w19, #1;
    /* 0x9fbfd4 */ add sp, sp, #0x2c0;
    /* 0x9fbfd8 */ ldp x20, x19, [sp, #0x70];
    /* 0x9fbfdc */ ldp x22, x21, [sp, #0x60];
    /* 0x9fbfe0 */ ldp x24, x23, [sp, #0x50];
    /* 0x9fbfe4 */ ldp x26, x25, [sp, #0x40];
    /* 0x9fbfe8 */ ldp x28, x27, [sp, #0x30];
    return x0;
    sub_aa29c8();
    sub_a8ad80();
    sub_aa29c8();
    sub_a8ad80();
    sub_aa29c8();
    sub_a8b058();
    sub_aa29c8();
    sub_a8ad80();
    sub_aa29c8();
    sub_a8ad80();
    sub_5bec8c();
    sub_aa29c8();
    sub_a8ad80();
    wgpuTextureGetWidth();
    wgpuTextureGetHeight();
    sub_9fbb90();
    wgpuCommandEncoderBeginRenderPass();
    sub_a036d8();
    sub_a03b10();
    sub_a69af4();
    sub_5604d4();
    sub_6960f8();
    sub_751da0();
    sub_751e10();
    _ZdlPv();
    sub_a69af4();
    sub_5604d4();
    sub_6960f8();
    sub_751da0();
    sub_751e10();
    _ZdlPv();
    sub_a0392c();
    sub_a69af4();
    sub_5604d4();
    sub_6960f8();
    sub_751da0();
    sub_751e10();
    _ZdlPv();
    sub_a0392c();
    sub_66a274();
    sub_a69af4();
    sub_5604d4();
    sub_6960f8();
    sub_751da0();
    sub_751e10();
    _ZdlPv();
    sub_a0392c();
    sub_66a274();
    sub_a69af4();
    sub_5604d4();
    sub_6960f8();
    sub_751da0();
    sub_751e10();
    _ZdlPv();
    sub_a0392c();
    sub_66a274();
    sub_a69af4();
    sub_5604d4();
    _Znwm();
    sub_66a110();
    sub_a0392c();
    sub_66a274();
    _ZdlPv();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fbc18();
    sub_9fcef4();
    sub_751824();
    sub_9fcf34();
    sub_9fcf78();
    sub_9fcf78();
    sub_751824();
    sub_751824();
    sub_a03b00();
    sub_7517c0();
    wgpuTextureGetFormat();
    sub_a0426c();
    wgpuRenderPassEncoderEnd();
    sub_66a274();
    sub_a03850();
    _ZdlPv();
    sub_6960e4();
    sub_6960e4();
    sub_6960e4();
    sub_6960e4();
    sub_6960e4();
    sub_751e10();
    sub_66a274();
    _ZdlPv();
    sub_751e10();
    _ZdlPv();
    sub_66a274();
    sub_66a274();
    sub_a03850();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
