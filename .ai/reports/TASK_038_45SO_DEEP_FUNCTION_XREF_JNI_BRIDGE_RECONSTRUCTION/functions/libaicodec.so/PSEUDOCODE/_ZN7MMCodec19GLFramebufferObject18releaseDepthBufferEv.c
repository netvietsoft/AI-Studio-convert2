// Function: MMCodec::GLFramebufferObject::releaseDepthBuffer()
// RVA: 0x1758c8, Size: 60 bytes
int64_t _ZN7MMCodec19GLFramebufferObject18releaseDepthBufferEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glIsRenderbuffer(...); // call imported API via PLT at 0x1758dc
    glDeleteRenderbuffers(...); // call imported API via PLT at 0x1758f0
    return a0;
}
