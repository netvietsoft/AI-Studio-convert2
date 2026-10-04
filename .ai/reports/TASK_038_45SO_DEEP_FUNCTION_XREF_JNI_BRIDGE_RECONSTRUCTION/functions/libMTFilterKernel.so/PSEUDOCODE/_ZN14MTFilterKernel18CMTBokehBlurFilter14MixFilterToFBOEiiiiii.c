// Function: MTFilterKernel::CMTBokehBlurFilter::MixFilterToFBO(int, int, int, int, int, int)
// RVA: 0x123338, Size: 324 bytes
int64_t _ZN14MTFilterKernel18CMTBokehBlurFilter14MixFilterToFBOEiiiiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x12336c
    glViewport(...); // call PLT API at 0x123380
    glClear(...); // call PLT API at 0x123388
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x123390
    glActiveTexture(...); // call PLT API at 0x123398
    glBindTexture(...); // call PLT API at 0x1233a4
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1233b8
    glActiveTexture(...); // call PLT API at 0x1233c0
    glBindTexture(...); // call PLT API at 0x1233cc
    const char* str = "gradientTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1233e0
    glActiveTexture(...); // call PLT API at 0x1233e8
    glBindTexture(...); // call PLT API at 0x1233f4
    const char* str = "bodyMaskTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x123408
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x123430
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x123458
    glDrawArrays(...); // call PLT API at 0x123478
}
