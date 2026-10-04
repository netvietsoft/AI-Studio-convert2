// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbfeafc
// Recovered Name: sub_bfeafc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbfeafc | Size: 492 bytes | SHA256: d71fc8dcfa9ca8f7d7ad89959860c1553693a5d3010214e7e3683bae56a264e1
// Callers: 0 | Callees: 9 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "Failed to convert parameter to type 'Vector2'."
//   "Invalid number of parameters (expected 5)."
//   "Vector2"
//   "lua_GPMakeup2D_Judge2LineSegmentIntersect - Failed to match the given 5 parameters to a valid function signature."

void sub_bfeafc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 123 instructions
    /* 0xbfeafc */ stp x29, x30, [sp, #0x40];
    /* 0xbfeb00 */ str x23, [sp, #0x50];
    /* 0xbfeb04 */ stp x22, x21, [sp, #0x60];
    /* 0xbfeb08 */ stp x20, x19, [sp, #0x70];
    /* 0xbfeb0c */ add x29, sp, #0x40;
    /* 0xbfeb10 */ mrs x21, tpidr_el0;
    /* 0xbfeb14 */ mov x19, x0;
    /* 0xbfeb18 */ ldr x8, [x21, #0x28];
    /* 0xbfeb1c */ stur x8, [x29, #-8];
    sub_f0cb90();
    /* 0xbfeb24 */ cmp w0, #5;
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0ce7c();
    sub_f0d5d0();
    sub_f0e498();
    return x0;
    sub_bd9a38();
    sub_bd9c0c();
    sub_f0d5d0();
    sub_f0e498();
    sub_bd9c0c();
    sub_bfcc5c();
    sub_79b904();
    sub_f0d870();
    __stack_chk_fail();
}
