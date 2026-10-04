// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb00990
// Recovered Name: sub_b00990
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb00990 | Size: 832 bytes | SHA256: 7711ff68773f0229aaedf8e44ca15ce4e53803fcb323a924714cedef0216fecf
// Callers: 0 | Callees: 21 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "res/mosaic/MTFilter_SegmentSwellH.fs"
//   "res/mosaic/MTFilter_SegmentSwellH.vs"
//   "res/mosaic/MTFilter_SegmentSwellV.fs"
//   "res/mosaic/MTFilter_SegmentSwellV.vs"
//   "s_texture"

void sub_b00990(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 208 instructions
    /* 0xb00990 */ stp x29, x30, [sp, #0x40];
    /* 0xb00994 */ stp x28, x27, [sp, #0x50];
    /* 0xb00998 */ stp x26, x25, [sp, #0x60];
    /* 0xb0099c */ stp x24, x23, [sp, #0x70];
    /* 0xb009a0 */ stp x22, x21, [sp, #0x80];
    /* 0xb009a4 */ stp x20, x19, [sp, #0x90];
    /* 0xb009a8 */ add x29, sp, #0x40;
    /* 0xb009ac */ mrs x8, tpidr_el0;
    /* 0xb009b0 */ mov x19, x0;
    /* 0xb009b4 */ mov x0, x1;
    /* 0xb009b8 */ str x8, [sp];
    sub_da2fe4();
    sub_da2a38();
    sub_da2fe4();
    sub_da2a40();
    sub_d41edc();
    sub_d41edc();
    sub_d60368();
    sub_d622d8();
    sub_d5b06c();
    sub_d5b06c();
    sub_d42610();
    sub_d44604();
    sub_d7fb90();
    sub_d45160();
    sub_d7fbb4();
    sub_d44604();
    sub_d457d8();
    sub_d80558();
    sub_d5c9bc();
    sub_d80558();
    sub_d5c57c();
    sub_d62370();
    sub_d80558();
    sub_d5c9bc();
    sub_d42610();
    sub_d44604();
    sub_d7fb90();
    sub_d45160();
    sub_d7fbb4();
    sub_d44604();
    sub_d457d8();
    sub_d424a8();
    sub_d84cf4();
    sub_da2ed4();
    sub_d80558();
    sub_d5c9bc();
    sub_d80558();
    sub_d5c57c();
    sub_d62370();
    sub_d7ffbc();
    sub_d80558();
    sub_d5c9bc();
    sub_d7ffbc();
    sub_d424a8();
    sub_d84cf4();
    sub_da2ed4();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_d7ffbc();
    return x0;
    __stack_chk_fail();
}
