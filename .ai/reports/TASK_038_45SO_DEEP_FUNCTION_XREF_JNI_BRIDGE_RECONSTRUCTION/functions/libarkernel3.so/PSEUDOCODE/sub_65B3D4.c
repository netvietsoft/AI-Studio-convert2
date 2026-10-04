// Function: sub_65B3D4
// RVA: 0x65b3d4, Size: 452 bytes
int64_t sub_65B3D4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_1a1590 = "glGetTextureNativeHandleANGLE"; // string xref
    (*x8)(...); // indirect call at 0x65b488
    (*x8)(...); // indirect call at 0x65b4a0
    const char* s_1b12a2 = "FGraphics::createTextureWithD3D11Format"; // string xref
    const char* s_20705f = "FGraphics::createTextureWithOpenGLFormat"; // string xref
    wgpuDeviceCreateTexture(...); // call imported API via PLT at 0x65b540
    return a0;
    const char* s_199bc4 = "mtlabar3"; // string xref
    const char* s_1b1284 = "createTextureWithOpenGLFormat"; // string xref
    const char* s_1b87e9 = "createTextureWithOpenGLFormat not supported for GL internal format: 0x%X."; // string xref
    sub_CCCFE0(...); // call internal func at 0x65b588
    __stack_chk_fail(...); // call imported API via PLT at 0x65b594
}
