// Function: MMDetectionPlugin::ExColorTransferModule::~ExColorTransferModule()
// RVA: 0x6fc04, Size: 164 bytes
int64_t _ZN17MMDetectionPlugin21ExColorTransferModuleD1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_83010 = (void*)0x83010; // global ref
    vlai_graphics_env_make_context(...); // call imported API via PLT at 0x6fc2c
    vlai_color_transfer_exit_GL(...); // call imported API via PLT at 0x6fc38
    vlai_color_transfer_destroy(...); // call imported API via PLT at 0x6fc40
    vlai_color_ac_gl_exitGL(...); // call imported API via PLT at 0x6fc50
    vlai_color_ac_gl_destroy(...); // call imported API via PLT at 0x6fc58
    vlai_color_toning_ew_exitGL(...); // call imported API via PLT at 0x6fc68
    vlai_color_toning_ew_destroy(...); // call imported API via PLT at 0x6fc70
    vlai_destroy_graphics_env(...); // call imported API via PLT at 0x6fc7c
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x6fca0
    sub_3F3A4(...); // call internal func at 0x6fca4
}
