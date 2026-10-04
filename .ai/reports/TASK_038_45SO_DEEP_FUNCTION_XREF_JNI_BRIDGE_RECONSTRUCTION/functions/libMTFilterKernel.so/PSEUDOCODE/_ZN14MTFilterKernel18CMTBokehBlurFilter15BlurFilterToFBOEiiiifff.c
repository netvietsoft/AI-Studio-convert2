// Function: MTFilterKernel::CMTBokehBlurFilter::BlurFilterToFBO(int, int, int, int, float, float, float)
// RVA: 0x122e6c, Size: 316 bytes
int64_t _ZN14MTFilterKernel18CMTBokehBlurFilter15BlurFilterToFBOEiiiifff(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x122ea8
    glViewport(...); // call PLT API at 0x122ebc
    glClear(...); // call PLT API at 0x122ec4
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x122ecc
    const char* str = "singleStepOffsetWidth";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x122ee0
    const char* str = "singleStepOffsetHeight";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x122ef4
    const char* str = "type";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x122f08
    glActiveTexture(...); // call PLT API at 0x122f10
    glBindTexture(...); // call PLT API at 0x122f1c
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x122f30
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x122f58
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x122f80
    glDrawArrays(...); // call PLT API at 0x122fa4
}
