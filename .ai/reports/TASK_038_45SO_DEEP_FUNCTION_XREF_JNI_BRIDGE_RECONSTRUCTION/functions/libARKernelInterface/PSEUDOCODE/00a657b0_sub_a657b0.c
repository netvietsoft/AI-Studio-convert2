// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa657b0
// Recovered Name: sub_a657b0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa657b0 | Size: 2032 bytes | SHA256: 3c5daee13355249474cdf3666ae00807264607864cff8330a836987f0a2e2015
// Callers: 1 | Callees: 14 | Imports: 4

// Calls external APIs: _ZdlPv, _Znwm, __android_log_print, __stack_chk_fail
// Strings referenced:
//   "FSPath"
//   "FilterCommonShader::ReadConfig(const arkernel::PlistDict& filter): param group is empty."
//   "GenIndex"
//   "GenTextureDirection"
//   "GenValidRect"

void sub_a657b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 508 instructions
    /* 0xa657b0 */ stp x29, x30, [sp, #-0x60]!;
    /* 0xa657b4 */ stp x28, x27, [sp, #0x10];
    /* 0xa657b8 */ stp x26, x25, [sp, #0x20];
    /* 0xa657bc */ stp x24, x23, [sp, #0x30];
    /* 0xa657c0 */ stp x22, x21, [sp, #0x40];
    /* 0xa657c4 */ stp x20, x19, [sp, #0x50];
    /* 0xa657c8 */ mov x29, sp;
    /* 0xa657cc */ sub sp, sp, #0x430;
    /* 0xa657d0 */ mrs x27, tpidr_el0;
    /* 0xa657d4 */ mov x20, x1;
    /* 0xa657d8 */ mov x19, x0;
    sub_a65354();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_5a8d1c();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5b7fa8();
    _ZdlPv();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8da0();
    sub_5a8de8();
    sub_a65fa0();
    sub_a65fa0();
    sub_a66044();
    _Znwm();
    sub_7a6e6c();
    sub_7a6f44();
    sub_7a74dc();
    _ZdlPv();
    return x0;
    sub_5a6b20();
    __android_log_print();
    sub_a66044();
    __stack_chk_fail();
}
