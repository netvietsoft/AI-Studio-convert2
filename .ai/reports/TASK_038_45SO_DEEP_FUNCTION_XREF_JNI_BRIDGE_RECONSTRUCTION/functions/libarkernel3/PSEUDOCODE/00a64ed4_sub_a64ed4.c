// Library: libarkernel3.so
// Function ID: libarkernel3::0xa64ed4
// Recovered Name: sub_a64ed4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa64ed4 | Size: 1584 bytes | SHA256: 72ac2d56edc2ccc40a1cc406ecf5f5f9a38e9ceb152eb7d86566374edc4041d1
// Callers: 1 | Callees: 20 | Imports: 10

// Calls external APIs: _ZdlPv, __stack_chk_fail, memset, wgpuBindGroupRelease, wgpuDeviceCreateRenderPipeline, wgpuRenderPassEncoderDrawIndexed, wgpuRenderPassEncoderSetBindGroup, wgpuRenderPassEncoderSetIndexBuffer, wgpuRenderPassEncoderSetPipeline, wgpuRenderPassEncoderSetVertexBuffer
// Strings referenced:
//   "a_color"
//   "a_position"
//   "a_texCoord"
//   "encode"
//   "main"

void sub_a64ed4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 396 instructions
    /* 0xa64ed4 */ stp x29, x30, [sp, #-0x60]!;
    /* 0xa64ed8 */ stp x28, x27, [sp, #0x10];
    /* 0xa64edc */ stp x26, x25, [sp, #0x20];
    /* 0xa64ee0 */ stp x24, x23, [sp, #0x30];
    /* 0xa64ee4 */ stp x22, x21, [sp, #0x40];
    /* 0xa64ee8 */ stp x20, x19, [sp, #0x50];
    /* 0xa64eec */ mov x29, sp;
    /* 0xa64ef0 */ sub sp, sp, #0x270;
    /* 0xa64ef4 */ mrs x23, tpidr_el0;
    /* 0xa64ef8 */ mov x25, x2;
    /* 0xa64efc */ mov x19, x1;
    sub_aa29c8();
    sub_a7fc40();
    sub_a6a3d8();
    sub_a69d30();
    sub_a8ad80();
    sub_a8b058();
    sub_a69d30();
    sub_85b728();
    sub_a69d40();
    sub_a69d40();
    sub_a69d30();
    sub_a69d30();
    sub_cccfe0();
    return x0;
    sub_aa29c8();
    sub_a8aaa8();
    sub_a82200();
    sub_8496ac();
    sub_a65504();
    sub_a65504();
    sub_9fdf80();
    sub_a6a094();
    sub_a64c28();
    sub_a65720();
    sub_a69c84();
    sub_a69c84();
    sub_a69c84();
    memset();
    sub_9fdf80();
    wgpuDeviceCreateRenderPipeline();
    sub_a6581c();
    wgpuRenderPassEncoderSetPipeline();
    wgpuRenderPassEncoderSetBindGroup();
    wgpuRenderPassEncoderSetVertexBuffer();
    wgpuRenderPassEncoderSetIndexBuffer();
    wgpuRenderPassEncoderDrawIndexed();
    wgpuBindGroupRelease();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
