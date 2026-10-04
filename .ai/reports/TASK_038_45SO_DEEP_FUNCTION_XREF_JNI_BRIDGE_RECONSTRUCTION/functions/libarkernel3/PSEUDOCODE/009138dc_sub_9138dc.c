// Library: libarkernel3.so
// Function ID: libarkernel3::0x9138dc
// Recovered Name: sub_9138dc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9138dc | Size: 188 bytes | SHA256: 6e1214964768cc336d40375821030cfaf2bfca4232b73484d56c162f1673ef13
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "nose_mask"
//   "nose_mask_blur_horizontal"
//   "nose_mask_blur_vertical"

void sub_9138dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x9138dc */ stp x29, x30, [sp, #0x10];
    /* 0x9138e0 */ stp x20, x19, [sp, #0x20];
    /* 0x9138e4 */ add x29, sp, #0x10;
    /* 0x9138e8 */ mrs x20, tpidr_el0;
    /* 0x9138ec */ mov x19, x0;
    /* 0x9138f0 */ ldr x8, [x20, #0x28];
    /* 0x9138f4 */ str x8, [sp, #8];
    /* 0x9138f8 */ ldrb w8, [x0, #0xc0];
    /* 0x9138fc */ mov w0, wzr;
    /* 0x913900 */ cbz w8, #0x913974;
    /* 0x913904 */ ldr w8, [x19, #0x20];
    sub_9139a0();
    sub_9139a0();
    sub_9139a0();
    return x0;
    __stack_chk_fail();
}
