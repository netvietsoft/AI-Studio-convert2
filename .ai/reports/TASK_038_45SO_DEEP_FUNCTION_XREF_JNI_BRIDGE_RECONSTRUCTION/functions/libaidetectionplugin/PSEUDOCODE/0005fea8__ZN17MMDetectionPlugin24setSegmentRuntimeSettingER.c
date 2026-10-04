// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x5fea8
// Recovered Name: _ZN17MMDetectionPlugin24setSegmentRuntimeSettingER35vlai_segment_runtime_setting_handlePKNS_16_DetectionOptionE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x5fea8 | Size: 264 bytes | SHA256: 91c3fb93356673adf219156722ccd1aac11539ec9ef05d03ea0818d5ad117fa7
// Callers: 0 | Callees: 0 | Imports: 9

// Calls external APIs: vlai_segment_runtime_setting_set_enable_face_crop, vlai_segment_runtime_setting_set_enable_first_frame, vlai_segment_runtime_setting_set_enable_space_depth_cache, vlai_segment_runtime_setting_set_facial_accumulate_mask, vlai_segment_runtime_setting_set_is_process_multi_face, vlai_segment_runtime_setting_set_merge_by_alpha, vlai_segment_runtime_setting_set_opt_flow, vlai_segment_runtime_setting_set_opt_flow_dis, vlai_segment_runtime_setting_set_rt_need_cpu_data

void _ZN17MMDetectionPlugin24setSegmentRuntimeSettingER35vlai_segment_runtime_setting_handlePKNS_16_DetectionOptionE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 66 instructions
    /* 0x5fea8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5feac */ str x21, [sp, #0x10];
    /* 0x5feb0 */ stp x20, x19, [sp, #0x20];
    /* 0x5feb4 */ mov x29, sp;
    /* 0x5feb8 */ mov x20, x1;
    /* 0x5febc */ mov x19, x0;
    /* 0x5fec0 */ mov w21, wzr;
    /* 0x5fec4 */ ldr x0, [x19];
    /* 0x5fec8 */ ldr s0, [x20, #0xd0];
    /* 0x5fecc */ mov w1, w21;
    vlai_segment_runtime_setting_set_merge_by_alpha();
    vlai_segment_runtime_setting_set_enable_first_frame();
    vlai_segment_runtime_setting_set_opt_flow();
    vlai_segment_runtime_setting_set_opt_flow_dis();
    vlai_segment_runtime_setting_set_rt_need_cpu_data();
    vlai_segment_runtime_setting_set_rt_need_cpu_data();
    vlai_segment_runtime_setting_set_enable_space_depth_cache();
    vlai_segment_runtime_setting_set_opt_flow();
    vlai_segment_runtime_setting_set_opt_flow();
    return x0;
    vlai_segment_runtime_setting_set_is_process_multi_face();
    vlai_segment_runtime_setting_set_enable_face_crop();
}
