// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x6215c
// Recovered Name: sub_6215c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6215c | Size: 768 bytes | SHA256: 1ee056f40c95335e49ec5e440d70d9fb00fffa234ff2f0b43b6f9cfd16b7eea6
// Callers: 0 | Callees: 1 | Imports: 20

// Calls external APIs: _ZN10verenderer15MTRenderContext13getRenderTypeEv, _ZN10verenderer15MTRenderContext14currentContextEv, _ZN10verenderer18MTTexture2DBackend29createWithBackendTextureValueERKNS_15BackendTexValueE, _ZN10verenderer3Ref7releaseEv, _ZN17MMDetectionPlugin12SegmentBlockC1EPN5media5ImageENS_14_SegmentSwitchE, _ZN17MMDetectionPlugin12SegmentBlockC1ERKS0_, _ZN17MMDetectionPlugin12SegmentBlockD1Ev, _ZN5media3Ref7releaseEv, _ZN5media5Image19convertDataToFormatEPKhlN10verenderer11PixelFormatES4_PPhPl, _ZN5media5Image6createEv, _ZN5media5Image7setExifEi, _ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJRS2_EEEPS2_DpOT_, __android_log_print, __stack_chk_fail, free, malloc, vldp_get_texture_height, vldp_get_texture_metal_handle, vldp_get_texture_opengl_handle, vldp_get_texture_width
// Strings referenced:
//   "pushSegmentResult"

void sub_6215c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 192 instructions
    /* 0x6215c */ stp x29, x30, [sp, #0xa0];
    /* 0x62160 */ str x25, [sp, #0xb0];
    /* 0x62164 */ stp x24, x23, [sp, #0xc0];
    /* 0x62168 */ stp x22, x21, [sp, #0xd0];
    /* 0x6216c */ stp x20, x19, [sp, #0xe0];
    /* 0x62170 */ add x29, sp, #0xa0;
    /* 0x62174 */ mrs x24, tpidr_el0;
    /* 0x62178 */ ldr x8, [x24, #0x28];
    /* 0x6217c */ stur x8, [x29, #-8];
    /* 0x62180 */ ldr x0, [x1];
    /* 0x62184 */ cbz x0, #0x62208;
    vldp_get_texture_width();
    vldp_get_texture_height();
    _ZN10verenderer15MTRenderContext14currentContextEv();
    _ZN10verenderer15MTRenderContext13getRenderTypeEv();
    vldp_get_texture_metal_handle();
    __android_log_print();
    vldp_get_texture_opengl_handle();
    vldp_get_texture_width();
    vldp_get_texture_height();
    _ZN10verenderer18MTTexture2DBackend29createWithBackendTextureValueERKNS_15BackendTexValueE();
    vldp_get_texture_width();
    vldp_get_texture_height();
    malloc();
    vldp_get_texture_width();
    vldp_get_texture_height();
    _ZN5media5Image19convertDataToFormatEPKhlN10verenderer11PixelFormatES4_PPhPl();
    _ZN5media5Image6createEv();
    _ZN5media5Image7setExifEi();
    _ZN17MMDetectionPlugin12SegmentBlockC1EPN5media5ImageENS_14_SegmentSwitchE();
    _ZN17MMDetectionPlugin12SegmentBlockC1ERKS0_();
    free();
    _ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJRS2_EEEPS2_DpOT_();
    _ZN5media3Ref7releaseEv();
    _ZN17MMDetectionPlugin12SegmentBlockD1Ev();
    free();
    _ZN10verenderer3Ref7releaseEv();
    return x0;
    _ZN17MMDetectionPlugin12SegmentBlockD1Ev();
    sub_75c14();
    __stack_chk_fail();
}
