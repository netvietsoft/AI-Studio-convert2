// Library: libarkernel3.so
// Function ID: libarkernel3::0x9acd48
// Recovered Name: sub_9acd48
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9acd48 | Size: 104 bytes | SHA256: 572dbdd5af81f9f6b90847ee332bd79cb2884a49a52d3e77015b535cca248faf
// Callers: 0 | Callees: 3 | Imports: 0

// Strings referenced:
//   "BlurCount"
//   "LargeFactor"
//   "TriggerFactor"
//   "open mouth part"

void sub_9acd48(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0x9acd48 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9acd4c */ str x19, [sp, #0x10];
    /* 0x9acd50 */ mov x29, sp;
    /* 0x9acd54 */ mov x19, x0;
    sub_9b0424();
    /* 0x9acd5c */ adrp x1, #0x1b9000;
    /* 0x9acd60 */ add x1, x1, #0x448;
    /* 0x9acd64 */ add x0, x19, #0x80;
    sub_9acdb0();
    /* 0x9acd6c */ adrp x2, #0x19b000;
    /* 0x9acd70 */ add x2, x2, #0xc90;
    sub_9acfc4();
    sub_9acfc4();
}
