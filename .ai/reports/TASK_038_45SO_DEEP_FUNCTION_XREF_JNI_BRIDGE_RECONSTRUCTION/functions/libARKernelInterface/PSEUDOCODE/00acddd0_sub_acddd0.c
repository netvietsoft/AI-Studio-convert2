// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xacddd0
// Recovered Name: sub_acddd0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xacddd0 | Size: 920 bytes | SHA256: 9923e1453e995d9952b249e233601bd3731d6c5c629e6ed043af47c97e06ebf3
// Callers: 0 | Callees: 4 | Imports: 4

// Calls external APIs: _ZdlPv, __stack_chk_fail, glDrawArrays, glViewport
// Strings referenced:
//   "BlurResult"
//   "a_position"
//   "a_texCoord"
//   "backMask"
//   "faceBrightAlpha"

void sub_acddd0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 230 instructions
    /* 0xacddd0 */ stp x29, x30, [sp, #0xe0];
    /* 0xacddd4 */ stp x28, x27, [sp, #0xf0];
    /* 0xacddd8 */ stp x26, x25, [sp, #0x100];
    /* 0xacdddc */ stp x24, x23, [sp, #0x110];
    /* 0xacdde0 */ stp x22, x21, [sp, #0x120];
    /* 0xacdde4 */ stp x20, x19, [sp, #0x130];
    /* 0xacdde8 */ add x29, sp, #0xe0;
    /* 0xacddec */ mrs x28, tpidr_el0;
    /* 0xacddf0 */ mov x21, x0;
    /* 0xacddf4 */ mov x0, x1;
    /* 0xacddf8 */ ldr x8, [x28, #0x28];
    sub_69b7cc();
    sub_69b7d4();
    glViewport();
    sub_fc2a84();
    sub_69b76c();
    sub_69b76c();
    sub_69b76c();
    sub_69b76c();
    glDrawArrays();
    return x0;
    __stack_chk_fail();
    return x0;
}
