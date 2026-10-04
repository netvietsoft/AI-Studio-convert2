// Function: sub_65B2A4
// RVA: 0x65b2a4, Size: 300 bytes
int64_t sub_65B2A4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_1a1590 = "glGetTextureNativeHandleANGLE"; // string xref
    (*x8)(...); // indirect call at 0x65b2f4
    (*x8)(...); // indirect call at 0x65b30c
    const char* s_1b12a2 = "FGraphics::createTextureWithD3D11Format"; // string xref
    const char* s_1da92a = "FGraphics::createTextureWithOpenGL"; // string xref
    wgpuDeviceCreateTexture(...); // call imported API via PLT at 0x65b3a0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x65b3cc
}
