// Library: libarkernel3.so
// Function ID: libarkernel3::0xbdf9e0
// Recovered Name: sub_bdf9e0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbdf9e0 | Size: 2188 bytes | SHA256: e0d0978ba0f20cb09714b0d129ca4502040bff1dff9c9f59349efae2edd4c1e5
// Callers: 0 | Callees: 4 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "GL_NV_ray_tracing"
//   "SPV_AMD_shader_explicit_vertex_parameter"
//   "SPV_ARM_core_builtins"
//   "SPV_EXT_shader_stencil_export"
//   "SPV_EXT_shader_viewport_index_layer"

void sub_bdf9e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 547 instructions
    /* 0xbdf9e0 */ stp x29, x30, [sp, #0x20];
    /* 0xbdf9e4 */ str x21, [sp, #0x30];
    /* 0xbdf9e8 */ stp x20, x19, [sp, #0x40];
    /* 0xbdf9ec */ add x29, sp, #0x20;
    /* 0xbdf9f0 */ mrs x20, tpidr_el0;
    /* 0xbdf9f4 */ sub w8, w1, #1;
    /* 0xbdf9f8 */ ldr x9, [x20, #0x28];
    /* 0xbdf9fc */ cmp w8, #0x95;
    /* 0xbdfa00 */ stur x9, [x29, #-8];
    /* 0xbdfa04 */ b.hi #0xbdfa38;
    /* 0xbdfa08 */ adrp x9, #0x2c9000;
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bdf028();
    sub_bd4a00();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bd4a00();
    sub_bdf028();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bdf028();
    sub_bd4a00();
    sub_bd4a00();
    sub_bd4730();
    sub_5644ac();
    _ZdlPv();
    sub_bd4a00();
    sub_bdf028();
    sub_bdf028();
    sub_bdf028();
    sub_bdf028();
    sub_bdf028();
    sub_bd4a00();
    sub_bdf028();
    sub_bd4a00();
    sub_bd4a00();
    sub_bdf028();
    sub_bdf028();
}
