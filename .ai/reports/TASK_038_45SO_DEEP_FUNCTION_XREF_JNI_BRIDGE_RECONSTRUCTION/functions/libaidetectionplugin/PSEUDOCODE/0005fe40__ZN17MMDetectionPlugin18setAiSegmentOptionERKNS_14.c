// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x5fe40
// Recovered Name: _ZN17MMDetectionPlugin18setAiSegmentOptionERKNS_14_SegmentOptionER33vlai_segment_setting_patch_handleR23vlai_require_set_handle
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x5fe40 | Size: 104 bytes | SHA256: 7ec831ceeabb2c5df5c29bf0cc4e732864d09ae874e8f690e56da2678bad9a19
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _ZN17MMDetectionPlugin18setAiMTSegmentModeERKNS_14_SegmentOptionER33vlai_segment_setting_patch_handle, _ZN17MMDetectionPlugin22getAiSegmentEnableEnumENS_14_SegmentSwitchER33vlai_segment_setting_patch_handleR23vlai_require_set_handle, vlai_segment_setting_patch_set_force_image_mode, vlai_segment_setting_patch_set_is_just_init

void _ZN17MMDetectionPlugin18setAiSegmentOptionERKNS_14_SegmentOptionER33vlai_segment_setting_patch_handleR23vlai_require_set_handle(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0x5fe40 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5fe44 */ str x21, [sp, #0x10];
    /* 0x5fe48 */ stp x20, x19, [sp, #0x20];
    /* 0x5fe4c */ mov x29, sp;
    /* 0x5fe50 */ mov x20, x2;
    /* 0x5fe54 */ mov x19, x1;
    /* 0x5fe58 */ mov x21, x0;
    _ZN17MMDetectionPlugin18setAiMTSegmentModeERKNS_14_SegmentOptionER33vlai_segment_setting_patch_handle();
    /* 0x5fe60 */ ldr x0, [x21, #0x30];
    /* 0x5fe64 */ mov x2, x20;
    _ZN17MMDetectionPlugin22getAiSegmentEnableEnumENS_14_SegmentSwitchER33vlai_segment_setting_patch_handleR23vlai_require_set_handle();
    vlai_segment_setting_patch_set_is_just_init();
    return x0;
}
