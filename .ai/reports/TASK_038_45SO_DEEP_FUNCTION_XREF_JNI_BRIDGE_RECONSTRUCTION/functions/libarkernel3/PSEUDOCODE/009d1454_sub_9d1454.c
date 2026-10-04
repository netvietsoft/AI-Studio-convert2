// Library: libarkernel3.so
// Function ID: libarkernel3::0x9d1454
// Recovered Name: sub_9d1454
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9d1454 | Size: 820 bytes | SHA256: 8683fa6a68b27f2a6033eac61759792b5bab819932df904308faa7085a057f8c
// Callers: 0 | Callees: 10 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "Body"
//   "BodyReverse"
//   "BrushFileInfo"
//   "BrushFilePath"
//   "Cloth"

void sub_9d1454(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 205 instructions
    /* 0x9d1454 */ stp x29, x30, [sp, #0x10];
    /* 0x9d1458 */ stp x22, x21, [sp, #0x20];
    /* 0x9d145c */ stp x20, x19, [sp, #0x30];
    /* 0x9d1460 */ add x29, sp, #0x10;
    /* 0x9d1464 */ mrs x22, tpidr_el0;
    /* 0x9d1468 */ mov x19, x0;
    /* 0x9d146c */ adrp x1, #0x1d2000;
    /* 0x9d1470 */ add x1, x1, #0xfac;
    /* 0x9d1474 */ ldr x8, [x22, #0x28];
    /* 0x9d1478 */ add x0, x0, #0x80;
    /* 0x9d147c */ str x8, [sp, #8];
    sub_6607b8();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_9d1788();
    sub_9d1890();
    sub_9d198c();
    sub_9d1a68();
    sub_9d1b64();
    sub_9d1b64();
    sub_9d1b64();
    sub_9d1c60();
    sub_a2d4dc();
    sub_a2d1c4();
    return x0;
    __stack_chk_fail();
}
