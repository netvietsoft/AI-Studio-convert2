// Library: libarkernel3.so
// Function ID: libarkernel3::0x601170
// Recovered Name: sub_601170
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x601170 | Size: 72 bytes | SHA256: 2fd094e3762dfdf281fb154749316e7ebc8e5f5a9a8ed7a6bd42af4d4185b622
// Callers: 1 | Callees: 1 | Imports: 0

// Strings referenced:
//   "GPInstanceSegmentData:getNoFaceMask get null pointer"
//   "getNoFaceMask"
//   "mtlabar3"

void sub_601170(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x601170 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x601174 */ str x19, [sp, #0x10];
    /* 0x601178 */ mov x29, sp;
    /* 0x60117c */ mov x19, x0;
    /* 0x601180 */ ldr x0, [x0, #0x20];
    /* 0x601184 */ cbnz x0, #0x6011ac;
    /* 0x601188 */ adrp x1, #0x199000;
    /* 0x60118c */ add x1, x1, #0xbc4;
    /* 0x601190 */ adrp x2, #0x26b000;
    /* 0x601194 */ add x2, x2, #0xe8a;
    /* 0x601198 */ adrp x3, #0x1a0000;
    sub_cccfe0();
    return x0;
}
