// Function: MTFilterKernel::GLUtils::CreateTextureFloat(int, int, float*)
// RVA: 0x1411bc, Size: 240 bytes
int64_t _ZN14MTFilterKernel7GLUtils18CreateTextureFloatEiiPf(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenTextures(...); // call PLT API at 0x1411f0
    glBindTexture(...); // call PLT API at 0x141200
    glTexParameteri(...); // call PLT API at 0x141210
    glTexParameteri(...); // call PLT API at 0x141220
    glTexParameteri(...); // call PLT API at 0x141230
    glTexParameteri(...); // call PLT API at 0x141240
    glTexImage2D(...); // call PLT API at 0x141268
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1412a8
}
