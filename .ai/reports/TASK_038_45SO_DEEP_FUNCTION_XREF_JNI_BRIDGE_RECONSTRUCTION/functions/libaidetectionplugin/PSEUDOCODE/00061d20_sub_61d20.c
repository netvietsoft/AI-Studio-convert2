// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x61d20
// Recovered Name: sub_61d20
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61d20 | Size: 1080 bytes | SHA256: 9ac219e32bbc9d809cd4dc015a32bf9bd1ecb68b7565c05959132e36f4d856dd
// Callers: 0 | Callees: 1 | Imports: 19

// Calls external APIs: _ZN17MMDetectionPlugin12SegmentBlock14setSegmentNameERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE, _ZN17MMDetectionPlugin12SegmentBlockC1EPN5media5ImageENS_14_SegmentSwitchE, _ZN17MMDetectionPlugin12SegmentBlockC1ERKS0_, _ZN17MMDetectionPlugin12SegmentBlockD1Ev, _ZN5media3Ref7releaseEv, _ZN5media5Image19convertDataToFormatEPKhlN10verenderer11PixelFormatES4_PPhPl, _ZN5media5Image6createEv, _ZN5media5Image7setExifEi, _ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE12emplace_backIJRS2_EEEvDpOT_, _ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJRS2_EEEPS2_DpOT_, __android_log_print, __stack_chk_fail, free, vldp_get_image_data, vldp_get_image_exif, vldp_get_image_format, vldp_get_image_height, vldp_get_image_width, vldp_image_valid
// Strings referenced:
//   "pushSegmentResult"

void sub_61d20(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 270 instructions
    /* 0x61d20 */ stp x29, x30, [sp, #0x70];
    /* 0x61d24 */ str x27, [sp, #0x80];
    /* 0x61d28 */ stp x26, x25, [sp, #0x90];
    /* 0x61d2c */ stp x24, x23, [sp, #0xa0];
    /* 0x61d30 */ stp x22, x21, [sp, #0xb0];
    /* 0x61d34 */ stp x20, x19, [sp, #0xc0];
    /* 0x61d38 */ add x29, sp, #0x70;
    /* 0x61d3c */ mrs x27, tpidr_el0;
    /* 0x61d40 */ mov x20, x4;
    /* 0x61d44 */ mov x19, x3;
    /* 0x61d48 */ ldr x8, [x27, #0x28];
    vldp_image_valid();
    vldp_get_image_format();
    vldp_get_image_data();
    vldp_get_image_width();
    vldp_get_image_height();
    _ZN5media5Image6createEv();
    vldp_get_image_width();
    vldp_get_image_height();
    vldp_get_image_exif();
    _ZN5media5Image7setExifEi();
    _ZN17MMDetectionPlugin12SegmentBlockC1EPN5media5ImageENS_14_SegmentSwitchE();
    _ZN17MMDetectionPlugin12SegmentBlock14setSegmentNameERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    _ZN17MMDetectionPlugin12SegmentBlockC1ERKS0_();
    __android_log_print();
    return x0;
    _ZN5media5Image6createEv();
    vldp_get_image_width();
    vldp_get_image_height();
    vldp_get_image_exif();
    _ZN5media5Image7setExifEi();
    _ZN17MMDetectionPlugin12SegmentBlockC1EPN5media5ImageENS_14_SegmentSwitchE();
    _ZN17MMDetectionPlugin12SegmentBlock14setSegmentNameERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    _ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE12emplace_backIJRS2_EEEvDpOT_();
    vldp_get_image_width();
    vldp_get_image_height();
    _ZN5media5Image19convertDataToFormatEPKhlN10verenderer11PixelFormatES4_PPhPl();
    _ZN5media5Image6createEv();
    vldp_get_image_width();
    vldp_get_image_height();
    vldp_get_image_exif();
    _ZN5media5Image7setExifEi();
    _ZN17MMDetectionPlugin12SegmentBlockC1EPN5media5ImageENS_14_SegmentSwitchE();
    _ZN17MMDetectionPlugin12SegmentBlock14setSegmentNameERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    _ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE12emplace_backIJRS2_EEEvDpOT_();
    _ZN5media3Ref7releaseEv();
    _ZN17MMDetectionPlugin12SegmentBlockD1Ev();
    _ZN5media3Ref7releaseEv();
    _ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJRS2_EEEPS2_DpOT_();
    _ZN5media3Ref7releaseEv();
    _ZN17MMDetectionPlugin12SegmentBlockD1Ev();
    free();
    _ZN17MMDetectionPlugin12SegmentBlockD1Ev();
    sub_75c14();
    __stack_chk_fail();
}
