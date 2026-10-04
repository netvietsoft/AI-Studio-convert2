// Library: libarkernel3.so
// Function ID: libarkernel3::0x77049c
// Recovered Name: sub_77049c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x77049c | Size: 124 bytes | SHA256: 947214a01cf835d253ddb1e4ef761ee34840912210682c93ef687f6e612e0452
// Callers: 0 | Callees: 5 | Imports: 0

// Strings referenced:
//   "DefaultSize"
//   "MaskBlurNumber"
//   "MaskBlurRange"
//   "MaskConfig"
//   "mosaic script part"

void sub_77049c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0x77049c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x7704a0 */ str x19, [sp, #0x10];
    /* 0x7704a4 */ mov x29, sp;
    /* 0x7704a8 */ mov x19, x0;
    sub_774ea4();
    /* 0x7704b0 */ adrp x1, #0x241000;
    /* 0x7704b4 */ add x1, x1, #0x60e;
    /* 0x7704b8 */ add x0, x19, #0x80;
    sub_770518();
    /* 0x7704c0 */ adrp x2, #0x1f8000;
    /* 0x7704c4 */ add x2, x2, #0x60;
    sub_77072c();
    sub_770828();
    sub_770924();
}
