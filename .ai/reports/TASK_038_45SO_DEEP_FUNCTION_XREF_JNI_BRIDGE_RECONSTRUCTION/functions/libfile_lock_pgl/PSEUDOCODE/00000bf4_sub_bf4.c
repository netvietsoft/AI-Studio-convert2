// Library: libfile_lock_pgl.so
// Function ID: libfile_lock_pgl::0xbf4
// Recovered Name: sub_bf4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbf4 | Size: 104 bytes | SHA256: 693468c26e20291e1863162cd0fdcd3d1a948521da462c22f0ed0c35060032eb
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __stack_chk_fail, fcntl

void sub_bf4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0xbf4 */ stp x29, x30, [sp, #0x30];
    /* 0xbf8 */ str x19, [sp, #0x40];
    /* 0xbfc */ add x29, sp, #0x30;
    /* 0xc00 */ mrs x19, tpidr_el0;
    /* 0xc04 */ ldr x8, [x19, #0x28];
    /* 0xc08 */ mov w0, w2;
    /* 0xc0c */ mov w9, #1;
    /* 0xc10 */ mov w10, #-1;
    /* 0xc14 */ add x2, sp, #8;
    /* 0xc18 */ mov w1, #6;
    /* 0xc1c */ stur x8, [x29, #-8];
    fcntl();
    return x0;
    __stack_chk_fail();
}
