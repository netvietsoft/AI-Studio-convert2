// Reconstructed Pseudocode for FN_libaidetectionplugin_0007378C (MMDetectionPlugin::PixarAnimateFaceModule::runExtraDetect(MMDetectionPlugin::_ExtraDetectionOption const*, MMDetectionPlugin::DetectionFrame const*, vlai_graphics_env_handle&, std::__ndk1::vector<std::__ndk1::shared_ptr<MMDetectionPlugin::DetectionResult>, std::__ndk1::allocator<std::__ndk1::shared_ptr<MMDetectionPlugin::DetectionResult>>>, std::__ndk1::vector<std::__ndk1::shared_ptr<MMDetectionPlugin::DetectionResult>, std::__ndk1::allocator<std::__ndk1::shared_ptr<MMDetectionPlugin::DetectionResult>>>&))
// Library: libaidetectionplugin.so | RVA: 0x7378C | Size: 1568B | Visibility: FACT

/* Imported APIs: vlai_graphics_env_make_context;vldp_create_point2f_array_pointer_array_pointer;vldp_create_float_array_pointer_array_pointer;vldp_set_float_array_pointer_array_pointer_at;vldp_release_float_array_pointer;vldp_create_point2f_array_pointer;vldp_get_point2f_array_pointer_ref;vldp_set_point2f_array_pointer_array_pointer_at;vldp_release_point2f_array_pointer;vldp_create_float_array_pointer */
/* String XREFs: rame_hdr at %lx: need at least 4 bytes of data but only got %zd;nsupported .eh_frame_hdr at %lx: need at least 4 bytes of data but only got %zd;MTMVCore;[%s(%d)]:> dense hair have no face;runExtraDetect */

int MMDetectionPlugin__PixarAnimateFaceModule__runExtraDetect(MMDetectionPlugin___ExtraDetectionOption_const*,_MMDetectionPlugin__DetectionFrame_const*,_vlai_graphics_env_handle&,_std____ndk1__vector<std____ndk1__shared_ptr<MMDetectionPlugin__DetectionResult>,_std____ndk1__allocator<std____ndk1__shared_ptr<MMDetectionPlugin__DetectionResult>>>,_std____ndk1__vector<std____ndk1__shared_ptr<MMDetectionPlugin__DetectionResult>,_std____ndk1__allocator<std____ndk1__shared_ptr<MMDetectionPlugin__DetectionResult>>>&)(void* ctx) {
    // Function prologue: set up stack frame
    sub_70B78(ctx);
    sub_70BE8(ctx);
    sub_43C0C(ctx);
    sub_6FAA8(ctx);
    sub_70B78(ctx);
    vlai_graphics_env_make_context(...);
    vldp_create_point2f_array_pointer_array_pointer(...);
    vldp_create_float_array_pointer_array_pointer(...);
    vldp_set_float_array_pointer_array_pointer_at(...);
    vldp_release_float_array_pointer(...);
    return 0;
}
