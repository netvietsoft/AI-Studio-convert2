// Library: libbmpKit.so
// Function ID: libbmpKit::0x346e4
// Recovered Name: sub_346e4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x346e4 | Size: 64 bytes | SHA256: 5158ccf6a3a2ea4cb2fc81c8ae4f142a474c040ae93908bf0a659cc4c8abf6c1
// Callers: 0 | Callees: 0 | Imports: 0


void sub_346e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x346e4 */ stp x29, x30, [sp, #0x20];
    /* 0x346e8 */ add x29, sp, #0x20;
    /* 0x346ec */ stur x0, [x29, #-8];
    /* 0x346f0 */ str x1, [sp, #0x10];
    /* 0x346f4 */ str x2, [sp, #8];
    /* 0x346f8 */ str w3, [sp, #4];
    /* 0x346fc */ ldur x0, [x29, #-8];
    /* 0x34700 */ ldr x8, [x0];
    /* 0x34704 */ ldr x8, [x8, #0x6b8];
    /* 0x34708 */ ldr x1, [sp, #0x10];
    /* 0x3470c */ ldr x2, [sp, #8];
    return x0;
}
