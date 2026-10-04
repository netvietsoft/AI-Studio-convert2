// Function: MTFilterKernel::GLUtils::getOpenGLSupport(char const*)
// RVA: 0x1462e8, Size: 56 bytes
int64_t _ZN14MTFilterKernel7GLUtils16getOpenGLSupportEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGetString(...); // call PLT API at 0x1462fc
    strstr(...); // call PLT API at 0x146308
    return a0;
}
