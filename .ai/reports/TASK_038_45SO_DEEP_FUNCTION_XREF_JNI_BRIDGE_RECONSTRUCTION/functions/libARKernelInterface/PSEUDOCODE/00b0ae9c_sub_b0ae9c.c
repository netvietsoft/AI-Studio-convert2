// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb0ae9c
// Recovered Name: sub_b0ae9c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb0ae9c | Size: 724 bytes | SHA256: 695b3443bc4489fd65f253630a949ef4f6c06a26dc6f91b9368e59a54dbf3a76
// Callers: 0 | Callees: 8 | Imports: 3

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "EnableFood"
//   "EnableGesture"
//   "EnableGyroscope"
//   "EnableHandPose"
//   "EnableSlam"

void sub_b0ae9c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 181 instructions
    /* 0xb0ae9c */ stp x29, x30, [sp, #0x30];
    /* 0xb0aea0 */ stp x26, x25, [sp, #0x40];
    /* 0xb0aea4 */ stp x24, x23, [sp, #0x50];
    /* 0xb0aea8 */ stp x22, x21, [sp, #0x60];
    /* 0xb0aeac */ stp x20, x19, [sp, #0x70];
    /* 0xb0aeb0 */ add x29, sp, #0x30;
    /* 0xb0aeb4 */ mrs x26, tpidr_el0;
    /* 0xb0aeb8 */ mov x19, x1;
    /* 0xb0aebc */ mov x20, x0;
    /* 0xb0aec0 */ ldr x8, [x26, #0x28];
    /* 0xb0aec4 */ stur x8, [x29, #-8];
    sub_61bfa0();
    sub_b0a4e0();
    sub_5b7fa8();
    sub_b0bf24();
    sub_b0c020();
    _ZdlPv();
    sub_57688c();
    sub_5a8d0c();
    sub_6225cc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    return x0;
    __stack_chk_fail();
}
