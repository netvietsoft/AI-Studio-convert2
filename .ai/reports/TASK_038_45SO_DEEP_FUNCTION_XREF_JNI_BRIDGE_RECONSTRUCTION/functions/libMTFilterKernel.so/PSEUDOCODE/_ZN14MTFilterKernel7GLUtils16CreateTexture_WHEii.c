// Function: MTFilterKernel::GLUtils::CreateTexture_WH(int, int)
// RVA: 0x1410d0, Size: 236 bytes
int64_t _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenTextures(...); // call PLT API at 0x141100
    glBindTexture(...); // call PLT API at 0x141110
    glTexImage2D(...); // call PLT API at 0x141138
    glTexParameteri(...); // call PLT API at 0x141148
    glTexParameteri(...); // call PLT API at 0x141158
    glTexParameteri(...); // call PLT API at 0x141168
    glTexParameteri(...); // call PLT API at 0x141178
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1411b8
}
