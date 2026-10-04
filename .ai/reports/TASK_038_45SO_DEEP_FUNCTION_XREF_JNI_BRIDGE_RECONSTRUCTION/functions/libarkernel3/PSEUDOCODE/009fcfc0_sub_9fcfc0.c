// Library: libarkernel3.so
// Function ID: libarkernel3::0x9fcfc0
// Recovered Name: sub_9fcfc0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9fcfc0 | Size: 2928 bytes | SHA256: e38122679dbd70f1d6d60d20eb4fc53e44ab40f4780f1287e2b7960428bd34bc
// Callers: 0 | Callees: 23 | Imports: 4

// Calls external APIs: _ZdlPv, wgpuCommandEncoderBeginRenderPass, wgpuRenderPassEncoderEnd, wgpuTextureGetFormat
// Strings referenced:
//   "DrawMeshToResult"
//   "a_Position"
//   "a_position"
//   "invalid Shader."
//   "invalid source texture."

void sub_9fcfc0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 732 instructions
    /* 0x9fcfc0 */ stp x29, x30, [sp, #0x10];
    /* 0x9fcfc4 */ stp x28, x27, [sp, #0x20];
    /* 0x9fcfc8 */ stp x26, x25, [sp, #0x30];
    /* 0x9fcfcc */ stp x24, x23, [sp, #0x40];
    /* 0x9fcfd0 */ stp x22, x21, [sp, #0x50];
    /* 0x9fcfd4 */ stp x20, x19, [sp, #0x60];
    /* 0x9fcfd8 */ add x29, sp, #0x10;
    /* 0x9fcfdc */ sub sp, sp, #0x250;
    /* 0x9fcfe0 */ mrs x20, tpidr_el0;
    /* 0x9fcfe4 */ mov x21, x7;
    /* 0x9fcfe8 */ mov w24, w6;
    sub_9fba8c();
    sub_cccfe0();
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
}
