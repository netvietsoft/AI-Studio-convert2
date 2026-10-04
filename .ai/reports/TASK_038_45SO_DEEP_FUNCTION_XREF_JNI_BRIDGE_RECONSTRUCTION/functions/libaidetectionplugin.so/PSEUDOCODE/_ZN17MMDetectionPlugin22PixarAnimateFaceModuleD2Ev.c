// Function: MMDetectionPlugin::PixarAnimateFaceModule::~PixarAnimateFaceModule()
// RVA: 0x7362c, Size: 116 bytes
int64_t _ZN17MMDetectionPlugin22PixarAnimateFaceModuleD2Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_83010 = (void*)0x83010; // global ref
    vlai_graphics_env_make_context(...); // call imported API via PLT at 0x73654
    vlai_pixar_animate_face_release_handle(...); // call imported API via PLT at 0x73668
    vlai_destroy_graphics_env(...); // call imported API via PLT at 0x73674
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x73698
    sub_3F3A4(...); // call internal func at 0x7369c
}
