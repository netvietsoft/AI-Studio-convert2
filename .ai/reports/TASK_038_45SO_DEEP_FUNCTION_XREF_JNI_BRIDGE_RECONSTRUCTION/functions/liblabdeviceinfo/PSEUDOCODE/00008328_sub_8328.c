// Library: liblabdeviceinfo.so
// Function ID: liblabdeviceinfo::0x8328
// Recovered Name: sub_8328
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8328 | Size: 172 bytes | SHA256: f2f8d1ea4068a1fdc44ca217745007dc2d1158ab94dc694fca86c51f03468e76
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_8328(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 43 instructions
    /* 0x8328 */ stp x29, x30, [sp, #0x10];
    /* 0x832c */ stp x20, x19, [sp, #0x20];
    /* 0x8330 */ add x29, sp, #0x10;
    /* 0x8334 */ mrs x19, tpidr_el0;
    /* 0x8338 */ mov w2, #6;
    /* 0x833c */ mov w20, #6;
    /* 0x8340 */ ldr x8, [x19, #0x28];
    /* 0x8344 */ mov x1, sp;
    /* 0x8348 */ movk w2, #1, lsl #16;
    /* 0x834c */ movk w20, #1, lsl #16;
    /* 0x8350 */ str x8, [sp, #8];
    return x0;
    __stack_chk_fail();
}
