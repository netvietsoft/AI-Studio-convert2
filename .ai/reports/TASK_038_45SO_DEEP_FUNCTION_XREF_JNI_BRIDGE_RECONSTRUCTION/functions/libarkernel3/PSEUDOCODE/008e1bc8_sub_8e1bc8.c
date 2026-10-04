// Library: libarkernel3.so
// Function ID: libarkernel3::0x8e1bc8
// Recovered Name: sub_8e1bc8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8e1bc8 | Size: 3316 bytes | SHA256: 70095f7b4582de958fe1cced8970a029aa0a5fd207b1e790468875777840207e
// Callers: 0 | Callees: 18 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "ALIGN_LEFT_BOTTOM"
//   "ALIGN_LEFT_TOP"
//   "ALIGN_MIDDLE_BOTTOM"
//   "ALIGN_MIDDLE_LEFT"
//   "ALIGN_MIDDLE_RIGHT"

void sub_8e1bc8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 829 instructions
    /* 0x8e1bc8 */ stp x29, x30, [sp, #0x20];
    /* 0x8e1bcc */ stp x28, x27, [sp, #0x30];
    /* 0x8e1bd0 */ stp x26, x25, [sp, #0x40];
    /* 0x8e1bd4 */ stp x24, x23, [sp, #0x50];
    /* 0x8e1bd8 */ stp x22, x21, [sp, #0x60];
    /* 0x8e1bdc */ stp x20, x19, [sp, #0x70];
    /* 0x8e1be0 */ add x29, sp, #0x20;
    /* 0x8e1be4 */ mrs x8, tpidr_el0;
    /* 0x8e1be8 */ mov x19, x0;
    /* 0x8e1bec */ str x8, [sp, #8];
    /* 0x8e1bf0 */ ldr x8, [x8, #0x28];
    sub_90e54c();
    sub_8e28bc();
    sub_8e298c();
    sub_8e298c();
    sub_8e298c();
    sub_8e298c();
    sub_8e298c();
    sub_8e298c();
    sub_8e298c();
    sub_8e298c();
    sub_8e298c();
    sub_871c78();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_871d48();
    sub_8e2b7c();
    sub_8e2c84();
    sub_8e2d80();
    sub_8e2e7c();
    sub_8e2f78();
    sub_8e3074();
    sub_8e3170();
    sub_8e3170();
    sub_8e2d80();
    sub_8e2d80();
    sub_8e326c();
    sub_8e3368();
    sub_8e2d80();
    sub_8e2d80();
    sub_8e2d80();
    sub_8e2d80();
    sub_8e2d80();
    sub_8e3170();
    sub_8e2d80();
    sub_8e2f78();
    sub_8e2f78();
    sub_8e3074();
    sub_8e3170();
    sub_8e2e7c();
    sub_8e2d80();
    sub_8e2d80();
    sub_8e2e7c();
    sub_8e2e7c();
    sub_8e3170();
    sub_8e2d80();
    sub_8e2f78();
    sub_8e3074();
    sub_8e3464();
    sub_8e2f78();
    sub_8e3170();
    sub_8e3074();
    sub_8e2e7c();
    sub_8e3170();
    sub_8e3540();
    sub_8e3540();
    sub_a2d510();
    sub_8e363c();
    return x0;
    __stack_chk_fail();
}
