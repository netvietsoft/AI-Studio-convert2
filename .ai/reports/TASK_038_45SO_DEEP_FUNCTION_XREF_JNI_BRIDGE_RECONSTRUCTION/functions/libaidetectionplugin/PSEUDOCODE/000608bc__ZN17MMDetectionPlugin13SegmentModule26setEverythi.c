// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x608bc
// Recovered Name: _ZN17MMDetectionPlugin13SegmentModule26setEverythingSegmentOptionER35vlai_segment_runtime_setting_handlePKNS_16_DetectionOptionEPKNS_14DetectionFrameE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x608bc | Size: 504 bytes | SHA256: 7ea6b98b2db50628d54c5bfc0544ba26adb32ef45b2c1e86684b2b7895ab043d
// Callers: 0 | Callees: 0 | Imports: 7

// Calls external APIs: _ZN5media10ImageUtils6resizeEPKhiiPhiii, free, malloc, vlai_segment_runtime_setting_set_segmentation_points, vlai_segment_runtime_setting_set_segmentation_pre_mask, vldp_create_image_ref, vldp_release_image

void _ZN17MMDetectionPlugin13SegmentModule26setEverythingSegmentOptionER35vlai_segment_runtime_setting_handlePKNS_16_DetectionOptionEPKNS_14DetectionFrameE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 126 instructions
    /* 0x608bc */ stp x29, x30, [sp, #-0x50]!;
    /* 0x608c0 */ str x25, [sp, #0x10];
    /* 0x608c4 */ stp x24, x23, [sp, #0x20];
    /* 0x608c8 */ stp x22, x21, [sp, #0x30];
    /* 0x608cc */ stp x20, x19, [sp, #0x40];
    /* 0x608d0 */ mov x29, sp;
    /* 0x608d4 */ ldrb w8, [x2, #0xcc];
    /* 0x608d8 */ tbz w8, #3, #0x60a48;
    /* 0x608dc */ ldr x22, [x2, #0x2a0];
    /* 0x608e0 */ cbz x22, #0x60a48;
    /* 0x608e4 */ ldr w8, [x22, #0x24];
    malloc();
    _ZN5media10ImageUtils6resizeEPKhiiPhiii();
    vldp_create_image_ref();
    vlai_segment_runtime_setting_set_segmentation_pre_mask();
    malloc();
    vlai_segment_runtime_setting_set_segmentation_points();
    free();
    return x0;
}
