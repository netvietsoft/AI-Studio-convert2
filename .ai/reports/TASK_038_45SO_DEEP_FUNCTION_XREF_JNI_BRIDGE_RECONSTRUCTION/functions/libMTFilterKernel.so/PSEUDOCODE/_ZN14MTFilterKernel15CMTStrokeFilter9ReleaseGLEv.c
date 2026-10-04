// Function: MTFilterKernel::CMTStrokeFilter::ReleaseGL()
// RVA: 0x13507c, Size: 80 bytes
int64_t _ZN14MTFilterKernel15CMTStrokeFilter9ReleaseGLEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteTextures(...); // call PLT API at 0x1350a0
    glDeleteFramebuffers(...); // call PLT API at 0x1350b8
    return a0;
}
