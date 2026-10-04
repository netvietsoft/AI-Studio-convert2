// Function: MMCodec::GLFramebufferObject::createDepthBuffer(int, int)
// RVA: 0x175800, Size: 200 bytes
int64_t _ZN7MMCodec19GLFramebufferObject17createDepthBufferEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x175854
    glGetIntegerv(...); // call imported API via PLT at 0x175864
    glGenRenderbuffers(...); // call imported API via PLT at 0x175870
    glBindRenderbuffer(...); // call imported API via PLT at 0x17587c
    glRenderbufferStorage(...); // call imported API via PLT at 0x175890
    glBindRenderbuffer(...); // call imported API via PLT at 0x17589c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1758c4
}
