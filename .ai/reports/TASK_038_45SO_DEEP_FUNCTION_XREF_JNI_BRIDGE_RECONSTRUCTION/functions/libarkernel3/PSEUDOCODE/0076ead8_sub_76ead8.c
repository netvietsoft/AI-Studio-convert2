// Library: libarkernel3.so
// Function ID: libarkernel3::0x76ead8
// Recovered Name: sub_76ead8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x76ead8 | Size: 440 bytes | SHA256: 1429ea4d36e1cd762ff162e7bff2db1e2d42cbb7e639a3f93645caf61db37334
// Callers: 0 | Callees: 13 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "Makeup"
//   "Script is not loaded, Path: %s, ResourcePath: %s"
//   "Segment mask is required but not ready, MaskType: %d"
//   "mtlabar3"
//   "onRenderImpl"

void sub_76ead8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 110 instructions
    /* 0x76ead8 */ stp x29, x30, [sp, #0x10];
    /* 0x76eadc */ stp x24, x23, [sp, #0x20];
    /* 0x76eae0 */ stp x22, x21, [sp, #0x30];
    /* 0x76eae4 */ stp x20, x19, [sp, #0x40];
    /* 0x76eae8 */ add x29, sp, #0x10;
    /* 0x76eaec */ mrs x22, tpidr_el0;
    /* 0x76eaf0 */ mov x19, x1;
    /* 0x76eaf4 */ mov x20, x0;
    /* 0x76eaf8 */ ldr x8, [x22, #0x28];
    /* 0x76eafc */ str x8, [sp, #8];
    sub_aa29ec();
    sub_a8e5a8();
    sub_76d53c();
    sub_76d338();
    sub_9fe8fc();
    sub_d7c64c();
    sub_e2da60();
    sub_a5a194();
    sub_a59d2c();
    sub_cccfe0();
    sub_ccccbc();
    sub_cccfe0();
    sub_76ec90();
    return x0;
    sub_76ec90();
    sub_106b814();
    __stack_chk_fail();
}
