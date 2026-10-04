// Reconstructed Pseudocode for FN_libaidetectionplugin_0006EEF8 (MMDetectionPlugin::ExDenseHairModule::runExtraDetect(MMDetectionPlugin::_ExtraDetectionOption const*, MMDetectionPlugin::DetectionFrame const*, vlai_graphics_env_handle&, std::__ndk1::vector<std::__ndk1::shared_ptr<MMDetectionPlugin::DetectionResult>, std::__ndk1::allocator<std::__ndk1::shared_ptr<MMDetectionPlugin::DetectionResult>>>, std::__ndk1::vector<std::__ndk1::shared_ptr<MMDetectionPlugin::DetectionResult>, std::__ndk1::allocator<std::__ndk1::shared_ptr<MMDetectionPlugin::DetectionResult>>>&))
// Library: libaidetectionplugin.so | RVA: 0x6EEF8 | Size: 2992B | Visibility: FACT

/* Imported APIs: vlai_frame_create;vlai_engine_runtime_setting;vlai_frame_set_first_frame;vlai_frame_set_capture_frame;vldp_create_texture_ref;__android_log_print;vlai_graphics_env_get_context;vldp_create_texture_ref_metal_with_context;vlai_texture_ref_texture;vlai_frame_ref_texture */
/* String XREFs: MTMVCore;[%s(%d)]:> error tex is null;runExtraDetect;rame_hdr at %lx: need at least 4 bytes of data but only got %zd;rame_hdr at %lx: need at least 4 bytes of data but only got %zd */

int MMDetectionPlugin__ExDenseHairModule__runExtraDetect(MMDetectionPlugin___ExtraDetectionOption_const*,_MMDetectionPlugin__DetectionFrame_const*,_vlai_graphics_env_handle&,_std____ndk1__vector<std____ndk1__shared_ptr<MMDetectionPlugin__DetectionResult>,_std____ndk1__allocator<std____ndk1__shared_ptr<MMDetectionPlugin__DetectionResult>>>,_std____ndk1__vector<std____ndk1__shared_ptr<MMDetectionPlugin__DetectionResult>,_std____ndk1__allocator<std____ndk1__shared_ptr<MMDetectionPlugin__DetectionResult>>>&)(void* ctx) {
    // Function prologue: set up stack frame
    sub_75AB0(ctx);
    sub_75AB0(ctx);
    sub_403DC(ctx);
    sub_403DC(ctx);
    sub_43C0C(ctx);
    vlai_frame_create(...);
    vlai_engine_runtime_setting(...);
    vlai_frame_set_first_frame(...);
    vlai_frame_set_capture_frame(...);
    vldp_create_texture_ref(...);
    return 0;
}
