// Library: libkoom-strip-dump.so
// Function ID: libkoom-strip-dump::0x37cc8
// Recovered Name: sub_37cc8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x37cc8 | Size: 212 bytes | SHA256: ee5fd0116e5a4e426284482897f4298642ba091420296ed48fa0db795635e300
// Callers: 0 | Callees: 2 | Imports: 3

// Calls external APIs: __stack_chk_fail, __system_property_get, atoi
// Strings referenced:
//   "ro.build.version.sdk"

void sub_37cc8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x37cc8 */ stp x29, x30, [sp, #0x70];
    /* 0x37ccc */ str x21, [sp, #0x80];
    /* 0x37cd0 */ stp x20, x19, [sp, #0x90];
    /* 0x37cd4 */ add x29, sp, #0x70;
    /* 0x37cd8 */ movi v0.2d, #0000000000000000;
    /* 0x37cdc */ mrs x20, tpidr_el0;
    /* 0x37ce0 */ mov x19, x0;
    /* 0x37ce4 */ ldr x8, [x20, #0x28];
    /* 0x37ce8 */ mov x21, x0;
    /* 0x37cec */ stur x8, [x29, #-8];
    /* 0x37cf0 */ strb wzr, [x0];
    __system_property_get();
    atoi();
    return x0;
    sub_37d9c();
    sub_37d9c();
    sub_8130c();
    __stack_chk_fail();
}
