// Function: MTFilterKernel::CMTFilterSoftHair::SoftHairFilterToFBO(int, int, int, int, int, int)
// RVA: 0x134d90, Size: 516 bytes
int64_t _ZN14MTFilterKernel17CMTFilterSoftHair19SoftHairFilterToFBOEiiiiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x134ddc
    glViewport(...); // call PLT API at 0x134df0
    glClear(...); // call PLT API at 0x134df8
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x134e18
    const char* str = "threshold";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x134e2c
    const char* str = "gain";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x134e40
    const char* str = "shiftingSize";
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(...); // call internal at 0x134e70
    const char* str = "kernel";
    _ZN14MTFilterKernel10CGLProgram13SetUniform1fvEPKcPKfi(...); // call internal at 0x134e88
    glActiveTexture(...); // call PLT API at 0x134e90
    glBindTexture(...); // call PLT API at 0x134e9c
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x134eb0
    glActiveTexture(...); // call PLT API at 0x134eb8
    glBindTexture(...); // call PLT API at 0x134ec4
    const char* str = "gradientTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x134ed8
    glActiveTexture(...); // call PLT API at 0x134ee0
    glBindTexture(...); // call PLT API at 0x134eec
    const char* str = "hairMaskTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x134f00
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x134f28
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x134f50
    glDrawArrays(...); // call PLT API at 0x134f60
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x134f90
}
