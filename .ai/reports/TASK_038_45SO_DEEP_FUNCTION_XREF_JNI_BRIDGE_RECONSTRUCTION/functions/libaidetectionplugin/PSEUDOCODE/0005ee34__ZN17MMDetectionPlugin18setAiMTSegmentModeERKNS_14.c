// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x5ee34
// Recovered Name: _ZN17MMDetectionPlugin18setAiMTSegmentModeERKNS_14_SegmentOptionER33vlai_segment_setting_patch_handle
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x5ee34 | Size: 64 bytes | SHA256: c01c971f928bcf6051304533bbd369ffb0a6f55abe1cae37052b70ecac83ef88
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN17MMDetectionPlugin18setAiMTSegmentModeERKNS_14_SegmentOptionER33vlai_segment_setting_patch_handle(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x5ee34 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x5ee38 */ stp x28, x27, [sp, #0x10];
    /* 0x5ee3c */ stp x26, x25, [sp, #0x20];
    /* 0x5ee40 */ stp x24, x23, [sp, #0x30];
    /* 0x5ee44 */ stp x22, x21, [sp, #0x40];
    /* 0x5ee48 */ stp x20, x19, [sp, #0x50];
    /* 0x5ee4c */ mov x29, sp;
    /* 0x5ee50 */ mov x19, x0;
    /* 0x5ee54 */ ldr x27, [x19], #8;
    /* 0x5ee58 */ cmp x27, x19;
    /* 0x5ee5c */ b.eq #0x5fbe4;
}
